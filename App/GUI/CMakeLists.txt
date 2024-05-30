cmake_minimum_required(VERSION 3.27)

project(zappy_gui
        DESCRIPTION "EPITECH | B-YEP-400 | Zappy | GUI"
        LANGUAGES CXX
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

# Libraries
add_subdirectory(lib)

# Main executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/gui.cpp
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/parser.cpp
        ${SRC_DIR}/pluginLoader.cpp
        ${SRC_DIR}/protocol.cpp
        ${SRC_DIR}/Inventory/resource.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE my_lib)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
