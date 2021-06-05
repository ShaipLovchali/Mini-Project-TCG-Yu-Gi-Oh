#include "Spell.h"

Spell::Spell() : Card(){}

Spell::Spell(const String& _name, const String& _effect) : Card(_name), effect(_effect) {}

bool Spell::isMonster() const
{
	return false;
}


void Spell::printCard() const
{
	std::cout << this->name << " " << this->effect << std::endl;
}
