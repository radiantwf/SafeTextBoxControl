// OcxHxeditPpg.cpp : Implementation of the COcxHxeditPropPage property page class.

#include "stdafx.h"
#include "ocxHxedit.h"
#include "OcxHxeditPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(COcxHxeditPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(COcxHxeditPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(COcxHxeditPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(COcxHxeditPropPage, "OCXHXEDIT.OcxHxeditPropPage.1",
	0x93674641, 0x41a2, 0x4b49, 0xbc, 0xd4, 0xf0, 0x57, 0x30, 0x65, 0x8f, 0xd3)


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditPropPage::COcxHxeditPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for COcxHxeditPropPage

BOOL COcxHxeditPropPage::COcxHxeditPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_OCXHXEDIT_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditPropPage::COcxHxeditPropPage - Constructor

COcxHxeditPropPage::COcxHxeditPropPage() :
	COlePropertyPage(IDD, IDS_OCXHXEDIT_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(COcxHxeditPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditPropPage::DoDataExchange - Moves data between page and properties

void COcxHxeditPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(COcxHxeditPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// COcxHxeditPropPage message handlers
