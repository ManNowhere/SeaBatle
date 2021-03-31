#include <iomanip>
#include <iostream>
#include <windows.h>
#include <AllField.h>
#include <Player_human.h>
#include <Drawer.h>
#include <Player_CPU.h>
#include <Game_observe.h>

using namespace std;


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
     Play = 2,
     Exit
   };



   void Write_Name_Game()//название игры
   {
       cout << "SEA BATLE";
   }

   void Write_Menu()//меню игры
   {
       cout << "Menu";
   }

   void get_coor()//получает размер консольного окна и устанавливает курсор в нужное положение
   {
       CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
       GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);

       X_coor = csbiInfo.srWindow.Right / 2;
       Y_coor = csbiInfo.srWindow.Top;

   }

   void Selection()//содержимое меню
   {
       cout << "Enter select: ";
       cin >> num;

       switch (num)
       {
           case Level:
               cout << "Level";//реализовать выбор сложности игры
               break;
           case Play:
               cout << "Play";//запуск игры
               system("cls");
//               nVector.Play();
               break;
           case Exit:
           exit(0);
               cout << "Exit";//выход из игры

               break;
       };
   }



private:



};



int main()
{

srand(time(NULL));
//BOOL GetCursorPos( LPPOINT lpPoint);

Game_observe A;
Menu m;

m.get_coor();
A.d.GoTo(m.X_coor - (strlen("SEA BATLE")/2), m.Y_coor);
m.Write_Name_Game();
A.d.GoTo(m.X_coor - (strlen("Menu")/2), m.Y_coor + 3);
m.Write_Menu();
cout << endl;
A.d.GoTo(m.X_coor - (strlen("Enter select: ")/2), m.Y_coor + 5);
m.Selection();
//system("PAUSE");
system("cls");


A.d.draw_border();

A.draw_ships();

A.d.draw_field_player(A.H.get_vector());

A.d.draw_field_CPU(A.CP.get_vector());

A.d.draw_borders();

A.Play();







return 0;
}










