cmake_minimum_required(VERSION 3.10)
project(labirinto CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Adiciona o executável e quais arquivos-fonte o compõem
add_executable(lab
    src/main.cpp
    src/gerador.cpp
    src/resover.cpp
)

# Pasta onde ficam os headers (.hpp)
target_include_directories(lab PRIVATE libs)

target_compile_options(lab PRIVATE -Wall -Wextra)
