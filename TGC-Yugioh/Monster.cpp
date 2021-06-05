#include "Monster.h"

Monster::Monster() : Card(), stars(0), attackingPoints(0), defensivePoints(0), position(nullptr) {}

Monster::Monster(const String& _name, size_t _stars, size_t _attackingPoints, size_t _defensivePoints, const String& _position) 
            : Card(_name), stars(_stars), attackingPoints(_attackingPoints), defensivePoints(_defensivePoints), position(_position) {}

size_t Monster::getAttackingPoints() const
{
    return this->attackingPoints;
}

size_t Monster::getDefensivePoints() const
{
    return this->defensivePoints;
}

String Monster::getPosition() const
{
    return this->position;
}

size_t Monster::getStars() const
{
    return this->stars;
}

void Monster::switchPositon()
{
    if (position == "attack") {
        position = "defense";
        return;
    }
    position = "attack";
}

bool Monster::isMonster() const
{
    return true;
}

void Monster::printCard() const
{
    std::cout << this->name << " " << this->stars << " " << this->attackingPoints << " " << this->defensivePoints << " " << this->position << std::endl;
}
