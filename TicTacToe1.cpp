#include <iostream>
#include <cctype>
//#include <string>
//#include "windows.h"
using namespace std;

char board[9];
bool isover = false;
bool forever = false;
int input;
int counter;

void PrintBoard();
void Reset();
void CheckWinCondition();
void moveX();
void moveO();

int main()
{
	Reset();

	while(!forever)
	{
		PrintBoard();
		moveX();
		CheckWinCondition();
		if(isover == true) break;
		PrintBoard();
		moveO();
		CheckWinCondition();
		if(isover == true) break;
	}
//Insert "Do you want to play again" here??

	return 0;
}

void PrintBoard()
{
	system("cls");
	cout << " " << board[1] << " | " << board[2] << " | " << board[3] <<  endl;
	cout << "---" << "+" << "---" << "+" << "---" << endl;
	cout << " " << board[4] << " | " << board[5] << " | " << board[6] << endl;
	cout << "---" << "+" << "---" << "+" << "---" << endl;
	cout << " " << board[7] << " | " << board[8] << " | " << board[9] << endl;

}

void Reset()
{
	strcpy(board, "0123456789");
}

void CheckWinCondition()
{
	if((board[1] == 'X' && board[2] == 'X' && board[3] == 'X') || (board[1] == 'O' && board[2] == 'O' && board[3] == 'O'))
	{
		PrintBoard();
		cout << board[1] << " je pobjedio!" << endl;
		isover = true;
	}
	else if((board[4] == 'X' && board[5] == 'X' && board[6] == 'X') || (board[4] == 'O' && board[5] == 'O' && board[6] == 'O'))
	{
		PrintBoard();
		cout << board[4] << " je pobjedio!" << endl;
		isover = true;
	}
//Insert all possible win conditions here...
}

void moveX()
{
opet:
	cin >> input;
	if(isalpha(board[input])) goto opet; //Prevents cheating?? 
	board[input] = 'X';
}

void moveO()
{
opet:
	cin >> input;
	if(isalpha(board[input])) goto opet; //Prevents cheating??
	board[input] = 'O';
}
