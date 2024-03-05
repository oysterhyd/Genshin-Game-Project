cmake_minimum_required(VERSION 3.27)
project(project C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
add_subdirectory(src)

target_link_libraries(project PRIVATE
        mingw32
        SDL2main
        SDL2
        SDL2_image
        SDL2_mixer
        SDL2_ttf
)