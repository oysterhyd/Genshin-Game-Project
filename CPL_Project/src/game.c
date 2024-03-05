//
// Created by 72802 on 2024/1/11.
//
#include <game.h>

bool select(SDL_Renderer *renderer) {
  SDL_RenderClear(renderer);
  Basicbackground_select(renderer);
  //渲染基本界面
  SDL_RenderPresent(renderer);
  //进入选牌画面

  bool running = true;
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        return false;
      } else if (event.type == SDL_MOUSEBUTTONDOWN && mousedownview_1(event, renderer)) {
        SDL_RenderClear(renderer);
        Basicbackground_select(renderer);
        jineng_1(renderer);

        SDL_RenderPresent(renderer);
      } else if (event.type == SDL_MOUSEBUTTONDOWN && mousedownview_2(event, renderer)) {
        SDL_RenderClear(renderer);
        Basicbackground_select(renderer);
        jineng_2(renderer);

        SDL_RenderPresent(renderer);
      } else if (event.type == SDL_MOUSEBUTTONDOWN && mousedownview_3(event, renderer)) {
        SDL_RenderClear(renderer);
        Basicbackground_select(renderer);
        jineng_3(renderer);

        SDL_RenderPresent(renderer);
      } else if (event.type == SDL_MOUSEBUTTONDOWN && mousedownstart(event, renderer)) {
        running = false;
      }
    }
  }
  return true;
}

