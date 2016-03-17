#if !defined(AFX_OCXHXEDITPPG_H__5F49EDDE_8D82_42A8_BEF7_BE10C1EAB5DC__INCLUDED_)
#define AFX_OCXHXEDITPPG_H__5F49EDDE_8D82_42A8_BEF7_BE10C1EAB5DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// OcxHxeditPpg.h : Declaration of the COcxHxeditPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// COcxHxeditPropPage : See OcxHxeditPpg.cpp.cpp for implementation.

class COcxHxeditPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(COcxHxeditPropPage)
	DECLARE_OLECREATE_EX(COcxHxeditPropPage)

// Constructor
public:
	COcxHxeditPropPage();

// Dialog Data
	//{{AFX_DATA(COcxHxeditPropPage)
	enum { IDD = IDD_PROPPAGE_OCXHXEDIT };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(COcxHxeditPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OCXHXEDITPPG_H__5F49EDDE_8D82_42A8_BEF7_BE10C1EAB5DC__INCLUDED)
