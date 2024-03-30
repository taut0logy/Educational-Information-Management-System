cmake_minimum_required(VERSION 3.0.0)
project(Educational-Info-management-System VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Educational-Info-management-System main.cpp Course.cpp Course.hpp Teacher.cpp Teacher.hpp Utility.hpp Utility.cpp User.cpp User.hpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
