#pragma once

// SafeTextBoxControlCtrl.h : CSafeTextBoxControlCtrl ActiveX 控件类的声明。


// CSafeTextBoxControlCtrl : 有关实现的信息，请参阅 SafeTextBoxControlCtrl.cpp。

class CSafeTextBoxControlCtrl : public COleControl
{
	DECLARE_DYNCREATE(CSafeTextBoxControlCtrl)

// 构造函数
public:
	CSafeTextBoxControlCtrl();

// 成员
private:
	CEdit m_Edit;

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CSafeTextBoxControlCtrl();

	DECLARE_OLECREATE_EX(CSafeTextBoxControlCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CSafeTextBoxControlCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CSafeTextBoxControlCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CSafeTextBoxControlCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
	};
};

