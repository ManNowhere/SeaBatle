#ifndef MENU_H
#define MENU_H
#include <vector>
#include <Game_observe.h>

class Menu
{
   Game_observe & nVector;
public:
   Menu() : nVector(* new Game_observe) {}
   ~Menu(){}
   int X_coor;
   int Y_coor;
   int num;
   enum Select_
   {
     Level = 1,
     Play,
     Exit
   };

    Game_observe A;

   void Write_Name_Game();//название игры


   void Write_Menu();//меню игры


   void get_coor();//получает размер консольного окна и устанавливает курсор в нужное положение


   void Selection();//содержимое меню

private:


};



#endif // MENU_H
