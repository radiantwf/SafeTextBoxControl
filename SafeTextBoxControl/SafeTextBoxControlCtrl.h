#pragma once

// SafeTextBoxControlCtrl.h : CSafeTextBoxControlCtrl ActiveX �ؼ����������


// CSafeTextBoxControlCtrl : �й�ʵ�ֵ���Ϣ������� SafeTextBoxControlCtrl.cpp��

class CSafeTextBoxControlCtrl : public COleControl
{
	DECLARE_DYNCREATE(CSafeTextBoxControlCtrl)

// ���캯��
public:
	CSafeTextBoxControlCtrl();

// ��Ա
private:
	CEdit edit;

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CSafeTextBoxControlCtrl();

	DECLARE_OLECREATE_EX(CSafeTextBoxControlCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CSafeTextBoxControlCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CSafeTextBoxControlCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CSafeTextBoxControlCtrl)		// �������ƺ�����״̬

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

