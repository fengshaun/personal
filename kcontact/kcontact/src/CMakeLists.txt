include_directories(${KDE4_INCLUDES})
include_directories(${QT_QTSQL_INCLUDE_DIR})

set(QT_USE_QTSQL 1)

set(kcontact_SRCS
	main.cpp 
	mainwindow.cpp
	mainwidget.cpp
	contactdialog.cpp
	contactdatabase.cpp)

kde4_add_executable(kcontact ${kcontact_SRCS})
target_link_libraries(kcontact ${KDE4_KDEUI_LIBS}
							   ${QT_LIBRARIES}
							   ${QT_QTSQL_LIBRARY})

install(TARGETS kcontact ${INSTALL_TARGETS_DEFAULT_ARGS})