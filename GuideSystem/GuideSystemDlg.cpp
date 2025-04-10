
// GuideSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "GuideSystem.h"
#include "GuideSystemDlg.h"
#include "afxdialogex.h"

#include <locale.h>//string->cstring乱码，问题还是没有解决

#include "MGraph.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGuideSystemDlg 对话框



CGuideSystemDlg::CGuideSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GUIDESYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CGuideSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_LABEL, m_label);//显示框
	DDX_Control(pDX, IDC_STATIC_TITLE, m_title1);//TITLE1起点
	DDX_Control(pDX, IDC_STATIC_TITLE2, m_title2);//TITLE2终点
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_STATIC_TITLE3, m_title3);
	DDX_Control(pDX, IDC_PIC_STATIC, m_pictureControl);
}

BEGIN_MESSAGE_MAP(CGuideSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_STATIC_LABEL, &CGuideSystemDlg::OnClickedStaticLabel)
	ON_BN_CLICKED(IDC_BUTTON1, &CGuideSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CGuideSystemDlg::OnBnClickedButton2)
	ON_STN_CLICKED(IDC_STATIC_TITLE2, &CGuideSystemDlg::OnStnClickedStaticTitle2)
	ON_BN_CLICKED(IDC_BUTTON3, &CGuideSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CGuideSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CGuideSystemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CGuideSystemDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CGuideSystemDlg::OnBnClickedButton7)
	ON_STN_CLICKED(IDC_PIC_STATIC, &CGuideSystemDlg::OnStnClickedPicStatic)
END_MESSAGE_MAP()


// CGuideSystemDlg 消息处理程序

BOOL CGuideSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	//自动读取文件，创建图
	MGraph MGraph;
	
	//界面部件设置
	m_title1.SetWindowTextW(TEXT("起点："));
	m_title2.SetWindowTextW(TEXT("终点："));
	m_title3.SetWindowTextW(TEXT("请输入地图对应的标号（1/2/3）："));
	m_label.SetWindowTextW(_T("点击上方按钮可以查看景点！\n最短路线：输入两个景点，就可以得到其最短线路，即：路程最短的行进方法；\n如果两者无线路 可通，就得出“两景点不可达的信息\n推荐路径：自动给出从入口（正门）到出口（正门）不重复地游览所有景点的线路；\n"));

	//设置图片->以下语句不管用
	//输出图片，默认第一张图
	//CBitmap对象，用于加载位图
	//CBitmap bitmap;
	////保持CBitmap加载的位图的句柄
	//HBITMAP hBmp;

	////将位图IDB_BITMAP1加载到bitmap
	//bitmap.LoadBitmapW(IDB_BITMAP1);
	//hBmp = (HBITMAP)bitmap.GetSafeHandle();
	//m_pictureControl.SetBitmap(hBmp);


	//检测一下find函数是否正常
	//SetDlgItemInt(IDC_STATIC_LABEL, MGraph.p->index2);

	//输出顶点个数
	//SetDlgItemInt(IDC_STATIC_LABEL, MGraph.getVertexNum());
	
	//输出景点
	//string strText = MGraph.getVertex();
	//CString cstr(strText.c_str());//string转CString
	//GetDlgItem(IDC_STATIC_LABEL)->SetWindowTextW(cstr);

	//输出一下返回错误的下标是景点名
	/*string strText = MGraph.s;
	CString cstr(strText.c_str());
	GetDlgItem(IDC_STATIC_LABEL)->SetWindowTextW(cstr);*/

	//输出边集
	/*string strText = MGraph.getArc();
	CString cstr(strText.c_str());
	GetDlgItem(IDC_STATIC_LABEL)->SetWindowTextW(cstr);*/

	//输出path
	/*string strText = MGraph.getPath();
	CString cstr(strText.c_str());
	GetDlgItem(IDC_STATIC_LABEL)->SetWindowTextW(cstr);*/

	//输出dist
	/*string strText = MGraph.getDist();
	CString cstr(strText.c_str());
	GetDlgItem(IDC_STATIC_LABEL)->SetWindowTextW(cstr);*/

	setlocale(LC_ALL, "chs");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGuideSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGuideSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGuideSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGuideSystemDlg::OnClickedStaticLabel()
{
	// TODO: 在此添加控件通知处理程序代码
}

//最短路径和推荐路线button的功能实现都依赖于编辑框IDC_EDIT3

void CGuideSystemDlg::OnEnChangeEdit1()
{
}

//最短路径
void CGuideSystemDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MGraph MGraph;

	//获取文本内容
	CString str1;
	CString str2;
	CString str3;
	int type = 0;//地图的标号

	m_edit1.GetWindowTextW(str1);
	m_edit2.GetWindowTextW(str2);
	m_edit3.GetWindowTextW(str3);

	CStringA stra3((TCHAR*)(LPCTSTR)(str3));
	string s3((char*)(LPCSTR)(stra3));

	//string->int
	istringstream ss(s3);
	ss >> type;

	//提示补全
	if (str1 == "" || str2 == "" || str3 == "" ) {
		m_label.SetWindowTextW(_T("请补全内容!"));
	}
	else if (type > 3 || type < 1) {
		m_label.SetWindowTextW(_T("请输入正确的地图下标!"));
	}
	//调用查找最短路径函数
	else {

		//Cstring->string
		CStringA stra1((TCHAR *)(LPCTSTR)(str1));
		string s1((char*)(LPCSTR)(stra1));

		CStringA stra2((TCHAR*)(LPCTSTR)(str2));
		string s2((char*)(LPCSTR)(stra2));

		//更改图数据
		MGraph.Change(type);

		//string->CString
		string strText = MGraph.ShortPath(s1,s2) + "\n地图下标：" + to_string(type);//返回路径
		CString cstr(strText.c_str());
		GetDlgItem(IDC_STATIC_LABEL)->SetWindowTextW(cstr);

		//清空文本
		/*m_edit1.SetWindowTextW(_T(""));
		m_edit2.SetWindowTextW(_T(""));*/
	}
}

