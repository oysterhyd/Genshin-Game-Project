//
// Created by 72802 on 2024/1/11.
//

#ifndef PROJECT_INCLUDE_COMMON_H_
#define PROJECT_INCLUDE_COMMON_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>

#define HANDLE_ERROR(msg) printf(msg ": %s\n", SDL_GetError()); \
exit(EXIT_FAILURE);

#endif //PROJECT_INCLUDE_COMMON_H_
