cmake_minimum_required(VERSION 3.9)
project(fdf)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenGL -framework AppKit")

set(SOURCE_FILES main.c parser.c part.c)

include_directories(/usr/local/include)

add_executable(fdf ${SOURCE_FILES})

target_link_libraries(fdf ${CMAKE_SOURCE_DIR}/libft/libft.a)
