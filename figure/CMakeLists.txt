cmake_minimum_required(VERSION 3.12)
project(figure LANGUAGES CXX C)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}../../../build)

add_library(${PROJECT_NAME} SHARED figure.cxx
                                   figure.hxx
                                   )

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)


