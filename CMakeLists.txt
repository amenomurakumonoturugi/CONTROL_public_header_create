# CMakeList.txt : CONTROL_public_header_create の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#
cmake_minimum_required (VERSION 3.8)

# サポートされている場合は、MSVC コンパイラのホット リロードを有効にします。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CONTROL_public_header_create")

# ソースをこのプロジェクトの実行可能ファイルに追加します。
add_executable (CONTROL_public_header_create "CONTROL_public_header_create.cpp" "CONTROL_public_header_create.h" "public_header.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CONTROL_public_header_create PROPERTY CXX_STANDARD 20)
endif()

# TODO: テストを追加し、必要な場合は、ターゲットをインストールします。
set(SOURCE_H "C:/Users/okita/source/repos/CONTROL_public_header_create/public_header.h")
set(OUTPUT_MQH "C:/Users/okita/AppData/Roaming/MetaQuotes/Terminal/ED051E4A9BEE8A33BDDD0F947358B2B2/MQL5/Experts/CONTROL/public_header.mqh")

add_custom_target(copy_headers ALL
    COMMAND ${CMAKE_COMMAND} -E copy ${SOURCE_H} ${OUTPUT_MQH}
    COMMENT "Copy .h to .mqh"
)

# 実行ファイルターゲットに依存させる
add_dependencies(CONTROL_public_header_create copy_headers)
