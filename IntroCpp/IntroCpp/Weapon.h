#pragma once
#include <iostream>
using namespace std;

enum WeaponType
{
	none,
	RANGED,
	MELEE,
};

class Weapon
{

private:
	string name = "";
	WeaponType type = none;
	int ammo = 0;
	float realoadTime = .0f;
	float jamChance = .0f;
	int damage = 0;

public:

	void DealDamage() const;

	void PrintInfo() const;

	Weapon(string weaponName, WeaponType weaponType, int dmg)
	{
		name = weaponName;
		type = weaponType;
		damage = dmg;
	}

};


/*

Creare una classe Weapon, con i seguenti membri:

nome arma
tipo
munizioni
tempoRicarica
inceppata
danno

metodo:

applicaDanno() -> stampare il danno e ritorna anche il danno

Informazioni() -> stampare le info base

Construttore custom (nome, tipo, danno)

*/