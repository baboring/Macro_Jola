// DlgToggle.cpp : implementation file
//

#include "stdafx.h"
#include "jola.h"
#include "DlgToggle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgToggle dialog


DlgToggle::DlgToggle(CWnd* pParent /*=NULL*/)
	: CDialog(DlgToggle::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgToggle)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgToggle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgToggle)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgToggle, CDialog)
	//{{AFX_MSG_MAP(DlgToggle)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgToggle message handlers
