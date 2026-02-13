///////////////////////////////////////////////////////////
//                                                       //
// このヘッダーファイルはmqhファイル側では変更しない     //
// .hと.mqhtとして両方、生成するcmakeが作成されるため    //
//                                                       //
///////////////////////////////////////////////////////////

namespace COMMON_DEFINE {

#ifndef CONTROL_H_PUBLIC_HEADER

#define CONTROL_H_PUBLIC_HEADER

#define CONTROL_SYSTEM_VERSION 260.211

	enum Error_Code {

		CUSTOM_ERROR_CODE_NONE_ONLY_EA = 1,                   //1
		CUSTOM_ERROR_CODE_NONE_DLL_EXIST,                     //2
		CUSTOM_ERROR_CODE_NONE_TRADW_ALLOWED,                 //3
		CUSTOM_ERROR_CODE_FAILED_LANGUAGE_SETING,             //4
		CUSTOM_ERROR_CODE_INPUT_FAILED_STRING_NONE_NUMBER,    //5
		CUSTOM_ERROR_CODE_INPUT_FAILED_STRING_LENGTH,         //6
		CUSTOM_ERROR_CODE_INPUT_FAILED_MAX_TRADE,             //7
		CUSTOM_ERROR_CODE_INPUT_FAILED_WAIT_TIME,             //8
		CUSTOM_ERROR_CODE_INPUT_FAILED_INDICATOR_VALUE,       //9
		CUSTOM_ERROR_CODE_INPUT_FAILED_PERCENTAGE_VALUE,      //10
		CUSTOM_ERROR_CODE_INPUT_FAILED_FIXID_VALUE,           //11
		CUSTOM_ERROR_CODE_INPUT_FAILED_COMMISION_USD_VALUE,   //12
		CUSTOM_ERROR_CODE_INPUT_FAILED_GMT_VALUE,             //13
		CUSTOM_ERROR_CODE_ONTIMRE_NOT_SUCCEDDED,              //14
		CUSTOM_ERROR_CODE_INPUT_TIME_VALUE_FAILED,            //15
		CUSTOM_ERROR_CODE_NONE_APP_EXIST,                     //16
		CUSTOM_ERROR_CODE_NONE_WATCH_WINDOW,                  //17
		CUSTOM_ERROR_CODE_FRAUD_SL_FILE,                      //18
		CUSTOM_ERROR_CODE_FAILED_CREATE_LOG,                  //19
		CUSTOM_ERROR_CODE_FAILED_OPEN_LOG,                    //20
		CUSTOM_ERROR_CODE_FAILED_WRITE_LOG,                   //21
		CUSTOM_ERROR_CODE_INPUT_TIME_SET_OR_UNSET_FAILED,     //22
		CUSTOM_ERROR_CODE_INPUT_TIME_DATE_CHANGE_TIME_FAILED, //23
		CUSTOM_ERROR_CODE_LOG_DELETED,                        //24
		CUSTOM_ERROR_CODE_FAILED_APP_BOOT,                    //25
		CUSTOM_ERROR_CODE_FAILED_SL_FILE_CREATE,              //26
		CUSTOM_ERROR_CODE_FAILED_SL_FILE_OPEN,                //27
		CUSTOM_ERROR_CODE_FAILED_SL_FILE_ACCESS,              //28
		CUSTOM_ERROR_CODE_NONE_ERROR_NUM_FILE,                //29
		CUSTOM_ERROR_CODE_NONE_MT5_LANGUAGE_FILE,             //30
		CUSTOM_ERROR_CODE_NONE_VISIBLE_ERROR_NUM_FILE,        //31
		CUSTOM_ERROR_CODE_UNKNOWN_ERROR,                      //32
		CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE,                    //33
		CUSTOM_ERROR_CODE_FAILED_GET_DRC,                     //34
		CUSTOM_ERROR_CODE_FAILED_GET_LOCAL_APP_DRC,           //35
		CUSTOM_ERROR_CODE_FAILED_OPEN_FILE,                   //36
		CUSTOM_ERROR_CODE_FAILED_READ_FILE_BYTE_SIZE,         //37
		CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE,        //38
		CUSTOM_ERROR_CODE_FAILED_FILE_LOCK,                   //39
		CUSTOM_ERROR_CODE_FAILED_FILE_UNLOCK,                 //40
		CUSTOM_ERROR_CODE_FAILED_LOG_NONE_GET_UNKNOWN_TIME,   //41
		CUSTOM_ERROR_CODE_FAILED_CORRECT_ALIGNMENT,           //42
		CUSTOM_ERROR_CODE_FAILED_UNAVAILABLE_HANDLE_VALUE,    //43
		CUSTOM_ERROR_CODE_FAILED_ROOT_DRC,                    //44
		CUSTOM_ERROR_CODE_FAILED_FILE_LOCK_ONE,               //45
		CUSTOM_ERROR_CODE_FAILED_GET_FILE_TIME,               //46
		CUSTOM_ERROR_CODE_FAILED_FILE_WRITE_FLASH,            //47
		CUSTOM_ERROR_CODE_FRAUD_COMMAND_LINE_VALUE,           //48
		CUSTOM_ERROR_CODE_FRAUD_CALL_NEW_PROCCESS,            //49
		CUSTOM_ERROR_CODE_FAILED_GET_ERROR_CODE_VALUE,        //50
		CUSTOM_ERROR_CODE_FRAUD_ERROR_CODE,                   //51
		CUSTOM_ERROR_CODE_FAILED_LOG_DRC_TOTAL_BYTE_SIZE,     //52
		CUSTOM_ERROR_CODE_FAILED_RUN_LOG_DELETED,             //53
		CUSTOM_ERROR_CODE_FAILED_OBJECT,                      //54
		CUSTOM_ERROR_CODE_FAILED_FILE_INIT,                   //55
		CUSTOM_ERROR_CODE_FAILED_FILE_WRITE,                  //56
		CUSTOM_ERROR_CODE_FAILED_GET_FILE_SIZE,               //57
		CUSTOM_ERROR_CODE_FAILED_FILE_POINTER_SET,            //58
		CUSTOM_ERROR_CODE_FAILED_FILE_READ,                   //59
		CUSTOM_ERROR_CODE_MAX_VALUE                           //60
	};



	///////////////////////////////////////////////////////////
	//
	// MQL5用の記述
	//

#ifdef COMPILER_FOO_MQH5

#include                                                    "C:\\Users\\okita\\AppData\\Roaming\\MetaQuotes\\Terminal\\ED051E4A9BEE8A33BDDD0F947358B2B2\\MQL5\\Experts\\CONTROL\\PCH.mqh"



#define BOOL                                                int
#define FALSE                                               0
#define DWORD                                               uint

#define CPP_MQH_LARGE                                       long
#define CPP_MQH_SECURITY_ATTRIBUTES                         PVOID
#define CPP_MQH_WCHAR_T                                     string

#define CPP_MQH_ADDRESS_OF(obj)                             obj
#define CPP_MQH_ADDRESS_NULL(obj)                           obj

#define FIND_ERROR_COUNT                                    5
#define FIND_VIS_COUNT                                      5
#define FIND_LANG_COUNT                                     3

#define GetWin32LastError()                                 RtlGetLastWin32Error()


