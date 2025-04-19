# Минимальная версия CMake
cmake_minimum_required(VERSION 3.19)

# Название проекта
project(leetcode)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Явное указание путей к компиляторам
set(CMAKE_C_COMPILER "C:/MinGW/bin/mingw32-gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/mingw32-g++.exe")

# Добавляем исполняемый файл
add_executable(main
    main.c
)
