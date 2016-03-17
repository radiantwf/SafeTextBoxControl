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
	ON_MESSAGE(OCM_COMMAND, &CSafeTextBoxControlCtrl::OnOcmCommand)
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
	0x482a86f5, 0x7f2e, 0x48a5, 0x92, 0xc0, 0x72, 0x7f, 0x72, 0xe, 0xa0, 0x5a)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CSafeTextBoxControlCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DSafeTextBoxControl = { 0xA560FDF4, 0x4DBD, 0x476D, { 0x8D, 0x48, 0xE6, 0x5A, 0x35, 0x4F, 0x7E, 0xCE } };
const IID IID_DSafeTextBoxControlEvents = { 0xB854B739, 0xADCF, 0x4E1D, { 0x80, 0xE2, 0xBC, 0x25, 0xFE, 0x8D, 0xB1, 0x7A } };

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
