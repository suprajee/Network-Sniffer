cmake_minimum_required(VERSION 3.16)

project(Netsnif VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required Qt packages (Charts included for both Qt5 and Qt6)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Charts)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets Charts)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    packetsniffer.cpp
    packetsniffer.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Netsnif
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Netsnif SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Netsnif
            ${PROJECT_SOURCES}
        )
    endif()
endif()

include_directories("C:/npcap-sdk/Include")
link_directories("C:/npcap-sdk/Lib/x64")

# Link Qt and Npcap libraries
target_link_libraries(Netsnif PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Charts
    "C:/npcap-sdk/Lib/x64/wpcap.lib"
        "C:/npcap-sdk/Lib/x64/Packet.lib"
    ws2_32
    iphlpapi
)

# App properties (for Windows/macOS bundling)
set_target_properties(Netsnif PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Install instructions
include(GNUInstallDirs)
install(TARGETS Netsnif
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Qt6: finalize
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Netsnif)
endif()