	const string CONTROL_FOLDER_DRC = "\\ReturnSafety\\CONTROL";

	const string ERR_MS_ERR_NUM_FILE_NAME = "\\err.bin";
	const string ERR_MS_ERR_NUM_FILE_DRC = "\\err_ms\\files\\err";

	const string ERR_MS_VISIBLE_ERR_NUM_FILE_NAME = "\\vis.bin";
	const string ERR_MS_VISIBLE_ERR_NUM_FILE_DRC = "\\err_ms\\files\\vis";

	const string MT5_LANGUAGE_NUM_FILE_NAME = "\\lang.bin";
	const string MT5_LANGUAGE_NUM_FILE_DRC = "\\lang";

	const string FIND_ROOT_STRING_ERROR[FIND_ERROR_COUNT] = {

		"\\ReturnSafety",
		"\\CONTROL",
		"\\err_ms",
		"\\files",
		"\\err"
	};

	const string FIND_ROOT_STRING_VIS[FIND_VIS_COUNT] = {

		"\\ReturnSafety",
		"\\CONTROL",
		"\\err_ms",
		"\\files",
		"\\vis"
	};

	const string FIND_ROOT_STRING_LANG[FIND_LANG_COUNT] = {

		"\\ReturnSafety",
		"\\CONTROL",
		"\\lang"
	};

	const string ERR_MS_WINDOW_TITLE = "CONTROL system error";

	const string ERR_MS_WINDOW_CLASS = "#32770";

	const string NULL_STRING = "";
	const string SPACE_STRING = " ";
	const string COLON_STRING = ":";
	const string LINE_BREAK = "\n";
	const string BACK_SLASH_STRING = "\\";
	const string COMMAND_LINE_ESCAPE = "\"";

	const int INVALID_HANDLE_VALUE = -1;

	const uint GENERIC_READ = (uint)0x80000000;
	const uint GENERIC_WRITE = 0x40000000;
	const uint OPEN_ALWAYS = 4;
	const uint FILE_ATTRIBUTE_NORMAL = 0x00000080;
	const uint FILE_BEGIN = 0;
	const uint CPP_MQH_FILE_SHARE_READ = 0x00000001;

	const uint LOCKFILE_EXCLUSIVE_LOCK = 0x00000002;
	const uint ERROR_FILE_NOT_FOUND = 2;
	const uint ERROR_ALREADY_EXISTS = 183;

	const uint ERROR_SUCCESS = 0;
	const uint ERROR_IO_PENDING = 997L;

	const uint DETACHED_PROCESS = 0x00000008;
	const uint HIGH_PRIORITY_CLASS = 0x00000080;

#endif


///////////////////////////////////////////////////////////
//
// c++用の記述
//

#ifdef COMPILER_FOO_CPP

#define CPP_MQH_ADDRESS_OF(obj)                             &(obj)
#define CPP_MQH_ADDRESS_NULL(obj)                           NULL

#define GetWin32LastError()                                 GetLastError()

	using ulong = unsigned __int64;
	using string = std::wstring;
	using ushort = unsigned short;
	using uint = unsigned int;

	using CPP_MQH_LARGE = LARGE_INTEGER;
	using CPP_MQH_SECURITY_ATTRIBUTES = SECURITY_ATTRIBUTES;
	using CPP_MQH_WCHAR_T = wchar_t*;

	using FIND_DATAW = WIN32_FIND_DATAW;

	const uint MAX_LOAD_STRING = 256;

	const uint FIND_ERROR_COUNT = 5;
	const uint FIND_VIS_COUNT = 5;
	const uint FIND_LANG_COUNT = 3;



	const std::wstring CONTROL_FOLDER_DRC = L"\\ReturnSafety\\CONTROL";

	const std::wstring ERR_MS_ERR_NUM_FILE_NAME = L"\\err.bin";
	const std::wstring ERR_MS_ERR_NUM_FILE_DRC = L"\\err_ms\\files\\err";

	const std::wstring ERR_MS_VISIBLE_ERR_NUM_FILE_NAME = L"\\vis.bin";
	const std::wstring ERR_MS_VISIBLE_ERR_NUM_FILE_DRC = L"\\err_ms\\files\\vis";

	const std::wstring MT5_LANGUAGE_NUM_FILE_NAME = L"\\lang.bin";
	const std::wstring MT5_LANGUAGE_NUM_FILE_DRC = L"\\lang";

	const std::wstring Error_Ms_Exe_Drc = L"C:\\Users\\okita\\source\\repos\\err_ms\\x64\\Debug\\err_ms.exe";
	const std::wstring Log_Mng_Exe_Drc = L"C:\\Users\\okita\\source\\repos\\log_mng\\x64\\Debug\\log_mng.exe";

	const std::wstring FIND_ROOT_STRING_ERROR[FIND_ERROR_COUNT] = {

		L"\\ReturnSafety",
		L"\\CONTROL",
		L"\\err_ms",
		L"\\files",
		L"\\err"
	};

	const std::wstring FIND_ROOT_STRING_VIS[FIND_VIS_COUNT] = {

		L"\\ReturnSafety",
		L"\\CONTROL",
		L"\\err_ms",
		L"\\files",
		L"\\vis"
	};

	const std::wstring FIND_ROOT_STRING_LANG[FIND_LANG_COUNT] = {

		L"\\ReturnSafety",
		L"\\CONTROL",
		L"\\lang"
	};

	const std::wstring ERR_MS_WINDOW_TITLE = L"CONTROL system error";

	const std::wstring ERR_MS_WINDOW_CLASS = L"#32770";

	const std::wstring NULL_STRING = L"";
	const std::wstring LINE_BREAK = L"\n";
	const std::wstring SPACE_STRING = L" ";
	const std::wstring COLON_STRING = L":";
	const std::wstring BACK_SLASH_STRING = L"\\";
	const std::wstring COMMAND_LINE_ESCAPE = L"\"";

	const std::wstring MUTEX_GLOBAL_NAME_LOG_PROCESS = L"Global\\ReturnSafety_CONTROL_Log_Mutex";
	const std::wstring MUTEX_GLOBAL_NAME_ERROR_PROCESS = L"Global\\ReturnSafety_CONTROL_Error_Mutex";

	const uint ERR_USER_ERROR_FIRST = 65536;

	const uint GET_MUTEX_TRIAL_MAX_COUNT = 10;
	const uint GET_MUTEX_TRIAL_SLEEP_MILLI_SEC = 100;
	const uint GET_MUTEX_WAIT_LOCK_MILLI_SEC = 20;

	const uint CPP_MQH_FILE_SHARE_READ = FILE_SHARE_READ;

#endif

	inline ulong CALC_CUSTOM_ERROR_CODE(ulong custom_err) {

		return custom_err + ERR_USER_ERROR_FIRST;
	}

#ifdef COMPILER_FOO_CPP

	

	bool StringAdd(string& string_var, string  add_substring) {

		string_var.append(add_substring);

		return true;
	}


