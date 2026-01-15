///////////////////////////////////////////////////////////
//                                                       //
// このヘッダーファイルはmqhファイル側では変更しない     //
// .hと.mqhtとして両方、生成するcmakeが作成されるため    //
//                                                       //
///////////////////////////////////////////////////////////

namespace COMMON_DEFINE {

#ifndef CONTROL_H_PUBLIC_HEADER

#define CONTROL_H_PUBLIC_HEADER


	///////////////////////////////////////////////////////////
	//
	// MQL5用の記述
	//

#ifdef COMPILER_FOO_MQH5

#include                                                    "C:\\Users\\okita\\AppData\\Roaming\\MetaQuotes\\Terminal\\ED051E4A9BEE8A33BDDD0F947358B2B2\\MQL5\\Experts\\CONTROL\\PCH.mqh"



#define BOOL                                                int

#define CPP_MQH_GO_WORD(source)                             (source)
#define CPP_MQH_LARGE                                       long
#define CPP_MQH_ULONG                                       ulong
#define CPP_MQH_VARIABLE_DATA_TYPE_WRITE                    ulong
#define CPP_MQH_VARIABLE_DATA_TYPE_READ                     ushort&
#define CPP_MQH_PLARGE                                      long
#define CPP_MQH_PATH                                        string
#define CPP_MQH_LPOVERLAPPED                                OVERLAPPED


	const string CONTROL_FOLDER_DRC = "\\ReturnSafety\\CONTROL";

	const string ERR_MS_ERR_NUM_FILE_NAME = "err.bin";
	const string ERR_MS_ERR_NUM_FILE_DRC = "\\err_ms\\files\\err\\";

	const string ERR_MS_VISIBLE_ERR_NUM_FILE_NAME = "vis.bin";
	const string ERR_MS_VISIBLE_ERR_NUM_FILE_DRC = "\\err_ms\\files\\vis\\";

	const string MT5_LANGUAGE_NUM_FILE_NAME = "lang.bin";
	const string MT5_LANGUAGE_NUM_FILE_DRC = "\\lang\\";

	const string ERR_MS_WINDOW_TITLE = "CONTROL system error";

	const string ERR_MS_WINDOW_CLASS = "#32770";

	const string NULL_STRING = "";
	const string SPACE_STRING = " ";
	const string COLON_STRING = ":";
	const string LINE_BREAK = "\n";
	const string BACK_SLASH_STRING = "\\";

	const uint MT5_LANGUAGE_NUM_FILE_SIZE = sizeof(ulong);
	const uint ERR_MS_ERR_NUM_FILE_SIZE = sizeof(ulong);
	const uint ERR_MS_VISIBLE_ERR_NUM_FILE_SIZE = sizeof(ulong);

	const int INVALID_HANDLE_VALUE = -1;

	const uint GENERIC_READ = (uint)0x80000000;
	const uint GENERIC_WRITE = 0x40000000;
	const uint OPEN_ALWAYS = 4;
	const uint FILE_ATTRIBUTE_NORMAL = 0x00000080;
	const uint FILE_BEGIN = 0;
	const uint CPP_MQH_FILE_SHARE_READ = 0x00000001;

	const uint LOCKFILE_EXCLUSIVE_LOCK = 0x00000002;

	const uint ERROR_SUCCESS = 0;
	const uint ERROR_IO_PENDING = 997L;

#endif


///////////////////////////////////////////////////////////
//
// c++用の記述
//

#ifdef COMPILER_FOO_CPP


	using ulong = unsigned __int64;
	using string = const wchar_t*;
	using ushort = unsigned short;
	using uint = unsigned int;

	using CPP_MQH_LARGE = LARGE_INTEGER;
	using CPP_MQH_ULONG = unsigned __int64;
	using CPP_MQH_PLARGE = PLARGE_INTEGER;
	using CPP_MQH_PATH = std::wstring;
	using CPP_MQH_LPOVERLAPPED = LPOVERLAPPED;



