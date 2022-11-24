cmake_minimum_required(VERSION 3.21)
project(Classes)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Classes
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
