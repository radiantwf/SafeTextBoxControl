// SafeTextBoxControlCtrl.cpp : CSafeTextBoxControlCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "SafeTextBoxControl.h"
#include "SafeTextBoxControlCtrl.h"
#include "SafeTextBoxControlPropPage.h"
#include "afxdialogex.h"
#include <hash_set>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CSafeTextBoxControlCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CSafeTextBoxControlCtrl, COleControl)
	ON_MESSAGE(OCM_COMMAND, &CSafeTextBoxControlCtrl::OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CSafeTextBoxControlCtrl, COleControl)
	DISP_PROPERTY_EX_ID(CSafeTextBoxControlCtrl, "SafeText", dispidSafeText, GetSafeText, SetNotSupported, VT_BSTR)
	DISP_STOCKPROP_TEXT()
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CSafeTextBoxControlCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO:  ����Ҫ��Ӹ�������ҳ��  ���ס���Ӽ���!
BEGIN_PROPPAGEIDS(CSafeTextBoxControlCtrl, 1)
	PROPPAGEID(CSafeTextBoxControlPropPage::guid)
END_PROPPAGEIDS(CSafeTextBoxControlCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CSafeTextBoxControlCtrl, "SAFETEXTBOXCONTR.SafeTextBoxContrCtrl.1",
	0xd40c51e, 0x2774, 0x4ff7, 0x94, 0x62, 0x57, 0x9, 0x16, 0x53, 0xaa, 0x87)

	// ����� ID �Ͱ汾

	IMPLEMENT_OLETYPELIB(CSafeTextBoxControlCtrl, _tlid, _wVerMajor, _wVerMinor)

	// �ӿ� ID

	const IID IID_DSafeTextBoxControl = { 0xDE709E5D, 0x8662, 0x4A83, { 0x92, 0x73, 0xA, 0xF3, 0x59, 0xB9, 0x1A, 0xB1 } };
const IID IID_DSafeTextBoxControlEvents = { 0xAD32A0DC, 0x6667, 0x45F0, { 0x9C, 0x64, 0xF0, 0x8C, 0x26, 0x2C, 0x93, 0x72 } };

// �ؼ�������Ϣ

static const DWORD _dwSafeTextBoxControlOleMisc =
OLEMISC_ACTIVATEWHENVISIBLE |
OLEMISC_SETCLIENTSITEFIRST |
OLEMISC_INSIDEOUT |
OLEMISC_CANTLINKINSIDE |
OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CSafeTextBoxControlCtrl, IDS_SAFETEXTBOXCONTROL, _dwSafeTextBoxControlOleMisc)

// CSafeTextBoxControlCtrl::CSafeTextBoxControlCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CSafeTextBoxControlCtrl ��ϵͳע�����

BOOL CSafeTextBoxControlCtrl::CSafeTextBoxControlCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

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

HHOOK hCallWndProcHook = NULL;
HHOOK hCallWndProcRetHook = NULL;
stdext::hash_set<CEdit*> hsEdit;
stdext::hash_set<HINSTANCE> hsHinstance;

// CSafeTextBoxControlCtrl::CSafeTextBoxControlCtrl - ���캯��
CSafeTextBoxControlCtrl::CSafeTextBoxControlCtrl()
{
	InitializeIIDs(&IID_DSafeTextBoxControl, &IID_DSafeTextBoxControlEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
	m_pEdit = (CEdit*)this;
	hsEdit.insert(m_pEdit);
}

// CSafeTextBoxControlCtrl::~CSafeTextBoxControlCtrl - ��������

CSafeTextBoxControlCtrl::~CSafeTextBoxControlCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
	hsEdit.erase(m_pEdit);
}

// CSafeTextBoxControlCtrl::OnDraw - ��ͼ����

void CSafeTextBoxControlCtrl::OnDraw(
	CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	DoSuperclassPaint(pdc, rcBounds);
}

