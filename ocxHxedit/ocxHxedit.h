#if !defined(AFX_OCXHXEDIT_H__6D187D14_3FB2_49E4_8972_0CCA2A4B6AEC__INCLUDED_)
#define AFX_OCXHXEDIT_H__6D187D14_3FB2_49E4_8972_0CCA2A4B6AEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// ocxHxedit.h : main header file for OCXHXEDIT.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COcxHxeditApp : See ocxHxedit.cpp for implementation.

class COcxHxeditApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXHXEDIT_H__6D187D14_3FB2_49E4_8972_0CCA2A4B6AEC__INCLUDED)
