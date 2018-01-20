cmake_minimum_required(VERSION 3.9)
project(RessourceManager)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)
include_directories("${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 17)

add_executable(RessourceManager
        IAudio.hpp
        IFont.hpp
        ITexture.hpp
        main.cpp
        RessourceManager.cpp
        RessourceManager.hpp
        sfmlAudio.cpp
        sfmlAudio.hpp
        sfmlFont.cpp
        sfmlFont.hpp
        sfmlTexture.cpp
        sfmlTexture.hpp)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(RessourceManager ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()