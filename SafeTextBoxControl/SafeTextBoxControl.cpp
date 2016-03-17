// SafeTextBoxControl.cpp : CSafeTextBoxControlApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "SafeTextBoxControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CSafeTextBoxControlApp theApp;

const GUID CDECL _tlid = { 0xB606A90E, 0xBCA9, 0x402E, { 0x89, 0x38, 0xC5, 0x8D, 0xB2, 0x8A, 0xB8, 0x1F } };
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
