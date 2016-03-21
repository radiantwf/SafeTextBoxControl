#pragma once
#include "StdAfx.h"

#include <Windows.h>
#include <Iphlpapi.h>
#include <iostream> 
#include <stdio.h>  
#include <shlwapi.h>

#include "APHash.h"
#include "AES.h"
#include "BASE64.h"

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "Shlwapi.lib")

extern "C" IMAGE_DOS_HEADER __ImageBase;

#define MACHINE_STR_LEGHTH 500
#define AES_KEY_LEGNTH sizeof(unsigned int) * 8
#define HASH_LEGNTH sizeof(unsigned int) * 8
#define AUTHORIZATION_INFO_LENGTH		200 * 1024

char* AuthorizationInfo = NULL;

struct AuthorizationInfoStruct
{
	char machineStr[MACHINE_STR_LEGHTH];
	time_t beginTime;
	time_t endTime;
	char aesKey[AES_KEY_LEGNTH];
	char beginTimeHash[HASH_LEGNTH];
	char endTimeHash[HASH_LEGNTH];
};

int reloadAuthorizationFile()
{
	using namespace std;
	LPWSTR strModule = new WCHAR[MAX_PATH];
	//得到当前模块路径
	::GetModuleFileName(reinterpret_cast<HMODULE>(&__ImageBase), strModule, MAX_PATH);
	//设置为当前工作路径为当时的上一级
	wstring tmpPath(strModule);
	tmpPath.append(L"//..//live_d.dll");
	FILE* file;
	_wfopen_s(&file, tmpPath.c_str(), L"r");
	delete[] strModule;
	tmpPath.~wstring();
	if (!file)
	{
		return ERROR_ACCESS_DENIED;
	}

	char *str = new char[AUTHORIZATION_INFO_LENGTH];
	memset(str, 0x00, AUTHORIZATION_INFO_LENGTH);
	fread_s(str, AUTHORIZATION_INFO_LENGTH, 1, AUTHORIZATION_INFO_LENGTH, file);
	fclose(file);
	if (!AuthorizationInfo)
		AuthorizationInfo = new char[AUTHORIZATION_INFO_LENGTH];
	memcpy(AuthorizationInfo, str, AUTHORIZATION_INFO_LENGTH);

	delete[] str;
	return ERROR_SUCCESS;
}

int loadAuthorizationFile()
{
	int ret = ERROR_SUCCESS;
	if (!AuthorizationInfo)
	{
		ret = reloadAuthorizationFile();
	}
	return ret;
}

int getMachineStr(char *machineStr, int machineStrSize)
{
	IP_ADAPTER_INFO AdapterInfo[16];			// Allocate information for up to 16 NICs
	DWORD dwBufLen = sizeof(AdapterInfo);		// Save the memory size of buffer

	DWORD dwStatus = GetAdaptersInfo(			// Call GetAdapterInfo
		AdapterInfo,							// [out] buffer to receive data
		&dwBufLen);								// [in] size of receive data buffer
	if (dwStatus != ERROR_SUCCESS)
		return dwStatus;

	char *mac = new char[18];
	memset(mac, 0, 18);

	PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;// Contains pointer to current adapter info
	do {
		if (pAdapterInfo->Type == MIB_IF_TYPE_ETHERNET && !strcmp((char*)&pAdapterInfo->IpAddressList.IpAddress, "0.0.0.0") == 0)
		{
			sprintf_s(mac, 18, "%02X-%02X-%02X-%02X-%02X-%02X", pAdapterInfo->Address[0], pAdapterInfo->Address[1], pAdapterInfo->Address[2], pAdapterInfo->Address[3], pAdapterInfo->Address[4], pAdapterInfo->Address[5]);
			break;
		}

		pAdapterInfo = pAdapterInfo->Next;		// Progress through linked list
	} while (pAdapterInfo);						// Terminate if last adapter

	if (strlen(mac) == 0)
	{
		delete[] mac;
		return ERROR_DEVICE_IN_USE;
	}


	char *strHash = new char[machineStrSize];
	char *tmpMachineStr = new char[machineStrSize];
	memset(tmpMachineStr, 0, machineStrSize);

	for (int i = 0; i < 6; i++)
	{
		if (i > 0)
			strcat_s(tmpMachineStr, machineStrSize, "-");

		unsigned int hash = i == 0 ? APHash(mac) : APHash(tmpMachineStr);

		sprintf_s(strHash, sizeof(unsigned int) * 8, "%u", hash);
		strcat_s(tmpMachineStr, machineStrSize, strHash);
	}
	memcpy(machineStr, tmpMachineStr, machineStrSize);

	delete[] mac;
	delete[] strHash;
	delete[] tmpMachineStr;

	return ERROR_SUCCESS;
}

