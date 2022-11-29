cmake_minimum_required(VERSION 3.20)
project(MasomoAssignment)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
add_subdirectory(unit_tests)

add_executable(MasomoAssignment
        AchievementDefinition.h
        DataContainer.cpp
        DataContainer.h
        GameLoop.cpp
        GameLoop.h
        main.cpp
        PlayerDataHandler.h
        Scene.h
        SimpleGameTypes.h
        Tap.h
        UIElement.h)
target_link_libraries(MasomoAssignment ${CURSES_LIBRARIES})
