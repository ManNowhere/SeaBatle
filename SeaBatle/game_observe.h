#ifndef GAME_OBSERVE_H
#define GAME_OBSERVE_H
#include <AllField.h>
#include <Player_human.h>
#include <Drawer.h>
#include <Player_CPU.h>


class Game_observe//следит за игрой
{
public:
   Game_observe() : human_hits(0), cpu_hits(0)
   {}
   ~Game_observe()
   {}

All_field H;
All_field CP;
Drawer d;
Player_human Player;
Player_CPU CPU;

void Game_over(int &Xh, int &Xc);//конец игры

void draw_ships();//рисует все корабли на поле игрока

bool hit_check(std::vector<std::vector<int>> &field_, int X, int Y, int &hits);//отмечает попадние на поле

void Play();//игровой процесс


private:
bool Shot;//переменная, следит за переходом хода

int deck2 = 4;//палубы корабля
int number = 1;//количество кораблей

int X_shot;//координаты выстрела
int Y_shot;

int human_hits;//попадания по кораблям
int cpu_hits;


};

#endif // GAME_OBSERVE_H
