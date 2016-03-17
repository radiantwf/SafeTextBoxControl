#pragma once

// SafeTextBoxControlCtrl.h : CSafeTextBoxControlCtrl ActiveX �ؼ����������


// CSafeTextBoxControlCtrl : �й�ʵ�ֵ���Ϣ������� SafeTextBoxControlCtrl.cpp��

class CSafeTextBoxControlCtrl : public COleControl
{
	DECLARE_DYNCREATE(CSafeTextBoxControlCtrl)

// ���캯��
public:
	CSafeTextBoxControlCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CSafeTextBoxControlCtrl();

	DECLARE_OLECREATE_EX(CSafeTextBoxControlCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CSafeTextBoxControlCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CSafeTextBoxControlCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CSafeTextBoxControlCtrl)		// �������ƺ�����״̬

	// ����ؼ�֧��
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
	};
};

