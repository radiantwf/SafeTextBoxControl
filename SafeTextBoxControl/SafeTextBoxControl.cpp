// SafeTextBoxControl.cpp : CSafeTextBoxControlApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "SafeTextBoxControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CSafeTextBoxControlApp theApp;

const GUID CDECL _tlid = { 0x2A9D671E, 0xF64E, 0x4C43, { 0xBA, 0xE8, 0x31, 0x24, 0x90, 0x9F, 0xFE, 0xD1 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CSafeTextBoxControlApp::InitInstance - DLL ��ʼ��

BOOL CSafeTextBoxControlApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CSafeTextBoxControlApp::ExitInstance - DLL ��ֹ

int CSafeTextBoxControlApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
