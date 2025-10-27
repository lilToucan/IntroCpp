#include "Weapon.h"

void Weapon::DealDamage() const
{
	cout << "dealt damage is: " << damage << "\n";
}

void Weapon::PrintInfo() const
{
	cout << "Name: " << name << "\n";
	switch (type)
	{
	case none:
		cout << "type: " << "none" << "\n";
		break;
	case RANGED:
		cout << "type: " << "Ranged" << "\n";
		break;
	case MELEE:
		cout << "Type: " << "Melee" << "\n";
		break;
	default:
		break;
	}
	cout << "Ammo: " << ammo << "\n";
	cout << "Reaload time: " << realoadTime << "\n";
	cout << "Jam chance: " << jamChance << "\n";
	cout << "Damage: " << damage << "\n";

}
