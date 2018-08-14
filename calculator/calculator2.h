// calculator2.h : main header file for the CALCULATOR2 application
//

#if !defined(AFX_CALCULATOR2_H__A7C1EF22_5A18_4E56_8311_F74AC4B61413__INCLUDED_)
#define AFX_CALCULATOR2_H__A7C1EF22_5A18_4E56_8311_F74AC4B61413__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCalculator2App:
// See calculator2.cpp for the implementation of this class
//

class CCalculator2App : public CWinApp
{
public:
	CCalculator2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculator2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCalculator2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATOR2_H__A7C1EF22_5A18_4E56_8311_F74AC4B61413__INCLUDED_)
