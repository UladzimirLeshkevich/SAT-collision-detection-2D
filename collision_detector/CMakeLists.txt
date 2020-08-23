cmake_minimum_required(VERSION 3.12)
project(collision_detector LANGUAGES CXX C)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}../../../build)

add_library(${PROJECT_NAME} SHARED collision_detector.cxx
                                   collision_detector.hxx
                                   )

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)


