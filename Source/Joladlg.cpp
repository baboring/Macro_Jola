// jolaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "jola.h"
#include "jolaDlg.h"
#include "DlgConfig.h"

#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
#define		UM_ICONNOTIFY		WM_USER+1
#define		TG_STEP		24

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJolaDlg dialog

CJolaDlg::CJolaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJolaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJolaDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_bInitial  =	FALSE;
	m_nTimerID	=	0;
	m_nTimerID2 =	0;
	m_nTimerIDAll = 0;
	m_nAutoSpeed		=	150;
	m_bTaskFlag	=	FALSE;
	m_bPUSH		=	FALSE;
	m_lpLineageWnd	=	NULL;

	m_nToggleRange	=	0;
	m_nToggleCount	=	0;
	m_nToggleType	=	1;
	m_nAccuracy		=	2;


	m_bFunc[0]	=	FALSE;
	m_bFunc[1]	=	FALSE;
	m_bFunc[2]	=	FALSE;
	m_bFunc[3]	=	FALSE;

	m_bMacroFlag=	FALSE;
	m_bMacro	=	FALSE;
	m_nAutoString=	0;
	m_nAutoStringCnt= 0;
	m_nToggleVer	=	0;

}

void CJolaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJolaDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CJolaDlg, CDialog)
	//{{AFX_MSG_MAP(CJolaDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_MESSAGE(UM_ICONNOTIFY,OnDispNotify)
	ON_BN_CLICKED(IDC_BN_HIDE, OnBnHide)
	ON_BN_CLICKED(IDC_LABEL, OnLabel)
	ON_BN_CLICKED(IDC_BN_CONFIG, OnBnConfig)
	ON_BN_CLICKED(IDC_BN_HELP, OnBnHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJolaDlg message handlers

BOOL CJolaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_nAutoKeyStart = 0;
	m_nAutoKeyEnd	= 0;

	// ===================================================
	m_bTaskFlag	=	FALSE;
	m_bPUSH		=	FALSE;
	m_bToggling	=	FALSE;

	ReadProfile();

	// ==========================================
	m_nTimerID = SetTimer(10,m_nAutoSpeed,NULL);
//	m_nTimerIDAll = SetTimer(10,1011,NULL);
	// ==========================================

	UpdateData(FALSE);

	m_bInitial = TRUE;

	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CJolaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CJolaDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CJolaDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CJolaDlg::ReadProfile()
{
	CJolaApp* pApp = (CJolaApp*)AfxGetApp();
	m_nAutoKeyStart = pApp->GetProfileInt(JOLA_HEADER,"start",1);
	m_nAutoKeyEnd	= pApp->GetProfileInt(JOLA_HEADER,"end",2);
	m_nToggleKey	= pApp->GetProfileInt(JOLA_HEADER,"toggle",3);
	m_nAutoSpeed	= pApp->GetProfileInt(JOLA_HEADER,"time",150);
	m_bSwAutoMouse	= pApp->GetProfileInt(JOLA_HEADER,"SW_AUTO",TRUE);
	m_bSwToggle		= pApp->GetProfileInt(JOLA_HEADER,"SW_TOGGLE",TRUE);
	m_nToggleRange	= pApp->GetProfileInt(JOLA_HEADER,"TOGGLE_RANGE",4);
	m_nToggleCount	= pApp->GetProfileInt(JOLA_HEADER,"TOGGLE_COUNT",1);
	m_nToggleType	= pApp->GetProfileInt(JOLA_HEADER,"TOGGLE_TYPE",1);
	m_bF12			= pApp->GetProfileInt(JOLA_HEADER,"TOGGLE_F12",FALSE);
	m_bMacro		= pApp->GetProfileInt(JOLA_HEADER,"TOGGLE_MACRO",FALSE);
	m_nAccuracy		= pApp->GetProfileInt(JOLA_HEADER,"THETA",2); // accuracy..
	m_nToggleType	= pApp->GetProfileInt(JOLA_HEADER,"TOGGLE_TYPE",0); // accuracy..


}
void CJolaDlg::WriteProfile()
{
	CJolaApp* pApp = (CJolaApp*)AfxGetApp();
	pApp->WriteProfileInt(JOLA_HEADER,"start",m_nAutoKeyStart);
	pApp->WriteProfileInt(JOLA_HEADER,"end",m_nAutoKeyEnd);
	pApp->WriteProfileInt(JOLA_HEADER,"toggle",m_nToggleKey);
	pApp->WriteProfileInt(JOLA_HEADER,"time",m_nAutoSpeed);
	pApp->WriteProfileInt(JOLA_HEADER,"SW_AUTO",m_bSwAutoMouse);
	pApp->WriteProfileInt(JOLA_HEADER,"SW_TOGGLE",m_bSwToggle);
	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_RANGE",m_nToggleRange);
	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_COUNT",m_nToggleCount);
	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_TYPE",m_nToggleType);
	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_F12",m_bF12);
	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_MACRO",m_bMacro);
	pApp->WriteProfileInt(JOLA_HEADER,"THETA",m_nAccuracy); // accuracy..
	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_TYPE",m_nToggleType);
}

void CJolaDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

int CJolaDlg::GetRange()
{
	return m_nToggleRange*TG_STEP;
}
// v1.52d
void CJolaDlg::ProcessToggle(int mSXSize,int mSYSize,POINT pos1,POINT pos2)
{
	// Depth == 0
	SetCursorPos(pos.x,pos.y);
	mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x,pos.y,0,0);
	SetCursorPos(pos2.x,pos2.y);
	mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
	if(m_nToggleType == 0) // 키보드 사용때만 가능..
		for(int ni=0;ni<2;ni++)
		{
			// 자신의 자리는 검색..
			SetCursorPos(pos.x,pos.y);
			mouse_event(MOUSEEVENTF_RIGHTDOWN,pos.x,pos.y,0,0);
			mouse_event(MOUSEEVENTF_RIGHTUP,pos.x,pos.y,0,0);
			mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x,pos.y,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,pos.x,pos.y,0,0);
		}
	int x,y;
	float rd = 0.0f;
	int nR = 45;
	for(int n=1;n<GetRange();n+=TG_STEP)
	{
		nR -= 3;
		if(nR < 1)
			nR = 5;
		for(int r=0;r<360;r+=nR)
		{
			rd = (float)r * 3.14f / 180.0f;
			x = (int)(cos(rd) * (float)n) ;
			y = (int)(sin(rd) * (float)n);
			if(rd < 90 && rd > 270)
				x *= -1;
			if(rd > 180)
				y *= -1;

			// --------------------------------
			SetCursorPos(pos.x+x,pos.y+y);
			keybd_event(VK_SHIFT,0,0,0);
			mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x+x,pos.y+y,0,0);
			SetCursorPos(pos2.x,pos2.y);
			mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
			// --------------------------------
/*			if(m_nToggleType == 0) // 키보드 사용때만 가능..
				for(int k=0;k<1;k++)
				{
					SetCursorPos(pos.x+x,pos.y+y);
					mouse_event(MOUSEEVENTF_RIGHTDOWN,pos.x+x,pos.y+y,0,0);
					mouse_event(MOUSEEVENTF_RIGHTUP,pos.x+x,pos.y+y,0,0);

					keybd_event(VK_SHIFT,0,0,0);
					mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x+x,pos.y+y,0,0);
					SetCursorPos(pos2.x,pos2.y);
					mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
					mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
				}
*/		}
	}
}
// v1.53f
void CJolaDlg::ProcessToggle2(int mSXSize,int mSYSize,POINT pos1,POINT pos2)
{
	// Depth == 0
	SetCursorPos(pos.x,pos.y);
	mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x,pos.y,0,0);
	SetCursorPos(pos2.x,pos2.y);
	mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
	if(m_nToggleType == 0) // 키보드 사용때만 가능..
		for(int ni=0;ni<2;ni++)
		{
			// 자신의 자리는 검색..
			SetCursorPos(pos.x,pos.y);
			mouse_event(MOUSEEVENTF_RIGHTDOWN,pos.x,pos.y,0,0);
			mouse_event(MOUSEEVENTF_RIGHTUP,pos.x,pos.y,0,0);
			mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x,pos.y,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,pos.x,pos.y,0,0);
		}
	int x,y;
	float rd = 0.0f;
	int nR = 30;
	for(int r=0;r<360;r+=nR)
	{
		rd = (float)r * 3.14f / 180.0f;
		x = (int)(cos(rd) * (float)GetRange()) ;
		y = (int)(sin(rd) * (float)GetRange());
		if(rd < 90 && rd > 270)
			x *= -1;
		if(rd > 180)
			y *= -1;

		// --------------------------------
		SetCursorPos(pos.x+x,pos.y+y);
		keybd_event(VK_SHIFT,0,0,0);
		mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x+x,pos.y+y,0,0);
		SetCursorPos(pos2.x,pos2.y);
		mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
		mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
		mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
		mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
		// --------------------------------
	}
}
// v1.53a
void CJolaDlg::ProcessToggle3(int mSXSize,int mSYSize,POINT pos1,POINT pos2)
{
	// Depth == 0
	SetCursorPos(pos.x,pos.y);
	mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x,pos.y,0,0);
	SetCursorPos(pos2.x,pos2.y);
	mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
	int x,y;
	float rd = 0.0f;
	int nR = 45;

	int nr[8] = {0,60,90,120,180,210,270,300};
	for(int r=0;r<8;r++)
	{
		rd = (float)nr[r] * 3.14f / 180.0f;
		x = (int)(cos(rd) * (float)TG_STEP * 2.2f);
		y = (int)(sin(rd) * (float)TG_STEP);
		if(rd < 90 && rd > 270)
			x *= -1;
		if(rd > 180)
			y *= -1;

		// --------------------------------
		keybd_event(VK_SHIFT,0,0,0);
		SetCursorPos(pos.x+x,pos.y+y);
		for(int cl=0;cl<10000;cl++)
		mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x+x,pos.y+y,0,0);
