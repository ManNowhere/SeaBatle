#include <Player_human.h>
#include <vector>
#include <iostream>
using namespace std;




   void Player_human::init_ship(std::vector<std::vector<int>>& Fi, int deck)//создает корабль для своего поля d - количество палуб корабля
   {
//        находит свободную клетку.
//        вызывает функцию, которая проверят возможность установки корабля в это место
//        (корабль должен иметь по одной свободной клетке со всех сторон)

               flag = true;

               while(flag)
               {
                   int X = rand() % 10;
                   int Y = rand() % 10;
                   if(empty_place(Fi, X, Y, deck))
                     {
                         flag = false;
                         for(int k = 0; k < deck; ++k)
                         {
                             Fi[Y][X] = '*';
                              ++X;
                         };
                     }
               }
   }

   bool Player_human::empty_place(std::vector<std::vector<int>>& t, int X1, int Y1, int deck1)//проверяет поле вокруг указанного адреса
   {
       if((X1+deck1) > 10)
       {
           return false;
       }

       for (int y = Y1 - 1; y < (Y1 + 2); ++y)
       {
           for (int x = X1 - 1; x < (X1 + deck1+1); ++x)
           {
               if((x >= 0 && x <= 9) && (y >= 0 && y<= 9))
               {
                   if(t[y][x] != 0)
                   {
                       return false;
                   }
               }
           }
       }

       return true;
   }

   void Player_human::fire_human(int &place_ship_X, int &place_ship_Y)//выстрел
   {
//        LPPOINT lpPoint;
//        GetCursorPos(lpPoint);
//        lpPoint->
//        place_ship_X = rand() % 10;
//        place_ship_Y = rand() % 10;

       cout << "human move" << endl;
       cout << "enter coordinates X and Y : " << endl;
       cin >> place_ship_X >> place_ship_Y;
       cout << "X = " << place_ship_X << endl;
       cout << "Y = " << place_ship_Y << endl;
       --place_ship_X;
       --place_ship_Y;

   }

