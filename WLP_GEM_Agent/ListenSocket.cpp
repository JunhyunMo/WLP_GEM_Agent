// ListenSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "WLP_GEM_Agent.h"
#include "ListenSocket.h"
#include "ClientSocket.h"

#include "WLP_GEM_AgentDlg.h"

// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}

// CListenSocket 멤버 함수
void CListenSocket::OnAccept(int nErrorCode)
{
	CClientSocket* pClient = new CClientSocket;
	if(Accept(*pClient))
	{
		pClient->SetListenSocket(this);
		m_ptrClientSocketList.AddTail(pClient);

		//CWLP_GEM_AgentDlg* pMain = (CWLP_GEM_AgentDlg*)AfxGetMainWnd();
		//pMain->SendMessage(WM_UPDATE_UI_EVA_CONN, 0, 0);
	}
	else
	{
		delete pClient;

		//To Do - 오류
		//AfxMessageBox(_T("ERROR: Failed to accept new client!"));
		//GetLog()->Debug(_T("CListenSocket::OnAccept(...) - Failed to accept new client nErrorCode = %d"),nErrorCode);
	}

	CAsyncSocket::OnAccept(nErrorCode);
}

void CListenSocket::CloseClientSocket(CSocket* pClient)
{
	POSITION pos;
	pos = m_ptrClientSocketList.Find(pClient);
	if(pos != NULL)
	{
		if(pClient != NULL)
		{
			pClient->ShutDown();
			pClient->Close();
		}

		m_ptrClientSocketList.RemoveAt(pos);
		delete pClient;
	}

	//CWLP_GEM_AgentDlg* pMain = (CWLP_GEM_AgentDlg*)AfxGetMainWnd();
	//pMain->SendMessage(WM_UPDATE_UI_EVA_CONN, 0, 0);
}

void CListenSocket::SendChatDataAll(TCHAR* pszMessage)
{
	POSITION pos;
	pos = m_ptrClientSocketList.GetHeadPosition();
	CClientSocket* pClient = NULL;

	while(pos != NULL)
	{
		pClient = (CClientSocket*)m_ptrClientSocketList.GetNext(pos);
		if(pClient != NULL)
		{
			pClient->Send(pszMessage, lstrlen(pszMessage) * 2);
		}
	}
}

BOOL CListenSocket::SendData(CString strIP, CString strSendData)
{
	POSITION pos;
	pos = m_ptrClientSocketList.GetHeadPosition();
	CClientSocket* pClient = NULL;
	CString strIPtemp;
	UINT nPort;

	BOOL bRet = FALSE;

	CString strTmp;

	CWLP_GEM_AgentDlg* pMain = (CWLP_GEM_AgentDlg*)AfxGetMainWnd();
	CHAR chSendPacket[1024];
	memset(chSendPacket,0x00,sizeof(chSendPacket));

	while(pos != NULL)
	{
		pClient = (CClientSocket*)m_ptrClientSocketList.GetNext(pos);
		if(pClient != NULL)
		{
			pClient->GetPeerName(strIPtemp,nPort);

			if(strIP == strIPtemp)
			{
			//2014-08-20
				//if(pMain->m_ctlChkMBCS.GetCheck() == BST_CHECKED)
				//{
				pMain->Unicode2MBCS(strSendData.GetBuffer(0),chSendPacket);
				int nRet = pClient->Send((LPVOID)chSendPacket, strlen(chSendPacket) + 1);

				if(nRet > 0)
				{
					bRet = TRUE;
				}
				else
				{
					bRet = FALSE;
				}
			}		
		}
	}
	return bRet;
}