bool Game(SDL_Renderer *renderer) {
  SDL_RenderClear(renderer);
  blood_1 = 10;
  blood_2 = 10;
  blood_3 = 10;
  blood_enermy = 30;
  energe_1 = 0;
  energe_2 = 0;
  energe_3 = 0;
  figure = 1;
  is_change = false;
  is_move_1 = false;
  is_move_2 = false;
  is_move_3 = false;
  is_fire = false;
  is_ice = false;
  is_defence = false;
  zhaohuan_time = 0;
  srand((unsigned int) time(NULL));
  int random_num = rand() % 3 + 3;
  white = random_num;
  black = 10 - white;
  xingdong = 3;
  Basicbackground_game(renderer);
  SDL_RenderPresent(renderer);

  bool running = true;
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        printf("退出游戏\n");
        return false;
      } else if (blood_enermy == 0) {
        printf("你赢了！！！\n");
        is_win = true;
        running = false;
      } else if (blood_1 == 0 && blood_2 == 0 && blood_3 == 0) {
        printf("连这么简单的七圣召唤都赢不了，哥哥可真是一条杂鱼呢\n");
        running = false;
        is_win = false;
      } else if ((figure == 1 && blood_1 == 0) || (figure == 2 && blood_2 == 0) || (figure == 3 && blood_3 == 0)) {
        die(event, renderer);
        SDL_RenderClear(renderer);
        Basicbackground_game(renderer);
        SDL_RenderPresent(renderer);
      } else if (event.type == SDL_MOUSEBUTTONDOWN && mousedownend(event, renderer)) {
        printf("我方宣布回合结束\n");
        moveenermy_end(renderer);
        printf("回合结束\n");
        SDL_RenderClear(renderer);
        zhaohuanwuattach();
        Basicbackground_game(renderer);
        weilefengzhuang(renderer);
        if (blood_enermy == 0) {
          printf("你赢了！！！\n");
          is_win = true;
          return true;
        }
        SDL_RenderClear(renderer);
        roundend(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        SDL_RenderClear(renderer);
        srand((unsigned int) time(NULL));
        int num = rand() % 3 + 3;
        white = num;
        black = 10 - white;
        xingdong = 3;
        Basicbackground_game(renderer);
        SDL_RenderPresent(renderer);
      } else if (event.type == SDL_MOUSEBUTTONDOWN && mousedownchange(event, renderer) && black > 0) {
        change_select();
      } else if (event.type == SDL_MOUSEBUTTONDOWN && figure != 1 && mousedownfigure_1(event, renderer) && is_change
          && blood_1 > 0) {
        printf("出战角色切换为凯亚\n");
        figure = 1;
        is_change = false;
        black--;
        SDL_RenderClear(renderer);
        Basicbackground_game(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        SDL_RenderClear(renderer);
        moveenermy(renderer);
      } else if (event.type == SDL_MOUSEBUTTONDOWN && figure != 2 && mousedownfigure_2(event, renderer) && is_change
          && blood_2 > 0) {
        printf("出战角色切换为迪卢克\n");
        figure = 2;
        is_change = false;
        black--;
        SDL_RenderClear(renderer);
        Basicbackground_game(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        SDL_RenderClear(renderer);
        moveenermy(renderer);
      } else if (event.type == SDL_MOUSEBUTTONDOWN && figure != 3 && mousedownfigure_3(event, renderer) && is_change
          && blood_3 > 0) {
        printf("出战角色切换为神里凌华（我是神里凌华的狗！）\n");
        figure = 3;
        is_change = false;
        black--;
        SDL_RenderClear(renderer);
        Basicbackground_game(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        SDL_RenderClear(renderer);
        moveenermy(renderer);
      } else if (event.type == SDL_MOUSEBUTTONDOWN && mousedownmove_1(event, renderer) && black >= 2 && white >= 1
          && !is_change && !is_move_2 && !is_move_3) {
        move_select_1();
      } else if (event.type == SDL_MOUSEBUTTONDOWN && mousedownmove_2(event, renderer) && black >= 1 && white >= 2
          && !is_change && !is_move_1 && !is_move_3) {
        move_select_2();
      } else if (event.type == SDL_MOUSEBUTTONDOWN && mousedownmove_3(event, renderer) && white >= 3 && !is_change
          && !is_move_1 && !is_move_2) {
        move_select_3();
      } else if (event.type == SDL_MOUSEBUTTONDOWN && mousedownenermy(event, renderer) && !is_change && is_move_1
          && black >= 2 && white >= 1) {
        SDL_RenderClear(renderer);
        Move(renderer);
        SDL_Delay(1000);
        SDL_RenderClear(renderer);
        moveenermy(renderer);
      }else if (event.type == SDL_MOUSEBUTTONDOWN && mousedownenermy(event, renderer) && !is_change && is_move_2
          && black >= 1 && white >= 2) {
        SDL_RenderClear(renderer);
        Move(renderer);
        SDL_Delay(1000);
        SDL_RenderClear(renderer);
        moveenermy(renderer);
      }else if (event.type == SDL_MOUSEBUTTONDOWN && mousedownenermy(event, renderer) && !is_change && is_move_3
          && white >= 3) {
        SDL_RenderClear(renderer);
        Move(renderer);
        SDL_Delay(1000);
        SDL_RenderClear(renderer);
        moveenermy(renderer);
      }
    }
  }
  return true;
}
void WIN(SDL_Renderer *renderer) {
  SDL_Surface *surface_background_3 = IMG_Load("res/img/Win.jpg");
  SDL_Texture *texture_background_3 = SDL_CreateTextureFromSurface(renderer, surface_background_3);
  SDL_RenderCopy(renderer, texture_background_3, NULL, NULL);

  SDL_FreeSurface(surface_background_3);
  SDL_DestroyTexture(texture_background_3);
}
void LOSE(SDL_Renderer *renderer) {
  SDL_Surface *surface_background_3 = IMG_Load("res/img/Lose.jpg");
  SDL_Texture *texture_background_3 = SDL_CreateTextureFromSurface(renderer, surface_background_3);
  SDL_RenderCopy(renderer, texture_background_3, NULL, NULL);
  restart(renderer);

  SDL_FreeSurface(surface_background_3);
  SDL_DestroyTexture(texture_background_3);
}
static void restart(SDL_Renderer *renderer) {
  SDL_Surface *surface_background_3 = IMG_Load("res/img/restart.jpg");
  SDL_Texture *texture_background_3 = SDL_CreateTextureFromSurface(renderer, surface_background_3);
  SDL_Rect rect = {.x = 1000, .y = 700, .w = surface_background_3->w, .h = surface_background_3->h};
  SDL_RenderCopy(renderer, texture_background_3, NULL, &rect);

  SDL_FreeSurface(surface_background_3);
  SDL_DestroyTexture(texture_background_3);
}

static void View(SDL_Renderer *renderer) {
  SDL_Surface *surface_1 = IMG_Load("res/img/view.jpg");
  SDL_Texture *texture_1 = SDL_CreateTextureFromSurface(renderer, surface_1);
  SDL_Rect rect_1 = {.x = 200, .y = 400, .w = surface_1->w, .h = surface_1->h};

  SDL_RenderCopy(renderer, texture_1, NULL, &rect_1);
  SDL_FreeSurface(surface_1);
  SDL_DestroyTexture(texture_1);

  SDL_Surface *surface_2 = IMG_Load("res/img/view.jpg");
  SDL_Texture *texture_2 = SDL_CreateTextureFromSurface(renderer, surface_2);
  SDL_Rect rect_2 = {.x = 450, .y = 400, .w = surface_2->w, .h = surface_2->h};

  SDL_RenderCopy(renderer, texture_2, NULL, &rect_2);
  SDL_FreeSurface(surface_2);
  SDL_DestroyTexture(texture_2);

  SDL_Surface *surface_3 = IMG_Load("res/img/view.jpg");
  SDL_Texture *texture_3 = SDL_CreateTextureFromSurface(renderer, surface_3);
  SDL_Rect rect_3 = {.x = 700, .y = 400, .w = surface_3->w, .h = surface_3->h};

  SDL_RenderCopy(renderer, texture_3, NULL, &rect_3);
  SDL_FreeSurface(surface_3);
  SDL_DestroyTexture(texture_3);
}//渲染查看键的函数
static void Figure_select(SDL_Renderer *renderer) {
  SDL_Surface *surface_figure_1 = IMG_Load("res/img/kaiya.jpg");
  SDL_Surface *surface_figure_2 = IMG_Load("res/img/diluke.jpg");
  SDL_Surface *surface_figure_3 = IMG_Load("res/img/linghua.jpg");
  SDL_Texture *texture_figure_1 = SDL_CreateTextureFromSurface(renderer, surface_figure_1);
  SDL_Texture *texture_figure_2 = SDL_CreateTextureFromSurface(renderer, surface_figure_2);
  SDL_Texture *texture_figure_3 = SDL_CreateTextureFromSurface(renderer, surface_figure_3);
  SDL_Rect viewport_1 = {.x = 150, .y = 100, .w = surface_figure_1->w, .h = surface_figure_1->h};
  SDL_RenderCopy(renderer, texture_figure_1, NULL, &viewport_1);
  //渲染凯亚图片和名字
  SDL_Rect viewport_2 = {.x = 400, .y = 100, .w = surface_figure_2->w, .h = surface_figure_2->h};
  SDL_RenderCopy(renderer, texture_figure_2, NULL, &viewport_2);
  //渲染迪卢克图片和名字
  SDL_Rect viewport_3 = {.x = 650, .y = 100, .w = surface_figure_3->w, .h = surface_figure_3->h};
  SDL_RenderCopy(renderer, texture_figure_3, NULL, &viewport_3);
  //渲染神里凌华图片和名字
  SDL_FreeSurface(surface_figure_1);
  SDL_FreeSurface(surface_figure_2);
  SDL_FreeSurface(surface_figure_3);
  SDL_DestroyTexture(texture_figure_1);
  SDL_DestroyTexture(texture_figure_2);
  SDL_DestroyTexture(texture_figure_3);
}
static void Font_select(SDL_Renderer *renderer) {
  TTF_Font *font = TTF_OpenFont("res/font/YeZiGongChangAoYeHei-2.ttf", 24);
  SDL_Color font_color_1 = {61, 89, 171, 0xff};
  SDL_Color font_color_2 = {0xff, 0, 0, 0xff};
  SDL_Color font_color_3 = {30, 144, 255, 0xff};
  SDL_Surface *surface_font_1 = TTF_RenderUTF8_Solid(font, "凯亚", font_color_1);
  SDL_Surface *surface_font_2 = TTF_RenderUTF8_Solid(font, "迪卢克", font_color_2);
  SDL_Surface *surface_font_3 = TTF_RenderUTF8_Solid(font, "神里凌华", font_color_3);
  SDL_Texture *texture_font_1 = SDL_CreateTextureFromSurface(renderer, surface_font_1);
  SDL_Texture *texture_font_2 = SDL_CreateTextureFromSurface(renderer, surface_font_2);
  SDL_Texture *texture_font_3 = SDL_CreateTextureFromSurface(renderer, surface_font_3);
  SDL_Rect viewport_font_1 = {.x = 200, .y = 60, .w = surface_font_1->w, .h = surface_font_1->h};
  SDL_Rect viewport_font_2 = {.x = 450, .y = 60, .w = surface_font_2->w, .h = surface_font_2->h};
  SDL_Rect viewport_font_3 = {.x = 700, .y = 60, .w = surface_font_3->w, .h = surface_font_3->h};
  SDL_RenderCopy(renderer, texture_font_1, NULL, &viewport_font_1);
  SDL_RenderCopy(renderer, texture_font_2, NULL, &viewport_font_2);
  SDL_RenderCopy(renderer, texture_font_3, NULL, &viewport_font_3);
  SDL_FreeSurface(surface_font_1);
  SDL_FreeSurface(surface_font_2);
  SDL_FreeSurface(surface_font_3);
  SDL_DestroyTexture(texture_font_1);
  SDL_DestroyTexture(texture_font_2);
  SDL_DestroyTexture(texture_font_3);
  TTF_CloseFont(font);
}
static void Background_select(SDL_Renderer *renderer) {
  SDL_Surface *surface_background_3 = IMG_Load("res/img/3.jpg");
  SDL_Texture *texture_background_3 = SDL_CreateTextureFromSurface(renderer, surface_background_3);
  SDL_RenderCopy(renderer, texture_background_3, NULL, NULL);

  SDL_FreeSurface(surface_background_3);
  SDL_DestroyTexture(texture_background_3);
}
static void Basicbackground_select(SDL_Renderer *renderer) {
  Background_select(renderer);
  Figure_select(renderer);
  Font_select(renderer);
  View(renderer);
  start(renderer);
}
static void jineng_1(SDL_Renderer *renderer) {
  SDL_Surface *surface_1 = IMG_Load("res/img/kaiyajineng.jpg");
  SDL_Texture *texture_1 = SDL_CreateTextureFromSurface(renderer, surface_1);
  SDL_Rect rect_1 = {.x = 150, .y = 500, .w = surface_1->w, .h = surface_1->h};

  SDL_RenderCopy(renderer, texture_1, NULL, &rect_1);
  SDL_FreeSurface(surface_1);
  SDL_DestroyTexture(texture_1);
}
static void jineng_2(SDL_Renderer *renderer) {
  SDL_Surface *surface_1 = IMG_Load("res/img/dilukejineng.jpg");
  SDL_Texture *texture_1 = SDL_CreateTextureFromSurface(renderer, surface_1);
  SDL_Rect rect_1 = {.x = 150, .y = 500, .w = surface_1->w, .h = surface_1->h};

  SDL_RenderCopy(renderer, texture_1, NULL, &rect_1);
  SDL_FreeSurface(surface_1);
  SDL_DestroyTexture(texture_1);
}
static void jineng_3(SDL_Renderer *renderer) {
  SDL_Surface *surface_1 = IMG_Load("res/img/linghuajineng.jpg");
  SDL_Texture *texture_1 = SDL_CreateTextureFromSurface(renderer, surface_1);
  SDL_Rect rect_1 = {.x = 150, .y = 500, .w = surface_1->w, .h = surface_1->h};

  SDL_RenderCopy(renderer, texture_1, NULL, &rect_1);
  SDL_FreeSurface(surface_1);
  SDL_DestroyTexture(texture_1);
}
static bool mousedownview_1(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/view.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 200, .y = 400, .w = surface->w, .h = surface->h};

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

  if (event.button.x >= rect.x && event.button.x <= rect.x + rect.w
      && event.button.y >= rect.y && event.button.y <= rect.y + rect.h) {
    return true;
  }
  return false;
}
static bool mousedownview_2(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/view.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 450, .y = 400, .w = surface->w, .h = surface->h};

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

  if (event.button.x >= rect.x && event.button.x <= rect.x + rect.w
      && event.button.y >= rect.y && event.button.y <= rect.y + rect.h) {
    return true;
  }
  return false;
}
static bool mousedownview_3(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/view.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 700, .y = 400, .w = surface->w, .h = surface->h};

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

  if (event.button.x >= rect.x && event.button.x <= rect.x + rect.w
      && event.button.y >= rect.y && event.button.y <= rect.y + rect.h) {
    return true;
  }
  return false;
}
static void start(SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/start.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 1000, .y = 700, .w = surface->w, .h = surface->h};

  SDL_RenderCopy(renderer, texture, NULL, &rect);
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}
static bool mousedownstart(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/start.jpg");
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
static void Background_game(SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/gamebackground.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}
static void Figure_game(SDL_Renderer *renderer, int i) {
  if (i == 1) {
    SDL_Surface *surface_figure_1 = IMG_Load("res/img/kaiya.jpg");
    SDL_Surface *surface_figure_2 = IMG_Load("res/img/diluke.jpg");
    SDL_Surface *surface_figure_3 = IMG_Load("res/img/linghua.jpg");
    SDL_Texture *texture_figure_1 = SDL_CreateTextureFromSurface(renderer, surface_figure_1);
    SDL_Texture *texture_figure_2 = SDL_CreateTextureFromSurface(renderer, surface_figure_2);
    SDL_Texture *texture_figure_3 = SDL_CreateTextureFromSurface(renderer, surface_figure_3);
    SDL_Rect viewport_1 = {.x = 250, .y = 450, .w = surface_figure_1->w, .h = surface_figure_1->h};
    SDL_RenderCopy(renderer, texture_figure_1, NULL, &viewport_1);
    //渲染凯亚图片和名字
    SDL_Rect viewport_2 = {.x = 500, .y = 500, .w = surface_figure_2->w, .h = surface_figure_2->h};
    SDL_RenderCopy(renderer, texture_figure_2, NULL, &viewport_2);
    //渲染迪卢克图片和名字
    SDL_Rect viewport_3 = {.x = 750, .y = 500, .w = surface_figure_3->w, .h = surface_figure_3->h};
    SDL_RenderCopy(renderer, texture_figure_3, NULL, &viewport_3);
    //渲染神里凌华图片和名字
    SDL_FreeSurface(surface_figure_1);
    SDL_FreeSurface(surface_figure_2);
    SDL_FreeSurface(surface_figure_3);
    SDL_DestroyTexture(texture_figure_1);
    SDL_DestroyTexture(texture_figure_2);
    SDL_DestroyTexture(texture_figure_3);
  }
  if (i == 2) {
    SDL_Surface *surface_figure_1 = IMG_Load("res/img/kaiya.jpg");
    SDL_Surface *surface_figure_2 = IMG_Load("res/img/diluke.jpg");
    SDL_Surface *surface_figure_3 = IMG_Load("res/img/linghua.jpg");
    SDL_Texture *texture_figure_1 = SDL_CreateTextureFromSurface(renderer, surface_figure_1);
    SDL_Texture *texture_figure_2 = SDL_CreateTextureFromSurface(renderer, surface_figure_2);
    SDL_Texture *texture_figure_3 = SDL_CreateTextureFromSurface(renderer, surface_figure_3);
    SDL_Rect viewport_1 = {.x = 250, .y = 500, .w = surface_figure_1->w, .h = surface_figure_1->h};
    SDL_RenderCopy(renderer, texture_figure_1, NULL, &viewport_1);
    //渲染凯亚图片和名字
    SDL_Rect viewport_2 = {.x = 500, .y = 450, .w = surface_figure_2->w, .h = surface_figure_2->h};
    SDL_RenderCopy(renderer, texture_figure_2, NULL, &viewport_2);
    //渲染迪卢克图片和名字
    SDL_Rect viewport_3 = {.x = 750, .y = 500, .w = surface_figure_3->w, .h = surface_figure_3->h};
    SDL_RenderCopy(renderer, texture_figure_3, NULL, &viewport_3);
    //渲染神里凌华图片和名字
    SDL_FreeSurface(surface_figure_1);
    SDL_FreeSurface(surface_figure_2);
    SDL_FreeSurface(surface_figure_3);
    SDL_DestroyTexture(texture_figure_1);
    SDL_DestroyTexture(texture_figure_2);
    SDL_DestroyTexture(texture_figure_3);
  }
  if (i == 3) {
    SDL_Surface *surface_figure_1 = IMG_Load("res/img/kaiya.jpg");
    SDL_Surface *surface_figure_2 = IMG_Load("res/img/diluke.jpg");
    SDL_Surface *surface_figure_3 = IMG_Load("res/img/linghua.jpg");
    SDL_Texture *texture_figure_1 = SDL_CreateTextureFromSurface(renderer, surface_figure_1);
    SDL_Texture *texture_figure_2 = SDL_CreateTextureFromSurface(renderer, surface_figure_2);
    SDL_Texture *texture_figure_3 = SDL_CreateTextureFromSurface(renderer, surface_figure_3);
    SDL_Rect viewport_1 = {.x = 250, .y = 500, .w = surface_figure_1->w, .h = surface_figure_1->h};
    SDL_RenderCopy(renderer, texture_figure_1, NULL, &viewport_1);
    //渲染凯亚图片和名字
    SDL_Rect viewport_2 = {.x = 500, .y = 500, .w = surface_figure_2->w, .h = surface_figure_2->h};
    SDL_RenderCopy(renderer, texture_figure_2, NULL, &viewport_2);
    //渲染迪卢克图片和名字
    SDL_Rect viewport_3 = {.x = 750, .y = 450, .w = surface_figure_3->w, .h = surface_figure_3->h};
    SDL_RenderCopy(renderer, texture_figure_3, NULL, &viewport_3);
    //渲染神里凌华图片和名字
    SDL_FreeSurface(surface_figure_1);
    SDL_FreeSurface(surface_figure_2);
    SDL_FreeSurface(surface_figure_3);
    SDL_DestroyTexture(texture_figure_1);
    SDL_DestroyTexture(texture_figure_2);
    SDL_DestroyTexture(texture_figure_3);
  }
}
static void change(SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/change.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 25, .y = 700, .w = surface->w, .h = surface->h};

  SDL_RenderCopy(renderer, texture, NULL, &rect);
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}
static void end(SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/end.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 140, .y = 700, .w = surface->w, .h = surface->h};

  SDL_RenderCopy(renderer, texture, NULL, &rect);
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}
static void enermy(SDL_Renderer *renderer) {
  if (!is_defence) {
    SDL_Surface *surface = IMG_Load("res/img/qiqiwang.jpg");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = 500, .y = 25, .w = surface->w, .h = surface->h};

    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
  } else {
    SDL_Surface *surface = IMG_Load("res/img/qiqiwang1.jpg");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = 500, .y = 25, .w = surface->w, .h = surface->h};

    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
  }
}
static void Basicbackground_game(SDL_Renderer *renderer) {
  Background_game(renderer);
  change(renderer);
  end(renderer);
  enermy(renderer);
  Blood(renderer, 180, 500, blood_1);
  Blood(renderer, 180, 600, energe_1);
  Blood(renderer, 430, 500, blood_2);
  Blood(renderer, 430, 600, energe_2);
  Blood(renderer, 680, 500, blood_3);
  Blood(renderer, 680, 600, energe_3);
  Blood(renderer, 1125, 195, white);
  Blood(renderer, 1125, 295, black);
  Blood(renderer, 430, 25, blood_enermy);
  White(renderer);
  Black(renderer);
  move(renderer);
  Figure_game(renderer, figure);
  ZHAOHUANWU(renderer);
}
static bool mousedownchange(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/change.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 25, .y = 700, .w = surface->w, .h = surface->h};

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

  if (event.button.x >= rect.x && event.button.x <= rect.x + rect.w
      && event.button.y >= rect.y && event.button.y <= rect.y + rect.h) {
    return true;
  }
  return false;
}
static bool mousedownend(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/end.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 140, .y = 700, .w = surface->w, .h = surface->h};

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

  if (event.button.x >= rect.x && event.button.x <= rect.x + rect.w
      && event.button.y >= rect.y && event.button.y <= rect.y + rect.h) {
    return true;
  }
  return false;
}
static void Blood(SDL_Renderer *renderer, int x, int y, int blood) {
  if (blood == 0) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "0", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 1) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "1", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 2) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "2", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 3) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "3", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 4) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "4", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 5) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "5", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 6) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "6", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 7) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "7", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 8) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "8", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 9) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "9", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 10) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "10", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 11) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "11", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 12) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "12", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 13) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "13", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 14) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "14", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 15) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "15", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 16) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "16", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 17) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "17", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 18) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "18", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 19) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "19", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 20) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "20", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 21) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "21", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 22) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "22", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 23) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "23", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 24) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "24", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 25) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "25", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 26) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "26", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 27) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "27", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 28) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "28", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 29) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "29", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
  if (blood == 30) {
    TTF_Font *font = TTF_OpenFont("res/font/GenshinDefault.ttf", 48);
    SDL_Color color = {0xff, 0, 0, 0xff};
    SDL_Surface *surface = TTF_RenderText_Blended(font, "30", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {.x = x, .y = y, .w = surface->w, .h = surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
  }
}
static void White(SDL_Renderer *renderer) {
  TTF_Font *font = TTF_OpenFont("res/font/YeZiGongChangAoYeHei-2.ttf", 48);
  SDL_Color color = {0xff, 0xff, 0xff, 0xff};
  SDL_Surface *surface = TTF_RenderUTF8_Solid(font, "白", color);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 1050, .y = 200, .w = surface->w, .h = surface->h};
  SDL_RenderCopy(renderer, texture, NULL, &rect);

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
  TTF_CloseFont(font);
}
static void Black(SDL_Renderer *renderer) {
  TTF_Font *font = TTF_OpenFont("res/font/YeZiGongChangAoYeHei-2.ttf", 48);
  SDL_Color color = {0, 0, 0, 0xff};
  SDL_Surface *surface = TTF_RenderUTF8_Solid(font, "黑", color);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 1050, .y = 300, .w = surface->w, .h = surface->h};
  SDL_RenderCopy(renderer, texture, NULL, &rect);

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
  TTF_CloseFont(font);
}
static void move(SDL_Renderer *renderer) {
  SDL_Surface *surface_1 = IMG_Load("res/img/1xingdong.jpg");
  SDL_Texture *texture_1 = SDL_CreateTextureFromSurface(renderer, surface_1);
  SDL_Rect rect_1 = {.x = 1000, .y = 700, .w = surface_1->w, .h = surface_1->h};

  SDL_RenderCopy(renderer, texture_1, NULL, &rect_1);
  SDL_FreeSurface(surface_1);
  SDL_DestroyTexture(texture_1);
  SDL_Surface *surface_2 = IMG_Load("res/img/2xingdong.jpg");
  SDL_Texture *texture_2 = SDL_CreateTextureFromSurface(renderer, surface_2);
  SDL_Rect rect_2 = {.x = 1050, .y = 700, .w = surface_2->w, .h = surface_2->h};

  SDL_RenderCopy(renderer, texture_2, NULL, &rect_2);
  SDL_FreeSurface(surface_2);
  SDL_DestroyTexture(texture_2);
  SDL_Surface *surface_3 = IMG_Load("res/img/3xingdong.jpg");
  SDL_Texture *texture_3 = SDL_CreateTextureFromSurface(renderer, surface_2);
  SDL_Rect rect_3 = {.x = 1100, .y = 700, .w = surface_2->w, .h = surface_2->h};

  SDL_RenderCopy(renderer, texture_3, NULL, &rect_3);
  SDL_FreeSurface(surface_3);
  SDL_DestroyTexture(texture_3);
}
static void moveenermy_end(SDL_Renderer *renderer) {
  while (1) {
    SDL_RenderClear(renderer);
    moveenermy(renderer);
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
    if (xingdong == 0) {
      return;
    }
  }
}
static void moveenermy(SDL_Renderer *renderer) {
  if (blood_enermy == 0) {
    return;
  }
  ZHAOHUANWU(renderer);
  if (xingdong == 0) {
    printf("敌人行动点数已用完\n");
    return;
  }
  if ((is_fire || is_ice) && !is_defence && blood_enermy < 20) {
    printf("丘丘岩盔王使用元素战技，获得一个可抵挡2点伤害的护盾\n");
    is_defence = true;
    SDL_RenderClear(renderer);
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
    xingdong--;
    return;
  }
  printf("丘丘岩盔王使用普通攻击，造成2点伤害\n");
  if (figure == 1) {
    xingdong--;
    if (blood_1 >= 2) {
      blood_1 -= 2;
    } else {
      blood_1 = 0;
    }
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
    return;
  }
  if (figure == 2) {
    xingdong--;
    if (blood_2 >= 2) {
      blood_2 -= 2;
    } else {
      blood_2 = 0;
    }
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
    return;
  }
  if (figure == 3) {
    xingdong--;
    if (blood_3 >= 2) {
      blood_3 -= 2;
    } else {
      blood_3 = 0;
    }
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
    return;
  }
}
static void roundend(SDL_Renderer *renderer) {
  SDL_Surface *surface_background_3 = IMG_Load("res/img/roundend.jpg");
  SDL_Texture *texture_background_3 = SDL_CreateTextureFromSurface(renderer, surface_background_3);
  SDL_RenderCopy(renderer, texture_background_3, NULL, NULL);

  SDL_FreeSurface(surface_background_3);
  SDL_DestroyTexture(texture_background_3);
}
static void change_select() {
  if (!is_change) {
    is_change = true;
  } else {
    is_change = false;
  }
}
static bool mousedownfigure_1(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/kaiya.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 250, .y = 500, .w = surface->w, .h = surface->h};

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

  if (event.button.x >= rect.x && event.button.x <= rect.x + rect.w
      && event.button.y >= rect.y && event.button.y <= rect.y + rect.h) {
    return true;
  }
  return false;
}
static bool mousedownfigure_2(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/diluke.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 500, .y = 500, .w = surface->w, .h = surface->h};

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

  if (event.button.x >= rect.x && event.button.x <= rect.x + rect.w
      && event.button.y >= rect.y && event.button.y <= rect.y + rect.h) {
    return true;
  }
  return false;
}
static bool mousedownfigure_3(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/linghua.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 750, .y = 500, .w = surface->w, .h = surface->h};

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

  if (event.button.x >= rect.x && event.button.x <= rect.x + rect.w
      && event.button.y >= rect.y && event.button.y <= rect.y + rect.h) {
    return true;
  }
  return false;
}
static bool mousedownmove_1(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/1xingdong.jpg");
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
static bool mousedownmove_2(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/2xingdong.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 1050, .y = 700, .w = surface->w, .h = surface->h};

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

  if (event.button.x >= rect.x && event.button.x <= rect.x + rect.w
      && event.button.y >= rect.y && event.button.y <= rect.y + rect.h) {
    return true;
  }
  return false;
}
static bool mousedownmove_3(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/3xingdong.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 1100, .y = 700, .w = surface->w, .h = surface->h};

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

  if (event.button.x >= rect.x && event.button.x <= rect.x + rect.w
      && event.button.y >= rect.y && event.button.y <= rect.y + rect.h) {
    return true;
  }
  return false;
}
static void Move(SDL_Renderer *renderer) {
  if (is_move_1 && figure == 1) {
    printf("凯亚使用普通攻击，造成2点物理伤害\n");
    if (energe_1 < 3) {
      energe_1++;
    }
    is_move_1 = false;
    black -= 2;
    white--;
    if (is_defence) {
      blood_enermy += 2;
    }
    is_defence = false;
    if (blood_enermy >= 2) {
      blood_enermy -= 2;
    } else {
      blood_enermy = 0;
      return;
    }
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
  }
  if (is_move_2 && figure == 1) {
    if (energe_1 < 3) {
      energe_1++;
    }
    is_move_2 = false;
    black--;
    white -= 2;
    if (is_defence) {
      blood_enermy += 2;
    }
    is_defence = false;
    if (blood_enermy >= 2) {
      blood_enermy -= 2;
    } else {
      blood_enermy = 0;
      printf("凯亚使用元素战技打败了敌人\n");
      return;
    }
    if (is_fire) {
      printf("凯亚使用元素战技，触发融化反应，造成3点伤害\n");
      is_fire = false;
      if (blood_enermy >= 1) {
        blood_enermy--;
      } else {
        blood_enermy = 0;
        return;
      }
    } else {
      printf("凯亚使用元素战技，造成2点冰元素伤害\n");
      is_ice = true;
    }
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
  }
  if (is_move_3 && figure == 1 && energe_1 == 3) {
    energe_1 = 0;
    is_move_3 = false;
    white -= 3;
    if (is_defence) {
      blood_enermy += 2;
    }
    is_defence = false;
    if (blood_enermy >= 3) {
      blood_enermy -= 3;
    } else {
      printf("凯亚使用元素爆发击败了敌人\n");
      blood_enermy = 0;
      return;
    }
    if (is_fire) {
      printf("凯亚使用元素爆发，触发融化反应，造成4点伤害\n");
      is_fire = false;
      if (blood_enermy >= 1) {
        blood_enermy--;
      } else {
        blood_enermy = 0;
        return;
      }
    } else {
      printf("凯亚使用元素爆发，造成3点冰元素伤害\n");
      is_ice = true;
    }
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
  }
  if (is_move_1 && figure == 2) {
    printf("迪卢克使用普通攻击，造成2点伤害\n");
    if (energe_2 < 3) {
      energe_2++;
    }
    is_move_1 = false;
    black -= 2;
    white--;
    if (is_defence) {
      blood_enermy += 2;
    }
    is_defence = false;
    if (blood_enermy >= 2) {
      blood_enermy -= 2;
    } else {
      blood_enermy = 0;
      return;
    }
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
  }
  if (is_move_2 && figure == 2) {
    if (energe_2 < 3) {
      energe_2++;
    }
    is_move_2 = false;
    black--;
    white -= 2;
    if (is_defence) {
      blood_enermy += 2;
    }
    is_defence = false;
    if (blood_enermy >= 2) {
      blood_enermy -= 2;
    } else {
      blood_enermy = 0;
      printf("迪卢克使用元素战技击败了敌人\n");
      return;
    }
    if (is_ice) {
      printf("迪卢克使用元素战技，触发融化反应，造成3点伤害\n");
      is_ice = false;
      if (blood_enermy >= 1) {
        blood_enermy--;
      } else {
        blood_enermy = 0;
        return;
      }
    } else {
      printf("迪卢克使用元素战技，造成2点火元素伤害\n");
      is_fire = true;
    }
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
  }
  if (is_move_3 && figure == 2 && energe_2 == 3) {
    energe_2 = 0;
    is_move_3 = false;
    white -= 3;
    if (is_defence) {
      blood_enermy += 2;
    }
    is_defence = false;
    if (blood_enermy >= 8) {
      blood_enermy -= 8;
    } else {
      blood_enermy = 0;
      printf("迪卢克使用元素爆发击败了敌人\n");
      return;
    }
    if (is_ice) {
      printf("迪卢克使用元素爆发，触发融化反应，造成9点伤害\n");
      is_ice = false;
      if (blood_enermy >= 1) {
        blood_enermy--;
      } else {
        blood_enermy = 0;
        return;
      }
    } else {
      printf("迪卢克使用元素爆发，造成8点火元素伤害\n");
      is_fire = true;
    }
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
  }
  if (is_move_1 && figure == 3) {
    printf("神里凌华使用普通攻击，造成2点伤害\n");
    if (energe_3 < 3) {
      energe_3++;
    }
    is_move_1 = false;
    black -= 2;
    white--;
    if (is_defence) {
      blood_enermy += 2;
    }
    is_defence = false;
    if (blood_enermy >= 2) {
      blood_enermy -= 2;
    } else {
      blood_enermy = 0;
      return;
    }
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
  }
  if (is_move_2 && figure == 3) {
    if (energe_3 < 3) {
      energe_3++;
    }
    is_move_2 = false;
    black--;
    white -= 2;
    if (is_defence) {
      blood_enermy += 2;
    }
    is_defence = false;
    if (blood_enermy >= 2) {
      blood_enermy -= 2;
    } else {
      blood_enermy = 0;
      printf("神里凌华使用元素战技击败了敌人\n");
      return;
    }
    if (is_fire) {
      printf("神里凌华使用元素战技，触发融化反应，造成3点伤害\n");
      is_fire = false;
      if (blood_enermy >= 1) {
        blood_enermy--;
      } else {
        blood_enermy = 0;
        return;
      }
    } else {
      printf("神里凌华使用元素战技，造成2点冰元素伤害\n");
      is_ice = true;
    }
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
  }
  if (is_move_3 && figure == 3 && energe_3 == 3) {
    energe_3 = 0;
    is_move_3 = false;
    white -= 3;
    if (is_defence) {
      blood_enermy += 2;
    }
    is_defence = false;
    if (blood_enermy >= 4) {
      blood_enermy -= 4;
    } else {
      blood_enermy = 0;
      printf("神里凌华使用元素爆发击败了敌人\n");
      return;
    }
    if (is_fire) {
      printf("神里凌华使用元素爆发，触发融化反应，造成5点伤害，并召唤霜见雪关扉\n");
      is_fire = false;
      if (blood_enermy >= 1) {
        blood_enermy--;
      } else {
        blood_enermy = 0;
        return;
      }
    } else {
      printf("神里凌华使用元素爆发，造成4点冰元素伤害，并召唤霜见雪关扉\n");
      is_ice = true;
    }
    zhaohuan_time = 2;
    Basicbackground_game(renderer);
    SDL_RenderPresent(renderer);
  }
}
static void move_select_1() {
  if (figure == 1 && blood_1 == 0) {
    return;
  }
  if (figure == 2 && blood_2 == 0) {
    return;
  }
  if (figure == 3 && blood_3 == 0) {
    return;
  }
  if (is_move_1) {
    is_move_1 = false;
  } else {
    is_move_1 = true;
  }
  return;
}
static void move_select_2() {
  if (figure == 1 && blood_1 == 0) {
    return;
  }
  if (figure == 2 && blood_2 == 0) {
    return;
  }
  if (figure == 3 && blood_3 == 0) {
    return;
  }
  if (is_move_2) {
    is_move_2 = false;
  } else {
    is_move_2 = true;
  }
  return;
}
static void move_select_3() {
  if (energe_1 != 3 && figure == 1) {
    return;
  }
  if (energe_2 != 3 && figure == 2) {
    return;
  }
  if (energe_3 != 3 && figure == 3) {
    return;
  }
  if (figure == 1 && blood_1 == 0) {
    return;
  }
  if (figure == 2 && blood_2 == 0) {
    return;
  }
  if (figure == 3 && blood_3 == 0) {
    return;
  }
  if (is_move_3) {
    is_move_3 = false;
  } else {
    is_move_3 = true;
  }
  return;
}
static bool mousedownenermy(SDL_Event event, SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/qiqiwang.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 500, .y = 25, .w = surface->w, .h = surface->h};

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);

  if (event.button.x >= rect.x && event.button.x <= rect.x + rect.w
      && event.button.y >= rect.y && event.button.y <= rect.y + rect.h) {
    return true;
  }
  return false;
}
static void zhaohuanwu(SDL_Renderer *renderer) {
  SDL_Surface *surface = IMG_Load("res/img/zhaohuanwu.jpg");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_Rect rect = {.x = 950, .y = 500, .w = surface->w, .h = surface->h};

  SDL_RenderCopy(renderer, texture, NULL, &rect);
  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}