//		mouse_event(MOUSEEVENTF_LEFTUP,pos.x+x,pos.y+y,0,0);
//		keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
		// --------------------------------
	}
	SetCursorPos(pos2.x,pos2.y);
	mouse_event(MOUSEEVENTF_LEFTDOWN,pos2.x,pos2.y,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);

	keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
}
// miss
void CJolaDlg::ProcessToggle4(int mSXSize,int mSYSize,POINT pos1,POINT pos2)
{
	// Depth == 0
	SetCursorPos(pos.x,pos.y);
	mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x,pos.y,0,0);
	SetCursorPos(pos2.x,pos2.y);
	mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
	int x,y;
	float rd = 0.0f;
	int nR = 45;
	for(int n=TG_STEP;n<GetRange();n+=TG_STEP)
	{
//		nR = 30;
//		if(n > TG_STEP*1)
//			nR = 45;
		{
//			float r2[8] = { 0.0f,sqrt(2)*0.5,90.0f,
		
		for(int r=0;r<360;r+=nR)
			rd = (float)r * 3.14f / 180.0f;
			x = (int)(cos(rd) * (float)n * 2.2f);
			y = (int)(sin(rd) * (float)n);
			if(rd < 90 && rd > 270)
				x *= -1;
			if(rd > 180)
				y *= -1;

			// --------------------------------
			SetCursorPos(pos.x+x,pos.y+y);
			keybd_event(VK_SHIFT,0,0,0);
			mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x+x,pos.y+y,0,0);
//			keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
			SetCursorPos(pos2.x,pos2.y);
			mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
			// --------------------------------
			if(m_nToggleType == 0) // 키보드 사용때만 가능..
				for(int k=0;k<1;k++)
				{
					SetCursorPos(pos.x+x,pos.y+y);
					mouse_event(MOUSEEVENTF_RIGHTDOWN,pos.x+x,pos.y+y,0,0);
					mouse_event(MOUSEEVENTF_RIGHTUP,pos.x+x,pos.y+y,0,0);

					keybd_event(VK_SHIFT,0,0,0);
					mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x+x,pos.y+y,0,0);
					SetCursorPos(pos2.x,pos2.y);
					mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
					mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
				}
		}
	}
	keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
}
void CJolaDlg::ProcessToggle1(int mSXSize,int mSYSize)
{
	if(m_bToggling == FALSE)
	{
		m_bToggling = TRUE;

		pos.x = mSXSize/2-1;
		pos.y = (float)mSYSize*(1.82f/3.);

		pos2.x = mSXSize/2-1;

		int nH = 13;
		for( nH=5;nH<10*5;nH+=20)
		{
			pos2.y = (float)mSYSize*(1.82f/3.) - nH;
			// Depth == 0
			SetCursorPos(pos.x,pos.y);
			mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x,pos.y,0,0);
			SetCursorPos(pos2.x,pos2.y);
			mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
			int x,y;
			float rd = 0.0f;
			for(int n=1;n<GetRange();n+=TG_STEP)
			{
				for(int r=0;r<360;r+=30)
				{
					rd = (float)r * 3.14f / 180.0f;
					x = (int)(cos(rd) * (float)n) ;
					y = (int)(sin(rd) * (float)n);
					if(rd < 90 && rd > 270)
						x *= -1;
					if(rd > 180)
						y *= -1;
//					for(int k=0;k<2;k++)
					{
						SetCursorPos(pos.x+x,pos.y+y);
//						for(int l=0;l<k;l++)
//							mouse_event(MOUSEEVENTF_RIGHTDOWN,pos.x+x,pos.y+y,0,0);

						keybd_event(VK_SHIFT,0,0,0);
						mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x+x,pos.y+y,0,0);
						SetCursorPos(pos2.x,pos2.y);
						mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
						mouse_event(MOUSEEVENTF_LEFTUP,pos2.x,pos2.y,0,0);
					}
				}
			}
		}

		keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
		m_bToggling = FALSE;
	}
}
void CJolaDlg::SendToggle()
{
	if(m_bSwToggle == FALSE)
		return ;

	if(m_bToggling == FALSE)
	{
		int mSXSize = ::GetSystemMetrics(SM_CXSCREEN);
		int mSYSize = ::GetSystemMetrics(SM_CYSCREEN);

//		ProcessToggle1(mSXSize,mSYSize);
//		return;
		// ====================
		m_bToggling = TRUE;
	
		pos.x = mSXSize/2;
		pos.y = (float)mSYSize*(1.82f/3.);

		pos.y = 290;
		pos2.x = mSXSize/2;
		pos2.y = pos.y;

		int nH = 13;
		int nInc = 50;
		if(m_nAccuracy == 0)
			nInc = 50;
		if(m_nAccuracy == 1)
			nInc = 50/2;
		if(m_nAccuracy == 2)
			nInc = 50/1;

		for( nH=0;nH<10*5;nH+=nInc)
		{
			pos2.y = pos.y - nH;
			switch(m_nToggleVer)
			{
			default:
			case 0:		// last work
				ProcessToggle3(mSXSize,mSYSize,pos,pos2);
				break;
			case 1:		// v1.52
				ProcessToggle2(mSXSize,mSYSize,pos,pos2);
				break;
			case 2:		// v1.00
				ProcessToggle(mSXSize,mSYSize,pos,pos2);
				break;
			}
		}

		keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
		m_bToggling = FALSE;
	}
}
// Macro Timer
void CJolaDlg::StartMacroTimer()
{
	EndMacroTimer();
	m_nTimerID2 = SetTimer(11,6*1000*60,NULL);
	CJolaApp* pApp = (CJolaApp*)AfxGetApp();
	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_MACRO",m_bMacro);
}
void CJolaDlg::EndMacroTimer()
{
	if(m_nTimerID2 !=0)
		KillTimer(m_nTimerID2);
	m_nTimerID2 = 0;
	CJolaApp* pApp = (CJolaApp*)AfxGetApp();
	pApp->WriteProfileInt(JOLA_HEADER,"TOGGLE_MACRO",m_bMacro);
}
void CJolaDlg::MacroEvent(UINT nIDEvent)
{
	if(nIDEvent == 11 && m_nTimerID2 != 0)
	{
//		m_bMacroFlag = !m_bMacroFlag;
		m_bMacro	= !m_bMacro;
	}
}
void CJolaDlg::KeySendString(char* szStr,int nTotal,int nCnt)
{
	keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
	// ==============test ===========
	keybd_event(VK_DIVIDE,0,0,0);
	keybd_event(VK_DIVIDE,0,KEYEVENTF_KEYUP,0);
	while(nTotal>nCnt)
	{
		keybd_event(szStr[nCnt],0,0,0);
		keybd_event(szStr[nCnt++],0,KEYEVENTF_KEYUP,0);
	}
	keybd_event(VK_RETURN,0,0,0);
	keybd_event(VK_RETURN,0,KEYEVENTF_KEYUP,0);
}
void CJolaDlg::KeySendString2(char* szStr,int nTotal,int nCnt)
{
	keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
	// ==============test ===========
	while(nTotal>nCnt)
	{
		keybd_event(szStr[nCnt],0,0,0);
		keybd_event(szStr[nCnt++],0,KEYEVENTF_KEYUP,0);
	}
	keybd_event(VK_RETURN,0,0,0);
	keybd_event(VK_RETURN,0,KEYEVENTF_KEYUP,0);
}
void CJolaDlg::ChangeLengCode()
{
	keybd_event(VK_SHIFT,0,0,0);
	keybd_event(VK_SPACE,0,0,0);
	keybd_event(VK_SPACE,0,KEYEVENTF_KEYUP,0);
	keybd_event(VK_SHIFT,0,KEYEVENTF_KEYUP,0);
	keybd_event(VK_ESCAPE,0,0,0);
	keybd_event(VK_ESCAPE,0,KEYEVENTF_KEYUP,0);
}
void CJolaDlg::ProcessMacro(UINT nIDEvent)
{
	// Macro system
	if(GetAsyncKeyState('1') && GetAsyncKeyState(VK_LCONTROL) && m_bF12)
	{
		m_bMacro = TRUE;
		StartMacroTimer();
	}
	if(GetAsyncKeyState('2') && GetAsyncKeyState(VK_LCONTROL) && m_bF12)
	{
		m_bMacro = FALSE;
		StartMacroTimer();
	}
	if(GetAsyncKeyState('3') && GetAsyncKeyState(VK_LCONTROL) && m_bF12)
	{
		m_bMacro = FALSE;
		EndMacroTimer();
	}
	if(GetAsyncKeyState(VK_INSERT))
	{
		keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
		char str[] = "AUTOSPELL";
		m_nAutoString = strlen(str);
		m_nAutoStringCnt = 0;
		MessageBeep(0xffffffff);
		KeySendString(str,m_nAutoString,0);
	}
	if(GetAsyncKeyState(VK_HOME))
	{
		keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
		char str[] = "FAST";
		m_nAutoString = strlen(str);
		m_nAutoStringCnt = 0;
		MessageBeep(0xffffffff);
		KeySendString(str,m_nAutoString,0);
	}
	if(GetAsyncKeyState(VK_DELETE))
	{
		keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
		char str[] = "GETALL";
		m_nAutoString = strlen(str);
		m_nAutoStringCnt = 0;
		MessageBeep(0xffffffff);
		KeySendString(str,m_nAutoString,0);
	}


	if(m_bMacro)
	{
		keybd_event(VK_F12,0,0,0);
		keybd_event(VK_F12,0,KEYEVENTF_KEYUP,0);
	}
/*	// Macro ................................................................
	if(m_bMacro)
	for(int fn=0;fn<4;fn++)
	{
		if(GetAsyncKeyState('3'+fn) && GetAsyncKeyState(VK_CONTROL))
				m_bMacroFlag = m_bFunc[fn] = FALSE;
		if(GetAsyncKeyState('3'+fn) && GetAsyncKeyState(VK_SHIFT))
				m_bMacroFlag = m_bFunc[fn] = TRUE;
		}
		if(	m_bFunc[fn] && m_bMacroFlag)
		{
			keybd_event(VK_F9+fn,0,0,0);
			keybd_event(VK_F9+fn,0,KEYEVENTF_KEYUP,0);
		}

	}
*/

}
void CJolaDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	if(!m_bInitial)
		return;

	MacroEvent(nIDEvent); // 2*6000*60 
	
	// Timer Event 처리...
