cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CONTROL_public_header_create")

# パス定義（すべて / に統一）
set(SOURCE_H "C:/Users/okita/マイドライブ（okita@returnsafety.com）/public_header.h")
set(OUTPUT_MQH "C:/Users/okita/AppData/Roaming/MetaQuotes/Terminal/ED051E4A9BEE8A33BDDD0F947358B2B2/MQL5/Experts/CONTROL/public_header.mqh")

# 実行ファイル作成（ここもスラッシュに統一）
add_executable (CONTROL_public_header_create 
    "CONTROL_public_header_create.cpp" 
    "CONTROL_public_header_create.h" 
    "${SOURCE_H}"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CONTROL_public_header_create PROPERTY CXX_STANDARD 20)
endif()

# コピーコマンド（変数をクォートで保護）
add_custom_target(copy_headers ALL
    COMMAND ${CMAKE_COMMAND} -E copy "${SOURCE_H}" "${OUTPUT_MQH}"
    COMMENT "Copying header to MQL5 directory..."
)

add_dependencies(CONTROL_public_header_create copy_headers)