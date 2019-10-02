cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(web_server)

include_directories(
    ${CMAKE_BINARY_DIR}/dist/include
)

set(SOURCES_CXX_FILES
    main.cpp
)

add_executable(${PROJECT_NAME}
    ${SOURCES_CXX_FILES}
)

find_package(Threads REQUIRED)

target_link_libraries(${PROJECT_NAME} threadpool Threads::Threads)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
