cmake_minimum_required(VERSION 3.9.1)
# add_executable(executable Parser.cpp ProcessManager.cpp Process.cpp)
add_library(diri SHARED Parser.cpp ProcessManager.cpp)