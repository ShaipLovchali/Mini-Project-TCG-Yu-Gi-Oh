#pragma once
#include "String.h"
#include "Vector.cpp"
#include <iostream>
#include <fstream>

class Card {
protected:
	String name;
public:
	Card();
	Card(const String&);

	virtual size_t getAttackingPoints() const;
	virtual size_t getDefensivePoints() const;
	virtual String getPosition() const;
	virtual size_t getStars() const;
	virtual void switchPosition();
	String getName() const;
	bool operator==(const Card&) const;
	bool operator!=(const Card&) const;
	virtual bool isMonster() const = 0;
	virtual void printCard() const = 0;
};