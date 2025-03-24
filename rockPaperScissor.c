#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int genRand()
{
	srand(time(0));
	return (rand()%3)+1; //Returns a random integer between 1 and 3
}
int gameEngine(int input)
{
	int randomGen=genRand();
	if(randomGen==input)
		return 0;	//Draw
	else if(randomGen==1&&input==2||randomGen==2&&input==3||randomGen==3&&input==1)
		return 1;	//Player Won
	else if(randomGen==1&&input==3||randomGen==3&&input==2||randomGen==2&&input==1)
		return -1;	//Player Lost

}
int main()
{
	int userInp,choice,playerPts=0,attemptNum=1;
	do{
		printf("\n\t\t\t ROCK PAPER SCISSORS\n");
		printf("\t\t\t----------------------\n\n");
		printf("\t Game Points: %d \t Attemps: %d\n\n",playerPts,attemptNum);
		printf("\t1. Start Game\n\t0. Exit Game\n");
		printf("\tEnter Your Choice: ");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\n\t1. Rock\n\t2. Paper\n\t3. Scissors\n");
			printf("\tEnter Your Choice: ");
			scanf("%d",&userInp);
			int retVar=gameEngine(userInp);		//Return Variable 
			attemptNum++;
			if(retVar==0)
				printf("Both You and Machine took the same choice! Draw(+0pts)\n");
			else if(retVar==-1)
			{
				printf("You Lost! -10pts\n");
				playerPts=playerPts-10;
			}
			else if(retVar==1)
			{
				printf("You Won! +10pts\n");
				playerPts=playerPts+10;
			}
		}
	}while(choice!=0);
}
