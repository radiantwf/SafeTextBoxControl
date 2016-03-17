// SafeTextBoxControlCtrl.cpp : CSafeTextBoxControlCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "SafeTextBoxControl.h"
#include "SafeTextBoxControlCtrl.h"
#include "SafeTextBoxControlPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CSafeTextBoxControlCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CSafeTextBoxControlCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CSafeTextBoxControlCtrl, COleControl)
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
	0x98d55afe, 0x2e8b, 0x4e93, 0x9a, 0xd7, 0x54, 0xeb, 0x5e, 0xaf, 0x31, 0xf5)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CSafeTextBoxControlCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DSafeTextBoxControl = { 0x261FD803, 0x3037, 0x4D70, { 0x9C, 0x93, 0x72, 0xB7, 0x19, 0x65, 0xD1, 0x0 } };
const IID IID_DSafeTextBoxControlEvents = { 0xBB6E9CD7, 0x4898, 0x4140, { 0xA3, 0x11, 0xD6, 0xE9, 0xCA, 0xAA, 0x95, 0x55 } };

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


// CSafeTextBoxControlCtrl::CSafeTextBoxControlCtrl - 构造函数

CSafeTextBoxControlCtrl::CSafeTextBoxControlCtrl()
{
	InitializeIIDs(&IID_DSafeTextBoxControl, &IID_DSafeTextBoxControlEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CSafeTextBoxControlCtrl::~CSafeTextBoxControlCtrl - 析构函数

CSafeTextBoxControlCtrl::~CSafeTextBoxControlCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CSafeTextBoxControlCtrl::OnDraw - 绘图函数
#define  IDC_EDIT1 1000
void CSafeTextBoxControlCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	m_Edit.Create(WS_CHILD, rcBounds, this, IDC_EDIT1);
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);
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


// CSafeTextBoxControlCtrl 消息处理程序
