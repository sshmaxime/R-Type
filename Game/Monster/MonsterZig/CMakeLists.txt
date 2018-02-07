cmake_minimum_required(VERSION 3.9)
project(MonsterZig)


set(CMAKE_CXX_STANDARD 17)

include_directories(..)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)
if (WIN32)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ldl -Wall")
endif()
include_directories("${PROJECT_BINARY_DIR}")

add_library(MonsterZig SHARED
        MonsterZig.cpp
        ../../../Game/Behaviours/MonsterIA.h)

# Detect and add SFML
if(NOT DEFINED     SFML_ROOT  AND
        NOT DEFINED ENV{SFML_ROOT})
    if(WIN32)
        set(SFML_ROOT "C:/dev/libs/SFML")
    endif()
endif()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()