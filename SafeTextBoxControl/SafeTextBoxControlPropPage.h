#pragma once

// SafeTextBoxControlPropPage.h : CSafeTextBoxControlPropPage ����ҳ���������


// CSafeTextBoxControlPropPage : �й�ʵ�ֵ���Ϣ������� SafeTextBoxControlPropPage.cpp��

class CSafeTextBoxControlPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CSafeTextBoxControlPropPage)
	DECLARE_OLECREATE_EX(CSafeTextBoxControlPropPage)

// ���캯��
public:
	CSafeTextBoxControlPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_SAFETEXTBOXCONTROL };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

