set(CMAKE_C_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/plugins/)

set(SRC_DIR
        ${CMAKE_SOURCE_DIR}/src/
)

set(SRC_CMD_DIR
        ${SRC_DIR}/input
)

SET(INCLUDE_DIR
        ${CMAKE_SOURCE_DIR}/include/
)

set(WARNING_FLAGS
        -Wall
        -Wextra
        -Wmisleading-indentation
        -Wnull-dereference
        -Wpedantic
        -Wshadow
        -Wsign-conversion
        -Wunused
        -Wcast-align
        -Wno-padded
        -Wconversion
        -Wformat
        -Winit-self
        -Wmissing-include-dirs
        -Wredundant-decls
        -Wswitch-default
        -Wundef
)