#include <Game_observe.h>
#include <iostream>
using namespace std;



void Game_observe::Game_over(int &Xh, int &Xc)//конец игры
{
   if(Xh == 20)
   {
       cout << "Human won" << endl;
       return;
   }
   else if(Xc == 20)
   {
       cout << "CPU won" << endl;
       return;
   }
   return;
}

void Game_observe::draw_ships()//рисует все корабли на поле игрока
{
   for (int i = 0; i < 4; ++i)
   {
       for (int j = 0; j < number; ++j)
       {
          Player.init_ship(H.get_vector(), deck2);
          CPU.init_ship(CP.get_vector(), deck2);
       }
       --deck2;
       ++number;
   }
}

bool Game_observe::hit_check(std::vector<std::vector<int>> &field_, int X, int Y, int &hits)//отмечает попадние на поле
{
   if(field_[Y][X] == '*')
   {
       ++hits;
       field_[Y][X] = 'X';
       return true;
   }
   return false;
}

void Game_observe::Play()//игровой процесс
{
   while(1)
   {
       Shot = true;
       while (Shot)
       {
           d.GoTo(0, 14);
           Player.fire_human(X_shot, Y_shot);
           if(hit_check(CP.get_vector(), X_shot, Y_shot, human_hits))
           {
               d.draw_field_CPU(CP.get_vector());
               if(human_hits == 20)
               {
                   Game_over(human_hits, cpu_hits);
                   return ;
               }
           }
           else
           {
               CP.get_vector()[Y_shot][X_shot] = '.';
               d.draw_field_CPU(CP.get_vector());
               Shot = false;
           }
       }


       Shot = true;
       while (Shot)
       {
           d.GoTo(0, 14);
           CPU.fire_CPU(X_shot, Y_shot);
           if(hit_check(H.get_vector(), X_shot, Y_shot, cpu_hits))
           {
               d.draw_field_player(H.get_vector());

               if(cpu_hits == 20)
               {
                   Game_over(human_hits, cpu_hits);
                   return ;
               }
           }
           else
           {
               H.get_vector()[Y_shot][X_shot] = '.';
               d.draw_field_player(H.get_vector());
               Shot = false;
           }

       }
   }
}