// CSafeTextBoxControlCtrl::DoPropExchange - �־���֧��

void CSafeTextBoxControlCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CSafeTextBoxControlCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CSafeTextBoxControlCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CSafeTextBoxControlCtrl::PreCreateWindow - �޸� CreateWindowEx �Ĳ���

BOOL CSafeTextBoxControlCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("EDIT");
	BOOL bRet = COleControl::PreCreateWindow(cs);
	cs.hMenu = NULL;
	cs.style |= ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN;
	//hCallWndProcHook = SetWindowsHookEx(WH_CALLWNDPROC, (HOOKPROC)CallWndProc, wnd->GetSafeHwnd, GetCurrentThreadId());
	HINSTANCE ht = AfxGetInstanceHandle();
	if (hsHinstance.find(ht) == hsHinstance.end())
	{
		hCallWndProcHook = ::SetWindowsHookEx(WH_CALLWNDPROC, CallWndProc, AfxGetInstanceHandle(), 0);
		hCallWndProcRetHook = ::SetWindowsHookEx(WH_CALLWNDPROCRET, CallWndProcRet, AfxGetInstanceHandle(), 0);

		hsHinstance.insert(ht);
	}
	return bRet;
}

// CSafeTextBoxControlCtrl::IsSubclassedControl - ����һ������ؼ�

BOOL CSafeTextBoxControlCtrl::IsSubclassedControl()
{
	return TRUE;
}

// CSafeTextBoxControlCtrl::OnOcmCommand - ����������Ϣ

LRESULT CSafeTextBoxControlCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

	// TODO:  �ڴ˽�ͨ wNotifyCode��

	return 0;
}


// CSafeTextBoxControlCtrl ��Ϣ�������


BOOL CSafeTextBoxControlCtrl::PreTranslateMessage(MSG* pMsg)
{
	return COleControl::PreTranslateMessage(pMsg);
}

BSTR CSafeTextBoxControlCtrl::GetSafeText()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: �ڴ���ӵ��ȴ���������
	//int len = m_pEdit->GetWindowTextLengthW();
	//m_pEdit->GetWindowTextW(strResult);
	//strResult.ReleaseBuffer(len);
	strResult.Format(L"%s", this->GetText());
	return strResult.AllocSysString();
}

BOOL bPasteFlag = FALSE;
CString sEditContext;

//���Ӻ���
LRESULT CALLBACK CSafeTextBoxControlCtrl::CallWndProc(int code, WPARAM wParam, LPARAM lParam)
{
	CWnd *topWnd = (CWnd *)::GetTopWindow(NULL);
	CEdit *wnd = (CEdit *)topWnd->GetFocus();
	CWPSTRUCT *pMsg = (CWPSTRUCT*)lParam;
	if (code == HC_ACTION && hsEdit.find(wnd) != hsEdit.end())
	{
		switch (pMsg->message)
		{
		case WM_PASTE:
			bPasteFlag = TRUE;

			sEditContext.Format(L"%s", ((CSafeTextBoxControlCtrl *)wnd)->GetText());
		}
	}
	//������ȫ�ֹ��ӻ����Ϣ
	return CallNextHookEx(hCallWndProcHook, code, wParam, lParam);
}

LRESULT CALLBACK CSafeTextBoxControlCtrl::CallWndProcRet(int code, WPARAM wParam, LPARAM lParam)
{
	if (bPasteFlag)
	{
		CWPRETSTRUCT *pMsg = (CWPRETSTRUCT*)lParam;
		bPasteFlag = FALSE;
		CWnd *topWnd = (CWnd *)::GetTopWindow(NULL);
		CEdit *wnd = (CEdit *)topWnd->GetFocus();
		((CSafeTextBoxControlCtrl *)wnd)->SetText(sEditContext.AllocSysString());
		sEditContext.Empty();
	}
	return CallNextHookEx(hCallWndProcRetHook, code, wParam, lParam);
}
