// SafeTextBoxControlCtrl.cpp : CSafeTextBoxControlCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "SafeTextBoxControl.h"
#include "SafeTextBoxControlCtrl.h"
#include "SafeTextBoxControlPropPage.h"
#include "..\\CryptoLibrary\\CryptoLibrary.h"
#include "afxdialogex.h"
#include <hash_set>
#include <comdef.h>
#include <comutil.h>
#include <stdio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(lib, "comsupp.lib")
#pragma comment(lib, "..\\Debug\\CryptoLibrary.lib")

IMPLEMENT_DYNCREATE(CSafeTextBoxControlCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CSafeTextBoxControlCtrl, COleControl)
	ON_MESSAGE(OCM_COMMAND, &CSafeTextBoxControlCtrl::OnOcmCommand)
	ON_MESSAGE(WM_PASTE, OnPaste)
	ON_MESSAGE(WM_CONTEXTMENU, OnContextMenu)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CSafeTextBoxControlCtrl, COleControl)
	DISP_PROPERTY_EX_ID(CSafeTextBoxControlCtrl, "SafeText", dispidSafeText, GetSafeText, SetNotSupported, VT_BSTR)
	DISP_STOCKPROP_TEXT()
	DISP_PROPERTY_ID(CSafeTextBoxControlCtrl, "SafeKey", dispidSafeKey, m_SafeKey, VT_BSTR)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CSafeTextBoxControlCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO:  按需要添加更多属性页。  请记住增加计数!
BEGIN_PROPPAGEIDS(CSafeTextBoxControlCtrl, 1)
	PROPPAGEID(CSafeTextBoxControlPropPage::guid)
END_PROPPAGEIDS(CSafeTextBoxControlCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CSafeTextBoxControlCtrl, "SAFETEXTBOXCONTR.SafeTextBoxContrCtrl.1",
	0xd40c51e, 0x2774, 0x4ff7, 0x94, 0x62, 0x57, 0x9, 0x16, 0x53, 0xaa, 0x87)

	// 键入库 ID 和版本

	IMPLEMENT_OLETYPELIB(CSafeTextBoxControlCtrl, _tlid, _wVerMajor, _wVerMinor)

	// 接口 ID

	const IID IID_DSafeTextBoxControl = { 0xDE709E5D, 0x8662, 0x4A83, { 0x92, 0x73, 0xA, 0xF3, 0x59, 0xB9, 0x1A, 0xB1 } };
const IID IID_DSafeTextBoxControlEvents = { 0xAD32A0DC, 0x6667, 0x45F0, { 0x9C, 0x64, 0xF0, 0x8C, 0x26, 0x2C, 0x93, 0x72 } };

// 控件类型信息

static const DWORD _dwSafeTextBoxControlOleMisc =
OLEMISC_ACTIVATEWHENVISIBLE |
OLEMISC_SETCLIENTSITEFIRST |
OLEMISC_INSIDEOUT |
OLEMISC_CANTLINKINSIDE |
OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CSafeTextBoxControlCtrl, IDS_SAFETEXTBOXCONTROL, _dwSafeTextBoxControlOleMisc)

// CSafeTextBoxControlCtrl::CSafeTextBoxControlCtrlFactory::UpdateRegistry -
// 添加或移除 CSafeTextBoxControlCtrl 的系统注册表项

BOOL CSafeTextBoxControlCtrl::CSafeTextBoxControlCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_SAFETEXTBOXCONTROL,
			IDB_SAFETEXTBOXCONTROL,
			afxRegApartmentThreading,
			_dwSafeTextBoxControlOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}

//HHOOK hCallWndProcHook = NULL;
//HHOOK hCallWndProcRetHook = NULL;
//HHOOK hCallCBTHook = NULL;

//stdext::hash_set<CEdit*> hsEdit;
//stdext::hash_set<HINSTANCE> hsHinstance;

// CSafeTextBoxControlCtrl::CSafeTextBoxControlCtrl - 构造函数
CSafeTextBoxControlCtrl::CSafeTextBoxControlCtrl()
{
	InitializeIIDs(&IID_DSafeTextBoxControl, &IID_DSafeTextBoxControlEvents);
	// TODO:  在此初始化控件的实例数据。
	m_pEdit = (CEdit*)this;
	//hsEdit.insert(m_pEdit);
	m_SafeKey.Empty();
}

// CSafeTextBoxControlCtrl::~CSafeTextBoxControlCtrl - 析构函数

CSafeTextBoxControlCtrl::~CSafeTextBoxControlCtrl()
{
	// TODO:  在此清理控件的实例数据。
	//hsEdit.erase(m_pEdit);
}

// CSafeTextBoxControlCtrl::OnDraw - 绘图函数

void CSafeTextBoxControlCtrl::OnDraw(
	CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	DoSuperclassPaint(pdc, rcBounds);
}

// CSafeTextBoxControlCtrl::DoPropExchange - 持久性支持

void CSafeTextBoxControlCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}


// CSafeTextBoxControlCtrl::OnResetState - 将控件重置为默认状态

void CSafeTextBoxControlCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CSafeTextBoxControlCtrl::PreCreateWindow - 修改 CreateWindowEx 的参数

