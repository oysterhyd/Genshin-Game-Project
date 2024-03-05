//
// Created by 72802 on 2024/1/11.
//

#ifndef PROJECT_INCLUDE_GAME_H_
#define PROJECT_INCLUDE_GAME_H_

#include <common.h>

static int blood_1;
static int blood_2;
static int blood_3;
static int blood_enermy;
static int white;
static int black;
static int energe_1;
static int energe_2;
static int energe_3;
static int figure;
static bool is_change;
static bool is_move_1;
static bool is_move_2;
static bool is_move_3;
static bool is_ice;
static bool is_fire;
static int zhaohuan_time;
static bool is_defence;
static int xingdong;
static bool is_win;


bool select(SDL_Renderer *renderer);
static void View(SDL_Renderer *renderer);
static void Figure_select(SDL_Renderer *renderer);
static void Font_select(SDL_Renderer *renderer);
static void Background_select(SDL_Renderer *renderer);
static void Basicbackground_select(SDL_Renderer *renderer);
static void jineng_1(SDL_Renderer *renderer);
static void jineng_2(SDL_Renderer *renderer);
static void jineng_3(SDL_Renderer *renderer);
static bool mousedownview_1(SDL_Event event, SDL_Renderer *renderer);
static bool mousedownview_2(SDL_Event event, SDL_Renderer *renderer);
static bool mousedownview_3(SDL_Event event, SDL_Renderer *renderer);
static void start(SDL_Renderer *renderer);
static bool mousedownstart(SDL_Event event, SDL_Renderer *renderer);
bool Game(SDL_Renderer *renderer);
static void Background_game(SDL_Renderer *renderer);
static void change(SDL_Renderer *renderer);
static void end(SDL_Renderer *renderer);
static void Basicbackground_game(SDL_Renderer *renderer);
static void enermy(SDL_Renderer *renderer);
static void Figure_game(SDL_Renderer *renderer, int i);
static bool mousedownchange(SDL_Event event, SDL_Renderer *renderer);
static bool mousedownend(SDL_Event event, SDL_Renderer *renderer);
static void Blood(SDL_Renderer *renderer, int x, int y, int blood);
static void White(SDL_Renderer *renderer);
static void Black(SDL_Renderer *renderer);
static void move(SDL_Renderer *renderer);
static void moveenermy_end(SDL_Renderer *renderer);
static void moveenermy(SDL_Renderer *renderer);
static void roundend(SDL_Renderer *renderer);
static void change_select();
static bool mousedownfigure_1(SDL_Event event, SDL_Renderer *renderer);
static bool mousedownfigure_2(SDL_Event event, SDL_Renderer *renderer);
static bool mousedownfigure_3(SDL_Event event, SDL_Renderer *renderer);
static bool mousedownmove_1(SDL_Event event, SDL_Renderer *renderer);
static bool mousedownmove_2(SDL_Event event, SDL_Renderer *renderer);
static bool mousedownmove_3(SDL_Event event, SDL_Renderer *renderer);
static void Move(SDL_Renderer *renderer);
static void move_select_1();
static void move_select_2();
static void move_select_3();
static bool mousedownenermy(SDL_Event event, SDL_Renderer *renderer);
static void zhaohuanwu(SDL_Renderer *renderer);
static void zhaohuanwuattach();
static bool zhaohuanwuattach_1(SDL_Renderer *renderer);
static void weilefengzhuang(SDL_Renderer *renderer);
static void ZHAOHUANWU(SDL_Renderer *renderer);
static void die(SDL_Event event, SDL_Renderer *renderer);
void WIN(SDL_Renderer *renderer);
void LOSE(SDL_Renderer *renderer);
static void restart(SDL_Renderer *renderer);
bool ISWIN();

#endif //PROJECT_INCLUDE_GAME_H_
