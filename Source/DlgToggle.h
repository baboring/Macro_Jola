#if !defined(AFX_DLGTOGGLE_H__0FB649B8_A3C0_4F2A_B44F_BA9C0BDE6FE8__INCLUDED_)
#define AFX_DLGTOGGLE_H__0FB649B8_A3C0_4F2A_B44F_BA9C0BDE6FE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgToggle.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgToggle dialog

class DlgToggle : public CDialog
{
// Construction
public:
	DlgToggle(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgToggle)
	enum { IDD = IDD_DLG_TOGGLE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgToggle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgToggle)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTOGGLE_H__0FB649B8_A3C0_4F2A_B44F_BA9C0BDE6FE8__INCLUDED_)