BOOL CSafeTextBoxControlCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("EDIT");
	BOOL bRet = COleControl::PreCreateWindow(cs);
	cs.hMenu = NULL;
	cs.style |= ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN;
	//HINSTANCE ht = AfxGetInstanceHandle();
	//if (hsHinstance.find(ht) == hsHinstance.end())
	//{
	//	hCallWndProcHook = ::SetWindowsHookEx(WH_CALLWNDPROC, CallWndProc, AfxGetInstanceHandle(), 0);
	//	hCallWndProcRetHook = ::SetWindowsHookEx(WH_CALLWNDPROCRET, CallWndProcRet, AfxGetInstanceHandle(), 0);
	//	hCallCBTHook = ::SetWindowsHookEx(WH_CBT, CallCBT, AfxGetInstanceHandle(), 0);

	//	hsHinstance.insert(ht);
	//}
	return bRet;
}

// CSafeTextBoxControlCtrl::IsSubclassedControl - 这是一个子类控件

BOOL CSafeTextBoxControlCtrl::IsSubclassedControl()
{
	return TRUE;
}

// CSafeTextBoxControlCtrl::OnOcmCommand - 处理命令消息

LRESULT CSafeTextBoxControlCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

	// TODO:  在此接通 wNotifyCode。

	return 0;
}


// CSafeTextBoxControlCtrl 消息处理程序


BOOL CSafeTextBoxControlCtrl::PreTranslateMessage(MSG* pMsg)
{
	return COleControl::PreTranslateMessage(pMsg);
}

BSTR CSafeTextBoxControlCtrl::GetSafeText()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	m_SafeKey = L"你好么？";
	// TODO: 在此添加调度处理程序代码
	strResult.Format(L"%s", this->GetText());
	char* tmp = _com_util::ConvertBSTRToString(strResult.AllocSysString());
	char* key =_com_util::ConvertBSTRToString(m_SafeKey.AllocSysString());
	//strResult.~CStringT();
	char* encryptStr = HISIGN_Encrypt(key, tmp);
	delete[] tmp;
	BSTR encryptResult = CComBSTR(encryptStr);
	delete[] encryptStr;
	char* encryptStr2 = _com_util::ConvertBSTRToString(encryptResult);
	SysFreeString(encryptResult);
	char *decryptStr = HISIGN_Decrypt(key, encryptStr2);
	delete[] encryptStr2;
	BSTR strResult3 = CComBSTR(decryptStr);
	return strResult3;
}


LRESULT CSafeTextBoxControlCtrl::OnPaste(WPARAM w, LPARAM l)
{
	return TRUE;
}

LRESULT CSafeTextBoxControlCtrl::OnContextMenu(WPARAM w, LPARAM l)
{
	return TRUE;
}

//BOOL bPasteFlag = FALSE;
//CString sEditContext;
//
////钩子函数
//LRESULT CALLBACK CSafeTextBoxControlCtrl::CallWndProc(int code, WPARAM wParam, LPARAM lParam)
//{
//	//CWnd *topWnd = (CWnd *)::GetTopWindow(NULL);
//	//CEdit *wnd = (CEdit *)topWnd->GetFocus();
//	//CWPSTRUCT *pMsg = (CWPSTRUCT*)lParam;
//	//if (code == HC_ACTION && hsEdit.find(wnd) != hsEdit.end())
//	//{
//	//	switch (pMsg->message)
//	//	{
//	//	case WM_PASTE:
//	//		bPasteFlag = TRUE;
//	//		sEditContext.Format(L"%s", ((CSafeTextBoxControlCtrl *)wnd)->GetText());
//	//	}
//	//}
//	//让其他全局钩子获得消息
//	return CallNextHookEx(hCallWndProcHook, code, wParam, lParam);
//}
//
//LRESULT CALLBACK CSafeTextBoxControlCtrl::CallWndProcRet(int code, WPARAM wParam, LPARAM lParam)
//{
//	if (bPasteFlag)
//	{
//		CWPRETSTRUCT *pMsg = (CWPRETSTRUCT*)lParam;
//
//		CWnd *topWnd = (CWnd *)::GetTopWindow(NULL);
//		CEdit *wnd = (CEdit *)topWnd->GetFocus();
//		((CSafeTextBoxControlCtrl *)wnd)->SetText(sEditContext.AllocSysString());
//		return true;
//	}
//	return CallNextHookEx(hCallWndProcRetHook, code, wParam, lParam);
//}
//LRESULT CALLBACK CSafeTextBoxControlCtrl::CallCBT(int code, WPARAM wParam, LPARAM lParam)
//{
//	if (bPasteFlag)
//	{
//		bPasteFlag = FALSE;
//		CWPRETSTRUCT *pMsg = (CWPRETSTRUCT*)lParam;
//
//		CWnd *topWnd = (CWnd *)::GetTopWindow(NULL);
//		CEdit *wnd = (CEdit *)topWnd->GetFocus();
//		int start, end;
//		((CSafeTextBoxControlCtrl *)wnd)->SetText(sEditContext.AllocSysString());
//		wnd->SetSel(0, -1);
//		return true;
//	}
//	return CallNextHookEx(hCallCBTHook, code, wParam, lParam);
//}
