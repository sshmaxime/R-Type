cmake_minimum_required(VERSION 3.9)
project(R_Type)

include_directories("Common/Network/Request")

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

file(GLOB_RECURSE COMMON Common/*.cpp)

file(GLOB_RECURSE SERVER_FILES Server/*cpp)
file(GLOB_RECURSE CLIENT_FILES Client/*cpp)


find_package(Boost 1.58.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()


add_executable(server
        ${COMMON}
        ${SERVER_FILES})

add_executable(client
        ${COMMON}
        ${CLIENT_FILES} Server/Global/Global.cpp Server/Global/Global.h)

target_link_libraries(server ${Boost_LIBRARIES})
target_link_libraries(client ${Boost_LIBRARIES})