int createMachineIdFile()
{
	using namespace std;
	LPWSTR strModule = new WCHAR[MAX_PATH];
	//得到当前模块路径
	::GetModuleFileName(reinterpret_cast<HMODULE>(&__ImageBase), strModule, MAX_PATH);
	//设置为当前工作路径为当时的上一级
	wstring tmpPath(strModule);
	tmpPath.append(L"//..//machine.id");
	delete[] strModule;

	if (PathFileExists(tmpPath.c_str()))
	{
		tmpPath.~wstring();
		return ERROR_SUCCESS;
	}

	FILE* file;
	_wfopen_s(&file, tmpPath.c_str(), L"w");
	tmpPath.~wstring();

	if (!file)
	{
		return ERROR_ACCESS_DENIED;
	}

	char *machineStr = new char[MACHINE_STR_LEGHTH];
	int ret = getMachineStr(machineStr, MACHINE_STR_LEGHTH);
	if (ret != ERROR_SUCCESS)
	{
		return ret;
	}

	fputs(machineStr, file);
	fclose(file);
	delete[] machineStr;
	return ERROR_SUCCESS;
}

int getAesKey(char* machineStr, char *key)
{
	unsigned int hash = APHash(machineStr);

	sprintf_s(key, AES_KEY_LEGNTH, "%u", hash);

	return ERROR_SUCCESS;
}

char * createAuthorizationStr(char* machineStr, int days)
{
	if (days <= 0)
	{
		return NULL;
	}

	// 构造授权信息（原始）
	AuthorizationInfoStruct info;
	// 设备字符串
	memcpy_s(info.machineStr, MACHINE_STR_LEGHTH, machineStr, MACHINE_STR_LEGHTH);

	// AES算法密钥
	char aesKey[AES_KEY_LEGNTH];
	int ret = getAesKey(machineStr, aesKey);
	if (ret != ERROR_SUCCESS)
	{
		return NULL;
	}
	memcpy_s(info.aesKey, AES_KEY_LEGNTH, aesKey, AES_KEY_LEGNTH);

	// 授权日期
	time_t beginDate;
	tm tt;
	time(&beginDate);
	localtime_s(&tt, &beginDate);
	tt.tm_sec = 0;
	tt.tm_min = 0;
	tt.tm_hour = 0;
	beginDate = mktime(&tt);
	time_t endDate = beginDate + 3600 * 24 * days;
	info.beginTime = beginDate;
	info.endTime = endDate;

	// 授权日期Hash值
	unsigned char tmp[sizeof(time_t)];
	memcpy(tmp, &beginDate, sizeof(time_t));
	unsigned int hash = APHash(tmp, sizeof(time_t));
	sprintf_s(info.beginTimeHash, HASH_LEGNTH, "%u", hash);
	memcpy(tmp, &endDate, sizeof(time_t));
	hash = APHash(tmp, sizeof(time_t));
	sprintf_s(info.endTimeHash, HASH_LEGNTH, "%u", hash);

	char *authorizationStr = new char[AUTHORIZATION_INFO_LENGTH];

	// 加密
	unsigned char key[8];
	memcpy(key, aesKey, 8);
	AES aes((unsigned char *)key);
	aes.Cipher(&info, sizeof(AuthorizationInfoStruct) / 16 * 16);

	// 格式化输出
	CBase64 base64;
	base64.EncodeBase64((unsigned char *)&info, authorizationStr, sizeof(AuthorizationInfoStruct), AUTHORIZATION_INFO_LENGTH);

	return authorizationStr;
}

