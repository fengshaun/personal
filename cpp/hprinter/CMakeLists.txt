project (hprinter)

find_package(KDE4 REQUIRED)
include(KDE4Defaults)

include_directories(${KDE4_INCLUDES} ${QT_INCLUDES})
add_definitions(${QT_DEFINITIONS} ${QDBUS_DEFINITIONS} ${KDE4_DEFINITIONS})

set(hprinter_SRCS main.cpp)

kde4_add_executable(hprinter ${hprinter_SRCS})

target_link_libraries(hprinter ${KDE4_KDEUI_LIBS} ${KDE4_SOLID_LIBS})
