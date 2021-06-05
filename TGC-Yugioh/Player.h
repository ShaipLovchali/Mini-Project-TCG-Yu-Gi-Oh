#pragma once
#include "Card.h"
#include "Deck.h"

class Player {
private:
	Deck deck;
	Vector<Card*> hand;
	Vector<Card*> summoned;
	Vector<Card*> graveyard;
	int lifePoints;

	void attackDirectly(Player&);
	void attack(Player&);
	bool summonMonster(Card*);
public:
	Player();
	void attackPlayer(Player&);
	void summon();
	void destroy(Card*);
	void draw();
	size_t getDeckSize() const;
	int getLifePoints();
};