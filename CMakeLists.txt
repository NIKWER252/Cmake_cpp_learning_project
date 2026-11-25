# CMakeList.txt: проект CMake для CMake_C++_learning; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.10)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMake_C++_learning")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMake_C++_learning "CMake_C++_learning.cpp" "CMake_C++_learning.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMake_C++_learning PROPERTY CXX_STANDARD 20)
endif()

if (MSVC)
    add_compile_options(/utf-8)
endif()
# текст
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
add_executable(Lab1_n1 Lab1/Lab1_n1.cpp)
add_executable(Lab1_n2 Lab1/Lab1_n2.cpp)
add_executable(Lab1_n3 Lab1/Lab1_n3.cpp)
add_executable(Lab1_n4 Lab1/Lab1_n4.cpp)
add_executable(Lab1_n5 Lab1/Lab1_n5.cpp)

add_executable(Lab2_n1 Lab2/Lab2_n1.cpp)
add_executable(Lab2_n2 Lab2/Lab2_n2.cpp)
add_executable(Lab2_n3 Lab2/Lab2_n3.cpp)
add_executable(Lab2_n4 Lab2/Lab2_n4.cpp)
add_executable(Lab2_n5 Lab2/Lab2_n5.cpp)

add_executable(Lab3_n1 Lab3/Lab3_n1.cpp)
add_executable(Lab3_n2 Lab3/Lab3_n2.cpp)
add_executable(Lab3_n3 Lab3/Lab3_n3.cpp)
add_executable(Lab3_n4_a Lab3/Lab3_n4_a.cpp)
add_executable(Lab3_n4_b Lab3/Lab3_n4_b.cpp)
add_executable(Lab3_n5 Lab3/Lab3_n5.cpp)

add_executable(Lab4_n1 Lab4/Lab4_n1.cpp)
add_executable(Lab4_n2 Lab4/Lab4_n2.cpp)
add_executable(Lab4_n3 Lab4/Lab4_n3.cpp)
add_executable(Lab4_n4 Lab4/Lab4_n4.cpp)
add_executable(Lab4_n5 Lab4/Lab4_n5.cpp)
add_executable(Lab4_all Lab4/Lab4_all.cpp)

add_executable(Lab5_n1 Lab5/Lab5_n1.cpp)
add_executable(Lab5_n2 Lab5/Lab5_n2.cpp)
add_executable(Lab5_n3 Lab5/Lab5_n3.cpp)
add_executable(Lab5_n4 Lab5/Lab5_n4.cpp)
add_executable(Lab5_n5 Lab5/Lab5_n5.cpp)
add_executable(Lab5_all Lab5/Lab5_all.cpp)

add_executable(Lab6_n1 Lab6/Lab6_n1.cpp)
add_executable(Lab6_n2 Lab6/Lab6_n2.cpp)
add_executable(Lab6_n3 Lab6/Lab6_n3.cpp)
add_executable(Lab6_n4 Lab6/Lab6_n4.cpp)
add_executable(Lab6_n5 Lab6/Lab6_n5.cpp)
add_executable(Lab6_all Lab6/Lab6_all.cpp)