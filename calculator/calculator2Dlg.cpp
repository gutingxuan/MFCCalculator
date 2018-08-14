// calculator2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "calculator2.h"
#include "calculator2Dlg.h"
#include "calculate.h"

#include <cmath>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

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
// CCalculator2Dlg dialog

CCalculator2Dlg::CCalculator2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculator2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalculator2Dlg)
	m_show = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculator2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalculator2Dlg)
	DDX_Text(pDX, IDC_EDIT1, m_show);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalculator2Dlg, CDialog)
	//{{AFX_MSG_MAP(CCalculator2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0, On0)
	ON_BN_CLICKED(IDC_1, On1)
	ON_BN_CLICKED(IDC_2, On2)
	ON_BN_CLICKED(IDC_3, On3)
	ON_BN_CLICKED(IDC_4, On4)
	ON_BN_CLICKED(IDC_5, On5)
	ON_BN_CLICKED(IDC_6, On6)
	ON_BN_CLICKED(IDC_7, On7)
	ON_BN_CLICKED(IDC_8, On8)
	ON_BN_CLICKED(IDC_9, On9)
	ON_BN_CLICKED(IDC_DOT, OnDot)
	ON_BN_CLICKED(IDC_BACKSPACE, OnBackspace)
	ON_BN_CLICKED(IDC_CE, OnCe)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_LEFT, OnLeft)
	ON_BN_CLICKED(IDC_RIGHT, OnRight)
	ON_BN_CLICKED(IDC_MINUS, OnMinus)
	ON_BN_CLICKED(IDC_MULTIPLY, OnMultiply)
	ON_BN_CLICKED(IDC_EQUAL, OnEqual)
	ON_BN_CLICKED(IDC_DIVIDE, OnDivide)
	ON_BN_CLICKED(IDC_FACTORIAL, OnFactorial)
	ON_BN_CLICKED(IDC_PIE, OnPie)
	ON_BN_CLICKED(IDC_SIN, OnSin)
	ON_BN_CLICKED(IDC_COS, OnCos)
	ON_BN_CLICKED(IDC_SINH, OnSinh)
	ON_BN_CLICKED(IDC_COSH, OnCosh)
	ON_BN_CLICKED(IDC_DEGREE, OnDegree)
	ON_BN_CLICKED(IDC_RAD, OnRad)
	ON_BN_CLICKED(IDC_LN, OnLn)
	ON_BN_CLICKED(IDC_LOG, OnLog)
	ON_BN_CLICKED(IDC_SQRT, OnSqrt)
	ON_BN_CLICKED(IDC_INDEX, OnIndex)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculator2Dlg message handlers

BOOL CCalculator2Dlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	((CButton*)GetDlgItem(IDC_DEGREE))->SetCheck(TRUE);//Ĭ�ϳ�ʼʱѡ�нǶ���
	MessageBox("��ӭʹ��С�˵ļ�������\n      <(�����)>","ͻȻ���ֵ�WELCOME��");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculator2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculator2Dlg::OnPaint() 
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
HCURSOR CCalculator2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


//***************************************************************************************************

//����Ϊ������ʵ�ֲ���

//***************************************************************************************************


int ifindex=0;//�����жϵȺ������������沨��ʽ������ָ�� Ĭ���沨��ʽΪ0����ָ��Ϊ1
double base=0;//��ָ���ĵ���
double index=0;//��ָ����ָ��
int radio=0;//Ĭ�ϽǶ���Ϊ0��������Ϊ1
double pi=3.14159265358;

void CCalculator2Dlg::On0() //��Ӧ��ť��0��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='0';
	UpdateData(false);
}

void CCalculator2Dlg::On1() //��Ӧ��ť��1��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='1';
	UpdateData(false);
}

void CCalculator2Dlg::On2() //��Ӧ��ť��2��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='2';
	UpdateData(false);
}

void CCalculator2Dlg::On3() //��Ӧ��ť��3��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='3';
	UpdateData(false);
}

void CCalculator2Dlg::On4() //��Ӧ��ť��4��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='4';
	UpdateData(false);
}

void CCalculator2Dlg::On5() //��Ӧ��ť��5��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='5';
	UpdateData(false);
}

void CCalculator2Dlg::On6() //��Ӧ��ť��6��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='6';
	UpdateData(false);
}

void CCalculator2Dlg::On7() //��Ӧ��ť��7��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='7';
	UpdateData(false);
}

void CCalculator2Dlg::On8() //��Ӧ��ť��8��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='8';
	UpdateData(false);
}

void CCalculator2Dlg::On9() //��Ӧ��ť��9��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='9';
	UpdateData(false);
}


void CCalculator2Dlg::OnDot() //��Ӧ��ť��.��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='.';
	UpdateData(false);
}

void CCalculator2Dlg::OnBackspace() //��Ӧ��ť��backspace��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show=m_show.Left(m_show.GetLength()-1);
	UpdateData(false);
}

void CCalculator2Dlg::OnCe() //��Ӧ��ť��AC��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show.Empty();
	UpdateData(false);
}

void CCalculator2Dlg::OnAdd() //��Ӧ��ť��+��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='+';
	UpdateData(false);
}

void CCalculator2Dlg::OnLeft() //��Ӧ��ť��(��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='(';
	UpdateData(false);
}

void CCalculator2Dlg::OnRight() //��Ӧ��ť��)��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+=')';
	UpdateData(false);
}

void CCalculator2Dlg::OnMinus() //��Ӧ��ť��-��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='-';
	UpdateData(false);
}

void CCalculator2Dlg::OnMultiply() //��Ӧ��ť��*��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='*';
	UpdateData(false);
}

