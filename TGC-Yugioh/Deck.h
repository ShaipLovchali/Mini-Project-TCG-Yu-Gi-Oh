#pragma once
#include "Parser.h"

class Deck {
private:
	Vector<Card*> cards;
public:
	void generateDeck();
	void shuffle();
	void popCard(Card*);
	size_t deckSize() const;
	const Card* operator[](size_t) const;
	Card* operator[](size_t);
	void print() const;
};