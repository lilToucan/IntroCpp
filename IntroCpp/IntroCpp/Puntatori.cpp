#include "Puntatori.h"
#include <iostream>
Puntatore::Puntatore()
{
}

Puntatore::~Puntatore()
{
}

void Puntatore::IntPointerFunction()
{
	// &value == pointer of value 
	intPointer = &HP;

	*intPointer = 150;

	// *pointer == value of said pointer
	std::cout << "Value: " <<HP << "\n";

	intPointer = arrayInt; // basicly doing &arrayInt[0] 
	intPointer = intPointer + 2; // in this case this would be arrayInt[2] (0+2)

	
}