	const std::wstring CONTROL_FOLDER_DRC = L"\\ReturnSafety\\CONTROL";

	const std::wstring ERR_MS_ERR_NUM_FILE_NAME = L"err.bin";
	const std::wstring ERR_MS_ERR_NUM_FILE_DRC = L"\\err_ms\\files\\err\\";

	const std::wstring ERR_MS_VISIBLE_ERR_NUM_FILE_NAME = L"vis.bin";
	const std::wstring ERR_MS_VISIBLE_ERR_NUM_FILE_DRC = L"\\err_ms\\files\\vis\\";

	const std::wstring MT5_LANGUAGE_NUM_FILE_NAME = L"lang.bin";
	const std::wstring MT5_LANGUAGE_NUM_FILE_DRC = L"\\lang\\";

	const std::wstring ERR_MS_WINDOW_TITLE = L"CONTROL system error";

	const std::wstring ERR_MS_WINDOW_CLASS = L"#32770";

	const std::wstring NULL_STRING = L"";
	const std::wstring LINE_BREAK = L"\n";
	const std::wstring SPACE_STRING = L" ";
	const std::wstring COLON_STRING = L":";
	const std::wstring BACK_SLASH_STRING = L"\\";

	const std::wstring MUTEX_GLOBAL_NAME_LOG_PROCESS = L"Global\\ReturnSafety_CONTROL_Log_Mutex";

	const uint ERR_USER_ERROR_FIRST = 65536;

	const uint GET_MUTEX_TRIAL_MAX_COUNT = 10;
	const uint GET_MUTEX_TRIAL_SLEEP_MILLI_SEC = 100;
	const uint GET_MUTEX_WAIT_LOCK_MILLI_SEC = 20;

	const uint CPP_MQH_FILE_SHARE_READ = FILE_SHARE_READ;

	

