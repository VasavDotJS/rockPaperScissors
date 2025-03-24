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
