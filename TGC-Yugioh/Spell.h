#pragma once
#include "Card.h"

class Spell : public Card{
private:
	String effect;
public:
	Spell();
	Spell(const String&, const String&);
	bool isMonster() const;
	void printCard() const;
};