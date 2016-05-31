// DlgConfig.cpp : implementation file
//

#include "stdafx.h"
#include "jola.h"
#include "DlgConfig.h"
#include "DlgAccuracy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgConfig dialog


CDlgConfig::CDlgConfig(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgConfig)
	m_bSW_Toggle = FALSE;
	m_bToggleMouse = FALSE;
	m_nTypeToggle = 1;
	m_bSW_AutoMouse = FALSE;
	m_szSpeed = _T("");
	m_szVelocity = _T("");
	m_bF12 = FALSE;
	m_szToggleStart = _T("");
	m_nToggleType = 0;
	//}}AFX_DATA_INIT

	m_nAutoSpeed		=	150;
}


void CDlgConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgConfig)
	DDX_Control(pDX, IDC_LBL_TOGGLEKEY, m_lblToggleKey);
	DDX_Control(pDX, IDC_LBL_TOGGLECOUNT, m_lblToggleCount);
	DDX_Control(pDX, IDC_LBL_TOGGLERANGE, m_lblToggleRange);
	DDX_Control(pDX, IDC_LBL_KEY_START, m_lblKeyStart);
	DDX_Control(pDX, IDC_LBL_KEY_END, m_lblKeyEnd);
	DDX_Control(pDX, IDC_SPIN_LOOP, m_ctlSpinLoop);
	DDX_Control(pDX, IDC_SPIN_TOGGLE, m_ctlSpinToggle);
	DDX_Control(pDX, IDC_CMB_TOGGLEKEY, m_ctlKeyToggle);
	DDX_Control(pDX, IDC_SCRSPEED, m_ctlAutoSpeed);
	DDX_Control(pDX, IDC_CMB_STARTKEY, m_ctlKeyStart);
	DDX_Control(pDX, IDC_CMB_ENDKEY, m_ctlKeyEnd);
	DDX_Check(pDX, IDC_CHK_SWITCH_TOGGLE, m_bSW_Toggle);
	DDX_Check(pDX, IDC_CHK_TOGGLE_MOUSECLICK, m_bToggleMouse);
	DDX_Radio(pDX, IDC_RAD_KEY, m_nTypeToggle);
	DDX_Check(pDX, IDC_CHK_SWITCH_AUTO, m_bSW_AutoMouse);
	DDX_Text(pDX, IDC_TXT_SPEED, m_szSpeed);
	DDX_Text(pDX, IDC_TXT_THETA, m_szVelocity);
	DDX_Check(pDX, IDC_CHK_F12, m_bF12);
	DDX_Text(pDX, IDC_TXT_TOGGLESTART, m_szToggleStart);
	DDX_CBIndex(pDX, IDC_CMB_TYPE, m_nToggleType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgConfig, CDialog)
	//{{AFX_MSG_MAP(CDlgConfig)
	ON_BN_CLICKED(IDC_CHK_SWITCH_TOGGLE, OnChkSwitchToggle)
	ON_BN_CLICKED(IDC_RAD_KEY, OnRadKey)
	ON_BN_CLICKED(IDC_RAD_MOUSE, OnRadMouse)
	ON_BN_CLICKED(IDC_CHK_SWITCH_AUTO, OnChkSwitchAuto)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_CHK_F12, OnChkF12)
	ON_BN_CLICKED(IDC_BN_ACCURACY, OnBnAccuracy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgConfig message handlers
void CDlgConfig::SetKeyToggle()
{
	m_lblToggleKey.EnableWindow(TRUE);	
	m_ctlKeyToggle.EnableWindow(TRUE);
//	m_ctlChkMouseToggle.EnableWindow(FALSE);
	m_szToggleStart = "Key 기동";
}
void CDlgConfig::SetMouseToggle()
{
	m_lblToggleKey.EnableWindow(FALSE);	
	m_ctlKeyToggle.EnableWindow(FALSE);
//	m_ctlChkMouseToggle.EnableWindow(TRUE);
	m_szToggleStart = "마우스 기동";
}
void CDlgConfig::SetToggleMode(BOOL bFlag)
{
	CWnd* pWnd = NULL;
	if(bFlag)
	{
		pWnd = GetDlgItem(IDC_RAD_KEY);
		pWnd->EnableWindow(TRUE);
		pWnd = GetDlgItem(IDC_RAD_MOUSE);
		pWnd->EnableWindow(TRUE);
//		m_lblToggleRange.EnableWindow(TRUE);
//		m_lblToggleCount.EnableWindow(TRUE);
		if(m_nTypeToggle==0)
		{
			SetKeyToggle();
		}
		else
		{
			SetMouseToggle();
		}
	}
	else
	{
		pWnd = GetDlgItem(IDC_RAD_KEY);
		pWnd->EnableWindow(FALSE);
		pWnd = GetDlgItem(IDC_RAD_MOUSE);
		pWnd->EnableWindow(FALSE);
		m_ctlKeyToggle.EnableWindow(FALSE);
//		m_lblToggleRange.EnableWindow(FALSE);
//		m_lblToggleCount.EnableWindow(FALSE);
	}
}


// 토글 ...on/off
void CDlgConfig::OnChkSwitchToggle() 
{
	UpdateData(TRUE);
	SetToggleMode(m_bSW_Toggle);	
}

void CDlgConfig::OnRadKey() 
{
	UpdateData(TRUE);
	SetKeyToggle();
}

void CDlgConfig::OnRadMouse() 
{
	UpdateData(TRUE);
	SetMouseToggle();
}
// --------------------------------------------------------------
void CDlgConfig::OnChkSwitchAuto() 
{
	UpdateData(TRUE);

	if(m_bSW_AutoMouse)
	{
		m_ctlKeyStart.EnableWindow(TRUE);
		m_ctlKeyEnd.EnableWindow(TRUE);
		m_lblKeyStart.EnableWindow(TRUE);
		m_lblKeyEnd.EnableWindow(TRUE);
	}
	else
	{
		m_ctlKeyStart.EnableWindow(FALSE);
		m_ctlKeyEnd.EnableWindow(FALSE);
		m_lblKeyStart.EnableWindow(FALSE);
		m_lblKeyEnd.EnableWindow(FALSE);
	}
	
}
void CDlgConfig::UpdateSpeed()
{
	UpdateData(TRUE);

	m_nAutoSpeed = m_ctlAutoSpeed.GetScrollPos() * 10;
	m_szSpeed.Format("%3.2f 초:max 20초",(float)m_nAutoSpeed/1000);

	UpdateData(FALSE);
	
}

void CDlgConfig::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nSBCode)
	{
		case SB_BOTTOM	:	//	   Scroll to bottom.
		case SB_LINEDOWN :		//	Scroll one line down.
		case SB_PAGEDOWN :		//	Scroll one page down.
			pScrollBar->SetScrollPos(pScrollBar->GetScrollPos()+1);

			if(&m_ctlAutoSpeed != pScrollBar)
			{
				if(pScrollBar->GetScrollPos() > 500)
					pScrollBar->SetScrollPos(500);
			}
			break;
		case SB_TOP	:				//	Scroll to top.
		case SB_LINEUP :			//	Scroll one line up.
		case SB_PAGEUP	:			//	Scroll one page up.
			pScrollBar->SetScrollPos(pScrollBar->GetScrollPos()-1);
			if(&m_ctlAutoSpeed != pScrollBar)
			{
				if(pScrollBar->GetScrollPos() < 1)
					pScrollBar->SetScrollPos(1);
			}
			break;
		case SB_THUMBPOSITION	:	//	Scroll to the absolute position. The current position is provided in nPos.
		case SB_THUMBTRACK	:		//	Drag scroll box to specified position. The current position is provided in nPos.
			pScrollBar->SetScrollPos(nPos);
			break;
		case SB_ENDSCROLL:	//		End scroll.
			break;
	}
	UpdateSpeed();

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