void CCalculator2Dlg::OnEqual() //��Ӧ��ť��=��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(index==0)
	{
		RPN rpn;
		rpn.Change(m_show);
		m_show.Format("%g",rpn.Compute(rpn.num));
		if(m_show=="1.#INF") m_show="��������Ϊ0���r(�s���t)�q";
		if(rpn.err=="bracket") m_show="������������󣡨r(�s���t)�q";
		if(rpn.err=="symbol") m_show="�����������󣡨r(�s���t)�q";
	}
	if(index==1)
	{
		UpdateData(true);
		index=atof(m_show);
		m_show.Format("%g",pow(base,index));
		if(m_show=="-1.#IND") 
		{
			m_show="�����������";
			MessageBox("����Ϊ������ָ��ΪС��\n��\n����Ϊ0��ָ��С�ڵ���0\n�ǲ��еģ�","��ܰ��ʾ��(������)��");
		}
		index=0;
	}
	UpdateData(false);
}

void CCalculator2Dlg::OnDivide() //��Ӧ��ť��/��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show+='/';
	UpdateData(false);
}

void CCalculator2Dlg::OnFactorial() //��Ӧ��ť��n!��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int temp=atoi(m_show);
	int ans=1;
	for(int i=2;i<=temp;i++)
		ans*=i;
	m_show.Format(_T("%d"),ans);
	if(temp>12) 
	{
		m_show="�������ݷ�Χ��";
		MessageBox("�����������ֻ���㵽12�Ľ׳ˣ�","��ܰ��ʾ��(������)��");
	}
	UpdateData(false);
}

void CCalculator2Dlg::OnPie() //��Ӧ��ť���С�
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show.Empty();
	if(radio==0) m_show+="180";
	if(radio==1) m_show+="3.14159265358";
	UpdateData(false);
}

void CCalculator2Dlg::OnSin() //��Ӧ��ť��sin��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(radio==0) m_show.Format(_T("%5.4f"),sin(atof(m_show)/180*pi));
	if(radio==1) m_show.Format(_T("%5.4f"),sin(atof(m_show)));
	if(atof(m_show)==0) m_show="0";
	UpdateData(false);
}

void CCalculator2Dlg::OnCos() //��Ӧ��ť��cos��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(radio==0) m_show.Format(_T("%5.4f"),cos(atof(m_show)/180*pi));
	if(radio==1) m_show.Format(_T("%5.4f"),cos(atof(m_show)));
	if(atof(m_show)==0) m_show="0";
	UpdateData(false);
}

void CCalculator2Dlg::OnSinh() //��Ӧ��ť��arcsin��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(radio==0)	m_show.Format(_T("%5.4f"),asin(atof(m_show))/pi*180);
	if(radio==1)	m_show.Format(_T("%5.4f"),asin(atof(m_show)));
	if(atof(m_show)==0) m_show="0";
	if(m_show=="-1.#IND") 
	{
		m_show="�����������";
		MessageBox("arcsin�����ݷ�ΧӦΪ-1��1��","��ܰ��ʾ��(������)��");
	}
	UpdateData(false);
}

void CCalculator2Dlg::OnCosh() //��Ӧ��ť��arccos��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(radio==0)	m_show.Format(_T("%5.4f"),acos(atof(m_show))/pi*180);
	if(radio==1)	m_show.Format(_T("%5.4f"),acos(atof(m_show)));
	if(atof(m_show)==0) m_show="0";
	if(m_show=="-1.#IND") 
	{
		m_show="�����������";
		MessageBox("arccos�����ݷ�ΧӦΪ-1��1��","��ܰ��ʾ��(������)�� ");
	}
	UpdateData(false);
}

void CCalculator2Dlg::OnDegree() //��Ӧ��ť���Ƕȡ�
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(radio==1) m_show.Format(_T("%.2f"),atof(m_show)/pi*180);
	UpdateData(false);
	radio=0;
}

void CCalculator2Dlg::OnRad() //��Ӧ��ť�����ȡ�
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(radio==0) m_show.Format(_T("%f"),atof(m_show)/180*pi);
	UpdateData(false);
	radio=1;
}

void CCalculator2Dlg::OnLn() //��Ӧ��ť��ln��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show.Format(_T("%g"),log(atof(m_show)));
	if(m_show=="-1.#IND") 
	{
		m_show="�����������";
		MessageBox("ln�������������0��","��ܰ��ʾ��(������)��");
	}
	if(m_show=="-1.#INF")	m_show="û���������ݣ�";
	UpdateData(false);
}

void CCalculator2Dlg::OnLog() //��Ӧ��ť��log��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show.Format(_T("%g"),log10(atof(m_show)));
	if(m_show=="-1.#IND") 
	{
		m_show="�����������";
		MessageBox("log�������������0��","��ܰ��ʾ��(������)��");
	}
	if(m_show=="-1.#INF")	m_show="û���������ݣ�";
	UpdateData(false);
}

void CCalculator2Dlg::OnSqrt() //��Ӧ��ť����x��
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_show.Format(_T("%g"),sqrt(atof(m_show)));
	if(m_show=="-1.#IND") 
	{
		m_show="�����������";
		MessageBox("���������������ڵ���0��","��ܰ��ʾ��(������)��");
	}
	UpdateData(false);
}

void CCalculator2Dlg::OnIndex() //��Ӧ��ť��x^y��
{
	// TODO: Add your control notification handler code here
	index=1;
	UpdateData(true);
	base=atof(m_show);
	m_show.Empty();
	UpdateData(false);
}
