#pragma once
#include "Card.h"

class Monster : public Card {
private:
	size_t stars;
	size_t attackingPoints;
	size_t defensivePoints;
	String position;

public:
	Monster();
	Monster(const String&, size_t, size_t, size_t, const String&);

	size_t getAttackingPoints() const;
	size_t getDefensivePoints() const;
	String getPosition() const;
	size_t getStars() const;
	void switchPositon();
	bool isMonster() const;
	void printCard() const;
};
