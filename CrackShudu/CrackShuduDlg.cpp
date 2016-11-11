
// CrackShuduDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CrackShudu.h"
#include "CrackShuduDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCrackShuduDlg dialog




CCrackShuduDlg::CCrackShuduDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCrackShuduDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCrackShuduDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CCrackShuduDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_START, &CCrackShuduDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_RESTART, &CCrackShuduDlg::OnBnClickedRestart)
	ON_BN_CLICKED(IDCANCEL, &CCrackShuduDlg::OnBnClickedCancel)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CCrackShuduDlg::OnNMDblclkList1)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CCrackShuduDlg::OnEnKillfocusEdit1)
END_MESSAGE_MAP()


// CCrackShuduDlg message handlers

BOOL CCrackShuduDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	InitList();
	InitData();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCrackShuduDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCrackShuduDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCrackShuduDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCrackShuduDlg::InitList()
{
	LONG lStyle;
	lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//��ȡ��ǰ����style
	lStyle |= LVS_REPORT; //����style
	DWORD dwStyle = m_list.GetExtendedStyle();   
	dwStyle |= LVS_EX_FULLROWSELECT;// ѡ��ĳ��ʹ���и�����ֻ������report ����listctrl ��   
	dwStyle |= LVS_EX_GRIDLINES;// �����ߣ�ֻ������report ����listctrl ��      
	m_list.SetExtendedStyle(dwStyle); // ������չ��� 
	m_list.InsertColumn(0, _T(""), LVCFMT_CENTER, 20); 

	char a[2]={0};
	for(short int i=1;i<=column;i++)
	{
		_itoa_s(i,a,2,10);
		m_list.InsertColumn(i, _T(a), LVCFMT_LEFT, 20); 
	}

	for (short int i=1;i<=line;i++)
	{
		_itoa_s(i,a,2,10);
		m_list.InsertItem(i,_T(a));
	}
}

void CCrackShuduDlg::InitData()
{
	//��ά�����ʼ��
	m_vtPoint.clear();
	vector<PointInfo> vt;
	PointInfo point;
	for (int i=0;i<line;i++)
	{
		vt.clear();
		for (int j=0;j<column;j++)
		{
			point.x=i;
			point.y=j;
			point.value=-1;
			point.IsInput=false;
			vt.push_back(point);
		}
		m_vtPoint.push_back(vt);
	}
	//����ջ 
	while (m_stack.size()>0)
	{
		m_stack.pop();
	}
	//�������
	for (int i=0;i<line;i++)
	{
		for (int j=0;j<column;j++)
		{
			m_list.SetItemText(i,j+1,"");//�������ݸ��µ�CListCtrl��
		}
	}

	m_bSuccess=false;
}

void CCrackShuduDlg::TestValue()
{
	m_vtPoint.at(0).at(6).value=3;m_vtPoint.at(0).at(7).value=1;
	m_vtPoint.at(1).at(4).value=6;m_vtPoint.at(1).at(8).value=4;
	m_vtPoint.at(2).at(1).value=2;m_vtPoint.at(2).at(2).value=3;m_vtPoint.at(2).at(3).value=9;m_vtPoint.at(2).at(7).value=6;
	m_vtPoint.at(3).at(2).value=2;m_vtPoint.at(3).at(5).value=6;m_vtPoint.at(3).at(8).value=9;
	m_vtPoint.at(4).at(1).value=8;m_vtPoint.at(4).at(3).value=4;m_vtPoint.at(4).at(8).value=3;
	m_vtPoint.at(5).at(2).value=1;m_vtPoint.at(5).at(4).value=5;m_vtPoint.at(5).at(7).value=7;
	m_vtPoint.at(6).at(0).value=8;m_vtPoint.at(6).at(1).value=5;
	m_vtPoint.at(7).at(2).value=9;m_vtPoint.at(7).at(3).value=2;
	m_vtPoint.at(8).at(1).value=3;m_vtPoint.at(8).at(4).value=9;m_vtPoint.at(8).at(7).value=8;m_vtPoint.at(8).at(8).value=7;
}


