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

		((CWLP_GEM_AgentDlg*)AfxGetMainWnd())->m_bEqConnect = TRUE;

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

//4.4	DYNAMIC EVENT REPORT CONFIGURATION
//This capability allows the host to increase or decrease the data flow according to need. The equipment supports the following event report configuration functionality through the SECS-II interface :
//•	Host definition / deletion of custom report
//•	Host linking / unlinking of defined reports to specified collection event
//•	Host enabling / disabling the reporting of specified collection events
//The equipment can be instructed by the host to enable or disable reporting of collection events on an individual or collective basis. Reports may be attached to an event report message. These reports are specifically linked to the desired event and typically contain variable data relating to that event. 
//
//The host is able to create reports and link them to events via the SECS-II interface. 
//The basic steps are:
//1.	create reports with S2, F33,
//2.	link the reports to an event with S2, F35, and 
//3.	enable event reporting with S2, F37.
//
//4.4.1	Dynamic Event Report Configuration Messages
//
//S2, F33  Define Report (DR)					   	    	M , H  E, reply
//
//Description	: Allows the Host to define a group of reports for the equipment.	
//If the data will require the sending of a multi-block message, this message will be proceeded by the S2, F39 / S2, F40 Inquire / Grant transaction.
//
//Structure	: L, 2
//		1. <U4 DATAID>
//		2. L, a 	{a = # of reports to define}
//			1. L, 2
//				1. <U2 RPTID1>
//				2. L, b	{b = # of variables in report}
//					1. <U2 VID1>
//					.
//					.
//					b. <U2 VIDb>
//			.
//			.
//			a. L, 2
//				1. <U2 RPTIDa>
//				2. L, c	{c = # of variables in report}
//					1. <U2 VID1>
//					.
//					.
//					c. <U2 VIDc>
//
//Exceptions	: A list of zero length following DATAID deletes all report definitions and associated links.
//A list of zero length following RPTID, deletes report type RPTID. All CEID links to this RPTID are also deleted.
//
//
//S2, F34  Define Report Acknowledge (DRA)		     		      	    S, H  E
//
//Description	: Acknowledge or error. If an error condition is detected, the entire message is rejected and no change is made to any reports on the equipment.
//
//Structure	: <B DRACK>
//
//Note		:
//DRACK	Indicates whether the Equipment was able to generate the reports.	
//0 = Accepted	
//1 = Denied. Insufficient space	
//2 = Denied. Invalid format	
//3 = Denied. At least one RPTID already defined	
//4 = Denied. At least one VID does not exist
//>4 = Other Error, not accepted	
//1~63 Reserved
//
//
//S2, F35  Link Event Report (LER)				   	    	M , H  E, reply
//
//Description	: Allows the Host to link a group of defined reports to an event (CEID). Once linked the event is by default DISABLED.	
//If the data will require the sending of a multi-block message, this message will be proceeded by the S2, F39 / S2, F40 Inquire / Grant transaction.
//
//Structure	: L, 2
//		1. <U4 DATAID>
//		2. L, a 	{a = # of events }
//			1. L, 2
//				1. <U4 CEID1>
//				2. L, b	{b = # of reports linked to CEID1}
//					1. <U2 RPTID1>
//					.
//					.
//					b. <U2 RPTIDb>
//			.
//			.
//			a. L, 2
//				1. <U4 CEIDa>
//				2. L, c	{c = # of reports linked to CEIDa}
//					1. <U2 RPTID1>
//					.
//					.
//					c. <U2 RPTIDc>
//
//Exceptions	: A list of zero length following CEID deletes all report links to that event.
//
//
//S2, F36  Link Event Report Acknowledge(LERA)		     		      	    S, H  E
//
//Description	: Acknowledge or error. If an error condition is detected, the entire message is rejected and no change is made to any events on the equipment.
//
//Structure	: <B LRACK>
//
//Note		:
//LRACK	Indicates whether the Equipment was able to link the reports to the events.	
//0 = Accepted	
//1 = Denied. Insufficient space	
//2 = Denied. Invalid format	
//3 = Denied. At least one CEID link already defined	
//4 = Denied. At least one CEID does not exists
//5 = Denied. At least one RPTID does not exists
//>5 = Other Error, not accepted	
//5~63 Reserved
//
//
//S2, F37  Enable / Disable Event Report (EDER)				   S , H  E, reply
//
//Description	: Allows the Host to enable or disable the reporting for a group of collection events (CEIDs).
//
//Structure	: L, 2
//		1. <BOOLEAN CEED>		{enable / disable}
//		2. L, n 	{n = # of events}
//			1. <U4 CEID1>
//			.
//			.
//			n. <U4 CEIDn>
//
//Exceptions	: A list of zero length following CEED means enable / disable all CEIDs that exist on the equipment.
//
//
//S2, F38 Enable / Disable Event Report Acknowledge (EERA)		    	    S, H  E
//
//Description	: Acknowledge or error. If an error condition is detected, the entire message is rejected and no change is made to any events on the equipment.
//
//Structure	: <B ERACK>
//
//Note		:
//ERACK	Indicates whether the Equipment was able to link the reports to the events.	
//0 = Accepted	
//1 = Denied. At least one CEID does not exists
//>1 = Other Error, not accepted	
//2~63 Reserved
