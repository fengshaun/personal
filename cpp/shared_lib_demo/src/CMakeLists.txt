include_directories(${shared_lib_demo_SOURCE_DIR}/libs)
add_executable(demo main.cpp)
target_link_libraries(demo pluginmanager)