	static bool Get_Local_App_Data(CPP_MQH_PATH& result) {

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



	static constexpr void ResetLastError() {

		return SetLastError(ERROR_SUCCESS);
	}
	


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

#ifdef COMPILER_FOO_CPP_ERR_MS_EXE


	using CPP_MQH_VARIABLE_DATA_TYPE = ulong;
	using CPP_MQH_VARIABLE_WRITE_DATA = ulong;



	const uint MT5_LANGUAGE_NUM_FILE_SIZE = sizeof(ulong);
	const uint ERR_MS_ERR_NUM_FILE_SIZE = sizeof(ulong);
	const uint ERR_MS_VISIBLE_ERR_NUM_FILE_SIZE = sizeof(ulong);
#endif

#ifdef COMPILER_FOO_CPP_LOG_MNG_EXE


	using CPP_MQH_VARIABLE_DATA_TYPE_WRITE = std::wstring;
	using CPP_MQH_VARIABLE_DATA_TYPE_READ = wchar_t*;



	const std::wstring LOG_MNG_CURRENT_LOG_FILE_NAME = L"current_log.log";
	const std::wstring LOG_MNG_CURRENT_LOG_FILE_DRC = L"\\log\\current\\log\\";

	const std::wstring LOG_MNG_LOG_FILE_NAME = L"log.log";
	const std::wstring LOG_MNG_LOG_FILE_DRC = L"\\log\\";
	
	const std::wstring LOG_FILE_BEGIN_VALUE_COLON = L":";



	const uint LOG_FILE_MAX_BYTE_SIZE = 5242880;
#endif

#endif



	const uint CUSTOM_ERROR_CODE_NONE_ONLY_EA = 1;
	const uint CUSTOM_ERROR_CODE_NONE_DLL_EXIST = 2;
	const uint CUSTOM_ERROR_CODE_NONE_TRADW_ALLOWED = 3;
	const uint CUSTOM_ERROR_CODE_FAILED_LANGUAGE_SETING = 4;
	const uint CUSTOM_ERROR_CODE_INPUT_FAILED_STRING_NONE_NUMBER = 5;
	const uint CUSTOM_ERROR_CODE_INPUT_FAILED_STRING_LENGTH = 6;
	const uint CUSTOM_ERROR_CODE_INPUT_FAILED_MAX_TRADE = 7;
	const uint CUSTOM_ERROR_CODE_INPUT_FAILED_WAIT_TIME = 8;
	const uint CUSTOM_ERROR_CODE_INPUT_FAILED_INDICATOR_VALUE = 9;
	const uint CUSTOM_ERROR_CODE_INPUT_FAILED_PERCENTAGE_VALUE = 10;
	const uint CUSTOM_ERROR_CODE_INPUT_FAILED_FIXID_VALUE = 11;
	const uint CUSTOM_ERROR_CODE_INPUT_FAILED_COMMISION_USD_VALUE = 12;
	const uint CUSTOM_ERROR_CODE_INPUT_FAILED_GMT_VALUE = 13;
	const uint CUSTOM_ERROR_CODE_ONTIMRE_NOT_SUCCEDDED = 14;
	const uint CUSTOM_ERROR_CODE_INPUT_TIME_VALUE_FAILED = 15;
	const uint CUSTOM_ERROR_CODE_NONE_APP_EXIST = 16;
	const uint CUSTOM_ERROR_CODE_NONE_WATCH_WINDOW = 17;
	const uint CUSTOM_ERROR_CODE_FAILED_SL_FILE_SIZE = 18;
	const uint CUSTOM_ERROR_CODE_FRAUD_SL_FILE = 19;
	const uint CUSTOM_ERROR_CODE_FAILED_CREATE_ERROR_LOG = 20;
	const uint CUSTOM_ERROR_CODE_FAILED_OPEN_ERROR_LOG = 21;
	const uint CUSTOM_ERROR_CODE_FAILED_CREATE_CURRENT_LOG = 22;
	const uint CUSTOM_ERROR_CODE_FAILED_OPEN_CURRENT_LOG = 23;
	const uint CUSTOM_ERROR_CODE_FAILED_WRITE_ERROR_LOG = 24;
	const uint CUSTOM_ERROR_CODE_FAILED_WRITE_CURRENT_LOG = 25;
	const uint CUSTOM_ERROR_CODE_INPUT_TIME_SET_OR_UNSET_FAILED = 26;
	const uint CUSTOM_ERROR_CODE_INPUT_TIME_DATE_CHANGE_TIME_FAILED = 27;
	const uint CUSTOM_ERROR_CODE_ERROR_LOG_DELETED = 28;
	const uint CUSTOM_ERROR_CODE_CURRENT_LOG_DELETED = 29;
	const uint CUSTOM_ERROR_CODE_FAILED_APP_BOOT = 30;
	const uint CUSTOM_ERROR_CODE_FAILED_SL_FILE_CREATE = 31;
	const uint CUSTOM_ERROR_CODE_FAILED_SL_FILE_OPEN = 32;
	const uint CUSTOM_ERROR_CODE_FAILED_SL_FILE_ACCESS = 33;
	const uint CUSTOM_ERROR_CODE_NONE_ERROR_NUM_FILE = 34;
	const uint CUSTOM_ERROR_CODE_NONE_MT5_LANGUAGE_FILE = 35;
	const uint CUSTOM_ERROR_CODE_NONE_VISIBLE_ERROR_NUM_FILE = 36;
	const uint CUSTOM_ERROR_CODE_UNKNOWN_ERROR = 37;
	const uint CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE = 38;
	const uint CUSTOM_ERROR_CODE_FAILED_GET_DAY_LOG_DRC = 39;
	const uint CUSTOM_ERROR_CODE_FAILED_GET_LOCAL_APP_DRC = 40;
	const uint CUSTOM_ERROR_CODE_FAILED_CREATE_LOG_DRC = 41;
	const uint CUSTOM_ERROR_CODE_FAILED_OPEN_FILE = 42;
	const uint CUSTOM_ERROR_CODE_FAILED_READ_FILE_BYTE_SIZE = 43;
	const uint CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE = 44;
	const uint CUSTOM_ERROR_CODE_FAILED_FILE_LOCK = 45;
	const uint CUSTOM_ERROR_CODE_FAILED_FILE_UNLOCK = 46;
	const uint CUSTOM_ERROR_CODE_FAILED_LOG_NONE_GET_UNKNOWN_TIME = 47;
	const uint CUSTOM_ERROR_CODE_FAILED_CORRECT_ALIGNMENT = 48;

	const uint CUSTOM_ERROR_CODE_MAX_VALUE = (49 + ERR_USER_ERROR_FIRST);

	const uint TIME_SCALE_PREMISE_YEAR = 1900;
	const uint TIME_SCALE_MOON_RETOUCH_VALUE = 1;

	const ulong MAX_FILE_SIZE = 4000000000ULL;



	inline CPP_MQH_PATH Get_Full_Path(const CPP_MQH_PATH& control_drc, const CPP_MQH_PATH& file_drc, const CPP_MQH_PATH& file_name) {

		CPP_MQH_PATH result = NULL_STRING;

		result += control_drc;;;
		result += file_drc;
		result += file_name;

		return result;
	}
	


	inline ulong CALC_CUSTOM_ERROR_CODE(ulong custom_err) {

		return custom_err + ERR_USER_ERROR_FIRST;
	}



	inline uint32_t FILE_LOCK_MASK_LOW(const ulong& file_data) {

		return (uint32_t)(file_data & 0xFFFFFFFF);
	}



	inline uint32_t FILE_LOCK_MASK_HIGH(const ulong& file_data) {

		return (uint32_t)(file_data >> 32);
	}


	enum MT5_LANGUAGE_NUMBER
	{
		EN,
		JP,
		OTHERS
	};



	class FILE_MANAGER_BASE {

	protected:

#pragma pack(1)

		union DATA_TYPE_MEMORY_MAP {

			ulong Data;
			ushort Data_To_Binary[sizeof(ulong) / sizeof(ushort)];

			struct CPP_PTR_VALUE {

				ulong value;
				uint Size;
			}; CPP_PTR_VALUE PTR;
		};

#pragma pack()

		DATA_TYPE_MEMORY_MAP Data;


		virtual inline uint Get_QuadPart_Cpp_Mqh(const CPP_MQH_LARGE& source) {

			return 0;
		}

		virtual inline ulong File_Initialization(const HANDLE& handle) {

			return 0;
		}

	public:

		virtual inline ulong File_Read(const HANDLE& file_handle) {

			return 0;
		}

		virtual inline ulong File_Write(const HANDLE& file_handle) {

			return 0;
		}

		inline ulong Alignment_Checker() {

			if (sizeof(Data) != 12) {

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_CORRECT_ALIGNMENT);
			}
			else {

				return ERROR_SUCCESS;
			}
		}

		virtual inline void Set_Write_Data(const ulong data) {


		}

		virtual inline ulong Get_Read_Data() {

			return 0;
		}

		inline ulong Open_File(HANDLE& file_handle, const string file_name, CPP_MQH_PLARGE& result_file_size) {

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

					ulong Error_Code = File_Initialization(file_handle);

					if (Error_Code != ERROR_SUCCESS) {

						CloseHandle(file_handle);

						return Error_Code;
					}
				}

				if (!GetFileSizeEx(file_handle, result_file_size)) {

					CloseHandle(file_handle);

					return GetLastError();
				}

				else {

					return ERROR_SUCCESS;
				}
			}
		}

		inline ulong Check_File_Size(const HANDLE& file_handle, const ulong& byte_size, const CPP_MQH_LARGE& file_size) {


			CPP_MQH_ULONG To_Size = Get_QuadPart_Cpp_Mqh(file_size);

			if (To_Size > MAX_FILE_SIZE) {

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE);
			}

			else if (byte_size != To_Size) {

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FRAUD_FILE_SIZE);
			}

			else {

				return ERROR_SUCCESS;
			}
		};

		inline ulong Lock_File(const HANDLE& file_handle, const ulong& file_size) {

			CPP_MQH_LPOVERLAPPED Ov_R = {};

			uint LockLow = FILE_LOCK_MASK_LOW(file_size);
			uint LockHigh = FILE_LOCK_MASK_HIGH(file_size);

			if (!LockFileEx(file_handle, LOCKFILE_EXCLUSIVE_LOCK, 0, LockLow, LockHigh, Ov_R)) {

				return CUSTOM_ERROR_CODE_FAILED_FILE_LOCK;
			}

			else {

				return ERROR_SUCCESS;
			}
		}

		inline ulong Reset_File_Pointer(const HANDLE& file_handle) {

			ResetLastError();

			CPP_MQH_LARGE Move_P = {};
			CPP_MQH_PLARGE result_P = {};

			if (!SetFilePointerEx(file_handle, Move_P, result_P, FILE_BEGIN)) {

				return GetLastError();
			}

			else {

				return ERROR_SUCCESS;
			}
		}

		inline ulong Unlock_File(const HANDLE& file_handle, const ulong& byte_size) {

			CPP_MQH_LPOVERLAPPED Ov_R = {};
			uint LockLow = FILE_LOCK_MASK_LOW(byte_size);
			uint LockHigh = FILE_LOCK_MASK_HIGH(byte_size);

			if (!UnlockFileEx(file_handle, 0, LockLow, LockHigh, Ov_R)) {

				return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_FILE_UNLOCK);
			}

			else {

				return ERROR_SUCCESS;
			}
		}

		inline void Close_File(const HANDLE& file_handle) {

			if (file_handle != INVALID_HANDLE_VALUE && file_handle != NULL) {

				CloseHandle(file_handle);
			}
		}
	};

