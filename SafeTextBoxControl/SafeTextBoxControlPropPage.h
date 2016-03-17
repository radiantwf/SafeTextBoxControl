#pragma once

// SafeTextBoxControlPropPage.h : CSafeTextBoxControlPropPage 属性页类的声明。


// CSafeTextBoxControlPropPage : 有关实现的信息，请参阅 SafeTextBoxControlPropPage.cpp。

class CSafeTextBoxControlPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CSafeTextBoxControlPropPage)
	DECLARE_OLECREATE_EX(CSafeTextBoxControlPropPage)

// 构造函数
public:
	CSafeTextBoxControlPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_SAFETEXTBOXCONTROL };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

