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
    // ���� class �̸��� ���� instance�� �ִ��� üũ�Ѵ�.
	if (pWndPrev)
    {
		MessageBeep(0xffffffff);

		CJolaDlg *pWndChild = (CJolaDlg *)pWndPrev;

//		pWndPrev->ShowWindow(SW_SHOW);
        // ���� ������ȭ �Ǿ��ִ� ���α׷��̶��
//		if(pWndChild->IsTray())
		{
//			pWndChild->EndTrayIcon();
			pWndPrev->ShowWindow(SW_SHOW);
//			AfxMessageBox("IsTray");
		}
        if (pWndPrev->IsIconic())
            pWndPrev->ShowWindow(SW_RESTORE);

        // ȭ���� ������ ����.
//		pWndChild->SetForegroundWindow();
		pWndPrev->SetForegroundWindow();
        
        return FALSE;
        
    }
    // First instance. Proceed as normal.        
    return TRUE;
}
BOOL CJolaApp::CheckInstance()
{

	// ���� ������ ����� ���α׷��� instance�� �ִٸ�,
    // �װ��� Ȱ��ȭ ��Ű�� ������ ���α׷��� instance��
    // �����Ű�� �ʴ´�. 

    if( !FirstInstance() )      // Instance�� üũ�ϴ� �Լ�.
        return FALSE;

    // ������ ����� ���α׷��� instance�� �����Ƿ�
    // ���ο� class �̸��� ����Ѵ�. 
    // ��, ���� �����쳻���� ����� ���α׷��� class�̸�����
    // �޶�� �ϰ���.. ^^".

    WNDCLASS wndcls;

    memset(&wndcls, 0, sizeof(WNDCLASS) ); // wndcls�� �ʱ�ȭ.

    wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
    wndcls.lpfnWndProc = ::DefWindowProc;
    wndcls.hInstance = AfxGetInstanceHandle();
    wndcls.hIcon = LoadIcon( IDR_MAINFRAME);
    wndcls.hCursor = LoadCursor( IDC_ARROW);
    wndcls.hbrBackground = (HBRUSH) (COLOR_WINDOW +1);
    wndcls.lpszMenuName = NULL;

    // ������ class �̸��� �ִ´�.
    // ���߿� FindWindow() �Լ��� ã�� �ȴ�.
    wndcls.lpszClassName = JOLA_HEADER;

    // ������ ���� class�� ����Ѵ�.
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
			// �� �����찡 ������ ���� ����ǥ�� �����Ͽ��°�?
			if(::GetProp(pPrevWnd->GetSafeHwnd(),m_pszAppName))
			{
				MessageBeep(0xffffffff);
				AfxMessageBox("�̹� �־�.mutex");
				((CJolaDlg *)pPrevWnd)->EndTrayIcon();

				pPrevWnd->ShowWindow(SW_SHOW);
				if(pPrevWnd->IsIconic())
					pPrevWnd->ShowWindow(SW_RESTORE);

				//������ ���� �����쿡 �����.
				pPrevWnd->SetForegroundWindow();

				//�����찡 �˾� �������̸� ������ �˾��� �����Ѵ�.
				pPrevWnd->GetLastActivePopup()->SetForegroundWindow();

				return FALSE;
			}

			// �����츦 ã�� ���Ͽ����Ƿ� ��Ͽ��� ������ �����츦 ��´�.
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
		AfxMessageBox("�̹� �����ϴ°� �����ϴ�.");
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