int createAuthorizationFile()
{
	using namespace std;
	LPWSTR strInputModule = new WCHAR[MAX_PATH];
	//得到当前模块路径
	::GetModuleFileName(reinterpret_cast<HMODULE>(&__ImageBase), strInputModule, MAX_PATH);
	//设置为当前工作路径为当时的上一级
	wstring tmpInputPath(strInputModule);
	delete[] strInputModule;
	tmpInputPath.append(L"//..//machine.id");
	FILE* inputFile = NULL;
	_wfopen_s(&inputFile, tmpInputPath.c_str(), L"r");

	tmpInputPath.~wstring();
	if (!inputFile)
	{
		return ERROR_ACCESS_DENIED;
	}

	char *machineStr = new char[AUTHORIZATION_INFO_LENGTH];
	memset(machineStr, 0x00, AUTHORIZATION_INFO_LENGTH);
	fread_s(machineStr, AUTHORIZATION_INFO_LENGTH, 1, AUTHORIZATION_INFO_LENGTH, inputFile);
	fclose(inputFile);

	char *authorizationStr = createAuthorizationStr(machineStr, 30 * 3);
	if (!authorizationStr)
	{
		return ERROR_ACCESS_DENIED;
	}

	LPWSTR strOutputModule = new WCHAR[MAX_PATH];
	//得到当前模块路径
	::GetModuleFileName(reinterpret_cast<HMODULE>(&__ImageBase), strOutputModule, MAX_PATH);
	//设置为当前工作路径为当时的上一级
	wstring tmpOutputPath(strOutputModule);
	tmpOutputPath.append(L"//..//live_d.dll");
	FILE* outputFile;
	_wfopen_s(&outputFile, tmpOutputPath.c_str(), L"w");
	delete[] strOutputModule;
	tmpOutputPath.~wstring();

	if (!outputFile)
	{
		return ERROR_ACCESS_DENIED;
	}

	fputs(authorizationStr, outputFile);
	fclose(outputFile);
	delete[] authorizationStr;
	return ERROR_SUCCESS;
}

int checkAuthorization()
{
	if (!AuthorizationInfo)
	{
		return ERROR_REQUEST_REFUSED;
	}

	// 获取机器码
	char machineStr[MACHINE_STR_LEGHTH];
	int ret = getMachineStr(machineStr, MACHINE_STR_LEGHTH);
	if (ret != ERROR_SUCCESS)
	{
		return ret;
	}

	// AES算法密钥
	char aesKey[AES_KEY_LEGNTH];
	ret = getAesKey(machineStr, aesKey);
	if (ret != ERROR_SUCCESS)
	{
		return ret;
	}

	// 解密
	unsigned char key[8];
	memcpy(key, aesKey, 8);
	AES aes((unsigned char *)key);
	AuthorizationInfoStruct info;
	CBase64 base64;
	base64.DecodeBase64(AuthorizationInfo, (unsigned char *)&info, (int)strlen(AuthorizationInfo));
	aes.InvCipher(&info, sizeof(AuthorizationInfoStruct) / 16 * 16);

	// 授权日期Hash值
	char beginTimeHash[HASH_LEGNTH], endTimeHash[HASH_LEGNTH];
	time_t t;
	memcpy(&t, &info.beginTime, sizeof(time_t));
	unsigned int hash = APHash((unsigned char *)&t, sizeof(time_t));
	sprintf_s(beginTimeHash, HASH_LEGNTH, "%u", hash);
	memcpy(&t, &info.endTime, sizeof(time_t));
	hash = APHash((unsigned char *)&t, sizeof(time_t));
	sprintf_s(endTimeHash, HASH_LEGNTH, "%u", hash);

	// 当前日期
	time_t todayDate;
	tm tt;
	time(&todayDate);
	localtime_s(&tt, &todayDate);
	tt.tm_sec = 0;
	tt.tm_min = 0;
	tt.tm_hour = 0;
	todayDate = mktime(&tt);

	if (!(strcmp(machineStr, info.machineStr) == 0
		&& strcmp(aesKey, info.aesKey) == 0
		&& strcmp(beginTimeHash, info.beginTimeHash) == 0
		&& strcmp(endTimeHash, info.endTimeHash) == 0))
	{
		return ERROR_DECRYPTION_FAILED;
	}

	if (todayDate >= info.beginTime && todayDate <= info.endTime)
	{
		return ERROR_SUCCESS;
	}

	return ERROR_REQUEST_REFUSED;
}
