#include "Deck.h"

void Deck::generateDeck()
{
        Parser parser;
        parser.parseMonstersData();
        parser.parseSpellCardsData();
        parser.parseTrapCardsData();

        for (size_t i = 0; i < 30; ++i)
        {
            size_t randIndex = rand() % 3 + 1;
            Card* card = nullptr;

            if (randIndex == 1) {
                card = parser.getRandomMonster();
            }
            else if (randIndex == 2) {
                card = parser.getRandomSpellCard();
            }
            else {
                card = parser.getRandomTrapCard();
            }
            cards.push_back(card);
        }
}

void Deck::shuffle()
{
    srand(time(0));
    size_t size = sizeof(cards) / sizeof(Card*);
    for (int i = 0; i < size; ++i) {
        int j = i + rand() % (size - i);
        std::swap(cards[i], cards[j]);
    }
}

void Deck::popCard(Card* card)
{
    cards.pop_by_data(card);
}

size_t Deck::deckSize() const
{
    return this->cards.getCapacity();
}

const Card* Deck::operator[](size_t index) const
{
    return this->cards[index];
}

Card* Deck::operator[](size_t index)
{
    return this->cards[index];
}

void Deck::print() const
{
    for (size_t i = 0; i < cards.getCapacity(); i++)
    {
        cards[i]->printCard();
    }
}

