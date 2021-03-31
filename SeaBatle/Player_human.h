#ifndef PLAYERHUMAN_H
#define PLAYERHUMAN_H
#include <vector>

class Player_human
{
public:
   Player_human(){}
   ~Player_human(){}

   void init_ship(std::vector<std::vector<int>>& Fi, int deck);//создает корабль для своего поля d - количество палуб корабля

//        находит свободную клетку.
//        вызывает функцию, которая проверят возможность установки корабля в это место
//        (корабль должен иметь по одной свободной клетке со всех сторон)



   bool empty_place(std::vector<std::vector<int>>& t, int X1, int Y1, int deck1);//проверяет поле вокруг указанного адреса


   void fire_human(int &place_ship_X, int &place_ship_Y);//выстрел


private:
   bool flag = true;
};

#endif // PLAYERHUMAN_H
