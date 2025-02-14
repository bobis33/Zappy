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

set(SOURCES_CMD_AI
        ${SRC_CMD_DIR}/client/AI/ai.c
        ${SRC_CMD_DIR}/client/AI/cmd_broadcast.c
        ${SRC_CMD_DIR}/client/AI/cmd_connection_nbr.c
        ${SRC_CMD_DIR}/client/AI/cmd_eject.c
        ${SRC_CMD_DIR}/client/AI/cmd_fork.c
        ${SRC_CMD_DIR}/client/AI/cmd_forward.c
        ${SRC_CMD_DIR}/client/AI/cmd_incantation.c
        ${SRC_CMD_DIR}/client/AI/cmd_inventory.c
        ${SRC_CMD_DIR}/client/AI/cmd_left.c
        ${SRC_CMD_DIR}/client/AI/cmd_look.c
        ${SRC_CMD_DIR}/client/AI/cmd_right.c
        ${SRC_CMD_DIR}/client/AI/cmd_set.c
        ${SRC_CMD_DIR}/client/AI/cmd_take.c
        ${SRC_CMD_DIR}/client/AI/rotate_player.c
)

set(SOURCES_CMD_GUI
        ${SRC_CMD_DIR}/client/GUI/gui.c
        ${SRC_CMD_DIR}/client/GUI/cmd_frequency_update.c
        ${SRC_CMD_DIR}/client/GUI/cmd_frequency.c
        ${SRC_CMD_DIR}/client/GUI/cmd_map_size.c
        ${SRC_CMD_DIR}/client/GUI/cmd_map_tile_content.c
        ${SRC_CMD_DIR}/client/GUI/cmd_player_inventory.c
        ${SRC_CMD_DIR}/client/GUI/cmd_player_lvl.c
        ${SRC_CMD_DIR}/client/GUI/cmd_player_pos.c
        ${SRC_CMD_DIR}/client/GUI/cmd_team_names.c
        ${SRC_CMD_DIR}/client/GUI/cmd_tile_content.c
)

set(SOURCES_INPUT
        ${SRC_DIR}/input/server.c
        ${SRC_DIR}/input/client/client.c
        ${SRC_DIR}/input/client/connect.c
        ${SOURCES_CMD_AI}
        ${SOURCES_CMD_GUI}
)

set (SOURCES_GAME
        ${SRC_DIR}/game/clock.c
        ${SRC_DIR}/game/game.c
        ${SRC_DIR}/game/map.c
        ${SRC_DIR}/game/resource.c
        ${SRC_DIR}/game/player.c
        ${SRC_DIR}/game/egg.c
        ${SRC_DIR}/game/update.c
)

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/main.c
        ${SRC_DIR}/parser.c
        ${SRC_DIR}/server.c
        ${SRC_DIR}/bind/bind.c
        ${SRC_DIR}/bind/bind_team.c
        ${SRC_DIR}/tools.c
        ${SRC_DIR}/client_tools.c
        ${SOURCES_GAME}
        ${SOURCES_INPUT}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

target_compile_features(${PROJECT_NAME} PRIVATE c_std_17)
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
