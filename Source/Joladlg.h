// jolaDlg.h : header file
//

#if !defined(AFX_JOLADLG_H__B8A08B67_9FE6_11D3_B8AA_D1B86A5846A7__INCLUDED_)
#define AFX_JOLADLG_H__B8A08B67_9FE6_11D3_B8AA_D1B86A5846A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CJolaDlg dialog

class CJolaDlg : public CDialog
{
// Construction
public:
	CJolaDlg(CWnd* pParent = NULL);	// standard constructor
	UINT			m_nTimerID;
	UINT			m_nTimerID2;		// 반복 타이머.
	UINT			m_nTimerIDAll;		// Always 타이머.
	UINT			m_nTimerIDMouse;	// toggle

	BOOL			m_bPUSH;			// 현재 눌러진 상채인지 구분
	BOOL			m_bTaskFlag;		// Tray Flag
	POINT			pos;
	POINT			pos2;
	NOTIFYICONDATA	m_nid;
	BOOL			m_bToggling;			// Toggle 중 
	BOOL			m_bInitial;
	CWnd			*m_lpLineageWnd;
	CString			m_szLineageTitle;

	BOOL			m_bSwAutoMouse;			// On/off
	BOOL			m_bSwToggle;			// On/off
	UINT			m_nAutoSpeed;				// Loop Time(auto speed)
	int				m_nAutoKeyStart;
	int				m_nAutoKeyEnd;
	int				m_nToggleType;		// key / Mouse
	int				m_nToggleKey;				// Toggle key ()
	int				m_nToggleRange;				// toggle 반경
	int				m_nToggleCount;				// toggle 반경
	int				m_nAccuracy;

	BOOL			m_bFunc[4];
	BOOL			m_bMacro;
	BOOL			m_bMacroFlag;
	BOOL			m_bF12;
	int				m_nAutoString;
	int				m_nAutoStringCnt;
	int				m_nToggleVer;


public:
	void		MacroEvent(UINT nIDEvent);
	void		ProcessMacro(UINT nIDEvent);
	void		ProcessToggle(int mSXSize,int mSYSize,POINT pos1,POINT pos2);
	void		ProcessToggle4(int mSXSize,int mSYSize,POINT pos1,POINT pos2);
	void		ProcessToggle3(int mSXSize,int mSYSize,POINT pos1,POINT pos2);
	void		ProcessToggle2(int mSXSize,int mSYSize,POINT pos1,POINT pos2);
	void		ProcessToggle1(int mSXSize,int mSYSize);
	void		ReadProfile();
	void		WriteProfile();
	void		InitTrayIconParam(CString szStr);
	void		UpdateSpeed();
	void		StartTrayIcon();
	void		EndTrayIcon();
	void		SendToggle();
	int			GetRange();	
	BOOL		IsTray() { return m_bTaskFlag;}

	void		StartMacroTimer();
	void		EndMacroTimer();
	void		KeySendString(char* szStr,int nTotal,int nCnt);
	void		KeySendString2(char* szStr,int nTotal,int nCnt);
	void		ChangeLengCode();


// Dialog Data
	//{{AFX_DATA(CJolaDlg)
	enum { IDD = IDD_JOLA_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJolaDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CJolaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg LRESULT OnDispNotify(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnHide();
	afx_msg void OnLabel();
	afx_msg void OnBnConfig();
	afx_msg void OnBnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOLADLG_H__B8A08B67_9FE6_11D3_B8AA_D1B86A5846A7__INCLUDED_)