bool CCrackShuduDlg::IsInputEmpty()
{
	for (int i=0;i<line;i++)
	{
		for (int j=0;j<column;j++)
		{
			if (m_vtPoint.at(i).at(j).value!=-1)
			{
				return false;
			}
		}
	}
	return true;
}

void CCrackShuduDlg::StartCrack()
{
	GetDlgItem(ID_START)->EnableWindow(false);

	bool m_bRecall=false;
	for (int i=0;i<line;i++)
	{
		for (int j=0;j<column;j++)
		{
			if (!m_bRecall)//������ǻ���
			{
				if (!m_vtPoint.at(i).at(j).IsInput)//����������룬��ִ��
				{
					int value=1;
					DoCrack(i,j,1,m_bRecall);//��ʼ�ƽ�
				}
			}
			else//�ǻ���
			{
				m_bRecall=false;//�ı��־
				//��ȡi��j��ֵ 
				if (m_vtPoint.at(i).at(j).IsInput)//������ݵ���һ��ʼ�����ֵ�����������
				{
					if (0==j)
					{
						i--;
						j=column-2;
					}
					else
					{
						j-=2;
					}
					m_bRecall=true;//��һ���ǻ���
				}
				else
				{
					if (m_vtPoint.at(i).at(j).value<9)//���1-8
					{
						DoCrack(i,j,m_vtPoint.at(i).at(j).value+1,m_bRecall);
					}
					else//����9
					{
						m_vtPoint.at(i).at(j).value=-1;
						if (0==j)
						{
							i--;
							j=column-2;
						}
						else
						{
							j-=2;
						}
						m_bRecall=true;
					}
				}
			}
		}
	}
	m_bSuccess=true;

}

void CCrackShuduDlg::DoCrack(int &x,int &y,int value,bool &rt)
{
	if(!Crack(x,y,value))//���������������ԣ���ֵ+1����
	{
		m_vtPoint.at(x).at(y).value=-1;
		value++;
		if (value>9)//����Ѿ��ӵ�9�˻��ǲ����ԣ���ô����
		{
			if (0==y)
			{
				x--;
				y=column-2;
			}
			else
			{
				y-=2;
			}
			rt=true;
		}
		else
		{
			DoCrack(x,y,value,rt);
		}
	}
}

bool CCrackShuduDlg::Crack(int x,int y,int value)
{
	//�ж������������Ƿ���ԣ������򷵻��棬���򷵻ؼ�
	//�Ȱ�ֵ����ջ�Ͷ�ά������
	m_vtPoint.at(x).at(y).value=value;
	//Ȼ���ж��Ƿ��������
	return IsTrue(x,y,value);//����������룬�򷵻�true

}


bool CCrackShuduDlg::IsTrue(int x,int y,int value)
{
	for (short int i=0;i<column;i++)
	{
		if (!(i==y))
		{
			if (value==m_vtPoint.at(x).at(i).value)
			{
				return false;
			}
		}
	}
	for (short int i=0;i<line;i++)
	{
		if (i!=x)
		{
			if (value==m_vtPoint.at(i).at(y).value)
			{
				return false;
			}
		}
	}

	////������ͬһ���Ź����ڲ��ظ�
	//���ж����ĸ��Ź������ж��Ƿ����ظ���
	int gradeNumber=-1;
	for (int i=0;i<3;i++)
	{
		if ((x>=0+i*3)&&(x<=2+i*3))
		{
			if (y>=0&&y<=2)
			{
				gradeNumber=0+i*3;
			}
			else if (y>=3&&y<=5)
			{
				gradeNumber=1+i*3;
			}
			else if (y>=6&&y<=8)
			{
				gradeNumber=2+i*3;
			}
		}
	}
	//�ж��Ƿ����ظ���
	for (int i=0+(gradeNumber/3)*3;i<=2+(gradeNumber/3)*3;i++)
	{
		for (int j=0+(gradeNumber%3)*3;j<=2+(gradeNumber%3)*3;j++)
		{
			if (!(i==x&&j==y))
			{
				if (value==m_vtPoint.at(i).at(j).value)
				{
					return false;
				}
			}
		}
	}

}


