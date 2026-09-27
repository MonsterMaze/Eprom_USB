cmake_minimum_required(VERSION 3.16)

project(Eprom_USB_v2 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Default debug build." FORCE)

set(GETTEXT_ROOT "C:/gettext")
include_directories("${GETTEXT_ROOT}/include")
link_directories("${GETTEXT_ROOT}/lib")

# find_library(LIBINTL_LIBRARY NAMES intl libintl PATHS "${GETTEXT_ROOT}/lib")
# find_library(LIBICONV_LIBRARY NAMES iconv libiconv PATHS "${GETTEXT_ROOT}/lib")
# if(NOT LIBINTL_LIBRARY)
#    set(LIBINTL_LIBRARY "${GETTEXT_ROOT}/lib/libintl.dll.a")
# endif()
# if(NOT LIBICONV_LIBRARY)
#    set(LIBICONV_LIBRARY "${GETTEXT_ROOT}/lib/libiconv.dll.a")
# endif()

add_compile_definitions(__USE_MINGW_ANSI_STDIO=1)

# Archivos comunes
set(COMMON_CPP_FILES 
    src/eprom.cpp
    src/ArduinoIO.cpp
)

# ==================== QT5 ====================
option(COMPILE_QT_APPLICATION "Compilar la aplicacion qt" ON)

if(COMPILE_QT_APPLICATION)
    # Le indicamos a CMake la ruta exacta de tu instalación de Qt5
    set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.14.2/5.14.2/mingw73_64")

    find_package(Qt5 COMPONENTS Core Widgets SerialPort REQUIRED)
    
    set(QT_APPLICATION_NAME "Eprom_USB_v2")
    
    SET(CMAKE_AUTOMOC ON)
    
    add_executable(${QT_APPLICATION_NAME} WIN32
        main.cpp 
        src/QtGui.cpp 
        ${COMMON_CPP_FILES}
    )
    
    target_link_libraries(${QT_APPLICATION_NAME} 
        Qt5::Widgets 
        Qt5::SerialPort
 #       "${LIBINTL_LIBRARY}"
 #       "${LIBICONV_LIBRARY}"
#        intl
        iconv
    )
    
    set_target_properties(${QT_APPLICATION_NAME} PROPERTIES 
        COMPILE_DEFINITIONS "QT_APPLICATION;APP_NAME=${QT_APPLICATION_NAME}"
    )
    
    install(TARGETS ${QT_APPLICATION_NAME} RUNTIME DESTINATION bin)
endif()
