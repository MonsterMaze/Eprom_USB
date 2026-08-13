cmake_minimum_required(VERSION 3.16)

project(Eprom_USB LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Default debug build." FORCE)

# Archivos comunes
set(COMMON_CPP_FILES 
    src/eprom.cpp
    src/ArduinoIO.cpp
)

# ==================== QT5 ====================
option(COMPILE_QT_APPLICATION "Compilar la aplicación Qt" ON)

if(COMPILE_QT_APPLICATION)
    find_package(Qt5 COMPONENTS Core Widgets SerialPort REQUIRED)
    
    set(QT_APPLICATION_NAME "EpQt")
    
    SET(CMAKE_AUTOMOC ON)
    
    add_executable(${QT_APPLICATION_NAME} 
        main.cpp 
        src/QtGui.cpp 
        ${COMMON_CPP_FILES}
    )
    
    target_link_libraries(${QT_APPLICATION_NAME} 
        Qt5::Widgets 
        Qt5::SerialPort
    )
    
    set_target_properties(${QT_APPLICATION_NAME} PROPERTIES 
        COMPILE_DEFINITIONS "QT_APPLICATION;APP_NAME=${QT_APPLICATION_NAME}"
    )
    
    install(TARGETS ${QT_APPLICATION_NAME} RUNTIME DESTINATION bin)
endif()
