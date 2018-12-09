#ifndef MENU_H
#define MENU_H

class Menu
{
public:
	void start(int err =0);

private:
	void showScore();
	void printMenu();
	void input(int err);
	void startGame();
	void continueGame();
};


#endif // !MENU_H

