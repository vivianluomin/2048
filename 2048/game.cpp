#include "gameboard.h"
#include "game.h"
#include <iostream>
#include <sstream>
#include "color.h"


void Game::startGame() {
	gameboard::clearSrccen();
	gameboard::drawTitle();
	play();

}

void Game::play() {
	constexpr auto err_text = "erro_input";
	std::ostringstream os_text;
	os_text << red << err_text <<def<< "\n";
	int array[4][4] = { 0 };
	array[3][3] = 2;
	array[3][2] = 4;
	gameboard::drawArray(array);
	
	char c;
	while (true) {
		std::cin >> c ;
		switch (c)
		{
		case 'w':
			move('w',array);
			break;
		case 's':
			move('s',array);
			break;
		case 'a':
			move('a',array);
			break;
		case 'd':
			move('d',array);
			break;

		default:
			std::cout<< os_text .str();
		}

		if (!gameboard::cango(array)) {
			std::cout << "finish game" << std::endl;
			return;
		}
	}
	
}

void Game::move(char input,int (&array)[4][4]) {
	switch (input)
	{
	case 'w':
		gameboard::moveUp(array);
		break;
	case 's':
		gameboard::moveDown(array);
		break;
	case 'a':
		gameboard::moveLeft(array);
		break;
	case 'd':
		gameboard::moveRight(array);
		break;
	}
}