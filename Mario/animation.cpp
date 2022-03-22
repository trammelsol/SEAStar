#include"animation.h"
void Action() {
	for (int step = 61,UserStep=1;step >= 12; step -= 12 , UserStep +=20) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED);
		cout << setw(UserStep) << "            ********       " << endl;
		cout << setw(UserStep) << "           ************    " << endl;
		cout << setw(UserStep) << "           ####....#.      " << endl;
		cout << setw(UserStep) << "         #..###.....##...  " << endl;
		cout << setw(UserStep) << "         ###.......######  " << setw(step); 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY 
			|FOREGROUND_RED | FOREGROUND_GREEN); cout<< "      ### " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY 
			| FOREGROUND_RED);
		cout << setw(UserStep) << "            ...........    " << setw(step); 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
			| FOREGROUND_RED | FOREGROUND_GREEN); cout<< "     #...#" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
			| FOREGROUND_RED);
		cout << setw(UserStep) << "           ##*#######      " << setw(step);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
			| FOREGROUND_RED | FOREGROUND_GREEN); cout<< "     #.#.#" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
			| FOREGROUND_RED);
		cout << setw(UserStep) << "        ####*******######  " << setw(step);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
			| FOREGROUND_RED | FOREGROUND_GREEN); cout<< "     #.#.#" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
			| FOREGROUND_RED);
		cout << setw(UserStep) << "       ...#***.****.*###.. " << setw(step);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
			| FOREGROUND_RED | FOREGROUND_GREEN); cout<< "     #...#" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
			| FOREGROUND_RED);
		cout << setw(UserStep) << "       ....**********##... " << setw(step);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
			| FOREGROUND_RED | FOREGROUND_GREEN); cout<< "      ### " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout << setw(UserStep) << "       ....****    *****.. " << endl;
		cout << setw(UserStep) << "         ####        ####  " << endl;
		cout << setw(UserStep) << "       ######        ######" << endl;
		cout << setw(UserStep) << "       @@@@@@        @@@@@@" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_GREEN);
		cout << "##############################################################              ##################################" << endl;
		cout << "#...#......#.##...#......#.##...#......#.##------------------#              #...#......#.##------------------#" << endl;
		cout << "###########################################------------------#              ###############------------------#" << endl;
		cout << "#..#....#....##..#....#....##..#....#....#####################              #..#....#....#####################" << endl;
		cout << "##########################################    #----------#                  ##############    #----------#" << endl;
		cout << "#.....#......##.....#......##.....#......#    #----------#                  #.....#......#    #----------#" << endl;
		cout << "##########################################    #----------#                  ##############    #----------#" << endl;
		cout << "#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#                  #.#..#....#..#    #----------#" << endl;
		Sleep(200 + step);
		system("cls");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}