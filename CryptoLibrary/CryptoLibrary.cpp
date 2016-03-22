// CryptoLibrary.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "StdAfx.h"
#include <iostream> 
#include <stdio.h>  
#include "CryptoLibrary.h"
#include "APHash.h"
#include "AES.h"
#include "BASE64.h"

#define AES_KEY_LEGNTH 8
#define HASH_LEGNTH sizeof(unsigned int) * 8


int getAesKey(const char* userKey, unsigned char *aesKey)
{

	unsigned int hash = 0;
	char* tmpKey = new char[sizeof(unsigned int) * 8];
	memset(tmpKey, 0x00, sizeof(unsigned int) * 8);
	if (userKey && *userKey != 0)
	{
		hash = APHash((char *)userKey);
	}
	else
	{
		hash = APHash("nokey");
	}

	sprintf_s(tmpKey, sizeof(unsigned int) * 8, "%u", hash);
	memcpy(aesKey, tmpKey + 4, AES_KEY_LEGNTH);
	delete[] tmpKey;
	return ERROR_SUCCESS;
}

char * __stdcall HISIGN_Encrypt(char * key, char * str)
{
	if (!str && *str == 0)
		return NULL;
	unsigned char aesKey[AES_KEY_LEGNTH];

	int ret = getAesKey(key, aesKey);
	if (ret != ERROR_SUCCESS)
	{
		return NULL;
	}

	// ����
	AES aes(aesKey);

	int strLength = strlen(str) + 1;
	int tmpStrLength = (strlen(str) + 1 + 15) / 16 * 16;
	char *tmpStr = new char[tmpStrLength];
	memset(tmpStr, 0x00, tmpStrLength);
	memcpy_s(tmpStr, tmpStrLength, str, strLength);
	aes.Cipher(tmpStr, tmpStrLength);

	char *encryptoStr = new char[tmpStrLength * 2];
	// ��ʽ�����
	CBase64 base64;
	int realLength = base64.EncodeBase64((unsigned char *)tmpStr, encryptoStr, tmpStrLength, tmpStrLength * 2);
	*(encryptoStr + realLength) = 0x00;
	return encryptoStr;
}

char * __stdcall HISIGN_Decrypt(char * key, char * str)
{
	if (!str && *str == 0)
		return NULL;
	unsigned char aesKey[AES_KEY_LEGNTH];

	int ret = getAesKey(key, aesKey);
	if (ret != ERROR_SUCCESS)
	{
		return NULL;
	}

	// ����
	AES aes(aesKey);

	int strLength = strlen(str);
	char *tmpStr = new char[strLength];
	memset(tmpStr, 0x00, strLength);
	memcpy_s(tmpStr, strLength, str, strLength);
	char *decryptoStr = new char[strLength];

	CBase64 base64;
	int realLength = base64.DecodeBase64(tmpStr, (unsigned char *)decryptoStr, strLength);
	aes.InvCipher(decryptoStr, realLength);

	return decryptoStr;
}
