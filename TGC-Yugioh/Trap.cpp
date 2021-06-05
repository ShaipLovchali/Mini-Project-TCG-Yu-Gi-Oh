#include "Trap.h"

Trap::Trap() : Card() {}

Trap::Trap(const String& _name, const String& _effect) : Card(_name), effect(_effect) {}

bool Trap::isMonster() const
{
	return false;
}


void Trap::printCard() const
{
	std::cout << this->name << " " << this->effect << std::endl;
}
