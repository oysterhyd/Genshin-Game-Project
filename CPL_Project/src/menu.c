//
// Created by 72802 on 2024/1/11.
//
#include <menu.h>

bool startup(SDL_Renderer *renderer) {
  SDL_Surface *surface_background_1 = IMG_Load("res/img/2.jpg");
  SDL_Surface *surface_background_2 = IMG_Load("res/img/Genshin.jpg");
  TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 24);
  SDL_Color font_color = {135, 206, 235, 0xff};
  SDL_Surface *surface_font = TTF_RenderText_Blended(font, "Click to Start", font_color);
  SDL_Texture *texture_background_1 = SDL_CreateTextureFromSurface(renderer, surface_background_1);
  SDL_Texture *texture_background_2 = SDL_CreateTextureFromSurface(renderer, surface_background_2);
  SDL_Texture *texture_font = SDL_CreateTextureFromSurface(renderer, surface_font);
  Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048);
  Mix_Music *bgm = Mix_LoadMUS("res/bgm/1.mp3");
  Mix_PlayMusic(bgm, 0);
  SDL_Rect viewport = {.x = 525, .y = 700, .w = surface_font->w, .h = surface_font->h};

  SDL_RenderCopy(renderer, texture_background_1, NULL, NULL);
  //渲染第一张背景
  SDL_FreeSurface(surface_background_1);
  SDL_DestroyTexture(texture_background_1);
  //清除第一张图片的内存
  SDL_RenderCopy(renderer, texture_font, NULL, &viewport);
  title(renderer);
  SDL_RenderPresent(renderer);
  //打印开始文字
  SDL_FreeSurface(surface_font);
  SDL_DestroyTexture(texture_font);
  SDL_RenderClear(renderer);
  //清除字体的内存

  bool running = true;
  while (running) {
    SDL_Event *event;
    while (SDL_PollEvent(event)) {
      if (event->type == SDL_QUIT) {
        return false;
      } else if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_LEFT) {
        mousePressCallback(renderer, texture_background_2);
        running = false;
      }
    }
  }//原神，启动！
  SDL_FreeSurface(surface_background_2);
  SDL_DestroyTexture(texture_background_2);
  //清除第二张图片的内存

  Mix_FreeMusic(bgm);
  Mix_CloseAudio();
  TTF_CloseFont(font);
  return true;
}

static void mousePressCallback(SDL_Renderer *renderer, SDL_Texture *texture) {
  for (int i = 50; i <= 255; ++i) {
    SDL_SetTextureAlphaMod(texture, i);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(15);
  }
}

static void title(SDL_Renderer *renderer){
  TTF_Font *font = TTF_OpenFont("res/font/YeZiGongChangAoYeHei-2.ttf",64);
  SDL_Color font_color = {255, 69, 0, 0xff};
  SDL_Surface *surface_font = TTF_RenderUTF8_Solid(font, "七圣召唤模拟器", font_color);
  SDL_Texture *texture_font = SDL_CreateTextureFromSurface(renderer, surface_font);
  SDL_Rect viewport = {.x = 400, .y = 200, .w = surface_font->w, .h = surface_font->h};
  SDL_RenderCopy(renderer, texture_font, NULL, &viewport);

  SDL_FreeSurface(surface_font);
  SDL_DestroyTexture(texture_font);
  TTF_CloseFont(font);
}