cmake_minimum_required(VERSION 3.10)

project(gxln LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all .cpp files in src and all subdirectories
file(GLOB_RECURSE ALL_SOURCES src/*.cpp)



# Enable fully static linking for MinGW (libgcc, libstdc++, etc.)
if (MINGW)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")
endif()

add_executable(gxln ${ALL_SOURCES})

# Install rules and CPack configuration (must be after add_executable)
install(TARGETS gxln DESTINATION bin)
install(FILES README.md DESTINATION .)
install(FILES LICENSE DESTINATION .)

# Install all files from /libs to /bin in the package/install tree
install(DIRECTORY "${CMAKE_SOURCE_DIR}/libs/"
        DESTINATION bin
        FILES_MATCHING PATTERN "*.*")

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
include(CPack)

# For future GUI support, uncomment and link Qt or wxWidgets
# find_package(Qt5 COMPONENTS Widgets REQUIRED)
# target_link_libraries(gxln Qt5::Widgets)
# find_package(wxWidgets REQUIRED COMPONENTS core base)
# include(${wxWidgets_USE_FILE})
# target_link_libraries(gxln ${wxWidgets_LIBRARIES})