//	if(nIDEvent == 1011 && m_nTimerIDAll != 0)
//	{
//	}
	if(nIDEvent == 10 && m_nTimerID != 0)
	{
//		m_lpLineageWnd = CWnd::FindWindow(LINEAGE_CLASSNAME,LINEAGE_TITLE);
//		if(m_lpLineageWnd == GetForegroundWindow() && m_lpLineageWnd)
		{
			// Timer Event 처리...
			ProcessMacro(nIDEvent);

			// Start Key
			if(m_nAutoKeyStart>0 && m_bSwAutoMouse)
			{
				if(m_nAutoKeyStart<12)
				{
					if(GetAsyncKeyState(VK_F1+m_nAutoKeyStart))
					{
						MessageBeep(0xffffffff);
						m_bPUSH = true;
					}
				}
				if(m_nAutoKeyStart == 12 ) // Mouse Left Button
				{
					if(GetAsyncKeyState(VK_LBUTTON))
					{
						MessageBeep(0xffffffff);
						m_bPUSH = true;
					}
				}
				if(m_nAutoKeyStart == 13 ) // Mouse Right Button
				{
					if(GetAsyncKeyState(VK_RBUTTON))
					{
						MessageBeep(0xffffffff);
						m_bPUSH = true;
					}
				}

			}
			// End Key
			if(m_nAutoKeyEnd>0 && m_bSwAutoMouse)
			{
				if(m_nAutoKeyEnd<12)
				{
					if(GetAsyncKeyState(VK_F1+m_nAutoKeyEnd))
					{
						MessageBeep(0xffffffff);
						m_bPUSH = false;
					}
				}
				if(m_nAutoKeyEnd == 12 ) // Mouse Left Button
				{
					if(GetAsyncKeyState(VK_LBUTTON))
					{
						MessageBeep(0xffffffff);
						m_bPUSH = false;
					}
					if(GetAsyncKeyState(VK_RBUTTON))
					{
						MessageBeep(0xffffffff);
						m_bPUSH = false;
					}
				}
			}
			// --------- Toggle
			if(m_bSwToggle)
			{
				if(m_nToggleType == 0) // Key Toggle
				{
					if(m_nToggleKey>0 && m_nToggleKey<12)
					{
						if(GetAsyncKeyState(VK_F1+m_nToggleKey))
							SendToggle();
					}
				}
				else // Mouse Toggle
				{
					if(GetAsyncKeyState(VK_RBUTTON))
					{
						MessageBeep(0xffffffff);
						SendToggle();
					}
				}
			}
			if(m_bPUSH)
			{
				GetCursorPos(&pos);
	//			SetAsyncKeyState(VK_LBUTTON);
	//			BroadcastSystemMessage(BSF_POSTMESSAGE,BSM_APPLICATIONS,WM_NCLBUTTONDBLCLK,pos.x,pos.y);
	//			::BroadcastSystemMessage(BSF_POSTMESSAGE,NULL,WM_NCLBUTTONDBLCLK,pos.x,pos.y);
	//			::SendNotifyMessage(HWND_BROADCAST,WM_NCLBUTTONDBLCLK,pos.x,pos.y);
	//			::SendMessage(HWND_BROADCAST,WM_NCLBUTTONDBLCLK,pos.x,pos.y);
	//			::PostMessage(HWND_BROADCAST,WM_NCLBUTTONDBLCLK,0,0);
	//			::PostMessage(HWND_BROADCAST,WM_NCLBUTTONDBLCLK,pos.x,pos.y);
	//			::PostMessage(::GetActiveWindow(),WM_NCLBUTTONDBLCLK,pos.x,pos.y);
	//			::PostMessage(::GetForegroundWindow(),WM_NCLBUTTONDBLCLK,pos.x,pos.y);
	//			::PostMessage(NULL,WM_NCLBUTTONDBLCLK,pos.x,pos.y);
				mouse_event(MOUSEEVENTF_LEFTDOWN,pos.x,pos.y,0,0);
				mouse_event(MOUSEEVENTF_LEFTUP,pos.x,pos.y,0,0);
			}
		}
	}
	
	CDialog::OnTimer(nIDEvent);
}

