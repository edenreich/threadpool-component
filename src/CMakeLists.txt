
cmake_minimum_required(VERSION 3.12)

project(threadpool
VERSION 1.0.0
LANGUAGES C CXX
DESCRIPTION "An easy to use component for creating a thread pool."
)

set(BUILD_SHARED_LIBS OFF)
set(DISTRIBUTE_DIR ${CMAKE_BINARY_DIR}/dist)

set(SOURCES_CXX_FILES_THREADPOOL
    pool.cpp
    pool_factory.cpp
)

add_library(${PROJECT_NAME}
    ${SOURCES_CXX_FILES_THREADPOOL}
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/dist)
file(COPY include DESTINATION ${CMAKE_BINARY_DIR}/dist)

install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${DISTRIBUTE_DIR}/bin
    LIBRARY DESTINATION ${DISTRIBUTE_DIR}/lib
    ARCHIVE DESTINATION ${DISTRIBUTE_DIR}/lib
)

message("[INFO] - Distribution dir: " ${DISTRIBUTE_DIR})

