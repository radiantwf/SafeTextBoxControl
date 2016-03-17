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
	0x98d55afe, 0x2e8b, 0x4e93, 0x9a, 0xd7, 0x54, 0xeb, 0x5e, 0xaf, 0x31, 0xf5)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CSafeTextBoxControlCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DSafeTextBoxControl = { 0x261FD803, 0x3037, 0x4D70, { 0x9C, 0x93, 0x72, 0xB7, 0x19, 0x65, 0xD1, 0x0 } };
const IID IID_DSafeTextBoxControlEvents = { 0xBB6E9CD7, 0x4898, 0x4140, { 0xA3, 0x11, 0xD6, 0xE9, 0xCA, 0xAA, 0x95, 0x55 } };

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
#define  IDC_EDIT1 1000
void CSafeTextBoxControlCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	m_Edit.Create(WS_CHILD, rcBounds, this, IDC_EDIT1);
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);
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


// CSafeTextBoxControlCtrl ��Ϣ�������
