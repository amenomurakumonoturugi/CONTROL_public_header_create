///////////////////////////////////////////////////////////
//                                                       //
// このヘッダーファイルはmqhファイル側では変更しない     //
// .hと.mqhtとして両方、生成するcmakeが作成されるため    //
//                                                       //
///////////////////////////////////////////////////////////

#ifndef CONTROL_H_PUBLIC_HEADER

#define CONTROL_H_PUBLIC_HEADER


///////////////////////////////////////////////////////////
//
// MQL5用の記述
//

#ifdef COMPILER_FOO_MQH5

#include                                                    "C:\\Users\\okita\\AppData\\Roaming\\MetaQuotes\\Terminal\\ED051E4A9BEE8A33BDDD0F947358B2B2\\MQL5\\Experts\\CONTROL\\PCH.mqh"

#define CONTROL_FOLDER_DRC                                  "\\ReturnSafety\\CONTROL"

#define ERR_MS_ERR_NUM_FILE_NAME                            "err.bin"
#define ERR_MS_ERR_NUM_FILE_DRC                             "\\err_ms\\files\\err\\"
#define ERR_MS_ERR_NUM_FULL_PATH                            CONTROL_FOLDER_DRC ERR_MS_ERR_NUM_FILE_DRC ERR_MS_ERR_NUM_FILE_NAME

#define ERR_MS_VISIBLE_ERR_NUM_FILE_NAME                    "vis.bin"
#define ERR_MS_VISIBLE_ERR_NUM_FILE_DRC                     "\\err_ms\\files\\vis\\"
#define ERR_MS_VISIBLE_ERR_NUM_FULL_PATH                    CONTROL_FOLDER_DRC ERR_MS_VISIBLE_ERR_NUM_FILE_DRC ERR_MS_VISIBLE_ERR_NUM_FILE_NAME

#define MT5_LANGUAGE_NUM_FILE_NAME                          "lang.bin"
#define MT5_LANGUAGE_NUM_FILE_DRC                           "\\lang\\"
#define MT5_LANGUAGE_NUM_FULL_PATH                          CONTROL_FOLDER_DRC MT5_LANGUAGE_NUM_FILE_DRC MT5_LANGUAGE_NUM_FILE_NAME

#define ERR_MS_WINDOW_TITLE                                 "CONTROL system error"
#define ERR_MS_WINDOW_CLASS                                 "#32770"
#define NULL_STRING                                         ""
#define SPACE_STRING                                        " "
#define COLON_STRING                                        ":"
#define LINE_BREAK                                          "\n"
#define BACK_SLASH_STRING                                   "\\"
#define MT5_LANGUAGE_NUM_FILE_SIZE                          sizeof(ulong)
#define ERR_MS_ERR_NUM_FILE_SIZE                            sizeof(ulong)
#define ERR_MS_VISIBLE_ERR_NUM_FILE_SIZE                    sizeof(ulong)

#define INVALID_HANDLE_VALUE                                -1
#define GENERIC_READ                                        0x80000000L
#define GENERIC_WRITE                                       0x40000000L
#define FILE_SHARE_READ                                     0x00000001
#define OPEN_ALWAYS                                         4
#define FILE_ATTRIBUTE_NORMAL                               0x00000080
#define LOCKFILE_EXCLUSIVE_LOCK                             0x00000002
#define ERROR_SUCCESS                                       0
#define ERROR_IO_PENDING                                    997L

#define CPP_MQH_GO_WORD(source)                             (&source)
#define CPP_MQH_LARGE                                       long
#define CPP_MQH_PLARGE(source)                              (source)
#define CPP_MQH_LONG                                        long
#define CPP_MQH_LPDWORD                                     uint
#define CPP_MQH_VARIABLE_DATA_TYPE                          ulong
#define CPP_MQH_VARIABLE_WRITE_DATA                         ulong


#endif


///////////////////////////////////////////////////////////
//
// c++用の記述
//

#ifdef COMPILER_FOO_CPP

#define CONTROL_FOLDER_DRC                                  L"\\ReturnSafety\\CONTROL"

#define ERR_MS_ERR_NUM_FILE_NAME                            L"err.bin"
#define ERR_MS_ERR_NUM_FILE_DRC                             L"\\err_ms\\files\\err\\"
#define ERR_MS_ERR_NUM_FULL_PATH                            CONTROL_FOLDER_DRC ERR_MS_ERR_NUM_FILE_DRC ERR_MS_ERR_NUM_FILE_NAME