//推荐路线
void CGuideSystemDlg::OnBnClickedButton2()
{

	MGraph MGraph;

	//获取文本内容
	CString str3;
	int type = 0;//地图的标号

	m_edit3.GetWindowTextW(str3);

	CStringA stra3((TCHAR*)(LPCTSTR)(str3));
	string s3((char*)(LPCSTR)(stra3));

	//string->int
	istringstream ss(s3);
	ss >> type;

	if (str3 == "") {
		m_label.SetWindowTextW(_T("请补全第三个编辑框->地图的标号(1/2/3)!"));
	}
	//记得改回3
	else if (type > 4 || type < 1) {
		m_label.SetWindowTextW(_T("请输入正确的地图下标!"));
	}
	else{
		//更改图的数据
		MGraph.Change(type);
		

		/*MGraph.getRoad();
		string strText = "Arc数组：\n" + MGraph.getArc() + "tmp数组：\n" + MGraph.getTmp() + "\ng数组：\n" + MGraph.getG();*/
		//string strText = "tmp数组：\n" + MGraph.getTmp() + "\ng数组：\n" + MGraph.getG();
		//string strText = "\nin数组：\n" + MGraph.getIn()

		/*MGraph.getRoad();
		string strText = MGraph.getG();*/

		//string->CString 没有乱码
		// string strText = MGraph.getArc();

		/*MGraph.getRoad();
		string strText ="len:" + MGraph.getLen() + "best:" +MGraph.getBest();*/


		//string strText =  MGraph.getRoad() + "\n地图的对应编号为:"+to_string(type);
		string road = MGraph.getRoad();
		string strText;
		if (MGraph.best > 20000) {
			strText = MGraph.p->Mysplit2(road) + "\n地图的对应编号为:" + to_string(type);
		}
		else {
			strText = MGraph.p->Mysplit2(road) + "\n最短距离为：" + to_string(MGraph.best) + "\n地图的对应编号为:" + to_string(type);
		}
		CString cstr(strText.c_str());

		GetDlgItem(IDC_STATIC_LABEL)->SetWindowTextW(cstr);
	} 
	

}

void CGuideSystemDlg::OnStnClickedStaticTitle2()
{
}


//清空
void CGuideSystemDlg::OnBnClickedButton3()
{ 
	// TODO: 在此添加控件通知处理程序代码

	//清空编辑框内容
	m_edit1.SetWindowTextW(_T(""));
	m_edit2.SetWindowTextW(_T(""));
	m_edit3.SetWindowTextW(_T(""));
	
}

//退出
void CGuideSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}


//以下按钮是想要提供换地图“图片”服务的，实际上数据的变化还是依赖编辑框IDC_EDIT3
//南海校区
void CGuideSystemDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	MGraph MGraph;

	string strText = MGraph.getVertex() + "\n该地图对应标号为1";
	CString cstr(strText.c_str());//string转CString
	GetDlgItem(IDC_STATIC_LABEL)->SetWindowTextW(cstr);

	//更改图片
	//CBitmap对象，用于加载位图
	CBitmap bitmap;
	//保持CBitmap加载的位图的句柄
	HBITMAP hBmp;

	//将位图IDB_BITMAP1加载到bitmap
	bitmap.LoadBitmapW(IDB_BITMAP1);
	hBmp = (HBITMAP)bitmap.GetSafeHandle();
	m_pictureControl.SetBitmap(hBmp);


}

//石牌校区
void CGuideSystemDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	MGraph MGraph;
	MGraph.Change(2);
	string strText = MGraph.getVertex() +"\n该地图对应标号为2";
	CString cstr(strText.c_str());//string转CString
	GetDlgItem(IDC_STATIC_LABEL)->SetWindowTextW(cstr);

	//更改图片
	//CBitmap对象，用于加载位图
	CBitmap bitmap;
	//保持CBitmap加载的位图的句柄
	HBITMAP hBmp;

	//将位图IDB_BITMAP1加载到bitmap
	bitmap.LoadBitmapW(IDB_BITMAP2);
	hBmp = (HBITMAP)bitmap.GetSafeHandle();
	m_pictureControl.SetBitmap(hBmp);

}

//大学城校区
void CGuideSystemDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	MGraph MGraph;
	MGraph.Change(3);
	string strText = MGraph.getVertex() + "\n该地图对应标号为3";
	//string转CString
	CString cstr(strText.c_str());
	GetDlgItem(IDC_STATIC_LABEL)->SetWindowTextW(cstr);

	//更改图片
	//CBitmap对象，用于加载位图
	CBitmap bitmap;
	//保持CBitmap加载的位图的句柄
	HBITMAP hBmp;

	//将位图IDB_BITMAP1加载到bitmap
	bitmap.LoadBitmapW(IDB_BITMAP3);
	hBmp = (HBITMAP)bitmap.GetSafeHandle();
	m_pictureControl.SetBitmap(hBmp); 

}


void CGuideSystemDlg::OnStnClickedPicStatic()
{
}