	static unsigned __int64 Get_Local_App_Drc(std::wstring& result) {

		PWSTR path = nullptr;

		if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &path))) {

			result = path;
			CoTaskMemFree(path);

			return ERROR_SUCCESS;
		}

		else {

			return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_LOCAL_APP_DRC);
		}
	}


	static ulong Select_Error_Code(const ulong& error_code, const ulong& visible_error) {

		if (error_code == ERROR_SUCCESS) {

			return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FRAUD_ERROR_CODE);
		}

		else {

			if (visible_error == ERROR_SUCCESS) {

				return error_code;
			}

			else {

				return visible_error;
			}
		}
	}
	

#endif

	const uint TIME_SCALE_PREMISE_YEAR = 1900;
	const uint TIME_SCALE_MOON_RETOUCH_VALUE = 1;

	const uint SLEEP_MILLI_SECOND_VALUE = 10;
	const uint TRY_FILE_LOCK_COUNTER = 10;

	const uint COMMAND_LINE_ASSIGNMENT_NUMBER_EXE_APP_NAME = 0;
	const uint COMMAND_LINE_ASSIGNMENT_NUMBER_CALL_APP_NAME = 1;
	const uint COMMAND_LINE_ASSIGNMENT_NUMBER_FILE_NAME = 2;
	const uint COMMAND_LINE_ASSIGNMENT_NUMBER_VERSION = 3;
	const uint COMMAND_LINE_ASSIGNMENT_NUMBER_LINE_NUMBER = 4;

	const uint COMMAND_LINE_ASSIGNMENT_NUMBER_TOTAL = 5;

	const ulong MT5_LANGUAGE_NUM_FILE_SIZE = sizeof(ulong);
	const ulong ERR_MS_ERR_NUM_FILE_SIZE = sizeof(ulong);
	const ulong ERR_MS_VISIBLE_ERR_NUM_FILE_SIZE = sizeof(ulong);



	enum MT5_LANGUAGE_NUMBER
	{
		EN,
		JP,
		OTHERS
	};

	
	class PROCESS_DATA {

	public:

		struct creation_flags {

			struct Log_Mng {

				uint32_t Detached_Process;
				uint32_t High_Priority;
			};

			Log_Mng Log;

			struct Error_Ms {

				uint32_t Detached_Process;
				uint32_t High_Priority;
			};

			Error_Ms Error;
		};

		creation_flags Creation_Flags;

		PROCESS_DATA() {

			Creation_Flags.Error.Detached_Process = DETACHED_PROCESS;
			Creation_Flags.Error.High_Priority = HIGH_PRIORITY_CLASS;

			Creation_Flags.Log.Detached_Process = DETACHED_PROCESS;
			Creation_Flags.Log.High_Priority = HIGH_PRIORITY_CLASS;
		}
	};


	class PROCESS_MANAGER {

	private:

#ifdef COMPILER_FOO_CPP

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

		static ulong Get_Command_Line(std::vector<wchar_t> result[COMMAND_LINE_ASSIGNMENT_NUMBER_TOTAL]) {


			LPWSTR Full_Cmd_Line = GetCommandLineW();

			int Argc;
			LPWSTR* Argv = CommandLineToArgvW(Full_Cmd_Line, &Argc);

			if (Argv != NULL && Argc == COMMAND_LINE_ASSIGNMENT_NUMBER_TOTAL) {

				for (size_t i = 0; i < Argc; i++) {

					size_t len = wcsnlen_s(Argv[i], MAX_LOAD_STRING);

					result[i].assign(Argv[i], Argv[i] + len + 1);
				}

				LocalFree(Argv);

				return ERROR_SUCCESS;
			}

			else {

				if (Argv != NULL) {

					LocalFree(Argv);
				}

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FRAUD_COMMAND_LINE_VALUE);
			}
		}

		

#endif

		static string Get_Command_Line_Norm(const string& source) {

			string result = COMMAND_LINE_ESCAPE;

			StringAdd(result, source);
			StringAdd(result, COMMAND_LINE_ESCAPE);

			return result;
		}

	public:

#ifdef COMPILER_FOO_CPP

		static std::wstring To_Command_Line_String(const std::vector<wchar_t> data[COMMAND_LINE_ASSIGNMENT_NUMBER_TOTAL]) {

			std::wstring result;

			result = NULL_STRING;

			result.append(L"program name ");
			result.append(data[COMMAND_LINE_ASSIGNMENT_NUMBER_CALL_APP_NAME].data());
			result.append(SPACE_STRING);

			result.append(L"file name ");
			result.append(data[COMMAND_LINE_ASSIGNMENT_NUMBER_FILE_NAME].data());
			result.append(SPACE_STRING);

			result.append(L"version ");
			result.append(data[COMMAND_LINE_ASSIGNMENT_NUMBER_VERSION].data());
			result.append(SPACE_STRING);

			result.append(L"line number ");
			result.append(data[COMMAND_LINE_ASSIGNMENT_NUMBER_LINE_NUMBER].data());
			result.append(SPACE_STRING);

			return result;
		}

		static ulong To_Command_Line_Message(std::wstring& result) {

			std::vector<wchar_t> Buf[COMMAND_LINE_ASSIGNMENT_NUMBER_TOTAL];

			ulong Error_Code = Get_Command_Line(Buf);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			result = To_Command_Line_String(Buf);

			return ERROR_SUCCESS;
		}

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

