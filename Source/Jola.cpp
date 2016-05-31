// jola.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "jola.h"
#include "jolaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJolaApp

BEGIN_MESSAGE_MAP(CJolaApp, CWinApp)
	//{{AFX_MSG_MAP(CJolaApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJolaApp construction

CJolaApp::CJolaApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_bFirst	=	TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CJolaApp object

CJolaApp theApp;
static BOOL bClassRegistered = FALSE;
/////////////////////////////////////////////////////////////////////////////
// CJolaApp initialization
BOOL CJolaApp::FirstInstance()
{
    CWnd *pWndPrev;

	pWndPrev = CWnd::FindWindow(NULL,JOLA_TITLE);
    // 같은 class 이름을 가진 instance가 있는지 체크한다.
	if (pWndPrev)
    {
		MessageBeep(0xffffffff);

		CJolaDlg *pWndChild = (CJolaDlg *)pWndPrev;

//		pWndPrev->ShowWindow(SW_SHOW);
        // 만약 아이콘화 되어있는 프로그램이라면
//		if(pWndChild->IsTray())
		{
//			pWndChild->EndTrayIcon();
			pWndPrev->ShowWindow(SW_SHOW);
//			AfxMessageBox("IsTray");
		}
        if (pWndPrev->IsIconic())
            pWndPrev->ShowWindow(SW_RESTORE);

        // 화면의 맨위로 띄운다.
//		pWndChild->SetForegroundWindow();
		pWndPrev->SetForegroundWindow();
        
        return FALSE;
        
    }
    // First instance. Proceed as normal.        
    return TRUE;
}
BOOL CJolaApp::CheckInstance()
{

	// 만약 이전에 실행된 프로그램의 instance가 있다면,
    // 그것을 활성화 시키고 지금의 프로그램의 instance는
    // 실행시키지 않는다. 

    if( !FirstInstance() )      // Instance를 체크하는 함수.
        return FALSE;

    // 이전에 실행된 프로그램의 instance가 없으므로
    // 새로운 class 이름을 등록한다. 
    // 단, 현재 윈도우내에서 실행된 프로그램의 class이름과는
    // 달라야 하겠죠.. ^^".

    WNDCLASS wndcls;

    memset(&wndcls, 0, sizeof(WNDCLASS) ); // wndcls를 초기화.

    wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
    wndcls.lpfnWndProc = ::DefWindowProc;
    wndcls.hInstance = AfxGetInstanceHandle();
    wndcls.hIcon = LoadIcon( IDR_MAINFRAME);
    wndcls.hCursor = LoadCursor( IDC_ARROW);
    wndcls.hbrBackground = (HBRUSH) (COLOR_WINDOW +1);
    wndcls.lpszMenuName = NULL;

    // 유일한 class 이름을 넣는다.
    // 나중에 FindWindow() 함수로 찾게 된다.
    wndcls.lpszClassName = JOLA_HEADER;

    // 위에서 만든 class를 등록한다.
    if( !AfxRegisterClass( &wndcls))
    {
        TRACE(" Class Registration Failed\n");
        return FALSE;
    }

    bClassRegistered = TRUE;

	return TRUE;
}

BOOL CJolaApp::InitInstance()
{
	AfxEnableControlContainer();
	
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	if(CheckInstance() == FALSE)
		return FALSE;

	m_bFirst	=	TRUE;
/*	CreateMutex(NULL,TRUE,m_pszAppName);
	if(GetLastError() == ERROR_ALREADY_EXISTS)
	{
		m_bFirst	=	FALSE;
		CWnd* pPrevWnd = CWnd::GetDesktopWindow()->GetWindow(GW_CHILD);
		while(pPrevWnd)
		{
			// 이 윈도우가 이전의 존재 꼬리표를 설정하였는가?
			if(::GetProp(pPrevWnd->GetSafeHwnd(),m_pszAppName))
			{
				MessageBeep(0xffffffff);
				AfxMessageBox("이미 있어.mutex");
				((CJolaDlg *)pPrevWnd)->EndTrayIcon();

				pPrevWnd->ShowWindow(SW_SHOW);
				if(pPrevWnd->IsIconic())
					pPrevWnd->ShowWindow(SW_RESTORE);

				//초점을 메인 윈도우에 맞춘다.
				pPrevWnd->SetForegroundWindow();

				//윈도우가 팝업 윈도우이면 초점을 팝업에 설정한다.
				pPrevWnd->GetLastActivePopup()->SetForegroundWindow();

				return FALSE;
			}

			// 윈도우를 찾지 못하였으므로 목록에서 다음의 윈도우를 얻는다.
			pPrevWnd = pPrevWnd->GetWindow(GW_HWNDNEXT);
		}
		TRACE("Could not finf previous instance main window\n");
		return FALSE;
	}
*/
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CJolaDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	::SetProp(m_pMainWnd->GetSafeHwnd(),m_pszAppName,(HANDLE)1);
	m_bFirst	=	TRUE;

	return FALSE;
}

int CJolaApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_bFirst)
	{
		::RemoveProp(m_pMainWnd->GetSafeHwnd(),m_pszAppName);
	}
	else
	{
//		MessageBeep(0xffffffff);
		AfxMessageBox("이미 존재하는것 같습니다.");
	}
    if( bClassRegistered )
        ::UnregisterClass("JOLA  V1.0", AfxGetInstanceHandle());

	return CWinApp::ExitInstance();
}

BOOL CJolaApp::InitApplication() 
{
	// TODO: Add your specialized code here and/or call the base class
//	if(CheckInstance() == FALSE)
//		return FALSE;

	return CWinApp::InitApplication();
}
