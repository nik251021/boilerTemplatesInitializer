cmake_minimum_required(VERSION 3.10.0)
project(%^%ProjectName%^% VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED true)

file(GLOB sources src/*.cpp)
file(GLOB headers include/*.hpp)

include_directories(include)

add_executable(%^%ProjectName%^% ${sources} ${headers})