#define ERR_MS_VISIBLE_ERR_NUM_FILE_NAME                    L"vis.bin"
#define ERR_MS_VISIBLE_ERR_NUM_FILE_DRC                     L"\\err_ms\\files\\vis\\"
#define ERR_MS_VISIBLE_ERR_NUM_FULL_PATH                    CONTROL_FOLDER_DRC ERR_MS_VISIBLE_ERR_NUM_FILE_DRC ERR_MS_VISIBLE_ERR_NUM_FILE_NAME

#define MT5_LANGUAGE_NUM_FILE_NAME                          L"lang.bin"
#define MT5_LANGUAGE_NUM_FILE_DRC                           L"\\lang\\"
#define MT5_LANGUAGE_NUM_FULL_PATH                          CONTROL_FOLDER_DRC MT5_LANGUAGE_NUM_FILE_DRC MT5_LANGUAGE_NUM_FILE_NAME

#define ERR_MS_WINDOW_TITLE                                 L"CONTROL system error"
#define ERR_MS_WINDOW_CLASS                                 L"#32770"
#define NULL_STRING                                         L""
#define ERR_USER_ERROR_FIRST                                65536
#define LINE_BREAK                                          L"\n"
#define SPACE_STRING                                        L" "
#define COLON_STRING                                        L":"
#define BACK_SLASH_STRING                                   L"\\"

#define MUTEX_GLOBAL_NAME_LOG_PROCESS                       L"Global\\ReturnSafety_CONTROL_Log_Mutex"

#define GET_MUTEX_TRIAL_MAX_COUNT                           10
#define GET_MUTEX_TRIAL_SLEEP_MILLI_SEC                     100
#define GET_MUTEX_WAIT_LOCK_MILLI_SEC                       20

#define ulong                                               unsigned __int64
#define string                                              const wchar_t*
#define ushort                                              unsigned short
#define uint                                                unsigned int

#define ResetLastError()                                    (SetLastError(ERROR_SUCCESS))

#define CPP_MQH_GO_WORD(source)                             (&source)
#define CPP_MQH_LARGE                                       LARGE_INTEGER
#define CPP_MQH_PLARGE(source)                              (&source)
#define CPP_MQH_LONG                                        __int64
#define CPP_MQH_LPDWORD                                     unsigned long

class PROCESS_MANAGER {

private:

	static bool Get_Mutex(const std::wstring_view mutex_name, HANDLE& mutex_handle, DWORD milli_second) {

		mutex_handle = CreateMutexW(NULL, FALSE, mutex_name.data());

		if (mutex_handle == NULL)
			return false;

		DWORD result = WaitForSingleObject(mutex_handle, milli_second);

		switch (result) {

		case WAIT_OBJECT_0:
			return true;
		case WAIT_ABANDONED:
			return true;
		case WAIT_TIMEOUT:
		case WAIT_FAILED:
		default:
			CloseHandle(mutex_handle);
			mutex_handle = INVALID_HANDLE_VALUE;
			return false;
		}
	}

public:

	static void Close(HANDLE handle) {

		if (handle != INVALID_HANDLE_VALUE) {

			ReleaseMutex(handle);

			CloseHandle(handle);
		}
	}

	static bool Trial_Get_Mutex(const std::wstring_view mutex_name, HANDLE& mutex_handle) {

		for (size_t i = 0; i < GET_MUTEX_TRIAL_MAX_COUNT; i++) {

			if (Get_Mutex(mutex_name, mutex_handle, GET_MUTEX_WAIT_LOCK_MILLI_SEC)) {

				return true;
			}

			else {

				Sleep(GET_MUTEX_TRIAL_SLEEP_MILLI_SEC);
			}
		}

		return false;
	}
};

static bool Get_Local_App_Data(std::wstring& result) {

	PWSTR path = nullptr;

	if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &path))) {

		result = path;
		CoTaskMemFree(path);

		return true;
	}

	else {

		return false;
	}
}


#ifdef COMPILER_FOO_CPP_ERR_MS_EXE

#define MT5_LANGUAGE_NUM_FILE_SIZE                          sizeof(ulong)
#define ERR_MS_ERR_NUM_FILE_SIZE                            sizeof(ulong)
#define ERR_MS_VISIBLE_ERR_NUM_FILE_SIZE                    sizeof(ulong)

