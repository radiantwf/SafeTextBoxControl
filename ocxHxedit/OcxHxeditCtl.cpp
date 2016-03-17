// OcxHxeditCtl.cpp : Implementation of the COcxHxeditCtrl ActiveX Control class.

#include "stdafx.h"
#include "ocxHxedit.h"
#include "OcxHxeditCtl.h"
#include "OcxHxeditPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(COcxHxeditCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(COcxHxeditCtrl, COleControl)
	//{{AFX_MSG_MAP(COcxHxeditCtrl)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
	ON_MESSAGE(OCM_COMMAND, OnOcmCommand)
//	ON_MESSAGE(WM_SETKEYTEXT, SetKeyText)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(COcxHxeditCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(COcxHxeditCtrl)
	DISP_PROPERTY_NOTIFY(COcxHxeditCtrl, "pwdStatue", m_pwdStatue, OnPwdStatueChanged, VT_BOOL)
	DISP_FUNCTION(COcxHxeditCtrl, "GetPwdText", GetPwdText, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(COcxHxeditCtrl, "GetDonePwd", GetDonePwd, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(COcxHxeditCtrl, "SetPwdStyle", SetPwdStyle, VT_EMPTY, VTS_BOOL)
	DISP_FUNCTION(COcxHxeditCtrl, "SetStatues", SetStatues, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(COcxHxeditCtrl, COleControl)
	//{{AFX_EVENT_MAP(COcxHxeditCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(COcxHxeditCtrl, 1)
	PROPPAGEID(COcxHxeditPropPage::guid)
END_PROPPAGEIDS(COcxHxeditCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(COcxHxeditCtrl, "OCXHXEDIT.OcxHxeditCtrl.1",
	0xf8281b45, 0x2419, 0x4dc3, 0xa4, 0x83, 0xbc, 0x67, 0x64, 0x7e, 0xda, 0x87)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(COcxHxeditCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DOcxHxedit =
		{ 0x88546a0f, 0x8b69, 0x435c, { 0x89, 0x6e, 0xd4, 0x94, 0xfd, 0x82, 0x10, 0x9 } };
const IID BASED_CODE IID_DOcxHxeditEvents =
		{ 0x61f34f35, 0x4b72, 0x4521, { 0x89, 0x80, 0xc7, 0x4c, 0x90, 0xbc, 0xfe, 0xa9 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwOcxHxeditOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(COcxHxeditCtrl, IDS_OCXHXEDIT, _dwOcxHxeditOleMisc)

COcxHxeditCtrl *COcxHxeditCtrl::s_pThis=NULL;


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditCtrl::COcxHxeditCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for COcxHxeditCtrl

BOOL COcxHxeditCtrl::COcxHxeditCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_OCXHXEDIT,
			IDB_OCXHXEDIT,
			afxRegApartmentThreading,
			_dwOcxHxeditOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditCtrl::COcxHxeditCtrl - Constructor

COcxHxeditCtrl::COcxHxeditCtrl()
{
	InitializeIIDs(&IID_DOcxHxedit, &IID_DOcxHxeditEvents);

	m_kbHook = NULL;
	m_password = _T("");
	m_pwdStatue = true;
	s_pThis = this;
	m_pEdit = (CEdit*)this;
	m_nStart = 0;
	m_nEnd   = 0;

	// TODO: Initialize your control's instance data here.
	SetInitialSize(150,20); //初始化编辑框大小
	m_pwdStyle = false;
	m_font.CreateFont(-14, 0, 0, 0, FW_NORMAL, 0, 0, 0, GB2312_CHARSET, 0, 0, 0, 0, _T("新宋体"));
}


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditCtrl::~COcxHxeditCtrl - Destructor

COcxHxeditCtrl::~COcxHxeditCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditCtrl::OnDraw - Drawing function

void COcxHxeditCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	DoSuperclassPaint(pdc, rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditCtrl::DoPropExchange - Persistence support

void COcxHxeditCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditCtrl::OnResetState - Reset control to default state

void COcxHxeditCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditCtrl::PreCreateWindow - Modify parameters for CreateWindowEx

BOOL COcxHxeditCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("EDIT");
	cs.style |= ES_AUTOHSCROLL | WS_BORDER;
	if (m_pwdStyle)
		cs.style |= ES_PASSWORD;
	return COleControl::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditCtrl::IsSubclassedControl - This is a subclassed control

BOOL COcxHxeditCtrl::IsSubclassedControl()
{
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditCtrl::OnOcmCommand - Handle command messages

LRESULT COcxHxeditCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
#ifdef _WIN32
	WORD wNotifyCode = HIWORD(wParam);
#else
	WORD wNotifyCode = HIWORD(lParam);
#endif

	// TODO: Switch on wNotifyCode here.

	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditCtrl message handlers
//获取原始密码
BSTR COcxHxeditCtrl::GetPwdText() 
{
	CString strResult;
	// TODO: Add your dispatch handler code here
	strResult = m_password;
	EncryptPwdStr(strResult, false);
//	return GetText();
//	return m_password;

	return strResult.AllocSysString();
}
//获取加密后的密码
BSTR COcxHxeditCtrl::GetDonePwd() 
{
	CString strResult = "";
	// TODO: Add your dispatch handler code here
	strResult = m_password;
//	SetText(_T("hllel"));

	return strResult.AllocSysString();
}
//修改密码显示属性
void COcxHxeditCtrl::SetPwdStyle(BOOL pwdStyle) 
{
	// TODO: Add your dispatch handler code here
	m_pwdStyle = pwdStyle;
	if (m_pwdStyle)
	{
		ModifyStyle(0,ES_PASSWORD);
		SendMessage(EM_SETPASSWORDCHAR, (WPARAM)(UINT)'*', (LPARAM)0);
	}
	else
	{
		ModifyStyle(ES_PASSWORD,0);
		SendMessage(EM_SETPASSWORDCHAR, (WPARAM)0, (LPARAM)0);
	}

//	AfxMessageBox(_T("hello"));

}


int COcxHxeditCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	HWND hwnd = GetSafeHwnd();
	if (hwnd != NULL)
	{
		SendMessage(WM_SETFONT, (WPARAM)m_font.GetSafeHandle(), MAKELPARAM(TRUE, 0));
	}
	
	return 0;
}

void COcxHxeditCtrl::OnSetFocus(CWnd* pOldWnd) 
{
	COleControl::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here
	ShowCaret();
	//获得焦点是装载钩子
	if (m_pwdStatue)
		SetHook(true);
	
}

void COcxHxeditCtrl::OnKillFocus(CWnd* pNewWnd) 
{
	COleControl::OnKillFocus(pNewWnd);
//	AfxMessageBox("killFocus");
	
	// TODO: Add your message handler code here
	//失去焦点时卸载钩子
	if (m_pwdStatue)
		SetHook(false);
	
}
//装卸键盘钩子（true装，false卸）
void COcxHxeditCtrl::SetHook(BOOL hookStatue)
{
	if (hookStatue)
	{
		if (m_kbHook == NULL)
			//装载键盘钩子
			m_kbHook = ::SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, AfxGetInstanceHandle(), 0);
	}
	else
	{
		if (m_kbHook != NULL)
		{
			::UnhookWindowsHookEx(m_kbHook);
			m_kbHook = NULL;
		}
	}
	int i=0;
}

LRESULT CALLBACK COcxHxeditCtrl::KeyboardProc(int nCode,WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		KBDLLHOOKSTRUCT *pKBS = (KBDLLHOOKSTRUCT *)lParam;
//		AfxMessageBox(s_pThis->m_password);
		if( FilterKeyboard(pKBS->vkCode, wParam==WM_KEYUP) )
			return 1;
	}
	return ::CallNextHookEx(s_pThis->m_kbHook, nCode, wParam, lParam);
}
//键盘消息过虑
BOOL COcxHxeditCtrl::FilterKeyboard(WPARAM vkCode, BOOL isKeyUp)
{
	BOOL bCtl = (::GetAsyncKeyState(VK_CONTROL)>>15)&1;
	BOOL bShift = (::GetAsyncKeyState(VK_SHIFT)>>15)&1;
	BOOL bAlt = (::GetAsyncKeyState(VK_MENU)>>15)&1;
	
	if ( bAlt )
		return FALSE;	//默认处理
	if ( bCtl )
		return TRUE;	//防Ctrl+X功能键，密码只能输入
	if ( vkCode==VK_ESCAPE || vkCode==VK_RETURN || vkCode==VK_TAB || vkCode==VK_CAPITAL ||
		 vkCode==VK_END || vkCode==VK_HOME || vkCode==VK_LEFT || vkCode==VK_RIGHT)//默认处理
		return FALSE;
	
	CHAR ch = 0;
	if ( vkCode == VK_BACK )
		ch = -1;
	if (vkCode == VK_DELETE)
		ch = -2;
	else if ( vkCode >= VK_NUMPAD0 && vkCode <= VK_NUMPAD9 )	//Num0-Num9
		ch='0' + vkCode - VK_NUMPAD0;
	else if ( vkCode >= 0x30 && vkCode <= 0x39 )				//0-9
	{
		//0-9对应的字升键字符
		CHAR buf[] ={')','!','@','#','$','%','^','&','*','('};
		ch = bShift? buf[vkCode-0x30]:'0'+(vkCode-0x30);
	}
	else if ( vkCode>=0x41 && vkCode<=0x5A )				//A-Z
	{
		BOOL bCaps = ::GetKeyState(VK_CAPITAL)&1;
		ch = bCaps^bShift? (vkCode-0x41):(vkCode-0x41)+32;
		ch += 'A';
	}
	else
	{
		switch(vkCode)
		{
		case 0xC0: ch = bShift? '~':'`'; break;
		case 0xbd: ch = bShift? '_':'-'; break;
		case 0xbb: ch = bShift? '+':'='; break;
		case 0xdc: ch = bShift? '|':'\\'; break;
		case 0xdb: ch = bShift? '{':'['; break;
		case 0xdd: ch = bShift? '}':']'; break;
		case 0xba: ch = bShift? ':':';'; break;
		case 0xde: ch = bShift? '"':'\''; break;
		case 0xbc: ch = bShift? '<':','; break;
		case 0xbe: ch = bShift? '>':'.'; break;
		case 0xbf: ch = bShift? '?':'/'; break;
		default:TRACE(_T("%c, %x\n"), vkCode, vkCode);
		}
	}
	
	if ( ch==0 )			//无需默认处理
		return TRUE;
	else if (isKeyUp)		//处理过的键屏蔽up消息
		return TRUE;
	else if ( ch == -1 )		//删除
		s_pThis->BackSpaceKeyChar();
	else if ( ch == -2 )
		s_pThis->DeleteKeyChar();
	else if ( ch>0 )		//添加
		s_pThis->AddKeyChar(ch);
	
	return TRUE;
}

void COcxHxeditCtrl::AddKeyChar(TCHAR tchKey)
{
	if ( s_pThis->m_password.GetLength() >= 32)//密码超过32位，报错
	{
		AfxMessageBox(_T("密码太长"));
		return ;
	}
	m_pEdit->GetSel(m_nStart, m_nEnd);
	CString	str = _T("");
	if (m_nStart == m_nEnd)
	{
		s_pThis->m_password.Insert(m_nStart,EncryptPwdChar(tchKey, true));
		EncryptPwdStr(s_pThis->m_password, true);
		str = s_pThis->GetText();
		TCHAR ch='*';
		str += ch;
		s_pThis->SetText(str);
		m_pEdit->SetSel(m_nStart+1,m_nStart+1);
	}
	else
	{
		s_pThis->m_password.Delete(m_nStart, m_nEnd-m_nStart);
		s_pThis->m_password.Insert(m_nStart,EncryptPwdChar(tchKey, true));
		str = s_pThis->GetText();
		str.Delete(0,m_nEnd-m_nStart);
		TCHAR ch=rand()%(127-32)+32;
		str += ch;
		s_pThis->SetText(str);
		m_pEdit->SetSel(m_nStart+1,m_nStart+1);
	}
/*	s_pThis->m_password += EncryptPwdChar(tchKey, true); //加密字符
	EncryptPwdStr(s_pThis->m_password, true);
	int len = s_pThis->m_password.GetLength();	
	
	CString	str = _T("");
	str = s_pThis->GetText();
	TCHAR ch=rand()%(127-32)+32;
	str += ch;
	s_pThis->SetText(str);
	s_pThis->SetCursorPosition();
	*/
	
}

//退格键处理
void COcxHxeditCtrl::BackSpaceKeyChar()
{
	m_pEdit->GetSel(m_nStart, m_nEnd);
	CString	str;
	str = s_pThis->GetText();
	int len = str.GetLength();
	if (m_nEnd == 0)
		return;
	if (m_nStart == m_nEnd)
	{
		m_nStart--;
		m_nEnd--;
		str.Delete(m_nStart);
		this->m_password.Delete(m_nStart);
		s_pThis->SetText(str);
		m_pEdit->SetSel(m_nStart,m_nEnd);
	}
	else
	{
		m_password.Delete(m_nStart, m_nEnd-m_nStart);
		str.Delete(0,m_nEnd-m_nStart);
		s_pThis->SetText(str);
		m_pEdit->SetSel(m_nStart,m_nStart);
	}
}
//delete键处理
void COcxHxeditCtrl::DeleteKeyChar()
{

	m_pEdit->GetSel(m_nStart, m_nEnd);
	CString	str, strLeft, strRight;
	str = s_pThis->GetText();
	int len = str.GetLength();
	if (m_nStart == len)
		return;
	if (m_nStart == m_nEnd)
	{
		str.Delete(m_nStart+1);
		this->m_password.Delete(m_nStart+1);
		s_pThis->SetText(str);
		m_pEdit->SetSel(m_nStart,m_nEnd);
	}
	else
	{
		m_password.Delete(m_nStart, m_nEnd-m_nStart);
		str.Delete(0,m_nEnd-m_nStart);
		s_pThis->SetText(str);
		m_pEdit->SetSel(m_nStart,m_nStart);
	}
}

//加密/解密密码串（true加密，false解密）
BOOL COcxHxeditCtrl::EncryptPwdStr(CString &strPwd, BOOL enStatue)
{
	BOOL nResult = false;
	if (enStatue)
	{
		//此处添加加密算法

		nResult = true;
	}
	else
	{
		CString temp;
		temp = _T("");
		TCHAR chPwd[64];
		lstrcpy(chPwd,strPwd.GetBuffer(0));
		for (int i = 0; i < strPwd.GetLength(); i++)
			temp += EncryptPwdChar(strPwd.GetAt(i),false);
		strPwd = temp;
		nResult = true;
	}
	return nResult;
}
//加密单个密码字符
TCHAR COcxHxeditCtrl::EncryptPwdChar(TCHAR chKey, BOOL bEncrypt)
{
	if ( bEncrypt )
		return (chKey%2)? chKey+12:chKey-6;
	else
		return (chKey%2)? chKey-12:chKey+6;
}
/*
BOOL COcxHxeditCtrl::DecryptPwdStr(CString &strPwd)
{
	CString temp;
	temp = _T("");
	TCHAR chPwd[64];
	lstrcpy(chPwd,strPwd.GetBuffer(0));
	for (int i = 0; i < strPwd.GetLength(); i++)
		temp += EncryptPwdChar(strPwd.GetAt(i),false);
	strPwd = temp;
	return true;
}
*/


void COcxHxeditCtrl::OnPwdStatueChanged() 
{
	// TODO: Add notification handler code

//	m_pwdStatue = true;
//	AfxMessageBox("proptyChanged");
	SetModifiedFlag();
}

//设置密码属性状态
void COcxHxeditCtrl::SetStatues() 
{
	// TODO: Add your dispatch handler code here
	m_pwdStatue = false;

}


//设置光标位置
void COcxHxeditCtrl::SetCursorPosition()
{
	CString str=_T("");	
	str = this->GetText();
	int len = str.GetLength();
	m_pEdit->SetSel(len,len);
}


BOOL COcxHxeditCtrl::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
		if(pMsg->message == WM_KEYDOWN)
		{
			if(pMsg->wParam==VK_TAB ||pMsg->wParam==VK_RETURN ||
				pMsg->wParam==VK_LEFT || pMsg->wParam==VK_RIGHT || 
				pMsg->wParam==VK_HOME || pMsg->wParam==VK_END)
			{
				SendMessage(pMsg->message,pMsg->wParam, pMsg->lParam);
				return TRUE;
			}
	} 
	
	return COleControl::PreTranslateMessage(pMsg);
}

void COcxHxeditCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	COleControl::OnLButtonDown(nFlags, point);
}

void COcxHxeditCtrl::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	COleControl::OnChar(nChar, nRepCnt, nFlags);
}
