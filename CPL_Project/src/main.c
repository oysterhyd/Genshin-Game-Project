#include <main.h>

#undef main

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, NULL);

  init_app();
  SDL_Window *window = SDL_CreateWindow("Genshin TCG Start!", 100, 50, 1200, 800, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!startup(renderer)) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    atexit(&quit_app);
    return 0;
  }
  printf("原神，启动！\n");
  done:if(!select(renderer)) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    atexit(&quit_app);
    return 0;
  }
  printf("游戏开始！\n");
  if(!Game(renderer)) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    atexit(&quit_app);
    return 0;
  }
  if(ISWIN()) {
    SDL_RenderClear(renderer);
    WIN(renderer);
    SDL_RenderPresent(renderer);
    SDL_Event event;
    while (1) {
      SDL_PollEvent(&event);
      if(event.type == SDL_QUIT) {
        break;
      }
    }
  } else {
    SDL_RenderClear(renderer);
    LOSE(renderer);
    SDL_RenderPresent(renderer);
    SDL_Event event;
    while (1) {
      SDL_PollEvent(&event);
      if(event.type == SDL_QUIT) {
        break;
      } else if(event.type == SDL_MOUSEBUTTONDOWN && mousedownreturn(event, renderer)) {
        goto done;
      }
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  atexit(&quit_app);
  return 0;
}
static void init_app() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
    HANDLE_ERROR("Init SDL")
  }
  if (!IMG_Init(IMG_INIT_JPG)) {
    HANDLE_ERROR("Init IMG")
  }
  if (!Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG)) {
    HANDLE_ERROR("Init Mixer")
  }
  if (TTF_Init() == -1) {
    HANDLE_ERROR("Init TTF")
  }
}
static void quit_app() {
  SDL_Quit();
  IMG_Quit();
  Mix_Quit();
  TTF_Quit();
}
static bool mousedownreturn(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/restart.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 1000, .y = 700, .w = surface->w, .h = surface->h};

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

  if (event.button.x >= rect.x && event.button.x <= rect.x + rect.w
      && event.button.y >= rect.y && event.button.y <= rect.y + rect.h) {
    return true;
  }
  return false;
}