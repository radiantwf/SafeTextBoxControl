// CryptoLibrary.cpp : 定义 DLL 应用程序的导出函数。
//

#include "StdAfx.h"
#include "CryptoLibrary.h"
#include "APHash.h"
#include "AES.h"
#include "BASE64.h"

#define AES_KEY_LEGNTH sizeof(unsigned int) * 8
#define HASH_LEGNTH sizeof(unsigned int) * 8

unsigned char * __stdcall HISIGN_Encrypt(const unsigned char * key, const unsigned char * str)
{
	return nullptr;
}

unsigned char * __stdcall HISIGN_Decrypt(const unsigned char * key, const unsigned char * str)
{
	return nullptr;
}
