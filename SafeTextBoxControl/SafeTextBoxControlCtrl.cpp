// SafeTextBoxControlCtrl.cpp : CSafeTextBoxControlCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "SafeTextBoxControl.h"
#include "SafeTextBoxControlCtrl.h"
#include "SafeTextBoxControlPropPage.h"
#include "afxdialogex.h"

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


// CSafeTextBoxControlCtrl::CSafeTextBoxControlCtrl - ���캯��

CSafeTextBoxControlCtrl::CSafeTextBoxControlCtrl()
{
	InitializeIIDs(&IID_DSafeTextBoxControl, &IID_DSafeTextBoxControlEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
	m_pEdit = (CEdit*)this;
}

// CSafeTextBoxControlCtrl::~CSafeTextBoxControlCtrl - ��������

CSafeTextBoxControlCtrl::~CSafeTextBoxControlCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
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
	ModifyStyle(WS_VSCROLL | ES_AUTOVSCROLL | ES_MULTILINE | ES_WANTRETURN, 0);
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


BSTR CSafeTextBoxControlCtrl::GetSafeText()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	int len = m_pEdit->LineLength();
	m_pEdit->GetLine(0, strResult.GetBuffer(len), len);
	strResult.ReleaseBuffer(len);
	// TODO: �ڴ���ӵ��ȴ���������

	return strResult.AllocSysString();
}
