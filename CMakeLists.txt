cmake_minimum_required(VERSION 3.10)

project(KPolynomials
    VERSION 0.0.1
    DESCRIPTION "KPolynomials"
    LANGUAGES CXX
)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(KPoly)

set(source "src")
set(kpoly "kpoly")

target_sources(KPoly
    PRIVATE ${source}/${kpoly}/Application.cpp
)

target_link_libraries(KPoly
    PRIVATE Qt5::Widgets
)