#endif

		static ulong Create_Proccess(

			const CPP_MQH_WCHAR_T app_name,
			CPP_MQH_WCHAR_T       command_line,
			const uint32_t& creation_flags,
			const CPP_MQH_WCHAR_T current_directory) {

			CPP_MQH_SECURITY_ATTRIBUTES Proccess = {}, Thread = {};
			PVOID Environment = {};


			STARTUPINFOW Startup_Info = {};
			PROCESS_INFORMATION Process_Information = {};

			Startup_Info.cb = sizeof(Startup_Info);

			if (CreateProcessW(

				app_name,
				command_line,
				CPP_MQH_ADDRESS_NULL(Proccess),
				CPP_MQH_ADDRESS_NULL(Thread),
				FALSE,
				creation_flags,
				CPP_MQH_ADDRESS_NULL(Environment),
				current_directory,
				CPP_MQH_ADDRESS_OF(Startup_Info),
				CPP_MQH_ADDRESS_OF(Process_Information))) {

				CloseHandle(Process_Information.hProcess);
				CloseHandle(Process_Information.hThread);

				return ERROR_SUCCESS;
			}

			else {

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FRAUD_CALL_NEW_PROCCESS);
			}
		}

		static ulong Proccess_Boot_File_Exist(const CPP_MQH_WCHAR_T drc) {

			FIND_DATAW Data = {};
			HANDLE Handle = FindFirstFileW(drc, CPP_MQH_ADDRESS_OF(Data));

			if (Handle == INVALID_HANDLE_VALUE) {

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_NONE_APP_EXIST);
			}

			else {

				FindClose(Handle);

				return ERROR_SUCCESS;
			}
		}

		static string Create_Command_Line(const string& exe_app,const string& call_app,const string& file_name,const string& version,const string& line_num) {

			string result = NULL_STRING;

			StringAdd(result,Get_Command_Line_Norm(exe_app));
			StringAdd(result, SPACE_STRING);

			StringAdd(result, Get_Command_Line_Norm(call_app));
			StringAdd(result, SPACE_STRING);

			StringAdd(result, Get_Command_Line_Norm(file_name));
			StringAdd(result, SPACE_STRING);

			StringAdd(result, Get_Command_Line_Norm(version));
			StringAdd(result, SPACE_STRING);

			StringAdd(result, Get_Command_Line_Norm(line_num));

			return result;
		}
	};



	class FILE_MANAGER_BASE {

	protected:


		union DATA_TYPE_MEMORY_MAP {

			ulong Mqh_Value;
			ulong Cpp_Value;
			ushort Data_To_Binary[sizeof(ulong) / sizeof(ushort)];

			DATA_TYPE_MEMORY_MAP() { Mqh_Value = 0; }
		};


		DATA_TYPE_MEMORY_MAP Data;

		struct FILE_LOCK_VALUE {

			bool Now_File_Lock;

			FILE_LOCK_VALUE() { Now_File_Lock = false; };
		};

		FILE_LOCK_VALUE Lock_value;


		void Now_File_Lock_Initialization() {

			Lock_value.Now_File_Lock = false;
		}

		bool Get_Now_File_Lock() {

			return Lock_value.Now_File_Lock;
		}

		void Set_Now_File_Lock(const bool& value) {

			Lock_value.Now_File_Lock = value;
		}

		ulong File_Lock_Only_1(ulong& line_num) {

			if (Get_Now_File_Lock()) {

				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_FILE_LOCK_ONE);
			}

			else {

				return ERROR_SUCCESS;
			}
		}

		inline ulong File_Write_Flash(const HANDLE& file_handle,ulong& line_num,ulong& sys_error) {

			if (!FlushFileBuffers(file_handle)) {

				sys_error = GetWin32LastError();
				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_FILE_WRITE_FLASH);
			}

			return ERROR_SUCCESS;
		}

		virtual inline ulong Get_Local_App_Data(string& result,ulong& line_num) {

			return 0;
		}

		virtual inline ulong Get_QuadPart_Cpp_Mqh(const CPP_MQH_LARGE& source) {

			return 0;
		}

		inline ulong File_Initialization(const HANDLE& handle,ulong& line_num,ulong& sys_error) {

			CPP_MQH_LARGE Move_P = {}, Result_P = {};

			if (!SetFilePointerEx(handle, Move_P, CPP_MQH_ADDRESS_NULL(Result_P), FILE_BEGIN)) {

				sys_error = GetWin32LastError();
				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_FILE_INIT);
			}

			else {

				Data.Cpp_Value = 0;

				SetLastError(ERROR_SUCCESS);

				DWORD Write_Size = 0;

				ulong Error_Code = File_Write(handle,line_num,sys_error);

				if (Error_Code != ERROR_SUCCESS) {

					return Error_Code;
				}

				else {

					Error_Code = File_Write_Flash(handle,line_num,sys_error);

					if (Error_Code != ERROR_SUCCESS) {

						return Error_Code;
					}

					return ERROR_SUCCESS;
				}
			}
		}

		inline uint32_t FILE_LOCK_MASK_LOW(const ulong& file_data) {

			return (uint32_t)(file_data & 0xFFFFFFFF);
		}

		inline uint32_t FILE_LOCK_MASK_HIGH(const ulong& file_data) {

			return (uint32_t)(file_data >> 32);
		}

		virtual inline ulong File_Read(const HANDLE& file_handle, ulong& line_num, ulong& sys_error) {

			return 0;
		}

		virtual inline ulong File_Write(const HANDLE& file_handle, ulong& line_num, ulong& sys_error) {

			return 0;
		}

		virtual inline HANDLE Create_File(const string& file_name) {

			return 0;
		}

		inline ulong Get_File_Last_Write_Time(const HANDLE& file_handle, ulong& result,ulong& line_num,ulong& sys_error) {

			FILETIME Create = {}, Access = {}, Write = {};

			if (!GetFileTime(file_handle, CPP_MQH_ADDRESS_NULL(Create), CPP_MQH_ADDRESS_NULL(Access), CPP_MQH_ADDRESS_OF(Write))) {

				sys_error = GetWin32LastError();
				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_FILE_TIME);
			}

			result = ((ulong)Write.dwHighDateTime << 32) | Write.dwLowDateTime;

			return ERROR_SUCCESS;
		}

		inline ulong Get_Full_Path(const string& control_drc, const string& file_drc, const string& file_name,string& result,ulong& line_num,ulong& sys_error) {

			ulong Error_Code = Get_Local_App_Data(result,line_num);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			else {

				if (!StringAdd(result, control_drc) ||
					!StringAdd(result, file_drc) ||
					!StringAdd(result, file_name)) {

					sys_error = GetLastError();
					line_num = __LINE__;

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_DRC);
				}

				else {

					return ERROR_SUCCESS;
				}
			}
		}

		inline ulong Open_File(HANDLE& file_handle, const string file_name, CPP_MQH_LARGE& result_file_size,ulong& line_num,ulong& sys_error) {

			SetLastError(ERROR_SUCCESS);

			file_handle = Create_File(file_name);

			if (file_handle == INVALID_HANDLE_VALUE) {

				sys_error = GetWin32LastError();
				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_OPEN_FILE);
			}


			else {


				if (GetWin32LastError() == ERROR_SUCCESS) {

					ulong Error_Code = File_Initialization(file_handle,line_num,sys_error);

					if (Error_Code != ERROR_SUCCESS) {

						CloseHandle(file_handle);

						return Error_Code;
					}
				}

				if (!GetFileSizeEx(file_handle, CPP_MQH_ADDRESS_OF(result_file_size))) {

					CloseHandle(file_handle);

					sys_error = GetWin32LastError();
					line_num = __LINE__;

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_FILE_SIZE);
				}

				else {

					Set_Now_File_Lock(true);

					return ERROR_SUCCESS;
				}
			}
		}

		inline ulong Check_File_Size(const HANDLE& file_handle, const ulong& byte_size, const CPP_MQH_LARGE& file_size,ulong& line_num) {


			ulong To_Size = Get_QuadPart_Cpp_Mqh(file_size);

			if (byte_size != To_Size) {

				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE);
			}

			else {

				return ERROR_SUCCESS;
			}
		};

		virtual inline ulong Get_Read_Data() {

			return 0;
		}

		inline ulong Unlock_File(const HANDLE& file_handle, const ulong& byte_size,ulong& line_num,ulong& sys_error) {

			OVERLAPPED Ov_R = {};
			uint LockLow = FILE_LOCK_MASK_LOW(byte_size);
			uint LockHigh = FILE_LOCK_MASK_HIGH(byte_size);

			if (!UnlockFileEx(file_handle, 0, LockLow, LockHigh, CPP_MQH_ADDRESS_OF(Ov_R))) {

				sys_error = GetWin32LastError();
				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_FILE_UNLOCK);
			}

			else {

				return ERROR_SUCCESS;
			}
		}

		inline ulong Lock_File(const HANDLE& file_handle, const ulong& file_size,ulong& line_num,ulong& sys_error) {

			OVERLAPPED Ov_R = {};

			uint LockLow = FILE_LOCK_MASK_LOW(file_size);
			uint LockHigh = FILE_LOCK_MASK_HIGH(file_size);

			if (!LockFileEx(file_handle, LOCKFILE_EXCLUSIVE_LOCK, 0, LockLow, LockHigh, CPP_MQH_ADDRESS_OF(Ov_R))) {

				sys_error = GetWin32LastError();
				line_num = __LINE__;

				return CUSTOM_ERROR_CODE_FAILED_FILE_LOCK;
			}

			else {

				return ERROR_SUCCESS;
			}
		}

		inline ulong Try_Lock_File(const HANDLE& file_handle, const ulong& file_size,ulong& line_num,ulong& sys_error) {

			ulong result = 0;

			for (uint i = 0; i < TRY_FILE_LOCK_COUNTER; i++) {

				result = Lock_File(file_handle, file_size,line_num,sys_error);

				if (result == ERROR_SUCCESS) {

					return ERROR_SUCCESS;
				}

				Sleep(SLEEP_MILLI_SECOND_VALUE);
			}

			return result;
		}

		inline ulong Reset_File_Pointer(const HANDLE& file_handle,ulong& line_num,ulong& sys_error) {

			SetLastError(ERROR_SUCCESS);

			CPP_MQH_LARGE Move_P = {}, result_P = {};

			if (!SetFilePointerEx(file_handle, Move_P, CPP_MQH_ADDRESS_NULL(result_P), FILE_BEGIN)) {

				sys_error = GetWin32LastError();
				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_FILE_POINTER_SET);
			}

			else {

				return ERROR_SUCCESS;
			}
		}

		virtual inline ulong Create_Folder(const string& folder_name, ulong& line_num, ulong& sys_error) {

			return 0;
		}

		virtual inline ulong Find_Drc(const string& drc_name, FIND_DATAW& result, ulong& line_num, ulong& sys_error) {

			return 0;
		}

		inline void Close_File(HANDLE& file_handle) {

			if (file_handle != INVALID_HANDLE_VALUE && file_handle != NULL) {

				CloseHandle(file_handle);

				file_handle = NULL;
			}
		}

	public:

		inline ulong Alignment_Checker() {

			if (sizeof(Data) != 8) {

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_CORRECT_ALIGNMENT);
			}
			else {

				return ERROR_SUCCESS;
			}
		}

		virtual inline void Set_Write_Data(const ulong data) {


		}
	};

