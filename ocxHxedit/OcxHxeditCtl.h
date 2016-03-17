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
	afx_msg BSTR GetPwdText();                //获取原始密码串
	afx_msg BSTR GetDonePwd();                //获取加密后的密码串
	afx_msg void SetPwdStyle(BOOL pwdStyle);  //指定控件显示明文还是密码符号"*"
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
	BOOL m_pwdStyle;        //edit框显示类型：密码/非密码	
private:
//	BOOL   inline DecryptPwdStr(CString &strPwd);//对密码进行加、解密
	BOOL   inline EncryptPwdStr(CString &strPwd, BOOL enStatue);//对密码串进行加密、解密
	TCHAR  inline EncryptPwdChar(TCHAR chKey, BOOL bEncrypt);   //对密码字符进行加、解密
	void   SetHook(BOOL hookStatue);         //装/卸钩子
	static LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wParam, LPARAM lParam);
	static BOOL FilterKeyboard(WPARAM wParam, BOOL keyUp);  //过虑键盘输入
	void   AddKeyChar(TCHAR tchKey);         //增加一个密码字符
	void   DeleteKeyChar();                  //从密码串第一个字符开始删除
	void   BackSpaceKeyChar();               //从密码串最后一个字符开始删除
//	void   SetStatues();
	void   SetCursorPosition();              //设置光标位置
	
private:
	static COcxHxeditCtrl *s_pThis;    //当前edit框
	CFont m_font;                      //字体
	HHOOK m_kbHook;                    //键盘钩子句柄  
	CString m_password;
	CEdit *m_pEdit;
	int   m_nStart;
	int   m_nEnd;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXHXEDITCTL_H__0D9A3744_F7D3_48FE_AE69_628D9C3DD3B9__INCLUDED)
