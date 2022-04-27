cmake_minimum_required(VERSION 3.20)

project(GOL_SERV_CM LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(tests)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets)

add_executable(GOL_SERV_CM
  #main.cpp
  ifield.h
  field.h
  field.cpp
  iencoder.h
  encoder.h
  encoder.cpp
  icycle.h
  cycle.h
  cycle.cpp
  irules.h
  rules.h
  rules.cpp
  server.h
  server.cpp
  igame.h
  game.h
  game.cpp
  tests/field_test.h
  tests/field_test.cpp
  tests/encoder_test.h
  tests/encoder_test.cpp
  tests/cycle_test.h
  tests/cycle_test.cpp
  tests/rules_test.h
  tests/rules_test.cpp
  tests/server_test.h
  tests/server_test.cpp
  tests/game_test.h
  tests/game_test.cpp
)

target_link_libraries(GOL_SERV_CM Qt${QT_VERSION_MAJOR}::Core Qt6::Network gtest gtest_main)
