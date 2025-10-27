#pragma once
#include "Weapon.h"

class Puntatore
{
public:
	Puntatore();
	~Puntatore();
	
	int value = 42;

	int* intPointer = nullptr;
	
	char* charPointer = nullptr;

	Weapon* weaponPointer = nullptr;

	int arrayInt[5] = { 1,2,3,4,5 };

	void IntPointerFunction();

private:
	int HP = 100;

};

