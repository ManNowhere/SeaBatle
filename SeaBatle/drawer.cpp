#include <Drawer.h>
#include <iomanip>
#include <iostream>
#include <windows.h>


using namespace std;

int start_field_player_x;
int start_field_player_y;

void Drawer::draw_field_player( std::vector<std::vector<int>>& vector) // рисует только поле игрока без рамки
{
    int x = 4;
    int y = 3;

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            GoTo(x,y);
            if(vector[i][j] == 'X')
            {
               cout << 'X';
            }
            else if(vector[i][j] != 0 && vector[i][j] != '.')
            {
                cout << '*';
            }
            else if(vector[i][j] == '.')
            {
                cout << '.';
            }
            x += 2;
        }
        ++y;
        x = 4;
    }
}

void Drawer::draw_field_CPU(  std::vector<std::vector<int>>& vector)//рисует только поле компьютера без рамки
{
    int x = 30;
    int y = 3;

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            GoTo(x,y);
            if(vector[i][j] == 'X')
            {
               cout << 'X';
            }
            else if(vector[i][j] != 0 && vector[i][j] != '.')
                {
                    cout << '*';
                }
            else if(vector[i][j] == '.')
            {
                cout << '.';
            }
                x += 2;
        }
        ++y;
        x = 30;
    }
}

void Drawer::draw_border()// рисует буквы и цифры
{
   int x = 0;
   int y = 0;

   char charaster = 97;

   for (int i = 0; i < 10; ++i)//цифры поля игрока
   {
       GoTo(x+1, (y+3)+i);
       cout << setw(2) << i + 1 << endl;

   }

   GoTo(x+3, y+1);
   for (int i = 0; i < 10; ++i)//буквы поля игрока
   {
       cout << setw(2) << charaster;
       ++charaster;
   }

   for (int i = 0; i < 10; ++i)//цифры поля комп.
   {
        GoTo(x+27, y+(3+i));
        cout << setw(2) << i + 1 << endl;
   }

   charaster = 97;
   GoTo(x+29, y+1);
   for (int i = 0; i < 10; ++i)//буквы поля комп.
   {
       cout << setw(2) << charaster;
       ++charaster;
   }
}

void Drawer::draw_borders()//границы игрового поля
{
   int x = 0;
   int y = 0;

   GoTo(x+3, y+2);
   for (int i = 0; i < 10; ++i)//верхняя и правая границы поля игрока
   {
       cout << setw(2) << (char)45;
       if(i == 9)
       {
           for (int i = 0; i < 10; ++i)
           {
               GoTo(x+23, y+3);
               cout << (char)124;
               ++y;
           }
       }
   }

   x = 0;
   y = 0;

   for (int i = 0; i < 10; ++i)//левая и нижняя границы поля игрока
   {
       GoTo(x+3, y+(i+3));
       cout << setw(1) << (char)124;
       if(i == 9)
       {
           GoTo(x+3, y+13);
           for (int i = 0; i < 10; ++i)
           {
               cout << setw(2) << (char)45;
           }
       }
   }


   x = 0;
   y = 0;

   GoTo(x+29, y+2);
   for (int i = 0; i < 10; ++i)// верхняя и правая границы поля комп.
   {
       cout << setw(2) << (char)45;
       if(i == 9)
       {
           for (int i = 0; i < 10; ++i)
           {
               GoTo(x+49, y+3);
               cout << (char)124;
               ++y;
           }
       }
   }

   x = 0;
   y = 0;

   for (int i = 0; i < 10; ++i)//левая и нижняя границы поля комп.
   {
       GoTo(x+29, y+(i+3));
       cout << setw(1) << (char)124;
       if(i == 9)
       {
           GoTo(x+29, y+13);
           for (int i = 0; i < 10; ++i)
           {
               cout << setw(2) << (char)45;
           }
       }
   }

//    cout << endl;
}

void Drawer::GoTo(int x, int y) const//установка курсора в нужную позицию
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

   COORD coord;
   coord.X = x;
   coord.Y = y;

   SetConsoleCursorPosition(hStdOut,coord);
}



