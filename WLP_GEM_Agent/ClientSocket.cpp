// ClientSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "WLP_GEM_Agent.h"
#include "ClientSocket.h"
#include "ListenSocket.h"

#include "WLP_GEM_AgentDlg.h"


// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket 멤버 함수
void CClientSocket::SetListenSocket(CAsyncSocket* pSocket)
{
	m_pListenSocket = pSocket;
}

void CClientSocket::OnClose(int nErrorCode)
{
	CSocket::OnClose(nErrorCode);

	CListenSocket* pServerSocket = (CListenSocket*)m_pListenSocket;
	pServerSocket->CloseClientSocket(this);

	((CWLP_GEM_AgentDlg*)AfxGetMainWnd())->m_bEqConnect = FALSE;
}

void CClientSocket::OnReceive(int nErrorCode)
{
	CString strIP = L"";
	UINT nPort = 0;
	
	CHAR	szBuffer[1024*10];
	::ZeroMemory(szBuffer, sizeof(szBuffer));

	TCHAR	szTBuffer[1024*10];
	::ZeroMemory(szTBuffer, sizeof(szTBuffer));
	
	GetPeerName(strIP, nPort);

	CString strRcv,strLog;

	if(Receive((BYTE*)szBuffer, sizeof(szBuffer)) > 0)
	{
		CWLP_GEM_AgentDlg* pMain = (CWLP_GEM_AgentDlg*)AfxGetMainWnd();

		pMain->MBCS2Unicode(szBuffer,szTBuffer);
		
		strRcv.Format(L"%s",szTBuffer);	
		pMain->ProcGEM_FromEQ(strRcv);

		strLog.Format(L"[RCV]%s",strRcv);
		GetLog()->Debug(strRcv.GetBuffer());
	}
	
	CSocket::OnReceive(nErrorCode);
	
}