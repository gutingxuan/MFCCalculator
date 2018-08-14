// calculator2Dlg.h : header file
//

#if !defined(AFX_CALCULATOR2DLG_H__F57B8789_2EF8_4A4C_B2F5_DD4C8477A376__INCLUDED_)
#define AFX_CALCULATOR2DLG_H__F57B8789_2EF8_4A4C_B2F5_DD4C8477A376__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalculator2Dlg dialog

class CCalculator2Dlg : public CDialog
{
// Construction
public:
	CCalculator2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalculator2Dlg)
	enum { IDD = IDD_CALCULATOR2_DIALOG };
	CString	m_show;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculator2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalculator2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void On0();
	afx_msg void On1();
	afx_msg void On2();
	afx_msg void On3();
	afx_msg void On4();
	afx_msg void On5();
	afx_msg void On6();
	afx_msg void On7();
	afx_msg void On8();
	afx_msg void On9();
	afx_msg void OnDot();
	afx_msg void OnBackspace();
	afx_msg void OnCe();
	afx_msg void OnAdd();
	afx_msg void OnLeft();
	afx_msg void OnRight();
	afx_msg void OnMinus();
	afx_msg void OnMultiply();
	afx_msg void OnEqual();
	afx_msg void OnDivide();
	afx_msg void OnFactorial();
	afx_msg void OnPie();
	afx_msg void OnSin();
	afx_msg void OnCos();
	afx_msg void OnSinh();
	afx_msg void OnCosh();
	afx_msg void OnDegree();
	afx_msg void OnRad();
	afx_msg void OnLn();
	afx_msg void OnLog();
	afx_msg void OnSqrt();
	afx_msg void OnIndex();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATOR2DLG_H__F57B8789_2EF8_4A4C_B2F5_DD4C8477A376__INCLUDED_)
