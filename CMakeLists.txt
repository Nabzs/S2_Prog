cmake_minimum_required(VERSION 3.24)

cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME FolderName)   
string(REPLACE " " "_" FolderName ${FolderName})

project(${FolderName}_Project)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

if (MSVC)
    add_compile_options(/W3)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -pedantic-errors)
endif()

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "TDS/src/*.cpp")
file(GLOB_RECURSE SRC_MAIN_FILES CONFIGURE_DEPENDS "TDS/src/*/main.cpp")

# Remove main files from SRC_FILES
foreach(SRC_MAIN_FILE ${SRC_MAIN_FILES})
    list(REMOVE_ITEM SRC_FILES ${SRC_MAIN_FILE})
endforeach()

message(STATUS "SRC_FILES: ")
foreach(SRC_FILE ${SRC_FILES})
    message(STATUS "    ${SRC_FILE}")
endforeach()

message(STATUS "SRC_MAIN_FILES: ")
foreach(SRC_MAIN_FILE ${SRC_MAIN_FILES})
    message(STATUS "    ${SRC_MAIN_FILE}")
endforeach()

foreach(SRC_MAIN_FILE ${SRC_MAIN_FILES})
    get_filename_component(SRC_MAIN_FILE_NAME ${SRC_MAIN_FILE} NAME_WE)
    get_filename_component(SRC_MAIN_FILE_DIR ${SRC_MAIN_FILE} DIRECTORY)
    get_filename_component(SRC_MAIN_FILE_DIR_NAME ${SRC_MAIN_FILE_DIR} NAME)
    string(REPLACE "main_" "" SRC_MAIN_FILE_NAME ${SRC_MAIN_FILE_NAME})

    set(EXECUTABLE_NAME "${SRC_MAIN_FILE_NAME}_${SRC_MAIN_FILE_DIR_NAME}_${FolderName}")

    message(STATUS "Creating executable: ${EXECUTABLE_NAME}")
    add_executable(${EXECUTABLE_NAME} ${SRC_MAIN_FILE} ${SRC_FILES})
    target_compile_features(${EXECUTABLE_NAME} PUBLIC cxx_std_20)
    target_include_directories(${EXECUTABLE_NAME} PUBLIC "TDS/src/")
endforeach()