#ifdef COMPILER_FOO_CPP

	class FILE_MANAGER_CPP : public FILE_MANAGER_BASE {

	protected:

		virtual inline uint Get_QuadPart_Cpp_Mqh(const CPP_MQH_LARGE& source) override {

			return (uint)source.QuadPart;
		}

		virtual inline ulong File_Initialization(const HANDLE& handle) override {

			CPP_MQH_LARGE Move_P = {};
			CPP_MQH_PLARGE Result_P = {};

			if (!SetFilePointerEx(handle, Move_P, Result_P, FILE_BEGIN)) {

				return GetLastError();
			}

			else {

				Data.PTR.value = 0;
				Data.PTR.Size = sizeof(Data.PTR.value);

				ResetLastError();

				DWORD Write_Size = 0;

				BOOL result = WriteFile(handle, &Data.PTR.value, Data.PTR.Size, &Write_Size, NULL);

				if (!result) {

					if (GetLastError() == ERROR_IO_PENDING) {

						return ERROR_SUCCESS;
					}

					else {

						return GetLastError();
					}
				}

				else {

					if ((uint)Write_Size != Data.PTR.Size) {

						return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE);
					}

					return ERROR_SUCCESS;
				}
			}
		}

	public:

		virtual inline ulong File_Read(const HANDLE& file_handle) override {

			ResetLastError();

			DWORD Read_Size = 0;

			if (!ReadFile(file_handle, &Data.PTR.value, Data.PTR.Size, &Read_Size, NULL)) {

				if (GetLastError() == ERROR_IO_PENDING) {

					return ERROR_SUCCESS;
				}

				else {

					return GetLastError();
				}
			}

			else {

				if ((uint)Read_Size != Data.PTR.Size) {

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE);
				}

				return ERROR_SUCCESS;
			}
		}

		virtual inline ulong File_Write(const HANDLE& file_handle) override {

			ResetLastError();

			DWORD Write_Size = 0;

			if (!WriteFile(file_handle, &Data.PTR.value, Data.PTR.Size, &Write_Size, NULL)) {

				if (GetLastError() == ERROR_IO_PENDING) {

					return ERROR_SUCCESS;
				}

				else {

					return GetLastError();
				}
			}

			else {

				if ((uint)Write_Size != Data.PTR.Size) {

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE);
				}

				return ERROR_SUCCESS;
			}
		}

		virtual inline void Set_Write_Data(const ulong data) override {

			Data.PTR.value = data;
			Data.PTR.Size = sizeof(data);
		}

		virtual inline ulong Get_Read_Data() override {

			return Data.PTR.value;
		}
	};

