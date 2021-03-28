cmake_minimum_required(VERSION 3.5)
project(my-render)
# set(SOURCES src/tgaimage.cc src/main.cc)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURCES)
aux_source_directory(${PROJECT_SOURCE_DIR}/lib/shaders/src SHADERS)

# static link to shaders lib
add_library(shader_library STATIC ${SHADERS})
target_include_directories(shader_library PUBLIC ${PROJECT_SOURCE_DIR}/lib/shaders/include)
target_include_directories(shader_library PUBLIC ${PROJECT_SOURCE_DIR}/include)


add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_options(my-render PRIVATE -g -O2 -std=c++14)
target_include_directories(my-render PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(my-render PRIVATE ${PROJECT_SOURCE_DIR}/lib/shaders/include)

target_link_libraries(my-render PRIVATE shader_library)