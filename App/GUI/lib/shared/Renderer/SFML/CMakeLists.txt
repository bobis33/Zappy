project(renderer_sfml
        DESCRIPTION "ZAPPY GUI SFML Renderer plugin"
        LANGUAGES CXX
)

set(SRC_DIR src)

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/entryPoint.cpp
        ${SRC_DIR}/SFML.cpp
        ${SRC_DIR}/Client/client.cpp
        ${SRC_DIR}/Client/commands.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR} include)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)