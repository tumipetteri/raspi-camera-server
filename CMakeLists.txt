cmake_minimum_required(VERSION 3.14)

project(raspi-camera-server LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS HttpServer REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS SslServer REQUIRED)

add_executable(raspi-camera-server
  main.cpp
  serverapp.cpp serverapp.h
  server.cpp server.h
  inputplugininterface.h
#  plugins/inputplugins.json
  plugins/raspicaminputplugin.cpp
  plugins/raspicaminputplugin.h
)


target_link_libraries(raspi-camera-server Qt5::HttpServer)
target_link_libraries(raspi-camera-server Qt${QT_VERSION_MAJOR}::Core)
