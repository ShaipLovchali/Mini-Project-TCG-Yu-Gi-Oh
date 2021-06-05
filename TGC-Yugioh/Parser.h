#pragma once
#include "Card.h"
#include "Monster.h"
#include "Spell.h"
#include "Trap.h"
#include <ctime>

class Parser {
private:
	Vector<String> monstersData;
	Vector<String> spellCardsData;
	Vector<String> trapCardsData;

	Vector<String> splitted;
	void splitCommand(const String&);
public:
	void parseMonstersData();
	void parseSpellCardsData();
	void parseTrapCardsData();
	Card* getRandomMonster();
	Card* getRandomSpellCard();
	Card* getRandomTrapCard();
};