BOOL CDlgConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	CJolaApp* pApp = (CJolaApp*)AfxGetApp();

	int nStartKey	= 1;
	int nEndKey		= 2;
	int nToggleKey	= 3;
	int nNum = 0;

	nStartKey	= pApp->GetProfileInt(JOLA_HEADER,"start",1);
	nEndKey		= pApp->GetProfileInt(JOLA_HEADER,"end",2);
	nToggleKey	= pApp->GetProfileInt(JOLA_HEADER,"toggle",3);
	m_nAutoSpeed= pApp->GetProfileInt(JOLA_HEADER,"time",150);
	m_nAccuracy = pApp->GetProfileInt(JOLA_HEADER,"THETA",2); // accuracy.. low

	m_ctlKeyStart	.SetCurSel(nStartKey);
	m_ctlKeyEnd		.SetCurSel(nEndKey);
	m_ctlKeyToggle	.SetCurSel(nToggleKey);
	m_ctlAutoSpeed.SetScrollRange(1,2000);
	m_ctlAutoSpeed.SetScrollPos(m_nAutoSpeed/10);
	// ===================================================
	nNum = pApp->GetProfileInt(JOLA_HEADER,"TOGGLE_RANGE",4);
	m_ctlSpinToggle.SetRange(1,10);
	m_ctlSpinToggle.SetBase(-1);
	m_ctlSpinToggle.SetPos(nNum);
	nNum = pApp->GetProfileInt(JOLA_HEADER,"TOGGLE_COUNT",1);
	m_ctlSpinLoop.SetRange(1,10);
	m_ctlSpinLoop.SetBase(-1);
	m_ctlSpinLoop.SetPos(nNum);

	m_bSW_AutoMouse	=	pApp->GetProfileInt(JOLA_HEADER,"SW_AUTO",TRUE);
	m_bSW_Toggle	=	pApp->GetProfileInt(JOLA_HEADER,"SW_TOGGLE",TRUE);
	m_nTypeToggle	=	pApp->GetProfileInt(JOLA_HEADER,"TOGGLE_TYPE",1);
	m_bF12			=	pApp->GetProfileInt(JOLA_HEADER,"TOGGLE_F12",FALSE);
	m_nToggleType	=	pApp->GetProfileInt(JOLA_HEADER,"TOGGLE_TYPE",0);

	UpdateData(FALSE);

	// Dialog 관련 초기화.............
	UpdateSpeed();
	OnChkSwitchAuto();
	OnChkSwitchToggle();
	DisplayAccuracy();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgConfig::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	CJolaApp* pApp = (CJolaApp*)AfxGetApp();

	pApp->WriteProfileInt(JOLA_HEADER,"start",m_ctlKeyStart.GetCurSel());
	pApp->WriteProfileInt(JOLA_HEADER,"end",m_ctlKeyEnd.GetCurSel());
	pApp->WriteProfileInt(JOLA_HEADER,"toggle",m_ctlKeyToggle.GetCurSel());
	pApp->WriteProfileInt(JOLA_HEADER,"time",m_nAutoSpeed);
	pApp->WriteProfileInt(JOLA_HEADER,"SW_AUTO",m_bSW_AutoMouse);
	pApp->WriteProfileInt(JOLA_HEADER,"SW_TOGGLE",m_bSW_Toggle);

	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_RANGE",m_ctlSpinToggle.GetPos());
	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_COUNT",m_ctlSpinLoop.GetPos());
	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_TYPE",m_nTypeToggle);
	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_F12",m_bF12);
	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_TYPE",m_nToggleType);
	pApp->WriteProfileInt(JOLA_HEADER,"THETA",m_nAccuracy); // accuracy..

	CDialog::OnOK();
}

void CDlgConfig::OnChkF12() 
{
	UpdateData(TRUE);	
}
void CDlgConfig::DisplayAccuracy()
{
	switch(m_nAccuracy)
	{
	case 0 : // high
		m_szVelocity = "높음";
		break;
	case 1 : // normal
		m_szVelocity = "보통";
		break;
	case 2 : // low
		m_szVelocity = "낮음";
		break;
	}
	UpdateData(FALSE);
}

void CDlgConfig::OnBnAccuracy() 
{
	CDlgAccuracy dlg;
	dlg.m_nAccuracy = m_nAccuracy;
	if(dlg.DoModal() == IDOK)
	{
		m_nAccuracy = dlg.m_nAccuracy;
		DisplayAccuracy();
	}
}
