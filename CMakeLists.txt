CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

project(runner
    VERSION 0.1.0.0
    LANGUAGES C
    DESCRIPTION "Baby Platformer"
)

set(CMAKE_C_STANDARD 11)

# Setting parameters for raylib
# Don't build the raylib examples or games
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) 
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) 

add_subdirectory(libs/raylib)

set(CMAKE_BINARY_DIR
    ${CMAKE_SOURCE_DIR}/build
)

set(EXECUTABLE_OUTPUT_PATH
    ${CMAKE_SOURCE_DIR}/bin
)

set(LIBRARY_OUTPUT_PATH
    ${CMAKE_SOURCE_DIR}/bin
)

include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${CMAKE_BINARY_DIR})

file(GLOB_RECURSE RUNNER_SRC
    "${PROJECT_SOURCE_DIR}/include/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.c"
)

add_executable(${PROJECT_NAME} ${RUNNER_SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_compile_definitions(
    ${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/"
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)