#include <iomanip>
#include <ctime>
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

enum direction { h, v };  // расположение корабля на поле



class Game_observe//содержит поля и следит за окончанием игры
{
public:
    Game_observe() : field_(10, std::vector<int>(10, 0))
    {
//        init_data();
    }
    ~Game_observe(){}

    std::vector<std::vector<int>>& get_vector()
    {
        return field_;
    }


    void shot(int x, int y)//принимает выстрел и проверят, куда попал
    {

    }


    bool Game_over()//конец игры
    {
        return true;
    }

private:

    std::vector<std::vector<int>> field_;

};



class Drawer//рисует все на свете
{
public:
 Drawer():
   start_field_player_x(3),
   start_field_player_y(3)
 {}
 ~Drawer(){}

 void draw_field_player( Game_observe& field_player) const// рисует только поле игрока без рамки
 {
     int x = 4;
     int y = 3;

     auto vector = field_player.get_vector();

     for (int i = 0; i < 10; ++i)
     {
         for (int j = 0; j < 10; ++j)
         {
             GoTo(x,y);
             std::cout << vector[i][j];
             x += 2;
         }
         ++y;
         x = 4;
     }
 }

 void draw_field_CPU( Game_observe& field_cpu)//рисует только поле компьютера без рамки
 {
     int x = 30;
     int y = 3;

     auto vector = field_cpu.get_vector();

     for (int i = 0; i < 10; ++i)
     {
         for (int j = 0; j < 10; ++j)
         {
             GoTo(x,y);
             std::cout << vector[i][j];
             x += 2;
         }
         ++y;
         x = 30;
     }
 }


void draw_border()// рисует буквы и цифры
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

void draw_borders()//границы игрового поля
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
        if(i == 8)
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

    cout << endl;
}


void GoTo(int x, int y) const//установка курсора в нужную позицию
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(hStdOut,coord);
}



private:
int start_field_player_x;
int start_field_player_y;
};

class Player_human
{
public:
    Player_human(){}
    ~Player_human(){}

    void init_ship(Game_observe& my_Field)//создает корабль для своего поля d - количество палуб корабля
    {
//        находит свободную клетку.
//        вызывает функцию, которая проверят возможность установки корабля в это место
//        (корабль должен иметь по одной свободной клетке со всех сторон)
        int X = 9;
        int Y = 9;

        std::vector<std::vector<int>>& Fi = my_Field.get_vector();

        while(deck > 0)
        {
//            X = rand()%10;
//            Y = rand()%10;

            if(Fi[X][Y] == 0)
            {
               if(empty_place(Fi, X, Y))
               {
                  for(int i = 0; i < deck; ++i)
                  {
                      Fi[X][Y] = deck;
                      ++Y;
                  }
                  --deck;
               }
            }            
        }

    }


    bool fire()//выстрел
    {
        return true;
    }


    bool empty_place(std::vector<std::vector<int>>& t, int x, int y)//проверяет поле вокруг указанного адреса
    {
        int row = x - 1;
        int column = y - 1;

        for(int i = 0;i < deck; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if(t[row][column] != 0)
                {
                    return false;
                }
                ++x;
            }
            ++y;
        }

        return true;
    }

private:

    int deck = 4;//палубы корабля
//    int p = 4;//координаты начала поля
//    int t = 3;

};

class Player_CPU
{
public:
    Player_CPU(){}
    ~Player_CPU(){}

    void init_ship()//генерация кораблей для своего поля
    {

    }

    bool turn()//выстрел и оповещение про сделанный ход
    {
        return true;
    }

};







int main()
{

 srand(time(NULL));

 Drawer d;
 Game_observe field_player;
 Game_observe field_cpu;
 Player_human Player;


 d.draw_border();
 d.draw_field_player(field_player);
 d.draw_field_CPU(field_cpu);
 d.draw_borders();
 Player.init_ship(field_player);





//  Game game;
//  game.Run();


 return 0;
}





