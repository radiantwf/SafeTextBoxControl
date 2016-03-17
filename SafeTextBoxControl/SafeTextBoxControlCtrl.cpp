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
	0x482a86f5, 0x7f2e, 0x48a5, 0x92, 0xc0, 0x72, 0x7f, 0x72, 0xe, 0xa0, 0x5a)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CSafeTextBoxControlCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DSafeTextBoxControl = { 0xA560FDF4, 0x4DBD, 0x476D, { 0x8D, 0x48, 0xE6, 0x5A, 0x35, 0x4F, 0x7E, 0xCE } };
const IID IID_DSafeTextBoxControlEvents = { 0xB854B739, 0xADCF, 0x4E1D, { 0x80, 0xE2, 0xBC, 0x25, 0xFE, 0x8D, 0xB1, 0x7A } };

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
