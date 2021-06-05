#pragma once
#include "Card.h"

class Trap : public Card{
private:
	String effect;
public:
	Trap();
	Trap(const String&, const String&);
	bool isMonster() const;
	void printCard() const;
};