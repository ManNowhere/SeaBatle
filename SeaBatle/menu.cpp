#include <Menu.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;


   void Menu::Write_Name_Game()//название игры
   {
       cout << "SEA BATLE";
   }

   void Menu::Write_Menu()//меню игры
   {
       cout << "Menu";
   }

   void Menu::get_coor()//получает размер консольного окна и устанавливает курсор в нужное положение
   {
       CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
       GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);

       X_coor = csbiInfo.srWindow.Right / 2;
       Y_coor = csbiInfo.srWindow.Top;

   }

   void Menu::Selection()//содержимое меню
   {
       cout << "Enter select: ";

       num = cin.get();
       while(cin)
       {
           cin.sync();
           if(((num > 48) &&( num < 52)))
           {
           switch (num)
               {
                   case 49:
                       cout << "Level";//реализовать выбор сложности игры
                       return;
                   case 50:
                       cout << "Play";//запуск игры
                       system("cls");
                       A.d.draw_border();
                       A.draw_ships();
                       A.d.draw_field_player(A.H.get_vector());
                       A.d.draw_field_CPU(A.CP.get_vector());
                       A.d.draw_borders();
                       A.Play();
                       break;
                   case 51:
        //               exit(0);
                   return;
               };

                  // _getche();
            }
           A.d.GoTo(X_coor + (strlen("Enter select: ")/2), Y_coor + 5);
           cout << " ";
           A.d.GoTo(X_coor + (strlen("Enter select: ")/2), Y_coor + 5);
           num = cin.get();

        }

   }