#ifdef COMPILER_FOO_CPP

	class FILE_MANAGER_CROSS : public FILE_MANAGER_BASE {

	protected:

		virtual ulong Get_Local_App_Data(string& result,ulong& line_num) override {

			PWSTR path = nullptr;

			if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &path))) {

				result = path;
				CoTaskMemFree(path);

				return ERROR_SUCCESS;
			}

			else {

				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_LOCAL_APP_DRC);
			}
		}

		virtual inline ulong Create_Folder(const string& folder_name,ulong& line_num,ulong& sys_error) override {

			if (CreateDirectoryW(folder_name.c_str(), NULL) == 0) {

				sys_error = GetWin32LastError();
				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_ROOT_DRC);
			}

			else {

				return ERROR_SUCCESS;
			}
		}

		virtual inline HANDLE Create_File(const string& file_name) override {

			return CreateFileW(

				file_name.c_str(),
				GENERIC_READ | GENERIC_WRITE,
				FILE_SHARE_READ,
				NULL,
				OPEN_ALWAYS,
				FILE_ATTRIBUTE_NORMAL,
				NULL);
		}

		virtual inline ulong Get_QuadPart_Cpp_Mqh(const CPP_MQH_LARGE& source) override {

			return source.QuadPart;
		}

		virtual inline ulong File_Read(const HANDLE& file_handle,ulong& line_num,ulong& sys_error) override {

			SetLastError(ERROR_SUCCESS);

			DWORD Read_Size = 0;

			if (!ReadFile(file_handle, &Data.Cpp_Value, sizeof(Data.Cpp_Value), &Read_Size, NULL)) {

				if (GetWin32LastError() == ERROR_IO_PENDING) {

					return ERROR_SUCCESS;
				}

				else {

					sys_error = GetWin32LastError();
					line_num = __LINE__;

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_FILE_READ);
				}
			}

			else {

				if ((uint)Read_Size != sizeof(Data.Cpp_Value)) {

					line_num = __LINE__;

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE);
				}

				return ERROR_SUCCESS;
			}
		}

		virtual inline ulong File_Write(const HANDLE& file_handle,ulong& line_num,ulong& sys_error) override {

			SetLastError(ERROR_SUCCESS);

			DWORD Write_Size = 0;

			if (!WriteFile(file_handle, &Data.Cpp_Value, sizeof(Data.Cpp_Value), &Write_Size, NULL)) {

				if (GetWin32LastError() == ERROR_IO_PENDING) {

					return ERROR_SUCCESS;
				}

				else {

					sys_error = GetWin32LastError();
					line_num = __LINE__;

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_FILE_WRITE);
				}
			}

			else {

				if ((uint)Write_Size != sizeof(Data.Cpp_Value)) {

					line_num = __LINE__;

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE);
				}

				return ERROR_SUCCESS;
			}
		}

		virtual inline ulong Get_Read_Data() override {

			return Data.Cpp_Value;
		}

		virtual inline ulong Find_Drc(const string& drc_name, FIND_DATAW& result,ulong& line_num,ulong& sys_error) override {

			HANDLE Drc_Handle = FindFirstFileW(drc_name.c_str(), &result);

			if (Drc_Handle == INVALID_HANDLE_VALUE) {

				sys_error = GetWin32LastError();
				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_DRC);
			}

			else {

				FindClose(Drc_Handle);

				return ERROR_SUCCESS;
			}
		}

	public:

		virtual inline void Set_Write_Data(const ulong data) override {

			Data.Cpp_Value = data;
		}
	};

#endif