#define CPP_MQH_VARIABLE_DATA_TYPE                          ulong
#define CPP_MQH_VARIABLE_WRITE_DATA                         ulong

#endif

#ifdef COMPILER_FOO_CPP_LOG_MNG_EXE

#define LOG_MNG_CURRENT_LOG_FILE_NAME                       L"current_log.log"
#define LOG_MNG_CURRENT_LOG_FILE_DRC                        L"\\log\\current\\log\\"
#define LOG_MNG_CURRENT_LOG_TREE_DRC                        CONTROL_FOLDER_DRC LOG_MNG_CURRENT_LOG_FILE_DRC

#define LOG_MNG_LOG_FILE_NAME                               L"log.log"
#define LOG_MNG_LOG_FILE_DRC                                L"\\log\\"
#define LOG_MNG_LOG_TREE_DRC                                CONTROL_FOLDER_DRC LOG_MNG_LOG_FILE_DRC

#define CPP_MQH_VARIABLE_DATA_TYPE                          std::wstring
#define CPP_MQH_VARIABLE_WRITE_DATA                         const wchar_t*

#define LOG_FILE_BEGIN_VALUE_COLON                          L":"
#define LOG_FILE_MAX_BYTE_SIZE                              5242880

#endif

#endif


#define CUSTOM_ERROR_CODE_NONE_ONLY_EA                       1
#define CUSTOM_ERROR_CODE_NONE_DLL_EXIST                     2
#define CUSTOM_ERROR_CODE_NONE_TRADW_ALLOWED                 3
#define CUSTOM_ERROR_CODE_FAILED_LANGUAGE_SETING             4
#define CUSTOM_ERROR_CODE_INPUT_FAILED_STRING_NONE_NUMBER    5
#define CUSTOM_ERROR_CODE_INPUT_FAILED_STRING_LENGTH         6
#define CUSTOM_ERROR_CODE_INPUT_FAILED_MAX_TRADE             7
#define CUSTOM_ERROR_CODE_INPUT_FAILED_WAIT_TIME             8
#define CUSTOM_ERROR_CODE_INPUT_FAILED_INDICATOR_VALUE       9
#define CUSTOM_ERROR_CODE_INPUT_FAILED_PERCENTAGE_VALUE      10
#define CUSTOM_ERROR_CODE_INPUT_FAILED_FIXID_VALUE           11
#define CUSTOM_ERROR_CODE_INPUT_FAILED_COMMISION_USD_VALUE   12
#define CUSTOM_ERROR_CODE_INPUT_FAILED_GMT_VALUE             13
#define CUSTOM_ERROR_CODE_ONTIMRE_NOT_SUCCEDDED              14
#define CUSTOM_ERROR_CODE_INPUT_TIME_VALUE_FAILED            15
#define CUSTOM_ERROR_CODE_NONE_APP_EXIST                     16
#define CUSTOM_ERROR_CODE_NONE_WATCH_WINDOW                  17
#define CUSTOM_ERROR_CODE_FAILED_SL_FILE_SIZE                18
#define CUSTOM_ERROR_CODE_FRAUD_SL_FILE                      19
#define CUSTOM_ERROR_CODE_FAILED_CREATE_ERROR_LOG            20
#define CUSTOM_ERROR_CODE_FAILED_OPEN_ERROR_LOG              21
#define CUSTOM_ERROR_CODE_FAILED_CREATE_CURRENT_LOG          22
#define CUSTOM_ERROR_CODE_FAILED_OPEN_CURRENT_LOG            23
#define CUSTOM_ERROR_CODE_FAILED_WRITE_ERROR_LOG             24
#define CUSTOM_ERROR_CODE_FAILED_WRITE_CURRENT_LOG           25
#define CUSTOM_ERROR_CODE_INPUT_TIME_SET_OR_UNSET_FAILED     26
#define CUSTOM_ERROR_CODE_INPUT_TIME_DATE_CHANGE_TIME_FAILED 27
#define CUSTOM_ERROR_CODE_ERROR_LOG_DELETED                  28
#define CUSTOM_ERROR_CODE_CURRENT_LOG_DELETED                29
#define CUSTOM_ERROR_CODE_FAILED_APP_BOOT                    30
#define CUSTOM_ERROR_CODE_FAILED_SL_FILE_CREATE              31
#define CUSTOM_ERROR_CODE_FAILED_SL_FILE_OPEN                32
#define CUSTOM_ERROR_CODE_FAILED_SL_FILE_ACCESS              33
#define CUSTOM_ERROR_CODE_NONE_ERROR_NUM_FILE                34
#define CUSTOM_ERROR_CODE_NONE_MT5_LANGUAGE_FILE             35
#define CUSTOM_ERROR_CODE_NONE_VISIBLE_ERROR_NUM_FILE        36
#define CUSTOM_ERROR_CODE_UNKNOWN_ERROR                      37
#define CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE                    38
#define CUSTOM_ERROR_CODE_FAILED_GET_DAY_LOG_DRC             39
#define CUSTOM_ERROR_CODE_FAILED_GET_LOCAL_APP_DRC           40
#define CUSTOM_ERROR_CODE_FAILED_CREATE_LOG_DRC              41
#define CUSTOM_ERROR_CODE_FAILED_OPEN_FILE                   42
#define CUSTOM_ERROR_CODE_FAILED_READ_FILE_BYTE_SIZE         43
#define CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE        44
#define CUSTOM_ERROR_CODE_FAILED_FILE_LOCK                   45
#define CUSTOM_ERROR_CODE_FAILED_FILE_UNLOCK                 46
#define CUSTOM_ERROR_CODE_FAILED_LOG_NONE_GET_UNKNOWN_TIME   47

