cmake_minimum_required(VERSION 3.16)

# source interface
# build interface
# install interface

project(one-project)

message("dir: ${PROJECT_SOURCE_DIR}")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install CACHE PATH "install prefix" FORCE)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
set(CMAKE_CXX_FLAGS "-Wall") #compiler flags - warnings
set(CMAKE_CXX_FLAGS_DEBUG "-g") # gdb 
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(                          # Создаём цель (исполняемый файл)
    ${PROJECT_NAME}                        # Имя файла
    main.cpp                               # Список файлов исходного кода
)

find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    target_link_libraries(${PROJECT_NAME} PUBLIC ${MATH_LIBRARY})
endif()

install(                                 # Указываем цель и путь установки
    TARGETS ${PROJECT_NAME}                # Путь прибавляется к префиксу
    RUNTIME DESTINATION bin                # bin - binary (путь к исполняемым файлам)
) 

message("CIP = ${CMAKE_INSTALL_PREFIX} (should be /foo/bar/bubba")

