cmake_minimum_required(VERSION 3.12)
project(game_client LANGUAGES CXX C)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}../../../build)

add_executable(	${PROJECT_NAME} game_client.cxx )

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

target_link_libraries( ${PROJECT_NAME} 	collision_detector 
										figure
										)