#endif

#ifdef COMPILER_FOO_MQH5


	class FILE_MANAGER_MQH : public FILE_MANAGER_BASE {

	protected:

		virtual inline uint Get_QuadPart_Cpp_Mqh(const CPP_MQH_LARGE& source) override {

			return (uint)source;
		}

		virtual inline ulong File_Initialization(const HANDLE& handle) override {

			CPP_MQH_LARGE Move_P = {};
			CPP_MQH_PLARGE Result_P = {};

			if (!SetFilePointerEx(handle, Move_P, Result_P, FILE_BEGIN)) {

				return GetLastError();
			}

			else {

				Data.Data = 0;
				int Size = ArraySize(Data.Data_To_Binary);

				ResetLastError();

				CPP_MQH_LPDWORD Write_Size = 0;

				BOOL result = WriteFile(handle, Data.Data_To_Binary, Size * sizeof(ushort), Write_Size, NULL);

				if (!result) {

					if (GetLastError() == ERROR_IO_PENDING) {

						return ERROR_SUCCESS;
					}

					else {

						return GetLastError();
					}
				}

				else {

					if ((int)Write_Size != Size) {

						return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE);
					}

					return ERROR_SUCCESS;
				}
			}
		}

	public:

		virtual inline ulong File_Read(const HANDLE& file_handle) override {

			ResetLastError();

			OVERLAPPED Ov_R = {};
			uint Result_Byte = 0;
			uint Read_Byte = ArraySize(Data.Data_To_Binary) * sizeof(ushort);

			if (!ReadFile(file_handle, Data.Data_To_Binary, Read_Byte, Result_Byte, Ov_R)) {

				if (GetLastError() == ERROR_IO_PENDING) {

					return ERROR_SUCCESS;
				}

				else {

					return GetLastError();
				}
			}

			else {

				if (Read_Byte != Result_Byte) {

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE);
				}

				return ERROR_SUCCESS;
			}
		}

		virtual inline ulong File_Write(const HANDLE& file_handle) override {

			ResetLastError();

			OVERLAPPED Ov_R = {};
			uint Result_Byte = 0;
			uint Write_Byte = ArraySize(Data.Data_To_Binary) * sizeof(ushort);

			if (!WriteFile(file_handle, Data.Data_To_Binary, Write_Byte, Result_Byte, Ov_R)) {

				if (GetLastError() == ERROR_IO_PENDING) {

					return ERROR_SUCCESS;
				}

				else {

					return GetLastError();
				}
			}

			else {

				if (Write_Byte != Result_Byte) {

					return CALC_CUSTOM_ERROR_CODE(CUSTOM_ERROR_CODE_FAILED_WRITE_FILE_BYTE_SIZE);
				}

				return ERROR_SUCCESS;
			}
		}

		virtual inline void Set_Write_Data(const ulong data) override {

			Data.Data = data;
		}

		virtual inline ulong Get_Read_Data() override {

			return Data.Data;
		}
	};

#endif

#endif
}