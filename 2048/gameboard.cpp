#include "gameboard.h"
#include <sstream>
#include "color.h"
#include <iostream>
#include <math.h>
#include <string>
#include <cstdio>
#include <iomanip>



 void  gameboard::drawTitle() {
	//原始字符串常量
	constexpr auto title_card_2048 = R"(
   /\\\\\\\\\          /\\\\\\\                /\\\         /\\\\\\\\\
  /\\\///////\\\      /\\\/////\\\            /\\\\\       /\\\///////\\\
  \///      \//\\\    /\\\    \//\\\         /\\\/\\\      \/\\\     \/\\\
             /\\\/    \/\\\     \/\\\       /\\\/\/\\\      \///\\\\\\\\\/
           /\\\//      \/\\\     \/\\\     /\\\/  \/\\\       /\\\///////\\\
         /\\\//         \/\\\     \/\\\   /\\\\\\\\\\\\\\\\   /\\\      \//\\\
        /\\\/            \//\\\    /\\\   \///////////\\\//   \//\\\      /\\\
        /\\\\\\\\\\\\\\\   \///\\\\\\\/              \/\\\      \///\\\\\\\\\/
        \///////////////      \///////                \///         \/////////
  )";

	std::ostringstream title_card_richtext;
	title_card_richtext << green << bold_on << title_card_2048 << bold_off << def;
	title_card_richtext << "\n\n\n";
	std::cout << title_card_richtext.str();
}

 void gameboard::clearSrccen() {
	system("cls");
}

 void gameboard::moveUp(int(&array)[4][4]) {
	int  a[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		int k = 0;
		for (int j = 0; j < 4; j++) {
			if (array[j][i] != 0) {
				a[k][i] = array[j][i];
				k++;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[j][i]!=0&&a[j][i] == a[j + 1][i]) {
				a[j][i] *= 2;
				a[j + 1][i] = 0;
			}
		}
	}

	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 3; j++) {
			if (a[j][i] == 0&& a[j + 1][i]!=0) {
				a[j][i] = a[j + 1][i];
				a[j + 1][i] = 0;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			array[i][j] = a[i][j];
		}
	}

	randomLocation(array);
	clearSrccen();
	drawTitle();
	drawArray(array);
}

 void gameboard::moveDown(int (&array)[4][4]) {

	int  a[4][4] = { 0 };
	for (int i = 3; i >= 0; i--) {
		int k = 3;
		for (int j = 3; j >= 0; j--) {
			if (array[j][i] != 0) {
				a[k][i] = array[j][i];
				k--;
			}
		}
	}

	for (int i = 3; i >=0; i--) {
		for (int j = 3; j >0; j--) {
			if (a[j][i] != 0 && a[j][i] == a[j - 1][i]) {
				a[j][i] *= 2;
				a[j - 1][i] = 0;
			}
		}
	}

	for (int i = 2; i >=0; i--) {
		for (int j = 2; j >0; j--) {
			if (a[j][i] == 0 && a[j- 1][i] != 0) {
				a[j][i] = a[j - 1][i];
				a[j - 1][i] = 0;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			array[i][j] = a[i][j];
		}
	}
	randomLocation(array);
	clearSrccen();
	drawTitle();
	drawArray(array);

}

 void gameboard::moveLeft(int(&array)[4][4]) {
	int  a[4][4] = { 0 };
	for (int i = 0; i < 4; i++) {
		int k = 0;
		for (int j = 0; j < 4; j++) {
			if (array[i][j] != 0) {
				a[i][k] = array[i][j];
				k++;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j] != 0 && a[i][j] == a[i][j + 1]) {
				a[i][j] *= 2;
				a[i][j + 1] = 0;
			}
		}
	}

	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 3; j++) {
			if (a[i][j] == 0 && a[i][j + 1] != 0) {
				a[i][j] = a[i][j + 1];
				a[i][j + 1] = 0;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			array[i][j] = a[i][j];
		}
	}

	randomLocation(array);
	clearSrccen();
	drawTitle();
	drawArray(array);
}

 void gameboard::moveRight(int(&array)[4][4]) {
	int a[4][4] = { 0 };
	for (int i = 3; i >= 0; i--) {
		int k = 3;
		for (int j = 3; j >= 0; j--) {
			if (array[i][j] != 0) {
				a[i][k] = array[i][j];
				k--;
			}
		}
	}

	for (int i = 3; i >= 0; i--) {
		for (int j = 3; j > 0; j--) {
			if (a[i][j] != 0 && a[i][j] == a[i][j - 1]) {
				a[i][j] *= 2;
				a[i][j - 1] = 0;
			}
		}
	}
	
	for (int i = 2; i >= 0; i--) {
		for (int j = 2; j > 0; j--) {
			if (a[i][j] == 0 && a[i][j - 1] != 0) {
				a[i][j] = a[i][j - 1];
				a[i][j - 1] = 0;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			array[i][j] = a[i][j];
		}
	}

	randomLocation(array);
	clearSrccen();
	drawTitle();
	drawArray(array);
	
}

 bool gameboard::cango(int(&a)[4][4]) {

	for(int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 3||j==3) {
				if (i == 3&&j!=3) {
					if (a[i][j] == a[i][j + 1]) {
						return true;

					}

					if (j == 3&&i!=3) {
						if (a[i][j] == a[i + 1][j]) {
							return true;
						}
					}
				}
			}
			else {
				if (a[i][j] == a[i + 1][j] || a[i][j] == a[i][j + 1]) {
					return true;
				}
			}


		}
	}
	return false;
}

 void gameboard::randomLocation(int(&array)[4][4]) {
	 std::cout << "rand  rand" << std::endl;
	int count = 0;
	int ss[16][2];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (array[i][j] == 0) {
				ss[count][0] = i;
				ss[count][1] = j;
				count++;
			}
		}
	}
	if (count > 0) {
	
	int f = rand() % count;
	std::cout << f << std::endl;
	int i1 = ss[f][0];
	int j1 = ss[f][1];
	std::cout << i1<<"  "<<j1 << std::endl;
	if (count >= 2) {
	int sec = rand() % count;
	int i2 = ss[sec][0];
	int j2 = ss[sec][1];
	array[i2][j2] = 4;
	}
	
	array[i1][j1] = 2;
	
	}
	
	std::cout << "rand  rand" << std::endl;
}

 void gameboard::drawArray(int (&arrays)[4][4]) {
	constexpr auto top_board =
		"┌───────────────────────────┐"; // Multibyte character set
	constexpr auto bottom_board =
		"└───────────────────────────┘"; // Multibyte character set

	std::cout << top_board << std::endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout <<std::setw(5)<<std::setiosflags(std::ios::left)<<arrays[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << bottom_board << std::endl;

}


