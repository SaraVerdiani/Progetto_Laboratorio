cmake_minimum_required(VERSION 3.5)

set(CXX_STANDARD 11)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp PlayerTest.cpp
        PlayerFixture.cpp
        GameTest.cpp
        GameFixture.cpp
        GameTileTest.cpp
        GameTileFixture.cpp
        MapTest.cpp
        MapFixture.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})



target_link_libraries(runAllTests gtest gtest_main core ${SFML_LIBRARIES})







