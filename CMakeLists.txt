CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(DSA1-Savegame-Editor)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
QT4_WRAP_CPP(main_headers_moc src/mainwindow.h)
FILE(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp
                  ${CMAKE_SOURCE_DIR}/src/*.h)

ADD_EXECUTABLE(main ${SOURCES} ${main_headers_moc})
TARGET_LINK_LIBRARIES(main ${QT_LIBRARIES})
