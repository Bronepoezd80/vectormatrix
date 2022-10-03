##
# Jakob Janzen
# jakob.janzen80@gmail.com
# 2022-10-03
##
set(__MINIMUM_VERSION 3.15)
cmake_minimum_required(VERSION ${__MINIMUM_VERSION} FATAL_ERROR)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(array
    VERSION
        1.0.0
    DESCRIPTION
        "Dynamic memory allocation for vectors and matrices in C."
    LANGUAGES
        C;CXX
)

include(GNUInstallDirs)

set(PRJ_DIR_ "${PROJECT_SOURCE_DIR}")
set(PRJ_INCLUDE_DIRS_ "${PRJ_DIR_}/include;${CMAKE_INSTALL_FULL_INCLUDEDIR}")
set(PRJ_SOURCE_DIR_ "${PRJ_DIR_}/src")
set(PRJ_LIBRARY_DIR_ "${PRJ_DIR_}/lib")
set(PRJ_BINARY_DIR_ "${PRJ_DIR_}/bin")

set(C_SRC_EXT_ c)
set(C_HDR_EXT_ h)
set(CXX_SRC_EXT_ cxx)
set(CXX_HDR_EXT_ hxx)

message(STATUS "[PROJECT] - ${PROJECT_NAME} ${PROJECT_VERSION}")
message(STATUS "\t${PROJECT_DESCRIPTION}")
message(STATUS "Local system library directory: ${CMAKE_INSTALL_FULL_LIBDIR}")
message(STATUS "Local system include directory: ${CMAKE_INSTALL_FULL_INCLUDEDIR}")
message(STATUS "Project root directory: ${PRJ_DIR_}")
message(STATUS "Project include directories: ${PRJ_INCLUDE_DIRS_}")
message(STATUS "Project library directory: ${PRJ_LIBRARY_DIR_}")
message(STATUS "Project source directory: ${PRJ_SOURCE_DIR_}")
message(STATUS "Project binary directory: ${PRJ_BINARY_DIR_}")

find_library(
    XALLOC_LIBRARY_
    xalloc
    PATHS "${CMAKE_INSTALL_FULL_LIBDIR}"
    REQUIRED
)

if(NOT EXISTS ${XALLOC_LIBRARY_})
    message(FATAL_ERROR "Required library xalloc not found!")
endif()

macro(add_program TARGET_ FILE_ LANGUAGE_)
    add_executable(${TARGET_})
    target_sources(${TARGET_} PUBLIC "${PRJ_SOURCE_DIR_}/${FILE_}.${LANGUAGE_}")
    target_include_directories(${TARGET_} SYSTEM BEFORE PUBLIC "${PRJ_INCLUDE_DIRS_}")
    target_link_libraries(${TARGET_} PUBLIC ${XALLOC_LIBRARY_})
    if(${LANGUAGE_} STREQUAL c)
        set_target_properties(${TARGET_} PROPERTIES
            LINKER_LANGUAGE C
            C_STANDARD 11
            RUNTIME_OUTPUT_DIRECTORY ${PRJ_BINARY_DIR_}
            INCLUDE_DIRECTORIES "${PRJ_INCLUDE_DIRS_}"
        )
    elseif(${LANGUAGE_} STREQUAL cxx)
        set_target_properties(${TARGET_} PROPERTIES
            LINKER_LANGUAGE CXX
            CXX_STANDARD 17
            RUNTIME_OUTPUT_DIRECTORY ${PRJ_BINARY_DIR_}
            INCLUDE_DIRECTORIES "${PRJ_INCLUDE_DIRS_}"
        )
    endif()
endmacro()

set(TARGET_TEST_ ${PROJECT_NAME}_test)

add_program(${TARGET_TEST_}1_${C_SRC_EXT_} ${TARGET_TEST_}1 ${C_SRC_EXT_})
#add_program(${TARGET_TEST_}2_${C_SRC_EXT_} ${TARGET_TEST_}2 ${C_SRC_EXT_})
#add_program(${TARGET_TEST_}3_${C_SRC_EXT_} ${TARGET_TEST_}3 ${C_SRC_EXT_})

#add_program(${TARGET_TEST_}1_${CXX_SRC_EXT_} ${TARGET_TEST_}1 ${CXX_SRC_EXT_})
#add_program(${TARGET_TEST_}2_${CXX_SRC_EXT_} ${TARGET_TEST_}2 ${CXX_SRC_EXT_})
#add_program(${TARGET_TEST_}3_${CXX_SRC_EXT_} ${TARGET_TEST_}3 ${CXX_SRC_EXT_})