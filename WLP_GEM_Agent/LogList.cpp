#include "stdafx.h"
#include "LogList.h"
#include "CsvParser.h"

//////////////////////////////////////////////////////////////////////
// CLogListGC
class CLogListGC
{
public:
	CLogListGC() {}
	~CLogListGC() { delete CLogList::m_pThis; CLogList::m_pThis = NULL; }
};
CLogListGC s_GC;

CLogList* CLogList::m_pThis = NULL;
CLogList::CLogList(void)
{
	for(int i=0; i < 9;i++)
	{
		m_bRefreshData[i] = true;
	}
	m_nMaxStringCount = 200;

	m_vecLogList_Debug.clear();
	m_vecLogList_Alarm.clear();
	m_vecLogList_Comm.clear();
	m_vecLogList.clear();
}

CLogList::~CLogList(void)
{
}

CLogList* CLogList::Instance()
{
	if( !m_pThis )
		m_pThis = new CLogList;
	return m_pThis;
}

CStringA CLogList::GetExecuteDirectory()
{
	CStringA strFolderPath;

	// 현재 프로그램의 실행 파일이 있는 폴더명을 추출함
	::GetModuleFileNameA(NULL, strFolderPath.GetBuffer(MAX_PATH), MAX_PATH);
	strFolderPath.ReleaseBuffer();
	if (strFolderPath.Find('\\') != -1)
	{
		for (int i = strFolderPath.GetLength() - 1; i >= 0; i--) 
		{
			CHAR ch = strFolderPath[i];
			strFolderPath.Delete(i);
			if (ch == '\\') break; 
		}
	}
	return strFolderPath;
}

void CLogList::Load_Data_Debug()
{
	SYSTEMTIME stTime;
	GetSystemTime(&stTime);

	CStringA strFileName;
	strFileName.Format("\\GEM_AGENT_LOG\\log_debug_%04d_%02d_%02d.txt",stTime.wYear,stTime.wMonth,stTime.wDay);
	CStringA strPath = GetExecuteDirectory();
	strPath += strFileName;

	cCsvTable table;

    if (!table.Load(strPath))
	{
		//MessageBox(_T("최근 알람 데이터가 없습니다.."));
        return;
	}
    
	table.AddAlias("date", 0);
	table.AddAlias("code", 1);
    table.AddAlias("text", 2);

	m_vecLogList_Debug.clear();
	int nCount = 0;
    while (table.Next())
    {
		std::string date = table.AsString("date");
		std::string inst = table.AsString("inst");
        std::string text = table.AsString("text");

		int nLen = MultiByteToWideChar(CP_ACP, 0, &date[0], date.size(), NULL, NULL);
		std::wstring wdate(nLen,0);
		MultiByteToWideChar(CP_ACP, 0, &date[0], date.size(), &wdate[0], nLen);

		nLen = MultiByteToWideChar(CP_ACP, 0, &inst[0], inst.size(), NULL, NULL);
		std::wstring winst(nLen,0);
		MultiByteToWideChar(CP_ACP, 0, &inst[0], inst.size(), &winst[0], nLen);

		nLen = MultiByteToWideChar(CP_ACP, 0, &text[0], text.size(), NULL, NULL);
		std::wstring wtext(nLen,0);
		MultiByteToWideChar(CP_ACP, 0, &text[0], text.size(), &wtext[0], nLen);

		m_vecLogList_Debug.push_back(wdate+L" "+L"["+winst+L"]"+L" "+wtext);

		nCount++;
    }

	//m_bRefreshData = false;
}

