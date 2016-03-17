// SafeTextBoxControlPropPage.cpp : CSafeTextBoxControlPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "SafeTextBoxControl.h"
#include "SafeTextBoxControlPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CSafeTextBoxControlPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CSafeTextBoxControlPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CSafeTextBoxControlPropPage, "SAFETEXTBOXCON.SafeTextBoxConPropPage.1",
	0xae3697f6, 0xc3c6, 0x450c, 0xa2, 0x92, 0x1c, 0x6d, 0x8a, 0x7a, 0x55, 0x4a)

// CSafeTextBoxControlPropPage::CSafeTextBoxControlPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CSafeTextBoxControlPropPage ��ϵͳע�����

BOOL CSafeTextBoxControlPropPage::CSafeTextBoxControlPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_SAFETEXTBOXCONTROL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CSafeTextBoxControlPropPage::CSafeTextBoxControlPropPage - ���캯��

CSafeTextBoxControlPropPage::CSafeTextBoxControlPropPage() :
	COlePropertyPage(IDD, IDS_SAFETEXTBOXCONTROL_PPG_CAPTION)
{
}

// CSafeTextBoxControlPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CSafeTextBoxControlPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CSafeTextBoxControlPropPage ��Ϣ�������
