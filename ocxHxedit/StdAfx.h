#if !defined(AFX_STDAFX_H__BF59DC4A_07A0_4C12_9744_6D82DDA414DE__INCLUDED_)
#define AFX_STDAFX_H__BF59DC4A_07A0_4C12_9744_6D82DDA414DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently
#define  _WIN32_WINNT   0x0500
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#include <afxwin.h>
#include <afxctl.h>         // MFC support for ActiveX Controls
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Comon Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

// Delete the two includes below if you do not wish to use the MFC
//  database classes
#include <afxdb.h>			// MFC database classes
#include <afxdao.h>			// MFC DAO database classes

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__BF59DC4A_07A0_4C12_9744_6D82DDA414DE__INCLUDED_)
