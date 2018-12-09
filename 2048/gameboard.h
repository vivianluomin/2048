#ifndef  GAME_BOARD_H
#define GAME_BOARD_H

class gameboard {

public:
	static void drawTitle();
	static void clearSrccen();
	static void drawArray(int(&)[4][4]);
	static void moveUp(int (&)[4][4]);
	static void moveDown(int(&)[4][4]);
	static void moveLeft(int(&)[4][4]);
	static void moveRight(int(&)[4][4]);
	static bool cango(int(&)[4][4]);
	static void randomLocation(int(&)[4][4]);
};
	


#endif // ! GAME_BOARD_H

