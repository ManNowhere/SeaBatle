#include <iomanip>
#include <iostream>
#include <windows.h>
#include <AllField.h>
#include <Player_human.h>
#include <Drawer.h>
#include <Player_CPU.h>
#include <Game_observe.h>
#include <Menu.h>


int main()
{
srand(time(NULL));

//Game_observe A;
Menu m;

m.A.d.draw_border();

m.A.draw_ships();

m.A.d.draw_field_player(m.A.H.get_vector());

m.A.d.draw_field_CPU(m.A.CP.get_vector());

m.A.d.draw_borders();

m.get_coor();
m.A.d.GoTo(m.X_coor - (strlen("SEA BATLE")/2), m.Y_coor);
m.Write_Name_Game();
m.A.d.GoTo(m.X_coor - (strlen("Menu")/2), m.Y_coor + 3);
m.Write_Menu();
std::cout << std::endl;
m.A.d.GoTo(m.X_coor - (strlen("Enter select: ")/2), m.Y_coor + 5);
m.Selection();

system("cls");



//A.Play();

return 0;
}










