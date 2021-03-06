// SafeTextBoxControlPropPage.cpp : CSafeTextBoxControlPropPage 属性页类的实现。

#include "stdafx.h"
#include "SafeTextBoxControl.h"
#include "SafeTextBoxControlPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CSafeTextBoxControlPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CSafeTextBoxControlPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CSafeTextBoxControlPropPage, "SAFETEXTBOXCON.SafeTextBoxConPropPage.1",
	0x308b39e7, 0xedf3, 0x4263, 0xa6, 0x55, 0xbe, 0x8a, 0x24, 0x75, 0x1a, 0xb0)

// CSafeTextBoxControlPropPage::CSafeTextBoxControlPropPageFactory::UpdateRegistry -
// 添加或移除 CSafeTextBoxControlPropPage 的系统注册表项

BOOL CSafeTextBoxControlPropPage::CSafeTextBoxControlPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_SAFETEXTBOXCONTROL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CSafeTextBoxControlPropPage::CSafeTextBoxControlPropPage - 构造函数

CSafeTextBoxControlPropPage::CSafeTextBoxControlPropPage() :
	COlePropertyPage(IDD, IDS_SAFETEXTBOXCONTROL_PPG_CAPTION)
{
}

// CSafeTextBoxControlPropPage::DoDataExchange - 在页和属性间移动数据

void CSafeTextBoxControlPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CSafeTextBoxControlPropPage 消息处理程序
