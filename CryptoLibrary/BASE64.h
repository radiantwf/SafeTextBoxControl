// Base64.h: interface for the CBase64 class.
//
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_BASE64_H__8D85F486_CD10_4A0A_A689_2299C9DE52CB__INCLUDED_)
#define AFX_BASE64_H__8D85F486_CD10_4A0A_A689_2299C9DE52CB__INCLUDED_

#pragma once

#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )

class DllExport CBase64
{
public:
	CBase64();
	virtual ~CBase64();
public:
	int DecodeBase64(const char* pSrc, unsigned char* pDst, int nSrcLen);
	int EncodeBase64(const unsigned char* pSrc, char* pDst, int nSrcLen, int nMaxLineLen);
};

#endif // !defined(AFX_BASE64_H__8D85F486_CD10_4A0A_A689_2299C9DE52CB__INCLUDED_)