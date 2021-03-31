#include <Menu.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
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
//       cout << "Level" << endl;
//       cout << "Play" << endl;
//       cout << "Exit" << endl;
       cout << "Enter select: ";

       cin >> num;

       switch (num)
       {
           case 1:
               cout << "Level";//реализовать выбор сложности игры
               break;
           case 2:
               cout << "Play";//запуск игры
               A.Play();
               //system("cls");
               break;
           case 3:
           exit(0);
               cout << "Exit";//выход из игры
       };
   }

