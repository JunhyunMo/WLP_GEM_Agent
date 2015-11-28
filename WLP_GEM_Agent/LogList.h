#pragma once

enum eLog_MchNum{
	eLog_MAINSCREEN = 0,
	eLog_ETHANDLER1 = 1,
	eLog_ETHANDLER2 = 2,
	eLog_ATLOADER = 3,
	eLog_ATHANDLER1 = 4,
	eLog_ATHANDLER2 = 5,
	eLog_ATSORTER = 6,
	eLog_AVI = 7,
	eLog_FINALSORTER = 8,
	eLog_MCH_MAX = 9,
};

enum eLog_Type{
	eLog_DebugNEvent = 0,
	eLog_Alarm = 1,
	eLog_Comm = 2,
	eLog_Type_MAX = 3,
};

struct stLOGLIST{
	int nMchNumber;
	int nType;
	std::wstring strText;
};

class CLogListGC;
class CLogList
{
public:
	friend class CLogListGC;
	static CLogList* Instance();

	void Load_Data_Debug();
	void Load_Data_Alarm();
	void Load_Data_Comm();

	void SetRefresh(int nMCHNUM, bool bRefresh) { m_bRefreshData[nMCHNUM] = bRefresh; };
	bool IsRefresh(int nMCHNum) { return m_bRefreshData[nMCHNum]; };

	bool GetDebugLogStringFromEnd(int nIndexfromEnd, std::wstring& strText);
	bool GetAlarmLogStringFromEnd(int nIndexfromEnd, std::wstring& strText);
	bool GetCommLogStringFromEnd(int nIndexfromEnd, std::wstring& strText);

	void AddText_Debug(LPCTSTR strText);
	void AddText_Alarm(LPCTSTR strText);
	void AddText_Comm(LPCTSTR strText);

	void Clear_LogList();

	int GetMaxStringCount() { return m_nMaxStringCount; };
	void SetMaxStringCount(int nCnt) { m_nMaxStringCount = nCnt; };

	void Add_LogData(int nMchNum, int nType, std::wstring& strText);
	bool GetLogStringFromEnd(int nMchNum, int nType, int nIndexfromEnd, std::wstring& strText);
	CString GetMchString(int nMchNum);

private:
	//std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::vector<std::wstring> m_vecLogList_Debug;
	std::vector<std::wstring> m_vecLogList_Alarm;
	std::vector<std::wstring> m_vecLogList_Comm;

	std::vector<stLOGLIST> m_vecLogList;
	int m_nMaxStringCount;
	bool m_bRefreshData[9];
	static CLogList* m_pThis;

	CLogList(void);
	~CLogList(void);

	CStringA GetExecuteDirectory();
};

