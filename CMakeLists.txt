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
add_executable(PS_TemplateMethod TemplateMethod/cpp/Beverage.cpp TemplateMethod/cpp/Beverage.h)
add_executable(PS_FactoryMethod
        FactoryMethod/cpp/Transport.cpp
        FactoryMethod/cpp/Transport.h
)
add_executable(PS_Prototype Prototype/cpp/Shape.cpp Prototype/cpp/Shape.h)
add_executable(PS_Command Command/cpp/Command.cpp Command/cpp/Command.h)
add_executable(PS_Adapter Adapter/cpp/PaymentProcessor.cpp Adapter/cpp/PaymentProcessor.h)
