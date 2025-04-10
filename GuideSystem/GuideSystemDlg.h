
// GuideSystemDlg.h: 头文件
//

#pragma once


// CGuideSystemDlg 对话框
class CGuideSystemDlg : public CDialogEx
{
// 构造
public:
	CGuideSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GUIDESYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
//	CStatic m_label;
//静态文本框
//	CFont m_font;
//字体变量
public:
	afx_msg void OnClickedStaticLabel();
private:
	CStatic m_label;
	CStatic m_title1;
	CStatic m_title2;
	CEdit m_edit1;
	CEdit m_edit2;
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnStnClickedStaticTitle2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
private:
	CEdit m_edit3;
public:
	CStatic m_title3;
private:
	CStatic m_pictureControl;
public:
	afx_msg void OnStnClickedPicStatic();
};