BOOL CJolaDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class

	if(m_nTimerID)
		KillTimer(m_nTimerID);
	if(m_nTimerIDAll)
		KillTimer(m_nTimerIDAll);

	EndMacroTimer();
		
	EndTrayIcon();

//	WriteProfile();

	return CDialog::DestroyWindow();
}

void CJolaDlg::InitTrayIconParam(CString szStr)
{
	// Task bar에 프로그램 내장
	m_nid.cbSize	=	sizeof(NOTIFYICONDATA); //TeskBar Area 구조체
	m_nid.hWnd	=	GetSafeHwnd();			//현재 클래스의 핸들 
	m_nid.uID		=	IDR_MAINFRAME;
	m_nid.hIcon	=	AfxGetApp()->LoadIcon(IDR_MAINFRAME);	//아이콘 ID
	m_nid.uFlags	=	NIF_MESSAGE | NIF_ICON | NIF_TIP;
	m_nid.uCallbackMessage = UM_ICONNOTIFY;	//사용자정의 메시지
											//그곳에 이벤트발생시 처리를 위한 메시지
	strcpy(m_nid.szTip,szStr);
}

void CJolaDlg::EndTrayIcon()
{
	if(m_bTaskFlag)
	{
//		InitTrayIconParam(JOLA_TITLE);
		Shell_NotifyIcon(NIM_DELETE,&m_nid);
	 	ShowWindow(SW_SHOW);
	}
	m_bTaskFlag	=	FALSE;
}

