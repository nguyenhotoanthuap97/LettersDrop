//
//Project Name: LetterDrop
//Author: Nguyen Ho Toan Thu
//Main.cpp
//

#include "Header.h"

//Main
void main()
{
	List *Letter = (List*) malloc(sizeof(List));
	Letter->pHead = NULL;
	Letter->pTail = NULL;
	Node *NewNode = NULL;
	Node *CountNode = NULL;
	int Score = 0;
	bool iskbhit = FALSE;
	int ch = 0;

	boxDraw();
	gotoXY(55, 23);
	printf("Author:Nguyen Ho Toan Thu");

	//Random first stack
	srand(time(NULL));

	for (int i = 0; i < 7; i++)
	{
		NewNode = createNode();
		NewNode->y = (-5) * i - 1;
		insertTail(Letter, NewNode);
	}

	while (1)
	{
		while (!iskbhit)
		{
			CountNode = Letter->pHead;
			while (CountNode != NULL)
			{
				if (CountNode->y == 0)
				{
					gotoXY(CountNode->x, CountNode->y);
					printf("%c", CountNode->Let);
				}
				else if (CountNode->y > 0 && CountNode->y < 24)
				{
					gotoXY(CountNode->x, CountNode->y - 1);
					printf(" ");
					gotoXY(CountNode->x, CountNode->y);
					printf("%c", CountNode->Let);
				}
				else if (CountNode->y == 24)
				{
					gotoXY(CountNode->x, CountNode->y - 1);
					printf(" ");
					gameOver(Score);
					getch();
					return;
				}
				(CountNode->y)++;
				CountNode = CountNode->pNext;
				iskbhit = kbhit();
				if (iskbhit)
				{
					ch = getch();
					if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
					{
						if ((ch == Letter->pHead->Let) || (ch - 32 == Letter->pHead->Let))
						{
							gotoXY(Letter->pHead->x, Letter->pHead->y - 1);
							printf(" ");
							deleteHead(Letter);
							Score++;
							NewNode = createNode();
							NewNode->y = Letter->pTail->y - 5;
							insertTail(Letter, NewNode);
						}
					}
					iskbhit = 0;
				}
			}
			Sleep(100);
		}
	}
}