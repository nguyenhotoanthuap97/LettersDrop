//
//Project Name: LetterDrop
//Author: Nguyen Ho Toan Thu
//Function.cpp
//

#include "Header.h"

//Macro set text's colors
#define setTextColor() HANDLE Color; Color = GetStdHandle(STD_OUTPUT_HANDLE);
#define textColor(...) SetConsoleTextAttribute(Color, __VA_ARGS__);

//Box Draw
//Left: 25 Right: 54
void boxDraw()
{
	for (int i = 0; i < 24; i++)
	{
		gotoXY(25, i);
		printf("%c", 186);
		gotoXY(54, i);
		printf("%c", 186);
	}
}

//Game over
void gameOver(int Score)
{
	for (int i = 25; i < 55; i++)
	{
		for (int j = 10; j < 14; j++)
		{
			gotoXY(i, j);
			printf(" ");
		}
	}
	gotoXY(36, 11);
	printf("GAME OVER");
	gotoXY(34, 12);
	printf("Your Score: %d", Score);
	gotoXY(0, 24);
}

//Random Letter Generate
char randomLetterGenerate()
{
	 int id = 0;
	 id = rand() % 26 + 1;
	 switch (id)
	 {
	 case 1:
		 return 'Q';
	 case 2:
		 return 'W';
	 case 3:
		 return 'E';
	 case 4:
		 return 'R';
	 case 5:
		 return 'T';
	 case 6:
		 return 'Y';
	 case 7:
		 return 'U';
	 case 8:
		 return 'I';
	 case 9:
		 return 'O';
	 case 10:
		 return 'P';
	 case 11:
		 return 'A';
	 case 12:
		 return 'S';
	 case 13:
		 return 'D';
	 case 14:
		 return 'F';
	 case 15:
		 return 'G';
	 case 16:
		 return 'H';
	 case 17:
		 return 'J';
	 case 18:
		 return 'K';
	 case 19:
		 return 'L';
	 case 20:
		 return 'Z';
	 case 21:
		 return 'X';
	 case 22:
		 return 'C';
	 case 23:
		 return 'V';
	 case 24:
		 return 'B';
	 case 25:
		 return 'N';
	 case 26:
		 return 'M';
	 }
	 return 0;
}

//Random Longtitude Generate
int randomLongtitudeGenerate()
{
	int RX = 0;
	RX = (rand() % 10 + 8) * 3 + 2;
	return RX;
}

//Goto x y
void gotoXY(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {x, y};
	SetConsoleCursorPosition(hStdout, position);
}

//Create Node
Node* createNode()
{
	Node *NewNode = (Node*) malloc(sizeof(Node));
	NewNode->Let = randomLetterGenerate();
	NewNode->x = randomLongtitudeGenerate();
	NewNode->pNext = NULL;
	return NewNode;
}

//Insert Node Tail
void insertTail(List *L, Node *NewNode)
{
	if (L->pHead == NULL)
	{
		L->pHead = NewNode;
		L->pTail = L->pHead;
	}
	else
	{
		L->pTail->pNext = NewNode;
		L->pTail = L->pTail->pNext;
	}
}

//Delete Head
void deleteHead(List *L)
{
	Node *p = NULL;
	if (L->pHead != NULL)
	{
		p = L->pHead;
		L->pHead = L->pHead->pNext;
		free(p);
	}
}

//Color: 7 -> 15