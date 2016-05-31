#if !defined(AFX_DLGCONFIG_H__99C4C1E2_C18B_11D3_B8AA_C850C148A1A7__INCLUDED_)
#define AFX_DLGCONFIG_H__99C4C1E2_C18B_11D3_B8AA_C850C148A1A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgConfig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgConfig dialog

class CDlgConfig : public CDialog
{
// Construction
public:
	CDlgConfig(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgConfig)
	enum { IDD = IDD_DLG_CONFIG };
	CStatic	m_lblToggleKey;
	CStatic	m_lblToggleCount;
	CStatic	m_lblToggleRange;
	CStatic	m_lblKeyStart;
	CStatic	m_lblKeyEnd;
	CSpinButtonCtrl	m_ctlSpinLoop;
	CSpinButtonCtrl	m_ctlSpinToggle;
	CComboBox	m_ctlKeyToggle;
	CScrollBar	m_ctlAutoSpeed;
	CComboBox	m_ctlKeyStart;
	CComboBox	m_ctlKeyEnd;
	BOOL		m_bSW_Toggle;
	BOOL		m_bToggleMouse;
	int			m_nTypeToggle;
	BOOL		m_bSW_AutoMouse;
	CString		m_szSpeed;
	CString		m_szVelocity;
	BOOL		m_bF12;
	CString	m_szToggleStart;
	int		m_nToggleType;
	//}}AFX_DATA
	// ................
	int			m_nAutoSpeed;
	int			m_nAccuracy;

	void		SetToggleMode(BOOL bFlag);
	void		SetKeyToggle();
	void		SetMouseToggle();
	void		UpdateSpeed();
	void		DisplayAccuracy();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgConfig)
	afx_msg void OnChkSwitchToggle();
	afx_msg void OnRadKey();
	afx_msg void OnRadMouse();
	afx_msg void OnChkSwitchAuto();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnOK();
	afx_msg void OnChkF12();
	afx_msg void OnBnAccuracy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCONFIG_H__99C4C1E2_C18B_11D3_B8AA_C850C148A1A7__INCLUDED_)
