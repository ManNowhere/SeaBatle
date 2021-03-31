#ifndef DRAWER_H
#define DRAWER_H
#include <vector>

class Drawer//рисует все на свете
{
public:
Drawer():
  start_field_player_x(3),
  start_field_player_y(3)
{}
~Drawer(){}

void draw_field_player( std::vector<std::vector<int>>& vector);// рисует только поле игрока без рамки

void draw_field_CPU(  std::vector<std::vector<int>>& vector); //рисует только поле компьютера без рамки

void draw_border(); // рисует буквы и цифры

void draw_borders(); //границы игрового поля



void GoTo(int x, int y)const; //установка курсора в нужную позицию


private:
int start_field_player_x;
int start_field_player_y;
};








#endif // DRAWER_H
