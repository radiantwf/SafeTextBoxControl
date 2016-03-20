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
	virtual BOOL CSafeTextBoxControlCtrl::PreTranslateMessage(MSG* pMsg);

// ��Ա
private:
	CEdit *m_pEdit;
	static LRESULT CALLBACK CallWndProc(int code, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK CallWndProcRet(int code, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK CallCBT(int code, WPARAM wParam, LPARAM lParam);

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
		dispidSafeText = 1L,
	};
	
protected:
	BSTR GetSafeText();
};

