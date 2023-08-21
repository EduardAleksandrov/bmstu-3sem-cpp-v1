cmake_minimum_required(VERSION 3.16)

project(one-project)

message("dir: ${PROJECT_SOURCE_DIR}")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install CACHE PATH "install prefix" FORCE)

set(CMAKE_CXX_STANDARD 17)

add_executable(                          # Создаём цель (исполняемый файл)
    ${PROJECT_NAME}                        # Имя файла
    main.cpp                               # Список файлов исходного кода
)

install(                                 # Указываем цель и путь установки
    TARGETS ${PROJECT_NAME}                # Путь прибавляется к префиксу
    RUNTIME DESTINATION bin                # bin - binary (путь к исполняемым файлам)
) 

message("CIP = ${CMAKE_INSTALL_PREFIX} (should be /foo/bar/bubba")