#ifdef COMPILER_FOO_MQH5


	class FILE_MANAGER_CROSS : public FILE_MANAGER_BASE {

	protected:

		virtual ulong Get_Local_App_Data(string& result, ulong& line_num) override {

			string Data_Path = TerminalInfoString(TERMINAL_DATA_PATH);

			int Result_Num = StringFind(Data_Path, "AppData", 0);

			if (Result_Num == -1) {

				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_LOCAL_APP_DATA);
			}

			else {

				result = StringSubstr(Data_Path, 0, Result_Num);

				if (result == NULL_STRING) {

					line_num = __LINE__;

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_LOCAL_APP_DATA);
				}

				else {
					
					string App_Data_Drc = "AppData\\Local\\";

					if (!StringAdd(result, App_Data_Drc)) {

						line_num = __LINE__;

						return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_LOCAL_APP_DATA);
					}

					else {

						return ERROR_SUCCESS;
					}
				}
			}
		}

		virtual inline ulong Create_Folder(const string& folder_name, ulong& line_num, ulong& sys_error) override {

			CPP_MQH_SECURITY_ATTRIBUTES Atr = {};

			if (CreateDirectoryW(folder_name, Atr) == 0) {

				sys_error = GetWin32LastError();
				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_ROOT_DRC);
			}

			else {

				return ERROR_SUCCESS;
			}
		}

		virtual inline HANDLE Create_File(const string& file_name) override {

			return CreateFileW(

				file_name,
				GENERIC_READ | GENERIC_WRITE,
				FILE_SHARE_READ,
				NULL,
				OPEN_ALWAYS,
				FILE_ATTRIBUTE_NORMAL,
				NULL);
		}

		virtual inline ulong Get_QuadPart_Cpp_Mqh(const CPP_MQH_LARGE& source) override {

			return source;
		}

		virtual inline ulong File_Read(const HANDLE& file_handle, ulong& line_num, ulong& sys_error) override {

			SetLastError(ERROR_SUCCESS);

			OVERLAPPED Ov_R = {};
			uint Result_Byte = 0;
			uint Read_Byte = ArraySize(Data.Data_To_Binary) * sizeof(ushort);

			if (!ReadFile(file_handle, Data.Data_To_Binary, Read_Byte, Result_Byte, Ov_R)) {

				if (GetWin32LastError() == ERROR_IO_PENDING) {

					return ERROR_SUCCESS;
				}

				else {

					sys_error = GetWin32LastError();
					line_num = __LINE__;

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_FILE_READ);
				}
			}

			else {

				if (Read_Byte != Result_Byte) {

					line_num = __LINE__;

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE);
				}

				return ERROR_SUCCESS;
			}
		}

		virtual inline ulong File_Write(const HANDLE& file_handle, ulong& line_num, ulong& sys_error) override {

			SetLastError(ERROR_SUCCESS);

			OVERLAPPED Ov_R = {};
			uint Result_Byte = 0;
			uint Write_Byte = ArraySize(Data.Data_To_Binary) * sizeof(ushort);

			if (!WriteFile(file_handle, Data.Data_To_Binary, Write_Byte, Result_Byte, Ov_R)) {

				if (GetWin32LastError() == ERROR_IO_PENDING) {

					return ERROR_SUCCESS;
				}

				else {

					sys_error = GetWin32LastError();
					line_num = __LINE__;

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_FILE_WRITE);
				}
			}

			else {

				if (Write_Byte != Result_Byte) {

					line_num = __LINE__;

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE);
				}

				return ERROR_SUCCESS;
			}
		}

		virtual inline ulong Get_Read_Data() override {

			return Data.Mqh_Value;
		}

		virtual inline ulong Find_Drc(const string& drc_name, FIND_DATAW& result, ulong& line_num, ulong& sys_error) override {

			HANDLE Drc_Handle = FindFirstFileW(drc_name, result);

			if (Drc_Handle == INVALID_HANDLE_VALUE) {

				sys_error = GetWin32LastError();
				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_GET_DRC);
			}

			else {

				FindClose(Drc_Handle);

				return ERROR_SUCCESS;
			}
		}

	public:

		virtual inline void Set_Write_Data(const ulong data) override {

			Data.Mqh_Value = data;
		}
	};

