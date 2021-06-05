#include "Player.h"

void Player::attackDirectly(Player& other)
{
	int randMonster = rand() % (summoned.getCapacity());
	if (summoned[randMonster]->getPosition() == "defense") {
		summoned[randMonster]->switchPosition();
	}

	other.lifePoints -= summoned[randMonster]->getAttackingPoints();
}

void Player::attack(Player& other)
{
	int randIndex = rand() % (summoned.getCapacity());
	int otherRandIndex = rand() % (other.summoned.getCapacity());

	Card* randMonster = summoned[randIndex];
	Card* otherRandMonster = other.summoned[otherRandIndex];

	if (randMonster->getPosition() == "defense") {
		randMonster->switchPosition();
	}

	if (otherRandMonster->getPosition() == "attack") {
		if (randMonster->getAttackingPoints() > otherRandMonster->getAttackingPoints()) {
			int diff = (randMonster->getAttackingPoints() - otherRandMonster->getAttackingPoints());
			other.destroy(otherRandMonster);
			other.lifePoints -= diff;
		}
		else {
			this->destroy(randMonster);
		}
	}
	else {
		if (randMonster->getAttackingPoints() > otherRandMonster->getDefensivePoints()) {
			other.destroy(otherRandMonster);
		}
		else {
			int diff = otherRandMonster->getDefensivePoints() - randMonster->getAttackingPoints();
			this->lifePoints -= diff;
			this->destroy(randMonster);
		}
	}
}

bool Player::summonMonster(Card* card)
{
	if (card->getStars() >= 10) {
		if (summoned.getCapacity() <= 2) {
			return false;
		}
		summoned.pop_back();
		summoned.pop_back();
		summoned.pop_back();
	}
	else if (card->getStars() >= 8) {
		if (summoned.getCapacity() <= 1) {
			return false;
		}
		summoned.pop_back();
		summoned.pop_back();
	}
	else if (card->getStars() >= 5) {
		if (summoned.getCapacity() == 0) {
			return false;
		}
		summoned.pop_back();
	}
	summoned.push_back(card);
	hand.pop_by_data(card);
	return true;
}

Player::Player()
{
	deck.generateDeck();
	deck.shuffle();
	for (size_t i = 0; i < 6; ++i)
	{
		Card* card = deck[i];
		hand.push_back(card);
		deck.popCard(card);
	}
	lifePoints = 4000;
}

void Player::attackPlayer(Player& other)
{
	this->draw();
	this->summon();

	if (this->summoned.getCapacity() > 0) {
		if (other.summoned.getCapacity() <= 0) {
			this->attackDirectly(other);
		}
		else {
			this->attack(other);
		}
	}
}

void Player::summon()
{
	int randIndex = rand() % hand.getCapacity();
	Card* randCard = hand[randIndex];

	if (randCard->isMonster()) {
		if (summonMonster(randCard)) {
			std::cout << "I'm playing " << randCard->getName() << std::endl;
		}
	}
	else {
		std::cout << "I'm playing " << randCard->getName() << std::endl;
		hand.pop_by_data(randCard);
	}

}

void Player::destroy(Card* card)
{
	summoned.pop_by_data(card);
	graveyard.push_back(card);
}

void Player::draw()
{
	Card* card = deck[0];
	hand.push_back(card);
	deck.popCard(card);
}

size_t Player::getDeckSize() const
{
	return this->deck.deckSize();
}

int Player::getLifePoints()
{
	return this->lifePoints;
}
