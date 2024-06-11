cmake_minimum_required(VERSION 3.27)
set(PROJECT_NAME test)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories("/opt/homebrew/Cellar/qt/6.7.0_1")
include_directories("/opt/homebrew/Cellar/moc/2.5.2_8")

# По идее, тебе строки, которые я удалил не должны пригодиться,
# но если вдруг Qt потеряется - оставь include_directories("/opt/homebrew/Cellar/qt/6.7.0_1")

find_package(Qt6 COMPONENTS Core Gui Widgets Charts REQUIRED)
add_executable(${PROJECT_NAME} main.cpp mainwindow.cpp)

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Gui Qt6::Charts)
