cmake_minimum_required(VERSION 3.0)

project(berdichevskaya_a_g)

set (CMAKE_PREFIX_PATH "C:\\Qt\\Qt5\\5.9.2\\msvc2015_64")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")
include(cmake/build_prefix.cmake)

qt5_add_resources(QRCS coursework/res.qrc)

set(berdichevskaya_a_g_SRCS
    coursework/cells.cpp
    coursework/field_size.cpp
    coursework/game_state.cpp
    coursework/mainwindow.cpp
    coursework/mainwindow.ui
    coursework/main.cpp
    ${QRCS}
)

add_executable(${PROJECT_NAME} ${berdichevskaya_a_g_SRCS})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