#define CUSTOM_ERROR_CODE_MAX_VALUE                          (48+ERR_USER_ERROR_FIRST)

#define CALC_CUSTOM_ERROR_CODE(custom_error)                 (custom_error+ERR_USER_ERROR_FIRST)

#define TIME_SCALE_PREMISE_YEAR                              1900
#define TIME_SCALE_MOON_RETOUCH_VALUE                        1
#define TIME_TO_STRING_BUF_SIZE                              32

#define FILE_LOCK_MASK_LOW(data)                             ((uint)(data & 0xFFFFFFFF))
#define FILE_LOCK_MASK_HIGH(data)                            ((uint)(data >> 32))
#define MAX_FILE_SIZE                                        4000000000ULL


enum MT5_LANGUAGE_NUMBER
{
	EN,
	JP,
	OTHERS
};

class FILE_MANAGER {

private:

#ifdef COMPILER_FOO_MQH5 
#define FILE_SIZE_FIXID_VALUE true
#elif defined(COMPILER_FOO_CPP_ERR_MS_EXE)
#define FILE_SIZE_FIXID_VALUE true
#elif defined(COMPILER_FOO_CPP_LOG_MNG_EXE)
#define FILE_SIZE_FIXID_VALUE false
#endif 
	
	static const bool File_Size_Fixid = FILE_SIZE_FIXID_VALUE;


	static ulong Get_QuadPart_Cpp_Mqh(const CPP_MQH_LARGE& source) {

#ifdef COMPILER_FOO_MQH5

		return source;
#endif

#ifdef COMPILER_FOO_CPP

		return source.QuadPart;
#endif
	}

	static ulong Get_Data_Type_Size(const CPP_MQH_VARIABLE_DATA_TYPE& data_type) {

#ifdef COMPILER_FOO_CPP_LOG_MNG_EXE

		return (ulong)(data_type.size() * sizeof(wchar_t));

#else 

		return (ulong)sizeof(data_type);
#endif
	}

	static CPP_MQH_VARIABLE_WRITE_DATA Get_Data_Pointer(const CPP_MQH_VARIABLE_DATA_TYPE& data_type) {

#ifdef COMPILER_FOO_CPP_LOG_MNG_EXE

		return data_type.data();

#else 

		return data_type;
#endif
	}
	
	static ulong File_Initialization(const HANDLE& handle,const CPP_MQH_VARIABLE_DATA_TYPE file_data) {

		CPP_MQH_LARGE Move_P = {};


		if (!SetFilePointerEx(handle, Move_P, NULL, FILE_BEGIN)) {

			return GetLastError();
		}

		else {

			ulong Byte_Size = Get_Data_Type_Size(file_data);
			CPP_MQH_LPDWORD Write_Size = 0;

			if (!WriteFile(handle, Get_Data_Pointer(file_data), Byte_Size, CPP_MQH_GO_WORD(Write_Size), NULL)) {

				if (GetLastError() == ERROR_IO_PENDING) {

					return ERROR_SUCCESS;
				}

				else {

					return GetLastError();
				}
			}

			else {

				return ERROR_SUCCESS;
			}
		}
	}

public:

