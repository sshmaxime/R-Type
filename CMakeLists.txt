cmake_minimum_required(VERSION 3.9)
project(R_Type)

include_directories("Common/Network/Request")

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE COMMON Common/*.cpp)

file(GLOB_RECURSE SERVER_FILES Server/*cpp)
file(GLOB_RECURSE CLIENT_FILES Client/*cpp)

add_executable(server
        ${COMMON}
        ${SERVER_FILES})

add_executable(client
        ${COMMON}
        ${CLIENT_FILES})
