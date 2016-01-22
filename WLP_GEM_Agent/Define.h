//////////////////////////////////////////////////////
// DEFINE.H

/*********************************************************/

/*********************************************************/

#define		RESULT_OK		0x00

#define		WM_TERMMSG_ACK		WM_USER+10000


///////////// Control State /////////////////
typedef enum
{
	CONTROL_UNKOWN = 0,
	CONTROL_EQUIPMENT_OFFLINE = 1,
	CONTROL_GOING_TO_ONLINE = 2,
	CONTROL_HOST_OFFLINE = 3,
	CONTROL_ONLINE_LOCAL = 4,
	CONTROL_ONLINE_REMOTE = 5,
} CONTROL_STATE;

typedef enum
{
	DFFAULT_EQUIPMENT_OFFLINE = 0,
	DEFAULT_HOST_OFFLINE = 1,
	DEFAULT_ONLINE_LOCAL = 2,
	DEFAULT_ONLINE_REMOTE = 3
} DEFAULT_CONTROL_STATE;

typedef enum
{
	SPOOL_INACTIVE = 0,
	SPOOL_ACTIVE = 1,
	SPOOL_FULL = 2,
	SPOOL_PURGE = 3,
	SPOOL_TRANSMIT = 4,
	SPOOL_NOSPOOL = 5,
	SPOOL_POWEROFF = 6,
	SPOOL_POWERON = 7,
} SPOOL_STATE;

#define HSMS			_T("HSMS")
#define HSMS_PORT		_T("PORT")
#define HSMS_DEVICEID	_T("DEVICEID")
#define HSMS_LINKTEST	_T("LINKTEST")
#define HSMS_RETRY		_T("RETRY")
#define HSMS_T3			_T("T3")
#define HSMS_T5			_T("T5")
#define HSMS_T6			_T("T6")
#define HSMS_T7			_T("T7")
#define HSMS_T8			_T("T8")

/////////////////////////////////////////////////////////////////////////////////////////
//WISOL WLP 외검시스템
//SVID - status variable
#define	SVID_PPID				2010
#define	SVID_CASSETTE_ID		2210
#define SVID_PORT_ID			2220
#define SVID_WAFER_ID			2230
#define SVID_SLOT_ID			2240
#define SVID_STATE				2250

//DVID - data variable
#define	DVID_COLLECTION_DATA	3000
#define DVID_TPWC				3100
#define DVID_INSP_TIME			3110
#define	DVID_INSP_EXEC_TIME		3120		
#define DVID_YIELD				3130
#define DVID_GOOD				3140					
#define DVID_NO_DIE_NG			3150
#define DVID_DICING_LINE_NG		3160
#define DVID_PLATE_NG			3170 //도금		
#define	DVID_ORIENT_NG			3180 //도금 방향	
#define DVID_FM_NG				3190 //이물 
#define DVID_CRACK_NG			3200
#define DVID_PRE_NG				3210 //이전 공정		
#define DVID_MULTI_NG			3220		

//CEID
#define CEID_BCR_READ				 1200
#define CEID_LOAD_REQUEST			 1300
#define CEID_LOAD_COMPLETE			 1400
#define CEID_PP_SELECTED			 1500
#define CEID_CASSETTE_START			 1600
#define CEID_WAFER_LOAD				 1700
#define CEID_WAFER_LOAD_FIRST		 1701
#define CEID_WAFER_START			 1800
#define CEID_WAFER_DCOL				 1900
#define CEID_WAFER_END				 2000
#define CEID_WAFER_UNLOAD			 2100
#define CEID_WAFER_UNLOAD_LAST		 2101
#define CEID_LAST_WAFER_UNLOAD		 2200
#define CEID_DATA_COLLECTION		 2300
#define CEID_CASSETTE_END			 2400
#define CEID_UNLOAD_REQUEST			 2500
#define CEID_UNLOAD_COMPLETE		 2600
#define CEID_Processing_State_Change 3000

//ECID
#define ECID_TCP_Port				3001
#define ECID_DEVICEID				3002
#define ECID_T3						3003
#define ECID_T5						3005
#define ECID_T6						3006
#define ECID_T7						3007
#define ECID_T8						3008
//#define ECID_CONVERSATION_TIMEOUT	3007
#define ECID_LINKTEST				3009
#define ECID_RETRY					3010
//etc

/////////////////////////////////////////////////////////////////////////////////////////
#define SVID_COMMSTATE			2001
#define SVID_CONTROLSTATE		2002
#define SVID_PREV_CONTROLSTATE	2003
#define SVID_ALID				2005
#define SVID_ALCD				2007
#define SVID_ALTX				2008

#define SVID_CLOCK				2012
#define SVID_MDLN				2013
#define SVID_SOFTREV			2014

#define SVID_OPERATOR_ID		2026

#define SVID_SPOOLCOUNT_TOTAL	2030
#define SVID_SPOOLCOUNT_ACTUAL	2031
#define SVID_SPOOL_FULLTIME		2032
#define SVID_SPOOL_STARTTIME	2033
#define SVID_SPOOL_STATE		2034
#define SVID_SPOOL_MAX_COUNT	2035

#define SVID_ECID				2041
#define SVID_ECVAL				2042

#define SVID_PROC_STATE			2050
#define SVID_PREV_PROCSTATE		2051

#define SVID_PPCHANGE_NAME		2061
#define SVID_PPCHANGE_STATUS	2062

//////////////////////////////////////////////////////////

//#define ECID_PORT					3001

#define	ECID_ESTABLISH_TIMEOUT		3001




#define ECID_DEFAULT_COMM_STATE		3010
#define ECID_DEFAULT_CONTROL_STATE	3011

//#define ECID_MDLN					3103
//#define ECID_SOFTREV				3104

#define ECID_MAX_SPOOL_SIZE			3012
#define ECID_MAXSPOOL_TRANSMIT		3013
#define ECID_SPOOL_OVERWRITE		3014
#define ECID_SPOOLING_MODE			3015

#define ECID_TIME_FORMAT			3016
#define ECID_JOBINFO_OPCONFIRM		3017
#define ECID_IDLE_TIME				3018
//#define ECID_BCR_USE				3600

#define INTERVAL_SETTIME			1000
#define TIMERID_TRAY				1001
#define TIMERID_START				1002
#define TIMERID_SETTIME				1003

///////////////////////////////////////////////////////////////////////
#define PROCESS_UNDEFINE		0
#define PROCESS_INIT			1
#define PROCESS_IDLE			2
#define PROCESS_SETUP			3
#define PROCESS_READY			4
#define PROCESS_EXECUTING		5
#define PROCESS_PAUSED			6

///////////////////////////////////////////////////////////////////////
#define LOCAL_HOST				L"127.0.0.1"
#define EPPD					L"C:\\HITS\\RECIPE\\" //Equipment Process Program Directory(EPPD...TO-DO 맞출것. 