void CLogList::Load_Data_Alarm()
{
	SYSTEMTIME stTime;
	GetSystemTime(&stTime);

	CStringA strFileName;
	strFileName.Format("\\GEM_AGENT_LOG\\log_alarm_%04d_%02d_%02d.txt",stTime.wYear,stTime.wMonth,stTime.wDay);
	CStringA strPath = GetExecuteDirectory();
	strPath += strFileName;

	cCsvTable table;

    if (!table.Load(strPath))
	{
		//MessageBox(_T("최근 알람 데이터가 없습니다.."));
        return;
	}
    
	table.AddAlias("date", 0);
	table.AddAlias("inst", 1);
	table.AddAlias("code", 2);
    table.AddAlias("text", 3);

	m_vecLogList_Alarm.clear();
	int nCount = 0;
    while (table.Next())
    {
		std::string date = table.AsString("date");
		std::string inst = table.AsString("inst");
		std::string code = table.AsString("code");
        std::string text = table.AsString("text");

		int nLen = MultiByteToWideChar(CP_ACP, 0, &date[0], date.size(), NULL, NULL);
		std::wstring wdate(nLen,0);
		MultiByteToWideChar(CP_ACP, 0, &date[0], date.size(), &wdate[0], nLen);

		nLen = MultiByteToWideChar(CP_ACP, 0, &inst[0], inst.size(), NULL, NULL);
		std::wstring winst(nLen,0);
		MultiByteToWideChar(CP_ACP, 0, &inst[0], inst.size(), &winst[0], nLen);

		nLen = MultiByteToWideChar(CP_ACP, 0, &code[0], code.size(), NULL, NULL);
		std::wstring wcode(nLen,0);
		MultiByteToWideChar(CP_ACP, 0, &code[0], code.size(), &wcode[0], nLen);

		nLen = MultiByteToWideChar(CP_ACP, 0, &text[0], text.size(), NULL, NULL);
		std::wstring wtext(nLen,0);
		MultiByteToWideChar(CP_ACP, 0, &text[0], text.size(), &wtext[0], nLen);

		m_vecLogList_Alarm.push_back(wdate+L" "+L"["+winst+L"]"+L" "+L"["+wcode+L"]"+L" "+wtext);

		nCount++;
    }

//	m_bRefreshData = false;
}

void CLogList::Load_Data_Comm()
{
	SYSTEMTIME stTime;
	GetSystemTime(&stTime);

	CStringA strFileName;
	strFileName.Format("\\GEM_AGENT_LOG\\log_comm_%04d_%02d_%02d.txt",stTime.wYear,stTime.wMonth,stTime.wDay);
	CStringA strPath = GetExecuteDirectory();
	strPath += strFileName;

	cCsvTable table;

    if (!table.Load(strPath))
	{
		//MessageBox(_T("최근 알람 데이터가 없습니다.."));
        return;
	}
    
	table.AddAlias("date", 0);
	table.AddAlias("code", 1);
    table.AddAlias("text", 2);

	m_vecLogList_Comm.clear();
	int nCount = 0;
    while (table.Next())
    {
		std::string date = table.AsString("date");
		std::string inst = table.AsString("inst");
        std::string text = table.AsString("text");

		int nLen = MultiByteToWideChar(CP_ACP, 0, &date[0], date.size(), NULL, NULL);
		std::wstring wdate(nLen,0);
		MultiByteToWideChar(CP_ACP, 0, &date[0], date.size(), &wdate[0], nLen);

		nLen = MultiByteToWideChar(CP_ACP, 0, &inst[0], inst.size(), NULL, NULL);
		std::wstring winst(nLen,0);
		MultiByteToWideChar(CP_ACP, 0, &inst[0], inst.size(), &winst[0], nLen);

		nLen = MultiByteToWideChar(CP_ACP, 0, &text[0], text.size(), NULL, NULL);
		std::wstring wtext(nLen,0);
		MultiByteToWideChar(CP_ACP, 0, &text[0], text.size(), &wtext[0], nLen);

		m_vecLogList_Comm.push_back(wdate+L" "+L"["+winst+L"]"+L" "+wtext);

		nCount++;
    }

//	m_bRefreshData = false;
}

bool CLogList::GetDebugLogStringFromEnd(int nIndexfromEnd, std::wstring& strText)
{
	if((int)m_vecLogList_Debug.size() <= nIndexfromEnd) return false;

	strText = m_vecLogList_Debug[m_vecLogList_Debug.size() - 1 - nIndexfromEnd];

	return true;
}

bool CLogList::GetAlarmLogStringFromEnd(int nIndexfromEnd, std::wstring& strText)
{
	if((int)m_vecLogList_Alarm.size() <= nIndexfromEnd) return false;

	strText = m_vecLogList_Alarm[m_vecLogList_Alarm.size() - 1 - nIndexfromEnd];

	return true;
}

