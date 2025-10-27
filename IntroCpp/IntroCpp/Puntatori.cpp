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
	std::cout << "Value: " << HP << "\n";
	std::cout << "10 * (*intPointer): " << 10 * (*intPointer) << "\n";

	intPointer = arrayInt; // basicly doing &arrayInt[0] 
	intPointer = intPointer + 2; // in this case this would be arrayInt[2] (0+2)


}

int Puntatore::Damage(int dmg, int dmgMult, int* totDmg)
{
	if (totDmg == nullptr)
		return -1;

	return *totDmg = dmg * dmgMult;
}

int Puntatore::DamageRef(int dmg, int dmgMult, int& totDmg)
{

	return totDmg = dmg * dmgMult;
}
