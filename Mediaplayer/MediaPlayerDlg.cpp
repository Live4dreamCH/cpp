// MediaPlayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MediaPlayer.h"
#include "MediaPlayerDlg.h"

#include "activemovie3.h"

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
// CMediaPlayerDlg dialog

CMediaPlayerDlg::CMediaPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMediaPlayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMediaPlayerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMediaPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMediaPlayerDlg)
	DDX_Control(pDX, IDC_FULSCREEEN, m_FullScreen);
	DDX_Control(pDX, IDC_REPEAT, m_Repeat);
	DDX_Control(pDX, IDC_UPPER, m_Upper);
	DDX_Control(pDX, IDC_LOWER, m_Lower);
	DDX_Control(pDX, IDC_CLOSE, m_Close);
	DDX_Control(pDX, IDCANCEL, m_Exit);
	DDX_Control(pDX, IDC_STOP, m_Stop);
	DDX_Control(pDX, IDC_PLAY, m_Play);
	DDX_Control(pDX, IDC_PAUSE, m_Pause);
	DDX_Control(pDX, IDC_OPEN, m_Open);
	DDX_Control(pDX, IDC_ACTIVEMOVIECONTROL1, m_ActiveMovie);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMediaPlayerDlg, CDialog)
	//{{AFX_MSG_MAP(CMediaPlayerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLOSE, OnClose)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	ON_BN_CLICKED(IDC_LOWER, OnLower)
	ON_BN_CLICKED(IDC_UPPER, OnUpper)
	ON_BN_CLICKED(IDC_REPEAT, OnRepeat)
	ON_BN_CLICKED(IDC_FULSCREEEN, OnFulscreeen)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMediaPlayerDlg message handlers

BOOL CMediaPlayerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	isRepeat=FALSE;

    /*
	//≥ı ºªØSlider
	m_Slider.SetRange(0,1000,FALSE);
	m_Slider.SetTicFreq(2);
	m_Slider.SetLineSize(2);
	m_Slider.SetPageSize(4);
	m_Slider.SetPos(0);
	*/



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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMediaPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMediaPlayerDlg::OnPaint() 
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
HCURSOR CMediaPlayerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMediaPlayerDlg::OnClose() 
{
	// TODO: Add your control notification handler code here
	m_ActiveMovie.CloseWindow();
	
}

void CMediaPlayerDlg::OnOpen() 
{
	// TODO: Add your control notification handler code here
	char szFileFilter[]=
		"Mp3 File(*.mp3)|*.mp3|"
		"Wma File(*.wma)|*.wma|"
		"Video File(*.dat)|*.dat|"
		"Wave File(*.wav)|*.wav|"
		"AVI File(*.avi)|*.avi|"
		"Movie File(*.mov)|*.mov|"
		"Media File(*.mmm)|*.mmm|"
		"Mid File(*.mid;*,rmi)|*.mid;*.rmi|"
		"MPEG File(*.mpeg)|*.mpeg|"
		"All File(*.*)|*.*||";

	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,szFileFilter);
	if(dlg.DoModal()==IDOK){
		CString PathName=dlg.GetPathName();
		PathName.MakeUpper();
		m_ActiveMovie.SetFileName(PathName);
	}

}



void CMediaPlayerDlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	m_ActiveMovie.Run();
	SetTimer(0,20,NULL);
	/*
	double CurrentPos=m_ActiveMovie.GetCurrentPosition();
    if(CurrentPos==0&&isRepeat)
		m_ActiveMovie.Run();
		*/
}

void CMediaPlayerDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	m_ActiveMovie.Stop();
	KillTimer(0);
	
}

void CMediaPlayerDlg::OnPause() 
{
	// TODO: Add your control notification handler code here
	m_ActiveMovie.Pause();
	
}

/*
void CMediaPlayerDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CSliderCtrl *pSlider=(CSliderCtrl*)pScrollBar;
	if(m_Slider!=(*pSlider)) return;
	long Volume=(long)m_Slider.GetPos();
	long PreVolume=m_ActiveMovie.GetVolume();
	m_ActiveMovie.Pause();
	m_ActiveMovie.SetVolume(PreVolume+Volume);
	m_ActiveMovie.Run();

	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
*/

void CMediaPlayerDlg::OnLower() 
{
	// TODO: Add your control notification handler code here
	long Volume=m_ActiveMovie.GetVolume();
	m_ActiveMovie.Pause();
	m_ActiveMovie.SetVolume(Volume-100);
	m_ActiveMovie.Run();
	
}

void CMediaPlayerDlg::OnUpper() 
{
	// TODO: Add your control notification handler code here
	long Volume=m_ActiveMovie.GetVolume();
	m_ActiveMovie.Pause();
	m_ActiveMovie.SetVolume(Volume+100);
	m_ActiveMovie.Run();

	
}

void CMediaPlayerDlg::OnRepeat() 
{
	// TODO: Add your control notification handler code here
	if(!isRepeat){
		isRepeat=TRUE;
		SetDlgItemText(IDC_STATIC2,"Status:Repeat");
	}	    
	else{
		isRepeat=FALSE;
		SetDlgItemText(IDC_STATIC2,"Status:Normal");
	}
}

void CMediaPlayerDlg::OnFulscreeen() 
{
	// TODO: Add your control notification handler code here
	m_ActiveMovie.Pause();
	m_ActiveMovie.SetFullScreenMode(true);
	m_ActiveMovie.SetMovieWindowSize(SW_SHOWMAXIMIZED);
	m_ActiveMovie.Run();
		
}

void CMediaPlayerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	double CurrentPos=m_ActiveMovie.GetCurrentPosition();
    if(CurrentPos==0&&isRepeat)
		m_ActiveMovie.Run();

	
	CDialog::OnTimer(nIDEvent);
}
