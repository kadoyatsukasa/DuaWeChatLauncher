cmake_minimum_required(VERSION 3.21)
project(DuaWeChatLauncher)

set(QT_DIR $ENV{QTROOT})
set(QTVERSION 6)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_PREFIX_PATH "C:\\Path\\6.6.0\\mingw_64\\lib\\cmake")
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt::Core Qt::Gui Qt::Widgets)

message("QT_DIR: $ENV{QTROOT}")

add_executable(${PROJECT_NAME} main.cpp ui/launcher.cpp ui/launcher.h ui/launcher.ui)
find_package(Qt${QTVERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} )