static void zhaohuanwuattach() {
  if (zhaohuan_time > 0) {
    zhaohuan_time--;
    if(is_defence) {
      blood_enermy += 2;
    }
    if (blood_enermy >= 2) {
      blood_enermy -= 2;
    } else {
      blood_enermy = 0;
      printf("霜见雪关扉发动，打败了敌人\n");
      return;
    }
    if (is_fire) {
      printf("霜见雪关扉发动，触发融化反应，造成3点伤害，使用次数-1\n");
      is_fire = false;
      if (blood_enermy >= 1) {
        blood_enermy--;
      } else {
        blood_enermy = 0;
        return;
      }
    } else {
      printf("霜见雪关扉发动，造成2点冰元素伤害，使用次数-1\n");
      is_ice = true;
    }
  }
}
static bool zhaohuanwuattach_1(SDL_Renderer *renderer) {
  if (zhaohuan_time > 0) {
    zhaohuanwu(renderer);
    return true;
  }
  return false;
}
static void weilefengzhuang(SDL_Renderer *renderer) {
  if (zhaohuanwuattach_1(renderer)) {
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
  } else {
    SDL_RenderPresent(renderer);
  }
}
static void ZHAOHUANWU(SDL_Renderer *renderer) {
  if (zhaohuan_time > 0) {
    zhaohuanwu(renderer);
  }
}
static void die(SDL_Event event, SDL_Renderer *renderer) {
  if (event.type == SDL_MOUSEBUTTONDOWN && mousedownfigure_1(event, renderer) && blood_1 > 0) {
    figure = 1;
    printf("出战角色切换为凯亚\n");
  }
  if (event.type == SDL_MOUSEBUTTONDOWN && mousedownfigure_2(event, renderer) && blood_2 > 0) {
    figure = 2;
    printf("出战角色切换为迪卢克\n");
  }
  if (event.type == SDL_MOUSEBUTTONDOWN && mousedownfigure_3(event, renderer) && blood_3 > 0) {
    figure = 3;
    printf("出战角色切换为神里凌华\n");
  }
}
bool ISWIN() {
  if(is_win) {
    return true;
  } else {
    return false;
  }
}