project(kcontact)

cmake_minimum_required(VERSION 2.6)

find_package(KDE4 REQUIRED)
find_package(Qt4 REQUIRED)
include(KDE4Defaults)
include(${QT_USE_FILE})

add_subdirectory(src)
