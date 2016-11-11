
// CrackShuduDlg.h : header file
//

#pragma once
const int a=9;
const int line=a;
const int column=a;

struct PointInfo 
{
	int x;
	int y;
	int value;
	bool IsInput;//是否为一开始输入的数
};

// CCrackShuduDlg dialog
class CCrackShuduDlg : public CDialogEx
{
// Construction
public:
	CCrackShuduDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CRACKSHUDU_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	int m_row;
	int m_column;
	vector<vector<PointInfo>> m_vtPoint;//存放个点信息
	stack<int> m_stack;//栈变量，回溯使用
	bool m_bSuccess;//破解成功标志
	int m_currentLine;
	int m_currentColumn;
	int m_STKLenght;//栈当前大小

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CEdit m_edit;
	



	void InitList();
	void InitData();
	void TestValue();//测试值
	bool IsInputEmpty();//检测输入是否为空
	void StartCrack();//开始破解数独
	void DoCrack(int &x,int &y,int value,bool &rt);
	bool Crack(int number);//破解
	bool Crack(int x,int y,int value);
	void Recall();//回溯
	bool IsTrue(int x,int y,int value);
	bool IsTrue();//填入的数字是否符合规则
	//void Push(int number);//把数字推入栈中，并计算栈大小
	//void Pop();//栈顶弹出，并计算栈大小
	void Display();//显示
	

	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedRestart();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnKillfocusEdit1();
};
