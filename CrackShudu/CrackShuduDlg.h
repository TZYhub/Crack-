
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
	bool IsInput;//�Ƿ�Ϊһ��ʼ�������
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
	vector<vector<PointInfo>> m_vtPoint;//��Ÿ�����Ϣ
	stack<int> m_stack;//ջ����������ʹ��
	bool m_bSuccess;//�ƽ�ɹ���־
	int m_currentLine;
	int m_currentColumn;
	int m_STKLenght;//ջ��ǰ��С

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
	void TestValue();//����ֵ
	bool IsInputEmpty();//��������Ƿ�Ϊ��
	void StartCrack();//��ʼ�ƽ�����
	void DoCrack(int &x,int &y,int value,bool &rt);
	bool Crack(int number);//�ƽ�
	bool Crack(int x,int y,int value);
	void Recall();//����
	bool IsTrue(int x,int y,int value);
	bool IsTrue();//����������Ƿ���Ϲ���
	//void Push(int number);//����������ջ�У�������ջ��С
	//void Pop();//ջ��������������ջ��С
	void Display();//��ʾ
	

	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedRestart();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnKillfocusEdit1();
};
