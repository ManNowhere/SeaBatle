#include <Player_CPU.h>
#include <vector>
#include <iostream>
using namespace std;

   void Player_CPU::init_ship(std::vector<std::vector<int>>& FiCPU, int deckCPU)//генерация кораблей для своего поля
   {
               flag = true;
               while(flag)
               {
                   int X = rand() % 10;
                   int Y = rand() % 10;
                   if(empty_placeCPU(FiCPU, X, Y, deckCPU))
                     {
                         flag = false;
                         for(int k = 0; k < deckCPU; ++k)
                         {
                             FiCPU[Y][X] = '*';
                              ++X;
                         };
                     }
               }

   }

   void Player_CPU::fire_CPU(int &place_ship_X, int &place_ship_Y)//выстрел и оповещение про сделанный ход
   {
//        place_ship_X = rand() % 10;
//        place_ship_Y = rand() % 10;


       cout << "CPU move" << endl;
       cout << "enter coordinates X and Y : " << endl;
       cin >> place_ship_X >> place_ship_Y;
       cout << "X = " << place_ship_X << endl;
       cout << "Y = " << place_ship_Y << endl;
       --place_ship_X;
       --place_ship_Y;

   }

   bool Player_CPU::empty_placeCPU(std::vector<std::vector<int>>& tC, int X1, int Y1, int deck2)//проверяет поле вокруг указанного адреса
   {
       if((X1+deck2) > 10)
       {
           return false;
       }

       for (int y = Y1 - 1; y < (Y1 + 2); ++y)
       {
           for (int x = X1 - 1; x < (X1 + deck2+1); ++x)
           {
               if((x >= 0 && x <= 9) && (y >= 0 && y<= 9))
               {
                   if(tC[y][x] != 0)
                   {
                       return false;
                   }
               }
           }
       }

       return true;
   }

