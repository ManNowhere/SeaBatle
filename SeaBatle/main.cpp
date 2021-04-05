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

Menu m;

m.get_coor();
m.A.d.GoTo(m.X_coor - (strlen("SEA BATLE")/2), m.Y_coor);
m.Write_Name_Game();
m.A.d.GoTo(m.X_coor - (strlen("Menu")/2), m.Y_coor + 3);
m.Write_Menu();
std::cout << std::endl;
m.A.d.GoTo(m.X_coor - (strlen("Enter select: ")/2), m.Y_coor + 5);
m.Selection();


return 0;
}