	static ulong Open_File(HANDLE& file_handle, const string file_name,const CPP_MQH_VARIABLE_DATA_TYPE& begin_value, CPP_MQH_LARGE& result_file_size) {

		ResetLastError();

		file_handle = CreateFileW(

			file_name,
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ,
			NULL,
			OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);

		if (file_handle == INVALID_HANDLE_VALUE) {

			return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_OPEN_FILE);
		}
		

		else {

			if (GetLastError() == ERROR_SUCCESS) {

				ulong Error_Code = File_Initialization(file_handle, begin_value);

				if (Error_Code != ERROR_SUCCESS) {

					CloseHandle(file_handle);

					return Error_Code;
				}
			}

			if (!GetFileSizeEx(file_handle, CPP_MQH_PLARGE(result_file_size))) {

				CloseHandle(file_handle);

				return GetLastError();
			}

			else {

				return ERROR_SUCCESS;
			}
		}
	}

	static ulong Check_File_Size(const HANDLE& file_handle, const ulong& byte_size,const CPP_MQH_LARGE& file_size) {


			CPP_MQH_LONG To_Size = Get_QuadPart_Cpp_Mqh(file_size);

			if (To_Size > MAX_FILE_SIZE) {

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE);
			}

			else if (To_Size > byte_size) {

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE);
			}

			else if (File_Size_Fixid && byte_size != To_Size) {

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE);
			}

			else {

				return ERROR_SUCCESS;
			}
	}

	static ulong Lock_File(const HANDLE& file_handle,const ulong& file_size) {

		OVERLAPPED Ov_R = {};

		uint LockLow = FILE_LOCK_MASK_LOW(file_size);
		uint LockHigh = FILE_LOCK_MASK_HIGH(file_size);

		if (!LockFileEx(file_handle, LOCKFILE_EXCLUSIVE_LOCK, 0, LockLow, LockHigh, &Ov_R)) {

			return CUSTOM_ERROR_CODE_FAILED_FILE_LOCK;
		}

		else {

			return ERROR_SUCCESS;
		}
	}

	static ulong Reset_File_Pointer(const HANDLE& file_handle) {

		ResetLastError();

		CPP_MQH_LARGE Move_P = {};

		if (!SetFilePointerEx(file_handle, Move_P, NULL, FILE_BEGIN)) {

			return GetLastError();
		}

		else {

			return ERROR_SUCCESS;
		}
	}

	static ulong Read_File(const HANDLE& file_handle,const uint& byte_size,ulong& result) {

		CPP_MQH_LPDWORD Read_Size = 0;

		if (!ReadFile(file_handle, &result, byte_size, CPP_MQH_GO_WORD(Read_Size), NULL)) {

				return GetLastError();
		}

		else {

			if (Read_Size != byte_size) {

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_READ_FILE_BYTE_SIZE);
			}

			else {

				return ERROR_SUCCESS;
			}
		}
	}

	static ulong Write_File(const HANDLE& file_handle, const CPP_MQH_VARIABLE_DATA_TYPE file_data) {


		ulong Byte_Size = Get_Data_Type_Size(file_data);
		CPP_MQH_LPDWORD Write_Size = 0;

		if (!WriteFile(file_handle, Get_Data_Pointer(file_data), Byte_Size, CPP_MQH_GO_WORD(Write_Size), NULL)) {

			return GetLastError();
		}

		else {

			if (Write_Size != Byte_Size) {

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE);
			}

			return ERROR_SUCCESS;
		}
	}

	static ulong Close_File(const HANDLE& file_handle,const ulong& byte_size) {

		OVERLAPPED Ov_R = {};
		uint LockLow = FILE_LOCK_MASK_LOW(byte_size);
		uint LockHigh = FILE_LOCK_MASK_HIGH(byte_size);

		if (!UnlockFileEx(file_handle, 0, LockLow, LockHigh, &Ov_R)) {

			CloseHandle(file_handle);

			return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_FILE_UNLOCK);
		}

		else {

			CloseHandle(file_handle);

			return ERROR_SUCCESS;
		}
	}
};


#endif