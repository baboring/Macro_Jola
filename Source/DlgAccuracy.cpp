// DlgAccuracy.cpp : implementation file
//

#include "stdafx.h"
#include "jola.h"
#include "DlgAccuracy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAccuracy dialog


CDlgAccuracy::CDlgAccuracy(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAccuracy::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAccuracy)
	m_nAccuracy = 0;
	//}}AFX_DATA_INIT
}


void CDlgAccuracy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAccuracy)
	DDX_Radio(pDX, IDC_RAD_ACCURACY, m_nAccuracy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAccuracy, CDialog)
	//{{AFX_MSG_MAP(CDlgAccuracy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAccuracy message handlers

void CDlgAccuracy::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	
	CDialog::OnOK();
}