void CCrackShuduDlg::Display()
{
	if (m_bSuccess)
	{
		char *str=new char[5];
		for (int i=0;i<line;i++)
		{
			for (int j=0;j<column;j++)
			{
				_itoa_s(m_vtPoint.at(i).at(j).value,str,5,10);
				m_list.SetItemText(i,j+1,str);//�������ݸ��µ�CListCtrl��
			}
		}
		delete []str;
		MessageBox("�ƽ�ɹ���");
	}
	else
	{
		MessageBox("�ƽ�ʧ�ܣ����������Ƿ���ȷ��");
	}
	GetDlgItem(ID_START)->EnableWindow(TRUE);
}

void CCrackShuduDlg::OnBnClickedStart()
{
	// TODO: Add your control notification handler code here
	TestValue();
	if (IsInputEmpty())
	{
		MessageBox("����Ϊ�գ����������ֺ����ƽ⣡");
		return;
	}

	StartCrack();
	Display();
}


void CCrackShuduDlg::OnBnClickedRestart()
{
	// TODO: Add your control notification handler code here
	InitData();
}


void CCrackShuduDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CCrackShuduDlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;
	CRect rc;
	if(pNMListView->iItem!=-1)
	{
		m_row=pNMListView->iItem;					//m_rowΪ��ѡ���е�����ţ�int���ͳ�Ա������
		m_column=pNMListView->iSubItem;				//m_columnΪ��ѡ���е�����ţ�int���ͳ�Ա������
		m_list.GetSubItemRect(pNMListView->iItem, pNMListView->iSubItem,LVIR_LABEL,rc);//ȡ������ľ���

		rc.bottom+=3;

		m_edit.SetParent(&m_list);
		char * ch=new char [5];
		m_list.GetItemText(pNMListView->iItem, pNMListView->iSubItem,ch,5);//ȡ�����������
		m_edit.SetWindowText(ch);					//�������������ʾ���༭����
		m_edit.ShowWindow(SW_SHOW);					//��ʾ�༭��
		m_edit.MoveWindow(&rc);						//���༭���ƶ����������棬������������
		m_edit.SetFocus();							//ʹ�༭��ȡ�ý���
		m_edit.CreateSolidCaret(1,rc.Height()-5);	//����һ�����
		m_edit.ShowCaret();							//��ʾ���
		m_edit.SetSel(-1);							//ʹ����Ƶ������
	}
	*pResult = 0;
}


void CCrackShuduDlg::OnEnKillfocusEdit1()
{
	// TODO: Add your control notification handler code here
	CString str;
	m_edit.GetWindowText(str);//ȡ�ñ༭�������
	m_list.SetItemText(m_row,m_column,str);//�������ݸ��µ�CListCtrl��
	//��������䵽2ά������ȥ
	int iValue=atoi(str);
	if (iValue>0&&iValue<10)
	{
		m_list.SetItemText(m_row,m_column,str);//�������ݸ��µ�CListCtrl��
		m_edit.ShowWindow(SW_HIDE);//���ر༭��
		//��������䵽2ά������ȥ
		//������ظ����ˣ���ôҲ��������
		//if ()
		//{
		//}
		m_vtPoint.at(m_row).at(m_column-1).value=iValue;
		m_vtPoint.at(m_row).at(m_column-1).IsInput=true;
	}
	else if (0==iValue)
	{
		m_edit.ShowWindow(SW_HIDE);//���ر༭��
	}
	else
	{
		MessageBox("���������Ϊ1-9");
	}
}
