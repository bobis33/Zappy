project(renderer_sfml
        DESCRIPTION "ZAPPY GUI SFML Renderer plugin"
        LANGUAGES CXX
)

set(SRC_DIR src)

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/entryPoint.cpp
        ${SRC_DIR}/SFML.cpp
        ${SRC_DIR}/event.cpp
        ${SRC_DIR}/Client/connection.cpp
        ${SRC_DIR}/Client/command.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR} include)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network my_lib)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)