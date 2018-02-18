cmake_minimum_required(VERSION 3.9)
project(R_Type)

include_directories("Common/Network/Request")

set(CMAKE_CXX_STANDARD 17)
if(WIN32)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else()
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -Wl,--no-as-needed -ldl")
endif()

file(GLOB_RECURSE COMMON Common/*.cpp)

file(GLOB_RECURSE SERVER_FILES Server/*.cpp)
file(GLOB_RECURSE CLIENT_FILES Client/*.cpp)

file(GLOB_RECURSE GAME_FILES_BEHAVIOURS Game/Behaviours/*.cpp)
file(GLOB_RECURSE GAME_FILES_CORE Game/Core/*.cpp)
file(GLOB_RECURSE GAME_FILES_ENTITY Game/Entity/*.cpp)
file(GLOB_RECURSE GAME_FILES_GAMEENGINE Game/GameEngine/*.cpp)
file(GLOB_RECURSE GAME_FILES_LEVEL Game/Level/*.cpp)
file(GLOB_RECURSE GAME_FILES _EVENTS Game/GameEngine/Events/*.cpp)


add_executable(server
        ${COMMON}
        ${GAME_FILES_BEHAVIOURS}
        ${GAME_FILES_CORE}
        ${GAME_FILES_ENTITY}
        ${GAME_FILES_GAMEENGINE}
        ${GAME_FILES_LEVEL}
        ${GAME_FILES_EVENTS}
        ${SERVER_FILES}
        Client/Global/CGlobal.cpp
        )

add_executable(client
        ${COMMON}
        ${GAME_FILES_BEHAVIOURS}
        ${GAME_FILES_CORE}
        ${GAME_FILES_ENTITY}
        ${GAME_FILES_GAMEENGINE}
        ${GAME_FILES_LEVEL}
        ${GAME_FILES_EVENTS}
        ${CLIENT_FILES})

target_link_libraries(server ${Boost_LIBRARIES})
target_link_libraries(client ${Boost_LIBRARIES})


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
    target_link_libraries(client ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    target_link_libraries(server ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

#Detect and add boost
if(NOT DEFINED     BOOST_ROOT  AND
        NOT DEFINED ENV{BOOST_ROOT})
    if(WIN32)
        set(BOOST_ROOT "C:/dev/libs/BOOST")
        set(Boost_USE_MULTITHREADED ON)
        set(Boost_USE_STATIC_RUNTIME OFF)
        set(Boost_USE_STATIC_LIBS OFF)
        add_definitions( -DBOOST_ALL_NO_LIB )
        add_definitions( -DBOOST_ALL_DYN_LINK )
    endif()
endif()
find_package(Boost 1.58.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(client ${Boost_LIBRARIES})
    target_link_libraries(server ${Boost_LIBRARIES})
endif()