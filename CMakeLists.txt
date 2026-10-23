cmake_minimum_required(VERSION 4.0)
project(PS)

set(CMAKE_CXX_STANDARD 14)

include_directories(Singleton/cpp)

add_executable(PS_Singleton
        Singleton/cpp/Logger.cpp
        Singleton/cpp/Logger.h
        )

add_executable(PS_Facade
        Facade/cpp/HomeCinema.h
        Facade/cpp/HomeCinema.cpp
        Facade/cpp/CinemaSystem.h
)

add_executable(PS_Strategy
        Strategy/cpp/Cart.h
        Strategy/cpp/Cart.cpp
)
add_executable(PS_TemplateMethod
        TemplateMethod/cpp/Beverage.cpp
        TemplateMethod/cpp/Beverage.h)
