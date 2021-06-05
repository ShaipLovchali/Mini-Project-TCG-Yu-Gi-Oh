#include "Parser.h"

void Parser::splitCommand(const String& input)
{
    splitted.clear();

    String subStr;
    for (size_t i = 0; input[i]; ++i)
    {
        if (input[i] == ' ') {
            splitted.push_back(subStr);
            subStr.clear();
            continue;
        }
        subStr.pushBack(input[i]);
    }

    splitted.push_back(subStr);
}

void Parser::parseMonstersData()
{
    std::ifstream monsters("monstersData.txt");

    while (monsters.good()) {
        String input;
        monsters >> input;

        monstersData.push_back(input);
    }
}

void Parser::parseSpellCardsData()
{
    std::ifstream spellCards("spellCardsData.txt");

    while (spellCards.good()) {
        String input;
        spellCards >> input;

        spellCardsData.push_back(input);
    }
}

void Parser::parseTrapCardsData()
{
    std::ifstream trapCards("trapCardsData.txt");

    while (trapCards.good()) {
        String input;
        trapCards >> input;

        trapCardsData.push_back(input);
    }
}

Card* Parser::getRandomMonster()
{
    size_t index = rand() % monstersData.getCapacity();
    splitCommand(monstersData[index]);
    monstersData.pop_by_data(monstersData[index]);

    return new Monster(splitted[0], splitted[1].stod(), splitted[2].stod(), splitted[3].stod(), splitted[4]);
}

Card* Parser::getRandomSpellCard()
{
    size_t index = rand() % spellCardsData.getCapacity();
    splitCommand(spellCardsData[index]);
    spellCardsData.pop_by_data(spellCardsData[index]);

    return new Spell(splitted[0], splitted[1]);
}

Card* Parser::getRandomTrapCard()
{
    size_t index = rand() % trapCardsData.getCapacity();
    splitCommand(trapCardsData[index]);
    trapCardsData.pop_by_data(trapCardsData[index]);

    return new Trap(splitted[0], splitted[1]);
}
