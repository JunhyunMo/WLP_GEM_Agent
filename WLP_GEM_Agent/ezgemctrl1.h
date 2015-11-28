#pragma once

// 컴퓨터에서 Microsoft Visual C++를 사용하여 생성한 IDispatch 래퍼 클래스입니다.

// 참고: 이 파일의 내용을 수정하지 마십시오. Microsoft Visual C++에서
//  이 클래스를 다시 생성할 때 수정한 내용을 덮어씁니다.

/////////////////////////////////////////////////////////////////////////////
// CEzgemctrl1 래퍼 클래스입니다.

class CEzgemctrl1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CEzgemctrl1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x67C03CC4, 0xF690, 0x46E7, { 0xA8, 0xD1, 0x53, 0x8E, 0xC1, 0xB1, 0x8, 0x7 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 특성입니다.
public:


// 작업입니다.
public:

// _DEZGEM

// Functions
//

	short Start()
	{
		short result;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	short Stop()
	{
		short result;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	void SetConfigFile(LPCTSTR strConfigFile)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strConfigFile);
	}
	short AcceptAndSetNewDateTime(long lMsgId, LPCTSTR strNewDateTime)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, strNewDateTime);
		return result;
	}
	short AcceptEstablishCommRequest(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short AcceptNewDateTimeSet(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short AcceptNewEquipConst(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short AcceptOnlineRequest(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short AcceptRemoteCommand(long lMsgId, LPCTSTR strCommand, short nState)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I2 ;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, strCommand, nState);
		return result;
	}
	BOOL AddAlarmID(long ALID, LPCTSTR strName, LPCTSTR strDescription)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ALID, strName, strDescription);
		return result;
	}
	BOOL AddCEID(long CEID, LPCTSTR strName, LPCTSTR strDescription)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CEID, strName, strDescription);
		return result;
	}
	BOOL AddECID(long ECID, LPCTSTR strName, LPCTSTR strUnit, LPCTSTR strDataFormat)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ECID, strName, strUnit, strDataFormat);
		return result;
	}
	BOOL AddRemoteCommand(LPCTSTR strCommandName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strCommandName);
		return result;
	}
	BOOL AddSVID(long SVID, LPCTSTR strName, LPCTSTR strDataFormat, LPCTSTR strUnit)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, SVID, strName, strDataFormat, strUnit);
		return result;
	}
	BOOL AddSubSVID(long SVID, short subSVID, LPCTSTR strName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 VTS_BSTR ;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, SVID, subSVID, strName);
		return result;
	}
	short DenyEstablishCommRequest(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short DenyNewDateTimeSet(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short DenyNewEquipConst(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short DenyOnlineRequest(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short DenyRemoteCommand(long lMsgId, LPCTSTR strCommand, short nState)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I2 ;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, strCommand, nState);
		return result;
	}
	short DisableCommunication()
	{
		short result;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	short EnableCommunication()
	{
		short result;
		InvokeHelper(0x2c, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	CString GetRemoteCommandParamName(long lMsgId, LPCTSTR strCommand, short nIndex)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I2 ;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lMsgId, strCommand, nIndex);
		return result;
	}
	CString GetRemoteCommandParamValue(long lMsgId, LPCTSTR strCommand, short nIndex)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I2 ;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lMsgId, strCommand, nIndex);
		return result;
	}
	BOOL IsEventEnabled(long CEID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CEID);
		return result;
	}
	BOOL IsOffline()
	{
		BOOL result;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL IsOnline()
	{
		BOOL result;
		InvokeHelper(0x31, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL SelectCurrentStatusValue(long SVID, short subSVID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, SVID, subSVID);
		return result;
	}
	BOOL SetCurrentStatusValue(long SVID, LPCTSTR strValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, SVID, strValue);
		return result;
	}
	BOOL SetEquipConstRange(long ECID, LPCTSTR strMinValue, LPCTSTR strMaxValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x34, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ECID, strMinValue, strMaxValue);
		return result;
	}
	BOOL SetEquipConstValue(long ECID, LPCTSTR strCurrentValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x35, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ECID, strCurrentValue);
		return result;
	}
	void SetModelName(LPCTSTR strMDLN)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strMDLN);
	}
	void SetSoftwareRev(LPCTSTR strSOFTREV)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strSOFTREV);
	}
	long GetNewEquipConst(long lMsgId, short nIndex)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, nIndex);
		return result;
	}
	CString GetNewEquipConstValue(long lMsgId, short nIndex)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lMsgId, nIndex);
		return result;
	}
	short AddUnformattedPP(LPCTSTR strPPID, LPCTSTR strFilename)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x3a, DISPATCH_METHOD, VT_I2, (void*)&result, parms, strPPID, strFilename);
		return result;
	}
	short RemoveProcessProgram(LPCTSTR strPPID)
	{
		short result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x3b, DISPATCH_METHOD, VT_I2, (void*)&result, parms, strPPID);
		return result;
	}
	short SetCurrentProcessProgram(LPCTSTR strPPID)
	{
		short result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x3c, DISPATCH_METHOD, VT_I2, (void*)&result, parms, strPPID);
		return result;
	}
	short DenyProcessProgramLoad(long lMsgId, short nErrorCode)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x3d, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, nErrorCode);
		return result;
	}
	short AcceptProcessProgram(long lMsgId, LPCTSTR PPID)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x3e, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, PPID);
		return result;
	}
	short DenyProcessProgram(long lMsgId, short nCode)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x3f, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, nCode);
		return result;
	}
	short AcceptDeleteProcessProgram(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short DenyDeleteProcessProgram(long lMsgId, short nCode)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, nCode);
		return result;
	}
	CString GetPPDeleteRequested(long lMsgId, short nIndex)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lMsgId, nIndex);
		return result;
	}
	short AcceptTerminalMessage(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short DenyTerminalMessage(short lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	CString GetTerminalMessageMulti(long lMsgId, short nIndex)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lMsgId, nIndex);
		return result;
	}
	short SendAlarmReport(long ALID, short ALCD)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_I2 ;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_I2, (void*)&result, parms, ALID, ALCD);
		return result;
	}
	short SendEventReport(long CEID)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_I2, (void*)&result, parms, CEID);
		return result;
	}
	short AcceptProcessProgramLoad(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	double GetProcessProgramSize(LPCTSTR PPID)
	{
		double result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x49, DISPATCH_METHOD, VT_R8, (void*)&result, parms, PPID);
		return result;
	}
	void EnableAutoReply(short nStream, short nFunction)
	{
		static BYTE parms[] = VTS_I2 VTS_I2 ;
		InvokeHelper(0x4a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nStream, nFunction);
	}
	void DisableAutoReply(short nStream, short nFunction)
	{
		static BYTE parms[] = VTS_I2 VTS_I2 ;
		InvokeHelper(0x4b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nStream, nFunction);
	}
	short AbortMsg(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4c, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short AddAsciiItem(long lMsgId, LPCTSTR strValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x4d, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, strValue, lCount);
		return result;
	}
	short AddBinaryItem(long lMsgId, short * pnValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0x4e, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, pnValue, lCount);
		return result;
	}
	short AddBoolItem(long lMsgId, short * pnValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0x4f, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, pnValue, lCount);
		return result;
	}
	short AddF4Item(long lMsgId, float * pfValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PR4 VTS_I4 ;
		InvokeHelper(0x50, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, pfValue, lCount);
		return result;
	}
	short AddF8Item(long lMsgId, double * prValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PR8 VTS_I4 ;
		InvokeHelper(0x51, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, prValue, lCount);
		return result;
	}
	long AddFileBinaryItem(long lMsgId, LPCTSTR strFilename)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x52, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strFilename);
		return result;
	}
	short AddI1Item(long lMsgId, short * pnValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0x53, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, pnValue, lCount);
		return result;
	}
	short AddI2Item(long lMsgId, short * pnValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0x54, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, pnValue, lCount);
		return result;
	}
	short AddI4Item(long lMsgId, long * plValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x55, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, plValue, lCount);
		return result;
	}
	short AddI8Item(long lMsgId, long * plValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x56, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, plValue, lCount);
		return result;
	}
	short AddJ8Item(long lMsgId, LPCTSTR pszValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x57, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, pszValue, lCount);
		return result;
	}
	short AddU1Item(long lMsgId, short * pnValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0x58, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, pnValue, lCount);
		return result;
	}
	short AddU2Item(long lMsgId, long * plValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x59, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, plValue, lCount);
		return result;
	}
	short AddU4Item(long lMsgId, double * prValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PR8 VTS_I4 ;
		InvokeHelper(0x5a, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, prValue, lCount);
		return result;
	}
	short AddU8Item(long lMsgId, double * prValue, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PR8 VTS_I4 ;
		InvokeHelper(0x5b, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, prValue, lCount);
		return result;
	}
	short CloseListItem(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x5c, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short CloseMsg(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x5d, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	long CreateMsg(short nStream, short nFunction, short bWaitReply)
	{
		long result;
		static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 ;
		InvokeHelper(0x5e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, nStream, nFunction, bWaitReply);
		return result;
	}
	long CreateReplyMsg(long lMsgId)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x5f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId);
		return result;
	}
	void DisableLog()
	{
		InvokeHelper(0x60, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void EnableLog()
	{
		InvokeHelper(0x61, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long GetAsciiItem(long lMsgId, BSTR * pszValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x62, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, pszValue);
		return result;
	}
	long GetAsciiItemD(long lMsgId, LPCTSTR strPointer, BSTR * pszValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x63, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, pszValue);
		return result;
	}
	CString GetAsciiItemString(long lMsgId)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lMsgId);
		return result;
	}
	CString GetAsciiItemStringD(long lMsgId, LPCTSTR strPointer)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lMsgId, strPointer);
		return result;
	}
	long GetBinaryItem(long lMsgId, short * pnValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 ;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, pnValue);
		return result;
	}
	long GetBinaryItemD(long lMsgId, LPCTSTR strPointer, short * pnValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI2 ;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, pnValue);
		return result;
	}
	long GetBoolItem(long lMsgId, short * pnValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 ;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, pnValue);
		return result;
	}
	long GetBoolItemD(long lMsgId, LPCTSTR strPointer, short * pnValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI2 ;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, pnValue);
		return result;
	}
	long GetF4Item(long lMsgId, float * pfValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PR4 ;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, pfValue);
		return result;
	}
	long GetF4ItemD(long lMsgId, LPCTSTR strPointer, float * pfValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PR4 ;
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, pfValue);
		return result;
	}
	long GetF8Item(long lMsgId, double * prValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PR8 ;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, prValue);
		return result;
	}
	long GetF8ItemD(long lMsgId, LPCTSTR strPointer, double * prValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PR8 ;
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, prValue);
		return result;
	}
	long GetFileBinaryItem(long lMsgId, LPCTSTR strFilename)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strFilename);
		return result;
	}
	long GetFileBinaryItemD(long lMsgId, LPCTSTR strPointer, LPCTSTR strFilename)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, strFilename);
		return result;
	}
	CString GetHeaderMsg(long lMsgId)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lMsgId);
		return result;
	}
	long GetI1Item(long lMsgId, short * pnValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 ;
		InvokeHelper(0x71, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, pnValue);
		return result;
	}
	long GetI1ItemD(long lMsgId, LPCTSTR strPointer, short * pnValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI2 ;
		InvokeHelper(0x72, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, pnValue);
		return result;
	}
	long GetI2Item(long lMsgId, short * pnValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 ;
		InvokeHelper(0x73, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, pnValue);
		return result;
	}
	long GetI2ItemD(long lMsgId, LPCTSTR strPointer, short * pnValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI2 ;
		InvokeHelper(0x74, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, pnValue);
		return result;
	}
	long GetI4Item(long lMsgId, long * plValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, plValue);
		return result;
	}
	long GetI4ItemD(long lMsgId, LPCTSTR strPointer, long * plValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x76, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, plValue);
		return result;
	}
	long GetI8Item(long lMsgId, long * plValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x77, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, plValue);
		return result;
	}
	long GetI8ItemD(long lMsgId, LPCTSTR strPointer, long * plValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x78, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, plValue);
		return result;
	}
	long GetJ8Item(long lMsgId, BSTR * pszValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x79, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, pszValue);
		return result;
	}
	long GetJ8ItemD(long lMsgId, LPCTSTR strPointer, BSTR * pszValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x7a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, pszValue);
		return result;
	}
	CString GetJ8ItemString(long lMsgId)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x7b, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lMsgId);
		return result;
	}
	CString GetJ8ItemStringD(long lMsgId, LPCTSTR strPointer)
	{
		CString result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x7c, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lMsgId, strPointer);
		return result;
	}
	short GetListItemClose(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x7d, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short GetListItemOpen(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x7e, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short GetMsgInfo(long lMsgId, short * pnStream, short * pnFunction, short * pnWaitReply, long * plMsgLength)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_PI2 VTS_PI2 VTS_PI4 ;
		InvokeHelper(0x7f, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, pnStream, pnFunction, pnWaitReply, plMsgLength);
		return result;
	}
	short GetMsgQueSize()
	{
		short result;
		InvokeHelper(0x80, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	short GetNextItemFormat(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x81, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short GetSubItemFormat(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x82, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	CString GetSystemByte(long lMsgId)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x83, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lMsgId);
		return result;
	}
	long GetU1Item(long lMsgId, short * pnValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 ;
		InvokeHelper(0x84, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, pnValue);
		return result;
	}
	long GetU1ItemD(long lMsgId, LPCTSTR strPointer, short * pnValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI2 ;
		InvokeHelper(0x85, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, pnValue);
		return result;
	}
	long GetU2Item(long lMsgId, long * plValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x86, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, plValue);
		return result;
	}
	long GetU2ItemD(long lMsgId, LPCTSTR strPointer, long * plValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x87, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, plValue);
		return result;
	}
	long GetU4Item(long lMsgId, double * prValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PR8 ;
		InvokeHelper(0x88, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, prValue);
		return result;
	}
	long GetU4ItemD(long lMsgId, LPCTSTR strPointer, double * prValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PR8 ;
		InvokeHelper(0x89, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, prValue);
		return result;
	}
	long GetU8Item(long lMsgId, double * prValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PR8 ;
		InvokeHelper(0x8a, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, prValue);
		return result;
	}
	long GetU8ItemD(long lMsgId, LPCTSTR strPointer, double * prValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PR8 ;
		InvokeHelper(0x8b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, strPointer, prValue);
		return result;
	}
	short OpenListItem(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8c, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short SendMsg(long lMsgId)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8d, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId);
		return result;
	}
	short SetComm(short nComPort, long lBaudRate, short nParity, short nDataBits, short nStopBits)
	{
		short result;
		static BYTE parms[] = VTS_I2 VTS_I4 VTS_I2 VTS_I2 VTS_I2 ;
		InvokeHelper(0x8e, DISPATCH_METHOD, VT_I2, (void*)&result, parms, nComPort, lBaudRate, nParity, nDataBits, nStopBits);
		return result;
	}
	void SetLogFile(LPCTSTR strFilename, short bLogSecsII)
	{
		static BYTE parms[] = VTS_BSTR VTS_I2 ;
		InvokeHelper(0x8f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strFilename, bLogSecsII);
	}
	void GoOnlineLocal()
	{
		InvokeHelper(0x90, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void GoOnlineRemote()
	{
		InvokeHelper(0x91, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void GoOffline()
	{
		InvokeHelper(0x92, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void EnableSpooling()
	{
		InvokeHelper(0x93, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void DisableSpooling()
	{
		InvokeHelper(0x94, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	CString GetSpoolStartTime()
	{
		CString result;
		InvokeHelper(0x95, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void SetMaxSpoolCount(short nMax)
	{
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x96, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMax);
	}
	short GetMaxSpoolCount()
	{
		short result;
		InvokeHelper(0x97, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	short GetActualSpoolCount()
	{
		short result;
		InvokeHelper(0x98, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	CString GetSpoolFullTime()
	{
		CString result;
		InvokeHelper(0x99, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void EnableSpoolOverWrite()
	{
		InvokeHelper(0x9a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void DisableSpoolOverWrite()
	{
		InvokeHelper(0x9b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL IsSpoolEnabled()
	{
		BOOL result;
		InvokeHelper(0x9c, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL IsSpoolOverWritable()
	{
		BOOL result;
		InvokeHelper(0x9d, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void SetMaxSpoolTransmit(short nMaxTransmit)
	{
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x9e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMaxTransmit);
	}
	short GemMaxSpoolTransmit()
	{
		short result;
		InvokeHelper(0x9f, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	BOOL SetFormatCodeCEID(short nFormatCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0xa0, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, nFormatCode);
		return result;
	}
	short GetFormatCodeCEID()
	{
		short result;
		InvokeHelper(0xa1, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	BOOL SetFormatCodeALID(short nFormatCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0xa2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, nFormatCode);
		return result;
	}
	short GetFormatCodeALID()
	{
		short result;
		InvokeHelper(0xa3, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	BOOL SetFormatCodeECID(short nFormatCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0xa4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, nFormatCode);
		return result;
	}
	short GetFormatCodeECID()
	{
		short result;
		InvokeHelper(0xa5, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	BOOL SetFormatCodeSVID(short nFormatCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0xa6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, nFormatCode);
		return result;
	}
	short GetFormatCodeSVID()
	{
		short result;
		InvokeHelper(0xa7, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	BOOL SetFormatCodeRPTID(short nFormatCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0xa8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, nFormatCode);
		return result;
	}
	short GetFormatCodeRPTID()
	{
		short result;
		InvokeHelper(0xa9, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	BOOL SetFormatCodeDATAID(short nFormatCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0xaa, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, nFormatCode);
		return result;
	}
	short GetFormatCodeDATAID()
	{
		short result;
		InvokeHelper(0xab, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	BOOL SetFormatCodeTRACEID(short nFormatCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0xac, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, nFormatCode);
		return result;
	}
	short GetFormatCodeTRACEID()
	{
		short result;
		InvokeHelper(0xad, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	BOOL CreateFormattedProcessProgram(LPCTSTR strPPID)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xae, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPPID);
		return result;
	}
	BOOL AddProcessProgramParameter(LPCTSTR strPPID, short nCommandCode, LPCTSTR strDataFormat, LPCTSTR strValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I2 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xaf, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPPID, nCommandCode, strDataFormat, strValue);
		return result;
	}
	CString GetCurrentECValue(long ECID)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xb0, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, ECID);
		return result;
	}
	CString GetEquipConstName(long ECID)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xb1, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, ECID);
		return result;
	}
	CString GetCurrentPPID()
	{
		CString result;
		InvokeHelper(0xb2, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	short SendProcessProgram(LPCTSTR strPPID)
	{
		short result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xb3, DISPATCH_METHOD, VT_I2, (void*)&result, parms, strPPID);
		return result;
	}
	void SetLogRetention(short nDays)
	{
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0xb4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nDays);
	}
	short GetLogRetention()
	{
		short result;
		InvokeHelper(0xb5, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	CString GetMsgText(long lMsgId)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xb6, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, lMsgId);
		return result;
	}
	long CreateEmptyMsg()
	{
		long result;
		InvokeHelper(0xb7, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	short SetHeaderByte(long lMsgId, short * pnBuff)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI2 ;
		InvokeHelper(0xb8, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, pnBuff);
		return result;
	}
	short GetHeaderByte(long lMsgId, short * pnBuff)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_PI2 ;
		InvokeHelper(0xb9, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, pnBuff);
		return result;
	}
	long SetMsgByte(long lMsgId, short * pnBuff, long lSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0xba, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, pnBuff, lSize);
		return result;
	}
	long GetMsgByte(long lMsgId, short * pnBuff, long lSize)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_I4 ;
		InvokeHelper(0xbb, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, pnBuff, lSize);
		return result;
	}
	void SetFormatCheck(short bEnabled)
	{
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0xbc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bEnabled);
	}
	short GetFormatCheck()
	{
		short result;
		InvokeHelper(0xbd, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	void SetFormatFile(LPCTSTR lpszFormatFile)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xbe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, lpszFormatFile);
	}
	void EnableMultiBlockInquire()
	{
		InvokeHelper(0xbf, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void DisableMultiBlockInquire()
	{
		InvokeHelper(0xc0, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void EnableAlarm(long ALID)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ALID);
	}
	void DisableAlarm(long ALID)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ALID);
	}
	void SetStatusValueRange(long SVID, LPCTSTR strMin, LPCTSTR strMax)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xc3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SVID, strMin, strMax);
	}
	void EnableErrorMessage()
	{
		InvokeHelper(0xc4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void DisableErrorMessage()
	{
		InvokeHelper(0xc5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	short AddListItem(long lMsgId, long lCount)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0xc6, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, lCount);
		return result;
	}
	long GetListItem(long lMsgId)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc7, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId);
		return result;
	}
	long SetReport(long RPTID, long * plSVID, long lCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_I4, (void*)&result, parms, RPTID, plSVID, lCount);
		return result;
	}
	long GetReport(long RPTID, long * plSVID)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, RPTID, plSVID);
		return result;
	}
	long ClearReport()
	{
		long result;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long RemoveReport(long RPTID)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_I4, (void*)&result, parms, RPTID);
		return result;
	}
	long SetEventReport(long CEID, long * plRPTID, long lCount)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0xcc, DISPATCH_METHOD, VT_I4, (void*)&result, parms, CEID, plRPTID, lCount);
		return result;
	}
	long GetEventReport(long CEID, long * plRPTID)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0xcd, DISPATCH_METHOD, VT_I4, (void*)&result, parms, CEID, plRPTID);
		return result;
	}
	long AddCurrentStatusValue(long lMsgId, long SVID)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0xce, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, SVID);
		return result;
	}
	CString GetCurrentStatusValue(long SVID)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xcf, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, SVID);
		return result;
	}
	CString GetSVName(long SVID)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd0, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, SVID);
		return result;
	}
	CString GetSVUnit(long SVID)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd1, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, SVID);
		return result;
	}
	void SetRemoteCommandErrorCode(long lMsgId, LPCTSTR strCommand, short nParamIndex, short nErrorCode)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I2 VTS_I2 ;
		InvokeHelper(0xd2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, lMsgId, strCommand, nParamIndex, nErrorCode);
	}
	short GetRuntimeState()
	{
		short result;
		InvokeHelper(0xd3, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	long GetTotalSpoolCount()
	{
		long result;
		InvokeHelper(0xd4, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void SetTimeFormat(short nLength)
	{
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0xd5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nLength);
	}
	long GetAlarmInfo(long ALID, short * pnALCD, BSTR * pszALTX)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI2 VTS_PBSTR ;
		InvokeHelper(0xd6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, ALID, pnALCD, pszALTX);
		return result;
	}
	short GetAlarmCode(long ALID)
	{
		short result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd7, DISPATCH_METHOD, VT_I2, (void*)&result, parms, ALID);
		return result;
	}
	CString GetAlarmText(long ALID)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd8, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, ALID);
		return result;
	}
	short ReplyRemoteCommand(long lMsgId, LPCTSTR strCommand, short nCode)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I2 ;
		InvokeHelper(0xd9, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lMsgId, strCommand, nCode);
		return result;
	}
	short UpdateAlarm(long ALID, LPCTSTR strName, short ALCD)
	{
		short result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I2 ;
		InvokeHelper(0xda, DISPATCH_METHOD, VT_I2, (void*)&result, parms, ALID, strName, ALCD);
		return result;
	}
	short SeparateLog(LPCTSTR szLogFileName, short nStream, short nFunction)
	{
		short result;
		static BYTE parms[] = VTS_BSTR VTS_I2 VTS_I2 ;
		InvokeHelper(0xdb, DISPATCH_METHOD, VT_I2, (void*)&result, parms, szLogFileName, nStream, nFunction);
		return result;
	}
	void SetMaxLogFileSize(short nMegaByte)
	{
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0xdc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nMegaByte);
	}
	long AddArrayItem(long lMsgId, LPCTSTR pszType, long nDataCount, LPCTSTR pszData)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR ;
		InvokeHelper(0xdd, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, pszType, nDataCount, pszData);
		return result;
	}
	long GetArrayItem(long lMsgId, BSTR * pszValue)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0xde, DISPATCH_METHOD, VT_I4, (void*)&result, parms, lMsgId, pszValue);
		return result;
	}
	void SkipLog(short nStream, short nFunction)
	{
		static BYTE parms[] = VTS_I2 VTS_I2 ;
		InvokeHelper(0xdf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nStream, nFunction);
	}