void CJolaDlg::StartTrayIcon()
{
	if(!m_bTaskFlag)
	{
		// Task bar에 프로그램 내장
		InitTrayIconParam(JOLA_TITLE);
												//그곳에 이벤트발생시 처리를 위한 메시지
		Shell_NotifyIcon(NIM_ADD,&m_nid);	// 시스템에 메시지 전달.

		SendMessage(WM_SETICON,(WPARAM)TRUE,(LPARAM)m_nid.hIcon);

		m_bTaskFlag = TRUE; //현재 Task Area에 존재함.

	}
}

LRESULT CJolaDlg::OnDispNotify(WPARAM wParam,LPARAM lParam)
{


    if(lParam != 517)  //mouse Right Click시만 처리
        return 1L;

    CMenu mainMenu;
    CMenu* pSubMenu;
    CPoint pt;
    TRACE("wParam = %d lParam = %ld\n",wParam, lParam);

    mainMenu.LoadMenu(IDR_MENU);  //사용자 정의 메뉴
    pSubMenu = mainMenu.GetSubMenu(0);

    GetCursorPos(&pt);
    SetForegroundWindow(); //화면에 다시 설정

    UINT uMenuID = pSubMenu->TrackPopupMenu(TPM_BOTTOMALIGN |TPM_LEFTBUTTON | 
                TPM_RIGHTBUTTON |TPM_RETURNCMD, pt.x, pt.y, this);

   ::PostMessage(m_hWnd, WM_NULL, 0, 0);

   switch (uMenuID)
    {
    //아래에는 서브메뉴의 ID에 따라 처리
    case IDC_TRAY_EXIT:
        PostMessage(WM_CLOSE,0,0);
        break;
    case IDC_VIEW_WINDOW:
	 	EndTrayIcon();
        break;
    }
    return 1L;
}

void CJolaDlg::OnLabel() 
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("마쿠로군주가 부캐릭터 입니다..보시면 인사라도 나누세요");	
}

BOOL CJolaDlg::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	cs.lpszClass = JOLA_HEADER;
	cs.lpszName = JOLA_HEADER;

	return CDialog::PreCreateWindow(cs);
}

void CJolaDlg::OnBnHide() 
{
	// TODO: Add your control notification handler code here
//	CAboutDlg dlgAbout;
//	dlgAbout.DoModal();

	StartTrayIcon();

	ShowWindow(SW_HIDE);
//	ShowWindow(SW_SHOWMINIMIZED);

//	UpdateSpeed();

}


void CJolaDlg::OnBnConfig() 
{
	CDlgConfig dlgConfig;

	dlgConfig.DoModal();
	ReadProfile();

	if(m_nTimerID != 0)
		KillTimer(m_nTimerID);

	m_nTimerID = SetTimer(10,m_nAutoSpeed,NULL);

}

void CJolaDlg::OnBnHelp() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}
