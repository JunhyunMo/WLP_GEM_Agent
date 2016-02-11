
// WLP_GEM_AgentDlg.h : 헤더 파일
//

#pragma once
#include "ezgemctrl1.h"
#include "ListenSocket.h"
#include "afxwin.h"
#include "Define.h"

// CWLP_GEM_AgentDlg 대화 상자
class CWLP_GEM_AgentDlg : public CDialogEx
{
// 생성입니다.
public:
	CWLP_GEM_AgentDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_WLP_GEM_AGENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

// 구현입니다.
protected:
	HICON m_hIcon;

	DECLARE_MESSAGE_MAP()
	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedBtGEMStart();
	afx_msg void OnBnClickedBtGEMStop();
	afx_msg void OnBnClickedBtSvrStop();
	afx_msg void OnBnClickedBtSvrStart();
	afx_msg void OnBnClickedBtRecipe();

public:
	CListenSocket	m_ListenSocket;
	CListBox		m_ctlListTCP;
	void			MBCS2Unicode(LPCSTR lpData,LPWSTR ReturnData);
	void			Unicode2MBCS(LPWSTR lpData,LPSTR lpRtd);
	void			AddLogTCP(CString str);
	
	CEzgemctrl1		m_GEM;
	CListBox		m_ctlListGEM;
	CString			m_strIniFilePath;
	CString			m_strCEIDFilePath; 
	CString			m_strSVIDFilePath; 
	CString			m_strECIDFilePath; 
	CString			m_strALIDFilePath;

	//////////Control State/////////
	UINT			m_nControlState;
	UINT			m_nPrevControlState;
	UINT			m_nDefaultControlState;

	///////////////// HSMS PARAM (ECID VARIABLES) ////
	UINT			m_nDeviceID;
	UINT			m_nRetry;
	UINT			m_nLinkInterval;
	UINT			m_nPort;
	UINT			m_nT3;
	UINT			m_nT5;
	UINT			m_nT6;
	UINT			m_nT7;
	UINT			m_nT8;
	UINT			m_nCTTime;
	CString			m_strIP;
	CString			m_strMODE;
	UINT m_nCommReqeustTimeout;
	
	struct _spoolinfo_
	{
		BOOL bSpoolEnabled;
		UINT nMaxSpoolSize;
		UINT nMaxSpoolTransmit;
		BOOL bSpoolOverwrite;
	} SPOOLINFO;

	TCHAR	m_szModelName[0xFF];
	TCHAR	m_szSoftRev[0xFF];
	UINT	m_nTimeFormat;	// 0, 1
	UINT	m_nDefaultCommState;
	BOOL	m_bJobInfoConfirm;
	CStringList m_strListRecipe;
	
	BOOL	 m_bEqConnect; //VISION Program 연결상태
	CString  GetExecuteDirectory();
	void	 AddSVID();
	void	 AddCEID();
	void	 AddALID();
	void	 AddECID();
	BOOL	 ReadConfigFile();
	BOOL	 LoadGemConfig();
	void     AddLogGEM(CString str);
	
	BOOL	GEMStart();
	BOOL	GEMStop();
	BOOL	SvrStart();
	BOOL	SvrStop();

	/*void	ProcGEM_FromEQ(CString strIP, CString strRcv);
	void	ProcGEM_FromEAP(CString strIP, CString strRcv);*/
	void	ProcGEM_FromEQ(CString strRcv);
	BOOL	ProcGEM_ToEQ(CString strSnd);

	int 	SendERS(CString strPacketBody);
	void	SendARS(CString strPacketBody);

	void    GetRecipeList(CStringList &strList);

	BOOL	CheckPort(CString strParamValue);
	BOOL	CheckPP(CString strParamValue);

	void	SelfShutDown();

	////2016-02-04 드림시스 도상호 대리 추가 개발 요구사항
	//Mode가 Online Local일 때 Event를 EAP로 동일하게 올려 주는 부분 개발 필요(EAP에서 명령 내리지 않고 동작하고, Event만 올리는 부분)
	//flag - ezGEM driver OnlineRemote에서 구분처리
	BOOL	m_bOnlineRemote; 

	//void	RemoveSV(int CEID);

	DECLARE_EVENTSINK_MAP()
	void OnConnectedEzgemctrl1();
	void OnDisconnectedEzgemctrl1();
	void OnSecsMsgInEzgemctrl1(short nStream, short nFunction, short nWbit, long lSysByte);
	void OnSecsMsgOutEzgemctrl1(short nStream, short nFunction, short nWbit, long lSysByte);
	void OnMsgRequestedEzgemctrl1(long lMsgId);
	void OnOnlineRequestEzgemctrl1(long lMsgId);
	void OnEstablishCommRequestEzgemctrl1(long lMsgId);
	void OnOnlineRemoteEzgemctrl1();
	void OnDateTimeSetRequestEzgemctrl1(long lMsgId, LPCTSTR strNewDateTime); //S2,F31
	void OnRemoteCommandEzgemctrl1(long lMsgId, LPCTSTR strCommand, short nParamCount); //S2,F41
	void OnTerminalMessageSingleEzgemctrl1(long lMsgId, LPCTSTR strMsg, short nCode); //S10,F3
	void OnOfflineRequestEzgemctrl1(long lMsgId);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