#endif

	class FILE_MANAGER_USE : public FILE_MANAGER_CROSS {

	private:

		struct HANDLES {

			HANDLE Error;
			HANDLE Vis;
			HANDLE Lang;
		};
		
		HANDLES Handle;

		struct FILES_SIZE {

			ulong Error;
			ulong Vis;
			ulong Lang;
		};

		FILES_SIZE File_Size;

		FILE_MANAGER_USE(const FILE_MANAGER_USE& source);

#ifdef COMPILER_FOO_CPP

		FILE_MANAGER_USE& operator=(const FILE_MANAGER_USE&) = delete;

#endif

	public:

		FILE_MANAGER_USE() {

			Handle.Error = INVALID_HANDLE_VALUE;
			Handle.Lang = INVALID_HANDLE_VALUE;
			Handle.Vis = INVALID_HANDLE_VALUE;

			File_Size.Error = 0;
			File_Size.Lang = 0;
			File_Size.Vis = 0;

			Now_File_Lock_Initialization();
		}

		~FILE_MANAGER_USE() {

			ulong line = 0, sys = 0;

			Unlock_File(Handle.Error, File_Size.Error, line, sys);
			Close_File(Handle.Error);

			Unlock_File(Handle.Vis, File_Size.Vis, line, sys);
			Close_File(Handle.Vis);

			Unlock_File(Handle.Lang, File_Size.Lang, line, sys);
			Close_File(Handle.Lang);
		}

	private:

		inline ulong Create_Root(const string& file_name,ulong& line_num,ulong& sys_error) {

			FIND_DATAW Find_Data = {};
			string Drc = NULL_STRING;

			ulong Error_Code = Get_Local_App_Data(Drc,line_num);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Find_Drc(Drc, Find_Data,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

					return Error_Code;
			}



			if (file_name == ERR_MS_ERR_NUM_FILE_NAME) {

				for (int i = 0; i < FIND_ERROR_COUNT; i++) {

					if (!StringAdd(Drc, FIND_ROOT_STRING_ERROR[i])) {

						sys_error = GetLastError();
						line_num = __LINE__;

						return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_ROOT_DRC);
					}

					Error_Code = Find_Drc(Drc, Find_Data,line_num,sys_error);

					if (Error_Code != ERROR_SUCCESS) {

						if (sys_error == ERROR_FILE_NOT_FOUND) {

							Error_Code = Create_Folder(Drc,line_num,sys_error);

							if (Error_Code != ERROR_SUCCESS && sys_error != ERROR_ALREADY_EXISTS) {

								return Error_Code;
							}
						}

						else {

							return Error_Code;
						}
					}
				}
			}

			if (file_name == ERR_MS_VISIBLE_ERR_NUM_FILE_NAME) {

				for (int i = 0; i < FIND_VIS_COUNT; i++) {

					if (!StringAdd(Drc, FIND_ROOT_STRING_VIS[i])) {

						sys_error = GetLastError();
						line_num = __LINE__;

						return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_ROOT_DRC);
					}

					Error_Code = Find_Drc(Drc, Find_Data,line_num,sys_error);

					if (Error_Code != ERROR_SUCCESS) {

						if (sys_error == ERROR_FILE_NOT_FOUND) {

							Error_Code = Create_Folder(Drc,line_num,sys_error);

							if (Error_Code != ERROR_SUCCESS && sys_error != ERROR_ALREADY_EXISTS) {

								return Error_Code;
							}
						}

						else {

							return Error_Code;
						}
					}
				}
			}

			if (file_name == MT5_LANGUAGE_NUM_FILE_NAME) {

				for (int i = 0; i < FIND_LANG_COUNT; i++) {

					if (!StringAdd(Drc, FIND_ROOT_STRING_LANG[i])) {

						sys_error = GetLastError();
						line_num = __LINE__;

						return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_ROOT_DRC);
					}

					Error_Code = Find_Drc(Drc, Find_Data,line_num,sys_error);

					if (Error_Code != ERROR_SUCCESS) {

						if (sys_error == ERROR_FILE_NOT_FOUND) {

							Error_Code = Create_Folder(Drc,line_num,sys_error);

							if (Error_Code != ERROR_SUCCESS && sys_error != ERROR_ALREADY_EXISTS) {

								return Error_Code;
							}
						}

						else {

							return Error_Code;
						}
					}
				}
			}


			if (!StringAdd(Drc, file_name)) {

				sys_error = GetLastError();
				line_num = __LINE__;

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_ROOT_DRC);
			}

			Error_Code = Find_Drc(Drc, Find_Data,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				if (sys_error == ERROR_FILE_NOT_FOUND) {

					HANDLE File_Handle = Create_File(Drc);

					if (File_Handle == INVALID_HANDLE_VALUE) {

						sys_error = GetWin32LastError();
						line_num = __LINE__;

						return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_ROOT_DRC);
					}

					Error_Code = File_Initialization(File_Handle,line_num,sys_error);

					Close_File(File_Handle);

					if (Error_Code != ERROR_SUCCESS) {

						return Error_Code;
					}
				}

				else {

					return Error_Code;
				}
			}

			return ERROR_SUCCESS;
		}

	public:

		inline ulong Read_Error(ulong& result,ulong& last_time,ulong& sys_error,ulong& line_num) {

			sys_error = ERROR_SUCCESS;
			line_num = 0;

			SetLastError(ERROR_SUCCESS);

			ulong Error_Code = File_Lock_Only_1(line_num);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			CPP_MQH_LARGE P_Large = {};

			string File_Path;

			Error_Code = Get_Full_Path(CONTROL_FOLDER_DRC, ERR_MS_ERR_NUM_FILE_DRC, ERR_MS_ERR_NUM_FILE_NAME, File_Path,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Create_Root(ERR_MS_ERR_NUM_FILE_NAME, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Open_File(Handle.Error, File_Path, P_Large,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Check_File_Size(Handle.Error, ERR_MS_ERR_NUM_FILE_SIZE, P_Large,line_num);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Error);

				return Error_Code;
			}

			File_Size.Error = Get_QuadPart_Cpp_Mqh(P_Large);

			Error_Code = Try_Lock_File(Handle.Error, File_Size.Error,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Error);

				return Error_Code;
			}

			Error_Code = Get_File_Last_Write_Time(Handle.Error, last_time,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Error);

				return Error_Code;
			}

			Error_Code = Reset_File_Pointer(Handle.Error,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Error);

				return Error_Code;
			}

			Error_Code = File_Read(Handle.Error,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				ulong Unlock_Error = Unlock_File(Handle.Error, File_Size.Error,line_num,sys_error);

				if (Unlock_Error == ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Error);

					return Error_Code;
				}

				else {

					Set_Now_File_Lock(false);

					Close_File(Handle.Error);

					return Unlock_Error;
				}
			}

			else {

				result = Get_Read_Data();

				Error_Code = Unlock_File(Handle.Error, File_Size.Error,line_num,sys_error);

				if (Error_Code != ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Error);

					return Error_Code;
				}
			}

			Set_Now_File_Lock(false);

			Close_File(Handle.Error);

			return ERROR_SUCCESS;
		};

		inline ulong Read_Lang(ulong& result,ulong& last_time,ulong& line_num,ulong& sys_error) {

			sys_error = ERROR_SUCCESS;
			line_num = 0;

			SetLastError(ERROR_SUCCESS);

			ulong Error_Code = File_Lock_Only_1(line_num);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			CPP_MQH_LARGE P_Large = {};

			string File_Path;

			Error_Code = Get_Full_Path(CONTROL_FOLDER_DRC, MT5_LANGUAGE_NUM_FILE_DRC, MT5_LANGUAGE_NUM_FILE_NAME, File_Path,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Create_Root(MT5_LANGUAGE_NUM_FILE_NAME, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Open_File(Handle.Lang, File_Path, P_Large, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Check_File_Size(Handle.Lang, MT5_LANGUAGE_NUM_FILE_SIZE, P_Large, line_num);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Lang);

				return Error_Code;
			}

			File_Size.Lang = Get_QuadPart_Cpp_Mqh(P_Large);

			Error_Code = Try_Lock_File(Handle.Lang, File_Size.Lang, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Lang);

				return Error_Code;
			}

			Error_Code = Get_File_Last_Write_Time(Handle.Lang, last_time, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Lang);

				return Error_Code;
			}

			Error_Code = Reset_File_Pointer(Handle.Lang, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Lang);

				return Error_Code;
			}

			Error_Code = File_Read(Handle.Lang, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				ulong Unlock_Error = Unlock_File(Handle.Lang, File_Size.Lang, line_num, sys_error);

				if (Unlock_Error == ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Lang);

					return Error_Code;
				}

				else {

					Set_Now_File_Lock(false);

					Close_File(Handle.Lang);

					return Unlock_Error;
				}
			}

			else {

				result = Get_Read_Data();

				Error_Code = Unlock_File(Handle.Lang, File_Size.Lang, line_num, sys_error);

				if (Error_Code != ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Lang);

					return Error_Code;
				}
			}

			Set_Now_File_Lock(false);

			Close_File(Handle.Lang);

			return ERROR_SUCCESS;
		};

		inline ulong Read_Vis(ulong& result, ulong& last_time, ulong& sys_error, ulong& line_num) {

			sys_error = ERROR_SUCCESS;
			line_num = 0;

			SetLastError(ERROR_SUCCESS);

			ulong Error_Code = File_Lock_Only_1(line_num);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			CPP_MQH_LARGE P_Large = {};

			string File_Path;

			Error_Code = Get_Full_Path(CONTROL_FOLDER_DRC, ERR_MS_VISIBLE_ERR_NUM_FILE_DRC, ERR_MS_VISIBLE_ERR_NUM_FILE_NAME, File_Path,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Create_Root(ERR_MS_VISIBLE_ERR_NUM_FILE_NAME,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Open_File(Handle.Vis, File_Path, P_Large,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Check_File_Size(Handle.Vis, ERR_MS_VISIBLE_ERR_NUM_FILE_SIZE, P_Large, line_num);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Vis);

				return Error_Code;
			}

			File_Size.Vis = Get_QuadPart_Cpp_Mqh(P_Large);

			Error_Code = Try_Lock_File(Handle.Vis, File_Size.Vis, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Vis);

				return Error_Code;
			}

			Error_Code = Get_File_Last_Write_Time(Handle.Vis, last_time, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Vis);

				return Error_Code;
			}

			Error_Code = Reset_File_Pointer(Handle.Vis, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Vis);

				return Error_Code;
			}

			Error_Code = File_Read(Handle.Vis, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				ulong Unlock_Error = Unlock_File(Handle.Vis, File_Size.Vis, line_num, sys_error);

				if (Unlock_Error == ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Vis);

					return Error_Code;
				}

				else {

					Set_Now_File_Lock(false);

					Close_File(Handle.Vis);

					return Unlock_Error;
				}
			}

			else {

				result = Get_Read_Data();

				Error_Code = Unlock_File(Handle.Vis, File_Size.Vis, line_num, sys_error);

				if (Error_Code != ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Vis);

					return Error_Code;
				}
			}

			Set_Now_File_Lock(false);

			Close_File(Handle.Vis);

			return ERROR_SUCCESS;
		};

		inline ulong Write_Error(const ulong& data,ulong& line_num,ulong& sys_error) {

			sys_error = ERROR_SUCCESS;
			line_num = 0;

			SetLastError(ERROR_SUCCESS);

			ulong Error_Code = File_Lock_Only_1(line_num);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			CPP_MQH_LARGE P_Large = {};

			string File_Path;

			Error_Code = Get_Full_Path(CONTROL_FOLDER_DRC, ERR_MS_ERR_NUM_FILE_DRC, ERR_MS_ERR_NUM_FILE_NAME, File_Path,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Create_Root(ERR_MS_ERR_NUM_FILE_NAME, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Open_File(Handle.Error, File_Path, P_Large, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Check_File_Size(Handle.Error, ERR_MS_ERR_NUM_FILE_SIZE, P_Large, line_num);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Error);

				return Error_Code;
			}

			File_Size.Error = Get_QuadPart_Cpp_Mqh(P_Large);

			Error_Code = Try_Lock_File(Handle.Error, File_Size.Error, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Error);

				return Error_Code;
			}

			Error_Code = Reset_File_Pointer(Handle.Error, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Error);

				return Error_Code;
			}

			Set_Write_Data(data);

			Error_Code = File_Write(Handle.Error, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				ulong Unlock_Error = Unlock_File(Handle.Error, File_Size.Error, line_num, sys_error);

				if (Unlock_Error == ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Error);

					return Error_Code;
				}

				else {

					Set_Now_File_Lock(false);

					Close_File(Handle.Error);

					return Unlock_Error;
				}
			}

			else {

				Error_Code = File_Write_Flash(Handle.Error, line_num, sys_error);

				if (Error_Code != ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Error);

					return Error_Code;
				}

				Error_Code = Unlock_File(Handle.Error, File_Size.Error, line_num, sys_error);

				if (Error_Code != ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Error);

					return Error_Code;
				}
			}

			Set_Now_File_Lock(false);

			Close_File(Handle.Error);

			return ERROR_SUCCESS;
		};

		inline ulong Write_Vis(const ulong& data,ulong& line_num,ulong& sys_error) {

			sys_error = ERROR_SUCCESS;
			line_num = 0;

			SetLastError(ERROR_SUCCESS);

			ulong Error_Code = File_Lock_Only_1(line_num);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			CPP_MQH_LARGE P_Large = {};

			string File_Path;

			Error_Code = Get_Full_Path(CONTROL_FOLDER_DRC, ERR_MS_VISIBLE_ERR_NUM_FILE_DRC, ERR_MS_VISIBLE_ERR_NUM_FILE_NAME, File_Path,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Create_Root(ERR_MS_VISIBLE_ERR_NUM_FILE_NAME, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Open_File(Handle.Vis, File_Path, P_Large, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Check_File_Size(Handle.Vis, ERR_MS_VISIBLE_ERR_NUM_FILE_SIZE, P_Large, line_num);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Vis);

				return Error_Code;
			}

			File_Size.Vis = Get_QuadPart_Cpp_Mqh(P_Large);

			Error_Code = Try_Lock_File(Handle.Vis, File_Size.Vis, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Vis);

				return Error_Code;
			}

			Error_Code = Reset_File_Pointer(Handle.Vis, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Vis);

				return Error_Code;
			}

			Set_Write_Data(data);

			Error_Code = File_Write(Handle.Vis, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				ulong Unlock_Error = Unlock_File(Handle.Vis, File_Size.Vis, line_num, sys_error);

				if (Unlock_Error == ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Vis);

					return Error_Code;
				}

				else {

					Set_Now_File_Lock(false);

					Close_File(Handle.Vis);

					return Unlock_Error;
				}
			}

			else {

				Error_Code = File_Write_Flash(Handle.Vis, line_num, sys_error);

				if (Error_Code != ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Vis);

					return Error_Code;
				}

				Error_Code = Unlock_File(Handle.Vis, File_Size.Vis, line_num, sys_error);

				if (Error_Code != ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Vis);

					return Error_Code;
				}
			}

			Set_Now_File_Lock(false);

			Close_File(Handle.Vis);

			return ERROR_SUCCESS;
		};

		inline ulong Write_Lang(const ulong& data,ulong& line_num,ulong& sys_error) {

			sys_error = ERROR_SUCCESS;
			line_num = 0;

			SetLastError(ERROR_SUCCESS);

			ulong Error_Code = File_Lock_Only_1(line_num);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			CPP_MQH_LARGE P_Large = {};

			string File_Path;

			Error_Code = Get_Full_Path(CONTROL_FOLDER_DRC, MT5_LANGUAGE_NUM_FILE_DRC, MT5_LANGUAGE_NUM_FILE_NAME, File_Path,line_num,sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Create_Root(MT5_LANGUAGE_NUM_FILE_NAME, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Open_File(Handle.Lang, File_Path, P_Large, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				return Error_Code;
			}

			Error_Code = Check_File_Size(Handle.Lang, MT5_LANGUAGE_NUM_FILE_SIZE, P_Large, line_num);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Lang);

				return Error_Code;
			}

			File_Size.Lang = Get_QuadPart_Cpp_Mqh(P_Large);

			Error_Code = Try_Lock_File(Handle.Lang, File_Size.Lang, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Lang);

				return Error_Code;
			}

			Error_Code = Reset_File_Pointer(Handle.Lang, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				Set_Now_File_Lock(false);

				Close_File(Handle.Lang);

				return Error_Code;
			}

			Set_Write_Data(data);

			Error_Code = File_Write(Handle.Lang, line_num, sys_error);

			if (Error_Code != ERROR_SUCCESS) {

				ulong Unlock_Error = Unlock_File(Handle.Lang, File_Size.Lang, line_num, sys_error);

				if (Unlock_Error == ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Lang);

					return Error_Code;
				}

				else {

					Set_Now_File_Lock(false);

					Close_File(Handle.Lang);

					return Unlock_Error;
				}
			}

			else {

				Error_Code = File_Write_Flash(Handle.Lang, line_num, sys_error);

				if (Error_Code != ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Lang);

					return Error_Code;
				}

				Error_Code = Unlock_File(Handle.Lang, File_Size.Lang, line_num, sys_error);

				if (Error_Code != ERROR_SUCCESS) {

					Set_Now_File_Lock(false);

					Close_File(Handle.Lang);

					return Error_Code;
				}
			}

			Set_Now_File_Lock(false);

			Close_File(Handle.Lang);

			return ERROR_SUCCESS;
		};
	};

#endif

};