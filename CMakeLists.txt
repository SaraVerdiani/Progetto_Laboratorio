cmake_minimum_required(VERSION 3.17)
project(Progetto_Laboratorio)

set(CMAKE_CXX_STANDARD 20)

add_executable(Progetto_Laboratorio main.cpp
        fsa.h
        stlastar.h
        Game.cpp
        Game.h
        Map.cpp
        Map.h
        GameTile.cpp
        GameTile.h
        Player.cpp
        Player.h
        MapSearchNode.cpp
        MapSearchNode.h
)


include_directories(headers /usr/include c:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Progetto_Laboratorio ${SFML_LIBRARIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()

add_subdirectory(test)

set(SOURCE_FILES fsa.h
        stlastar.h
        Game.cpp
        Game.h
        Map.cpp
        Map.h
        GameTile.cpp
        GameTile.h
        Player.cpp
        Player.h
        MapSearchNode.cpp
        MapSearchNode.h
)

add_library(core ${SOURCE_FILES})
target_link_libraries(Progetto_Laboratorio core)
