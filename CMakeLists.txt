cmake_minimum_required(VERSION 3.16)
project(CyberChat VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Enhanced C++17 configuration
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler-specific flags for C++17 support
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")
elseif(MINGW OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()

# Add Network module to Qt components
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        resources.qrc  # Add the resource file here
)

# Create Windows resource file for icon
if(WIN32)
    set(WIN_RESOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/app.rc")
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/app.rc.in" "${WIN_RESOURCE_FILE}" @ONLY)
    list(APPEND PROJECT_SOURCES "${WIN_RESOURCE_FILE}")
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CyberChat
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(CyberChat SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(CyberChat
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link both Widgets and Network modules
target_link_libraries(CyberChat PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)

# Ensure C++17 features are available
target_compile_features(CyberChat PRIVATE cxx_std_17)

# Additional compiler-specific settings for the target
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(CyberChat PRIVATE /Zc:__cplusplus)
endif()

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.CyberChat)
endif()

# Set application icon for different platforms
if(WIN32)
    # For Windows, you can set an icon
    set_target_properties(CyberChat PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
    # Windows icon is handled by app.rc file
endif()

if(APPLE)
    # For macOS, set the bundle icon
    set_target_properties(CyberChat PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_ICON_FILE "logo.png"
    )
    # Copy the icon file to the bundle
    set_source_files_properties("${CMAKE_CURRENT_SOURCE_DIR}/Images/CyberChat.png" PROPERTIES
        MACOSX_PACKAGE_LOCATION "Resources")
    target_sources(CyberChat PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Images/CyberChat.png")
endif()

set_target_properties(CyberChat PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS CyberChat
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CyberChat)
endif()