bool CLogList::GetCommLogStringFromEnd(int nIndexfromEnd, std::wstring& strText)
{
	if((int)m_vecLogList_Comm.size() <= nIndexfromEnd) return false;

	strText = m_vecLogList_Comm[m_vecLogList_Comm.size() - 1 - nIndexfromEnd];

	return true;
}

void CLogList::AddText_Debug(LPCTSTR strText)
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	CString strPutDate;
	strPutDate.Format( _T("%04d-%02d-%02d %02d:%02d:%02d %s"),
			st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, strText);

	m_vecLogList_Debug.push_back(strPutDate.GetBuffer());

//	m_bRefreshData = true;
}

void CLogList::AddText_Alarm(LPCTSTR strText)
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	CString strPutDate;
	strPutDate.Format( _T("%04d-%02d-%02d %02d:%02d:%02d %s"),
			st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, strText);

	m_vecLogList_Alarm.push_back(strPutDate.GetBuffer());

//	m_bRefreshData = true;
}

void CLogList::AddText_Comm(LPCTSTR strText)
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	CString strPutDate;
	strPutDate.Format( _T("%04d-%02d-%02d %02d:%02d:%02d %s"),
			st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, strText);

	m_vecLogList_Comm.push_back(strPutDate.GetBuffer());

//	m_bRefreshData = true;
}

void CLogList::Clear_LogList()
{
	m_vecLogList_Debug.clear();
	m_vecLogList_Alarm.clear();
	m_vecLogList_Comm.clear();
	m_vecLogList.clear();
}

void CLogList::Add_LogData(int nMchNum, int nType, std::wstring& strText)
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	CString strPutDate;
	strPutDate.Format( _T("%04d-%02d-%02d %02d:%02d:%02d %s"),
			st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, strText.c_str());

	stLOGLIST stTemp;
	int nCount = 0;
	stTemp.nMchNumber = nMchNum;
	stTemp.nType = nType;
	stTemp.strText = strPutDate.GetBuffer();

	if(m_vecLogList.size() >= (unsigned int)m_nMaxStringCount)
	{
		m_vecLogList.erase(m_vecLogList.begin());
	}

	m_vecLogList.push_back(stTemp);

	m_bRefreshData[nMchNum] = true;
	m_bRefreshData[0] = true;
}

bool CLogList::GetLogStringFromEnd(int nMchNum, int nType, int nIndexfromEnd, std::wstring& strText)
{
	if((int)m_vecLogList.size() <= nIndexfromEnd) return false;

	stLOGLIST stTemp;
	int nIndex = 0;
	bool bFind = false;
	CString strMchtext;

	for(int i = m_vecLogList.size() -1; i >= 0; i--)
	{
		// m_vecLogList 값중 마지막에 추가된 값부터 검사한다.
		stTemp = m_vecLogList[i];

		// 메인 스크린일 경우는 그냥 다 검색하자!
		if(stTemp.nMchNumber == nMchNum || nMchNum == 0)
		{
			if(stTemp.nType == nType || nType == 3)
			{
				if(nIndex == nIndexfromEnd)
				{
					strMchtext = GetMchString(stTemp.nMchNumber);
					strText = strMchtext.GetBuffer() + stTemp.strText;
					bFind = true;
					break;
				}
				nIndex++;
			}
		}
	}

	if(!bFind) return false;

	return true;
}

CString CLogList::GetMchString(int nMchNum)
{
	CString strMchtext = _T("");

	switch (nMchNum)
	{
	case eLog_ETHANDLER1: strMchtext.Format(_T("{ET #1} ")); break;
	case eLog_ETHANDLER2: strMchtext.Format(_T("{ET #2} ")); break;
	case eLog_ATLOADER:	  strMchtext.Format(_T("{ATL} ")); break;
	case eLog_ATHANDLER1: strMchtext.Format(_T("{ATH #1} ")); break;
	case eLog_ATHANDLER2: strMchtext.Format(_T("{ATH #2} ")); break;
	case eLog_ATSORTER:	  strMchtext.Format(_T("{ATS} ")); break;
	case eLog_FINALSORTER:strMchtext.Format(_T("{FS} ")); break;
	}

	return strMchtext;
}