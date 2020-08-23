cmake_minimum_required(VERSION 3.12)
project(SAT_collision_2d LANGUAGES CXX C)

add_subdirectory(collision_detector)
add_subdirectory(game_client)
add_subdirectory(figure)

file(GLOB resources "coordinates_files/*")

file(COPY ${resources} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../build/coordinates_files)
