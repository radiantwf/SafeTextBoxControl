// SafeTextBoxControl.cpp : CSafeTextBoxControlApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "SafeTextBoxControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CSafeTextBoxControlApp theApp;

const GUID CDECL _tlid = { 0xB67B4780, 0xD0E1, 0x4017, { 0x96, 0x25, 0xD8, 0xF1, 0x23, 0x40, 0x92, 0xE9 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CSafeTextBoxControlApp::InitInstance - DLL 初始化

BOOL CSafeTextBoxControlApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CSafeTextBoxControlApp::ExitInstance - DLL 终止

int CSafeTextBoxControlApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
