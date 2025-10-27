#include "IntroCPP.h"
#include <iostream>

int Rettangolo::calcoloArea() const
{
	return altezza * larghezza;
}

void Rettangolo::PrintInfo() const 
{
	std::cout << "Rectangle hight: " << altezza << "\n";
	std::cout << "Rectangle width: " << larghezza << "\n";
}
