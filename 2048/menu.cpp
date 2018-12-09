#include "menu.h"
#include <string>
#include <iostream>
#include <sstream>
#include "game.h"
#include "gameboard.h"
#include "color.h"

using namespace std;

void  Menu::start(int err) {
	constexpr auto greetings_text = "Welcome to ";
	constexpr auto gamename_text = "2048";
	constexpr auto sp = "  ";

	ostringstream str_os;
	ostringstream title_richtext;

	title_richtext << bold_on << sp << greetings_text << blue << gamename_text
		<< def << bold_off << "\n";

	constexpr auto menu_entry_text = R"(
				1. Play a New Game
				2. Continue Previous Game
				3. View Highscores and Statistics
				4. Exit
		)";

	gameboard::clearSrccen();
	gameboard::drawTitle();
	str_os << title_richtext.str();
	str_os << menu_entry_text;
	cout << str_os.str();
	input(err);

}

void Menu::input(int err) {
	constexpr auto err_input_text = "Invalid input. Please try again.";
	constexpr auto prompt_choice_text = "Enter Choice: ";
	constexpr auto sp = "  ";

	ostringstream str_os;
	ostringstream err_input_richtext;
	err_input_richtext << red <<sp<< err_input_text << def << "\n\n";
	ostringstream choice_text;
	choice_text << sp << prompt_choice_text;

	if (err) {
		str_os << err_input_richtext.str();
	}

	str_os << choice_text.str();
	cout << str_os.str();
	char c;
	cin >> c;

	switch (c)
	{
	case '1':
		startGame();
		break;
	case '2':
		//continueGame();
		break;
	case '3':
		//showScore();
		break;
	case '4':
		exit(0);
	default:
		start(1);
		break;
	}

}

void Menu::startGame() {

	Game game;
	game.startGame();

}
