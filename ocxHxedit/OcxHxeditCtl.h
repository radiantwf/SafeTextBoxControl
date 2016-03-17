#if !defined(AFX_OCXHXEDITCTL_H__0D9A3744_F7D3_48FE_AE69_628D9C3DD3B9__INCLUDED_)
#define AFX_OCXHXEDITCTL_H__0D9A3744_F7D3_48FE_AE69_628D9C3DD3B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// OcxHxeditCtl.h : Declaration of the COcxHxeditCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// COcxHxeditCtrl : See OcxHxeditCtl.cpp for implementation.
//COcxHxeditCtrl * COcxHxeditCtrl::s_pThis=NULL;
class COcxHxeditCtrl : public COleControl
{
	DECLARE_DYNCREATE(COcxHxeditCtrl)

// Constructor
public:
	COcxHxeditCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COcxHxeditCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation

protected:
	~COcxHxeditCtrl();

	DECLARE_OLECREATE_EX(COcxHxeditCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(COcxHxeditCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(COcxHxeditCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(COcxHxeditCtrl)		// Type name and misc status

	// Subclassed control support
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// Message maps
	//{{AFX_MSG(COcxHxeditCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(COcxHxeditCtrl)
	BOOL m_pwdStatue;
	afx_msg void OnPwdStatueChanged();
	afx_msg BSTR GetPwdText();                //��ȡԭʼ���봮
	afx_msg BSTR GetDonePwd();                //��ȡ���ܺ�����봮
	afx_msg void SetPwdStyle(BOOL pwdStyle);  //ָ���ؼ���ʾ���Ļ����������"*"
	afx_msg void SetStatues();
//	afx_msg void SetKeyText(WPARAM len);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// Event maps
	//{{AFX_EVENT(COcxHxeditCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(COcxHxeditCtrl)
	dispidPwdStatue = 1L,
	dispidGetPwdText = 2L,
	dispidGetDonePwd = 3L,
	dispidSetPwdStyle = 4L,
	dispidSetStatues = 5L,
	//}}AFX_DISP_ID
	};
protected:
	BOOL m_pwdStyle;        //edit����ʾ���ͣ�����/������	
private:
//	BOOL   inline DecryptPwdStr(CString &strPwd);//��������мӡ�����
	BOOL   inline EncryptPwdStr(CString &strPwd, BOOL enStatue);//�����봮���м��ܡ�����
	TCHAR  inline EncryptPwdChar(TCHAR chKey, BOOL bEncrypt);   //�������ַ����мӡ�����
	void   SetHook(BOOL hookStatue);         //װ/ж����
	static LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wParam, LPARAM lParam);
	static BOOL FilterKeyboard(WPARAM wParam, BOOL keyUp);  //���Ǽ�������
	void   AddKeyChar(TCHAR tchKey);         //����һ�������ַ�
	void   DeleteKeyChar();                  //�����봮��һ���ַ���ʼɾ��
	void   BackSpaceKeyChar();               //�����봮���һ���ַ���ʼɾ��
//	void   SetStatues();
	void   SetCursorPosition();              //���ù��λ��
	
private:
	static COcxHxeditCtrl *s_pThis;    //��ǰedit��
	CFont m_font;                      //����
	HHOOK m_kbHook;                    //���̹��Ӿ��  
	CString m_password;
	CEdit *m_pEdit;
	int   m_nStart;
	int   m_nEnd;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXHXEDITCTL_H__0D9A3744_F7D3_48FE_AE69_628D9C3DD3B9__INCLUDED)
