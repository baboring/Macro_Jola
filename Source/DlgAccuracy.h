#if !defined(AFX_DLGACCURACY_H__1E89F06B_BB29_41CD_A342_98B8EB04D4ED__INCLUDED_)
#define AFX_DLGACCURACY_H__1E89F06B_BB29_41CD_A342_98B8EB04D4ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAccuracy.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAccuracy dialog

class CDlgAccuracy : public CDialog
{
// Construction
public:
	CDlgAccuracy(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgAccuracy)
	enum { IDD = IDD_DLG_ACCURACY };
	int		m_nAccuracy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAccuracy)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAccuracy)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGACCURACY_H__1E89F06B_BB29_41CD_A342_98B8EB04D4ED__INCLUDED_)
