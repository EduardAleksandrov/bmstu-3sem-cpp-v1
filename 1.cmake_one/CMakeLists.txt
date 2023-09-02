cmake_minimum_required(VERSION 3.16)

# source interface
# build interface
# install interface

# project name
project(one-project)
# message
message("dir: ${PROJECT_SOURCE_DIR}")

#folder prefix for install
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install CACHE PATH "install prefix" FORCE)

#standart
set(CMAKE_CXX_STANDARD 17)

#compiler flags
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
set(CMAKE_CXX_FLAGS "-Wall") #compiler flags - warnings
set(CMAKE_CXX_FLAGS_DEBUG "-g") # gdb 
set(CMAKE_CXX_FLAGS_RELEASE "-O3") #-02

#adds executable file
add_executable(                          # Создаём цель (исполняемый файл)
    ${PROJECT_NAME}                        # Имя файла
    main.cpp                               # Список файлов исходного кода
)

# add included libraries
find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    target_link_libraries(${PROJECT_NAME} PUBLIC ${MATH_LIBRARY})
endif()

# install folder
install(                                 # Указываем цель и путь установки
    TARGETS ${PROJECT_NAME}                # Путь прибавляется к префиксу
    RUNTIME DESTINATION bin                # bin - binary (путь к исполняемым файлам)
) 

message("CIP = ${CMAKE_INSTALL_PREFIX} (should be /foo/bar/bubba")
message("CBD = ${CMAKE_BINARY_DIR}")


