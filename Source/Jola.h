// jola.h : main header file for the JOLA application
//

#if !defined(AFX_JOLA_H__B8A08B65_9FE6_11D3_B8AA_D1B86A5846A7__INCLUDED_)
#define AFX_JOLA_H__B8A08B65_9FE6_11D3_B8AA_D1B86A5846A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#define		JOLA_HEADER_10		"JOLA V1.0"
#define		JOLA_HEADER			"JOLA V1.54a"
#define		JOLA_HEADER_LAST	"JOLA V1.54a"
#define		LINEAGE_TITLE		"Lineage Windows Client"
#define		LINEAGE_CLASSNAME	"LINEAGE"
#define		JOLA_TITLE			"Á¹¶ó»¡¶ó v1.54a  (¹Ùº¸¸µ2)"

/////////////////////////////////////////////////////////////////////////////
// CJolaApp:
// See jola.cpp for the implementation of this class
//

class CJolaApp : public CWinApp
{
public:
	CJolaApp();

	BOOL			m_bFirst;

	BOOL			CheckInstance();
	BOOL			FirstInstance();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJolaApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual BOOL InitApplication();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CJolaApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOLA_H__B8A08B65_9FE6_11D3_B8AA_D1B86A5846A7__INCLUDED_)
