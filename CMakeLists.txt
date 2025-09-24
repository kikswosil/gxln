cmake_minimum_required(VERSION 3.10)

project(gxln LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all source files in src/gxln and src/ui
file(GLOB GXLN_SOURCES src/gxln/*.cpp)
file(GLOB UI_SOURCES src/ui/*.cpp)

add_executable(gxln src/main.cpp ${GXLN_SOURCES} ${UI_SOURCES})

# For future GUI support, uncomment and link Qt or wxWidgets
# find_package(Qt5 COMPONENTS Widgets REQUIRED)
# target_link_libraries(gxln Qt5::Widgets)
# find_package(wxWidgets REQUIRED COMPONENTS core base)
# include(${wxWidgets_USE_FILE})
# target_link_libraries(gxln ${wxWidgets_LIBRARIES})
