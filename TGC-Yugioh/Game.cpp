#include "Game.h"

void Game::start()
{
	while (player1.getLifePoints() > 0 && player2.getLifePoints() > 0 && player1.getDeckSize() > 0 && player2.getDeckSize() > 0) {
		player1.attackPlayer(player2);

		player2.attackPlayer(player1);
	}

	std::cout << "----------------------" << std::endl;
	if (player1.getLifePoints() <= 0 || player1.getDeckSize() <= 0) {
		std::cout << "The winner is player 2" << std::endl;
	}
	else {
		std::cout << "The winner is player 1" << std::endl;
	}
}
