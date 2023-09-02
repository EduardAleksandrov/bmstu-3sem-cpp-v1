# Запуск
# conan install path/to/conan/file --output-folder=build --build=missing
# conan install /home/eduard/Projects/iu7/CPP_v1/2.cmake-conan/conanfile-example.txt -of /home/eduard/Projects/iu7/CPP_v1/2.cmake-conan/build-conan --build=missing
# cd build
# source conanbuild.sh  - необязательный элемент
# cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
# cmake --build .
# source deactivate_conanbuild.sh
# ./timer

# vscode .vscode/c_cpp_properties.json    - чтобы vscode не подчеркивал
# {
#     "configurations": [
#         {
#             "name": "Linux",
#             "includePath": [
#                 "${workspaceFolder}/**",
#                 "~/.conan2/p/**"
#             ],
#             "intelliSenseMode": "linux-gcc-x64",
#             "compilerPath": "/usr/bin/g++"
#         }
#     ],
#     "version": 4
# }


cmake_minimum_required(VERSION 3.16)
project(FoundationTimer)
add_definitions("-std=c++17")
message("cl: ${CONAN_LIBS}")

#compiler flags
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release) # для debug не работает
endif()

include(${PROJECT_SOURCE_DIR}/build-conan/conan_toolchain.cmake)
find_package(Poco)



add_executable(timer timer.cpp)
target_link_libraries(timer Poco::Poco)
