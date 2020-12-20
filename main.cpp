#include <iomanip>
#include <ctime>
#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>


using namespace std;

enum direction { h, v };  // расположение корабля на поле

class All_field//содержит игровые поля
{
    public:
    All_field() : field_(10, std::vector<int>(10, 0))
    {}
    ~All_field(){}


    std::vector<std::vector<int>>& get_vector()//создается игровое поле
    {
        return field_;
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

 void draw_field_player( std::vector<std::vector<int>>& vector) // рисует только поле игрока без рамки
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
             else if(vector[j][i] == '.')
             {
                 cout << '.';
             }
             x += 2;
         }
         ++y;
         x = 4;
     }
 }

 void draw_field_CPU(  std::vector<std::vector<int>>& vector)//рисует только поле компьютера без рамки
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
             else if(vector[j][i] == '.')
             {
                 cout << '.';
             }
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

    void init_ship(std::vector<std::vector<int>>& Fi, int deck)//создает корабль для своего поля d - количество палуб корабля
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

    bool empty_place(std::vector<std::vector<int>>& t, int X1, int Y1, int deck1)//проверяет поле вокруг указанного адреса
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

    bool fire_human(int &place_ship_X, int &place_ship_Y)//выстрел
    {
//        LPPOINT lpPoint;
//        GetCursorPos(lpPoint);
//        lpPoint->
//        place_ship_X = rand() % 10;
//        place_ship_Y = rand() % 10;

        cout << endl << "human move" << endl;
        cout << "enter coordinates X and Y : " << endl;
        cin >> place_ship_X >> place_ship_Y;
        --place_ship_X;
        --place_ship_Y;
        return true;

    }

private:
    bool flag = true;
};

class Player_CPU
{
public:
    Player_CPU(){}
    ~Player_CPU(){}

    void init_ship(std::vector<std::vector<int>>& FiCPU, int deckCPU)//генерация кораблей для своего поля
    {
//        std::vector<std::vector<int>>& FiCPU = my_FieldCPU.get_vector();

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

    bool fire_CPU(int &place_ship_X, int &place_ship_Y)//выстрел и оповещение про сделанный ход
    {
//        place_ship_X = rand() % 10;
//        place_ship_Y = rand() % 10;


        cout << "CPU move" << endl;
        cout << "enter coordinates X and Y : " << endl;
        cin >> place_ship_X >> place_ship_Y;
        --place_ship_X;
        --place_ship_Y;
        return true;


    }

    bool empty_placeCPU(std::vector<std::vector<int>>& tC, int X1, int Y1, int deck2)//проверяет поле вокруг указанного адреса
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


private:
    bool flag = true;

};

class Game_observe//следит за игрой
{
public:
    Game_observe() : human_hits(0), cpu_hits(0)
    {}
    ~Game_observe()
    {}

All_field H;
All_field CP;
Drawer d;
Player_human Player;
Player_CPU CPU;

void Game_over(int &Xh, int &Xc)//конец игры
{
    if(Xh == 20)
    {
        std::cout << "Human won" << endl;
        return;
    }
    else if(Xc == 20)
    {
        std::cout << "CPU won" << endl;
        return;
    }
    return;
}

void draw_ships()//рисует все корабли на поле игрока
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
    std::cout << endl;
}

bool hit_check(std::vector<std::vector<int>> &field_, int X, int Y, int &hits)//отмечает попадние на поле
{
    if(field_[Y][X] == '*')
    {
        ++hits;
        field_[Y][X] = 'X';
        return true;
    }
    return false;
}

void Play()//игровой процесс
{
    while(1)
    {
        Shot = true;
        while (Shot)
        {
            d.GoTo(0, 15);
            Player.fire_human(X_shot, Y_shot);
            if(hit_check(CP.get_vector(), X_shot, Y_shot, human_hits))
            {
                d.draw_field_CPU(CP.get_vector());
                d.GoTo(0, 15);

                if(human_hits == 20)
                {
                    Game_over(human_hits, cpu_hits);
                    return ;
                }
            }
            else
            {
                CP.get_vector()[X_shot][Y_shot] = '.';
                d.draw_field_CPU(CP.get_vector());
                d.GoTo(0, 15);
                Shot = false;
            }

        }


        Shot = true;
        while (Shot)
        {
            d.GoTo(0, 15);
            CPU.fire_CPU(X_shot, Y_shot);
            if(hit_check(H.get_vector(), X_shot, Y_shot, cpu_hits))
            {
                d.draw_field_player(H.get_vector());
                d.GoTo(0, 15);

                if(cpu_hits == 20)
                {
                    Game_over(human_hits, cpu_hits);
                    return ;
                }
            }
            else
            {
                H.get_vector()[X_shot][Y_shot] = '.';
                d.draw_field_player(H.get_vector());
                d.GoTo(0, 15);
                Shot = false;
            }

        }
    }
}


bool Shot;

int deck2 = 4;//палубы корабля
int number = 1;//количество кораблей

int X_shot;//координаты выстрела
int Y_shot;

int human_hits;//попадания по кораблям
int cpu_hits;

private:
};





int main()
{

 srand(time(NULL));
//BOOL GetCursorPos( LPPOINT lpPoint);

Game_observe A;

A.d.draw_border();

A.draw_ships();

A.d.draw_field_player(A.H.get_vector());
A.d.draw_field_CPU(A.CP.get_vector());
A.d.draw_borders();
//cout << endl << endl;

A.Play();



//переделать выстрел

 return 0;
}








