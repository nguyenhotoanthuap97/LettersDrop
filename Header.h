//
//Project Name: LetterDrop
//Author: Nguyen Ho Toan Thu
//Header.h
//

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "time.h"
#include "Windows.h"

//Macro set text's colors
#define setTextColor() HANDLE Color; Color = GetStdHandle(STD_OUTPUT_HANDLE);
#define textColor(...) SetConsoleTextAttribute(Color, __VA_ARGS__);

//struct Node Letter
struct Node
{
	int x;
	int y;
	char Let;
	Node *pNext;
};

//struct List
struct List
{
	Node *pHead;
	Node *pTail;
};

//Game over
void gameOver(int Score);

//Box Draw
void boxDraw();

//Random Letter Generate
char randomLetterGenerate();

//Random Longtitude Generate
int randomLongtitudeGenerate();

//Goto x y
void gotoXY(int x, int y);

//Create Node
Node* createNode();

//Insert Node Tail
void insertTail(List *L, Node *NewNode);

//Delete Head
void deleteHead(List *L);

//Color: 7 -> 15