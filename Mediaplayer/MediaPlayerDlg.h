// MediaPlayerDlg.h : header file
//
//{{AFX_INCLUDES()
#include "activemovie3.h"
//}}AFX_INCLUDES

#if !defined(AFX_MEDIAPLAYERDLG_H__73D90D3B_EBAA_4F88_8D89_B671EB280CD6__INCLUDED_)
#define AFX_MEDIAPLAYERDLG_H__73D90D3B_EBAA_4F88_8D89_B671EB280CD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RoundButton.h"


/////////////////////////////////////////////////////////////////////////////
// CMediaPlayerDlg dialog

class CMediaPlayerDlg : public CDialog
{
// Construction
public:
	CMediaPlayerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMediaPlayerDlg)
	enum { IDD = IDD_MEDIAPLAYER_DIALOG };
	CRoundButton	m_FullScreen;
	CRoundButton	m_Repeat;
	CRoundButton	m_Upper;
	CRoundButton	m_Lower;
	CRoundButton	m_Close;
	CRoundButton	m_Exit;
	CRoundButton	m_Stop;
	CRoundButton	m_Play;
	CRoundButton	m_Pause;
	CRoundButton	m_Open;
	CActiveMovie3	m_ActiveMovie;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMediaPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	BOOL isRepeat;

	// Generated message map functions
	//{{AFX_MSG(CMediaPlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnOpen();
	afx_msg void OnPlay();
	afx_msg void OnStop();
	afx_msg void OnPause();
	afx_msg void OnLower();
	afx_msg void OnUpper();
	afx_msg void OnRepeat();
	afx_msg void OnFulscreeen();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIAPLAYERDLG_H__73D90D3B_EBAA_4F88_8D89_B671EB280CD6__INCLUDED_)
