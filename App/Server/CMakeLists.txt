cmake_minimum_required(VERSION 3.27)

project(zappy_server
        DESCRIPTION "EPITECH | B-YEP-400 | Zappy | Server"
        LANGUAGES C
        VERSION 0.1.0
)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

option(USE_CLANG_TIDY "Use Clang-tidy" OFF)

include(${CMAKE_MODULE_PATH}/myVariables.cmake)

# Build Doxygen documentation
include(${CMAKE_MODULE_PATH}/MakeDoc.cmake)

# Clang format
if (USE_CLANG_TIDY)
    include(${CMAKE_MODULE_PATH}/ClangTidy.cmake)
endif()

# Main executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/main.c
        ${SRC_DIR}/parser.c
        ${SRC_DIR}/server.c
        ${SRC_DIR}/bind/bind.c
        ${SRC_DIR}/bind/bind_team.c
        ${SRC_DIR}/tools.c
        ${SRC_DIR}/client_tools.c
        ${SRC_DIR}/input/client.c
        ${SRC_DIR}/input/server.c
        ${SRC_DIR}/input/cmd_server.c
        ${SRC_DIR}/input/cmd_client.c
        ${SRC_DIR}/game/game.c
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

target_compile_features(${PROJECT_NAME} PRIVATE c_std_17)
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
