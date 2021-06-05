#include "Card.h"

Card::Card(){}

Card::Card(const String& _name) : name(_name){}

size_t Card::getAttackingPoints() const
{
    return 0;
}

size_t Card::getDefensivePoints() const
{
    return 0;
}

String Card::getPosition() const
{
    return "";
}

size_t Card::getStars() const
{
    return 0;
}

void Card::switchPosition()
{

}

String Card::getName() const
{
    return this->name;
}

bool Card::operator==(const Card& other) const
{
    return this->name == other.name;
}

bool Card::operator!=(const Card& other) const
{
    return !(*this == other);
}
