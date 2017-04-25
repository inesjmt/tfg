// ClientMFCDlg.h : header file
//

#if !defined(AFX_CLIENTMFCDLG_H__89D3E720_73FD_4348_B6F3_ACCA1C07ECD9__INCLUDED_)
#define AFX_CLIENTMFCDLG_H__89D3E720_73FD_4348_B6F3_ACCA1C07ECD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define _AFXDLL
#define WM_ENABLEPANTILT	WM_APP + 1
#define WM_ENABLEZOOM		WM_APP + 2
#define WM_ENABLEOTHER		WM_APP + 3
#define WM_POD_SERVICE_NOTIFICATION	WM_APP + 4

#define TIMER_TEST 1
#define TIMER_QUERY_POS 2


/////////////////////////////////////////////////////////////////////////////
// CClientMFCDlg dialog

class CClientMFCDlg : public CDialog
{
// Construction
public:
	CClientMFCDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CClientMFCDlg(); // standard destructor

//
	enum { IDD = IDD_CLIENTMFC_DIALOG };
	CStatic	m_wndDragHere;
	CButton	m_wndControlAll;
	CButton	m_wndDown;
	CButton	m_wndGetInfo;
	CButton	m_wndTest;
	CButton	m_wndDoCommand;
	CButton	m_wndZoomHome;
	CButton	m_wndZoomOut;
	CButton	m_wndZoomIn;
	CButton	m_wndRight;
	CButton	m_wndLeft;
	CButton	m_wndHome;
	CButton	m_wndUp;
	CComboBox	m_wndControl;
	CListCtrl	m_wndDevices;
	BOOL	m_bControlAll;
	CString	m_strTrackerpodInfo;
	//}}AFX_DATA



	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
	void EnablePanTiltControls(BOOL bEnable);
	void EnableZoomControls(BOOL bEnable);
	void EnableOtherControls(BOOL bEnable);
	void PopulateDeviceList();
	bool ParseValue(CString strSource, CString strKey, CString& strValue);
	void DoCommand(CString strCommand, CString strParam);


	// Generated message map functions
	//{{AFX_MSG(CClientMFCDlg)

	 void OnSysCommand(UINT nID, LPARAM lParam);
	 void OnPaint();
	
	 void OnTimer(UINT nIDEvent);
	void OnButtonSelect();
	 void OnButtonLeft();
	 void OnButtonRight();
	 void OnButtonUp();
	 void OnButtonHome();
	 void OnButtonDown();
	 void OnButtonZoomIn();
	 void OnButtonZoomHome();
	 void OnButtonZoomOut();
	 void OnButtonTest();
	 void OnButtonDoCommand();
	 void OnButtonGetInfo();
	 void OnAppAbout();
	 void OnItemchangedListDevices(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg LRESULT OnWmPodServiceNotification(WPARAM wParam, LPARAM lParam);
	 void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	 void OnMouseMove(UINT nFlags, CPoint point);
	 void OnCheckControlAll();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTMFCDLG_H__89D3E720_73FD_4348_B6F3_ACCA1C07ECD9__INCLUDED_)
