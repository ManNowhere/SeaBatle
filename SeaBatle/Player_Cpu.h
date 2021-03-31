#ifndef PLAYER_CPU_H
#define PLAYER_CPU_H
#include <vector>


class Player_CPU
{
public:
   Player_CPU(){}
   ~Player_CPU(){}

   void init_ship(std::vector<std::vector<int>>& FiCPU, int deckCPU); //генерация кораблей для своего поля

   void fire_CPU(int &place_ship_X, int &place_ship_Y); //выстрел и оповещение про сделанный ход

   bool empty_placeCPU(std::vector<std::vector<int>>& tC, int X1, int Y1, int deck2); //проверяет поле вокруг указанного адреса

private:
   bool flag = true;

};


#endif // PLAYER_CPU_H