// Properties
//

long GetBaudRate()
{
	long result;
	GetProperty(0x1, VT_I4, (void*)&result);
	return result;
}
void SetBaudRate(long propVal)
{
	SetProperty(0x1, VT_I4, propVal);
}
short GetCommPort()
{
	short result;
	GetProperty(0x2, VT_I2, (void*)&result);
	return result;
}
void SetCommPort(short propVal)
{
	SetProperty(0x2, VT_I2, propVal);
}
short GetDataBits()
{
	short result;
	GetProperty(0x3, VT_I2, (void*)&result);
	return result;
}
void SetDataBits(short propVal)
{
	SetProperty(0x3, VT_I2, propVal);
}
short GetDeviceID()
{
	short result;
	GetProperty(0x4, VT_I2, (void*)&result);
	return result;
}
void SetDeviceID(short propVal)
{
	SetProperty(0x4, VT_I2, propVal);
}
BOOL GetHostMode()
{
	BOOL result;
	GetProperty(0x5, VT_BOOL, (void*)&result);
	return result;
}
void SetHostMode(BOOL propVal)
{
	SetProperty(0x5, VT_BOOL, propVal);
}
CString GetIP()
{
	CString result;
	GetProperty(0x6, VT_BSTR, (void*)&result);
	return result;
}
void SetIP(CString propVal)
{
	SetProperty(0x6, VT_BSTR, propVal);
}
short GetLinkTestInterval()
{
	short result;
	GetProperty(0x7, VT_I2, (void*)&result);
	return result;
}
void SetLinkTestInterval(short propVal)
{
	SetProperty(0x7, VT_I2, propVal);
}
short GetParity()
{
	short result;
	GetProperty(0x8, VT_I2, (void*)&result);
	return result;
}
void SetParity(short propVal)
{
	SetProperty(0x8, VT_I2, propVal);
}
BOOL GetPassiveMode()
{
	BOOL result;
	GetProperty(0x9, VT_BOOL, (void*)&result);
	return result;
}
void SetPassiveMode(BOOL propVal)
{
	SetProperty(0x9, VT_BOOL, propVal);
}
short GetPort()
{
	short result;
	GetProperty(0xa, VT_I2, (void*)&result);
	return result;
}
void SetPort(short propVal)
{
	SetProperty(0xa, VT_I2, propVal);
}
short GetRetry()
{
	short result;
	GetProperty(0xb, VT_I2, (void*)&result);
	return result;
}
void SetRetry(short propVal)
{
	SetProperty(0xb, VT_I2, propVal);
}
BOOL GetSecsI()
{
	BOOL result;
	GetProperty(0xc, VT_BOOL, (void*)&result);
	return result;
}
void SetSecsI(BOOL propVal)
{
	SetProperty(0xc, VT_BOOL, propVal);
}
short GetStopBits()
{
	short result;
	GetProperty(0xd, VT_I2, (void*)&result);
	return result;
}
void SetStopBits(short propVal)
{
	SetProperty(0xd, VT_I2, propVal);
}
short GetT1()
{
	short result;
	GetProperty(0xe, VT_I2, (void*)&result);
	return result;
}
void SetT1(short propVal)
{
	SetProperty(0xe, VT_I2, propVal);
}
short GetT2()
{
	short result;
	GetProperty(0xf, VT_I2, (void*)&result);
	return result;
}
void SetT2(short propVal)
{
	SetProperty(0xf, VT_I2, propVal);
}
short GetT3()
{
	short result;
	GetProperty(0x10, VT_I2, (void*)&result);
	return result;
}
void SetT3(short propVal)
{
	SetProperty(0x10, VT_I2, propVal);
}
short GetT4()
{
	short result;
	GetProperty(0x11, VT_I2, (void*)&result);
	return result;
}
void SetT4(short propVal)
{
	SetProperty(0x11, VT_I2, propVal);
}
short GetT5()
{
	short result;
	GetProperty(0x12, VT_I2, (void*)&result);
	return result;
}
void SetT5(short propVal)
{
	SetProperty(0x12, VT_I2, propVal);
}
short GetT6()
{
	short result;
	GetProperty(0x13, VT_I2, (void*)&result);
	return result;
}
void SetT6(short propVal)
{
	SetProperty(0x13, VT_I2, propVal);
}
short GetT7()
{
	short result;
	GetProperty(0x14, VT_I2, (void*)&result);
	return result;
}
void SetT7(short propVal)
{
	SetProperty(0x14, VT_I2, propVal);
}
short GetT8()
{
	short result;
	GetProperty(0x15, VT_I2, (void*)&result);
	return result;
}
void SetT8(short propVal)
{
	SetProperty(0x15, VT_I2, propVal);
}
short GetEstablishCommRetryTimer()
{
	short result;
	GetProperty(0x16, VT_I2, (void*)&result);
	return result;
}
void SetEstablishCommRetryTimer(short propVal)
{
	SetProperty(0x16, VT_I2, propVal);
}


};
