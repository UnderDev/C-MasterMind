#include "Header.h"
#define NumMainMenuItems 6
#define MaxNumOfGuesses 15

 //Header Functions
 void MainHeader();

 //Txt File reading/Writing
 void WriteToFile(void);
 void ReadFromFile(int iScoresFill[]);

 //Game Functions
 void Rules();
 void NoOfGuesses();
 void RandomizeTheArray();
 void ChkPosAndCmpArray();
 void UserGuess();
 void ChkAllPins();
 void GroupUsefullFunctions();
 void ResetScores();
 void CalcWinsAndLosses();
 int test();

 //Variables
 int iCompArrayNum[8], iUserArrayNum[7];
 int i, iGuessNum = 1, iChoice, iNoOfGuesses, iCheckForInt = 0, iScores[4];
 int iWins, iLosses, iCntGamesPlayed, iPercentWins, iPercentLosses,count = 0;;

//   *ShowMenu
void ShowMenu()//MENU
{
	CalcWinsAndLosses();
	do
	{
		system("cls");//clears command

		MainHeader();

		printf("\n\nOptions: 1, 2, 3, 4, 5 or 6\n");
		printf("\n1: Easy");
		printf("\n2: Medium");
		printf("\n3: Hard");
		printf("\n4: Rules");
		printf("\n5: Reset Scores");
		printf("\n6: Exit");
		printf("\n\nChoice: ");

		fflush(stdin);
		scanf_s("%d",&iChoice);

		iCheckForInt = iChoice;	//validation to only get numbers

		switch (iChoice)
		{
			case 1:
			case 2:
			case 3:
			{
				GroupUsefullFunctions();
				break;
			}
			case 4:
			{
				Rules();
				break;
			}
			case 5:
			{
				ResetScores();		
				break;
			}
			case 6:
			{
				exit(0);
				break;
			}
			default:
			{
				ShowMenu();
			}
		}//Switch
	} while ((iChoice < 1) || (iChoice > NumMainMenuItems) || (iChoice != iCheckForInt));
}//End ShowMenu();

//   *CalcWinsAndLosses
void CalcWinsAndLosses()
{
	double winScore = 0.0, loseScore = 0.0;

	ReadFromFile(iScores);//Read In the File

	iWins = iScores[0];//Store iScore at pos [0] in iWins
	iLosses = iScores[1];//Store iScore at pos [1] in iLosses
	iCntGamesPlayed = iScores[2];//Store iScore at pos [2] in iCntGamesPlayed


	if (iCntGamesPlayed > 0)//Only Calc %score if games played > 0
	{
		winScore = (iWins * 100.00) / iCntGamesPlayed + 0.5;//Calc to get persentage of winScore +0.5 To Round up
		loseScore = (iLosses * 100.00) / iCntGamesPlayed + 0.5;//Calc to get persentage of loseScore +0.5 To Round up
	}

	iScores[3] = (int)winScore; //Store winScore in iScores[3]
	iScores[4] = (int)loseScore;//Store loseScore in iScores[4]

	iPercentWins = iScores[3];//Store iScore at pos [3] in iPercentWins
	iPercentLosses = iScores[4];//Store iScore at pos [4] in iPercentLosses

	WriteToFile();//Writing to File 
}//End CalcWinsAndLosses()

//   *NoOfGuesses
void NoOfGuesses()
{
	do{
		printf("\nNumber of Guesses you would like: ");
		fflush(stdin);
		scanf_s("%d", &iNoOfGuesses);
		iCheckForInt = iNoOfGuesses;
	} while ((iNoOfGuesses < 1) || (iNoOfGuesses > MaxNumOfGuesses) || (iNoOfGuesses != iCheckForInt));
}//End NoOfGuesses():

int test()
{
	do{
		printf("\nNumber of Guesses you would like: ");
		fflush(stdin);
		scanf_s("%d", &iNoOfGuesses);
		iCheckForInt = iNoOfGuesses;
	} while ((iNoOfGuesses < 1) || (iNoOfGuesses > MaxNumOfGuesses) || (iNoOfGuesses != iCheckForInt));
}//End NoOfGuesses():

//   *Header
void MainHeader()
{
	printf("\n\t\t\t   *************************\n");
	printf("    ***********************       MASTER MIND       ***********************\n");
	printf("\t\t\t   *************************");
}//End	MainHeader()

//   *GroupUsefullFunctions
void GroupUsefullFunctions()
{
	RandomizeTheArray();
	NoOfGuesses();

	printf("\n\t         Wins:%d  Losses:%d   win:%d%%  Losses:%d%%  Count:%d\n", iWins, iLosses, iPercentWins, iPercentLosses,iCntGamesPlayed);
	printf("\n\t1=Red 2=Orange 3=Yellow 4=Green 5=Blue 6=Indigo 7=Violet 0=Space");
	printf("\n\n\t");
	printf("\n\t      %d            *************************            %d\n", iWins, iLosses);
	if (iChoice == 1)
	{
		printf("    ******** Wins *********        EASY GAME        ********* Losses *********\n");
	}
	else if (iChoice == 2)
	{
		printf("    ******** Wins *********       MEDIUM GAME       ********* Losses *********\n");
	}
	else if (iChoice == 3)
	{
		printf("    ******** Wins *********       HARD GAME         ********* Losses *********\n");
	}
	printf("\t     %-6.1f%%       *************************          %-6.1f%%\n", (double)iPercentWins, (double)iPercentLosses);

	//*********** ONLY USED TO SHOW ANSWER *******************
	/*printf("\t\t\t\t    ");
	for (i = 0; i < 4; i++)
	{
	printf("%d ", iCompArrayNum[i]);
	}//End for*/
	//******************************************************

	printf("\n\t\t************************************************\n");

	UserGuess();

	printf("\n\n");
}//End GroupUsefullFunctions():

//   *RandomizeTheArray
void RandomizeTheArray()
{
	srand(time(NULL));
	int j=0, temp;

	//Used to setup array, and reset array after every mode
	iCompArrayNum[0] = 1;
	iCompArrayNum[1] = 2;
	iCompArrayNum[2] = 3;
	iCompArrayNum[3] = 4;
	iCompArrayNum[4] = 5;
	iCompArrayNum[5] = 6;
	iCompArrayNum[6] = 7;
	iCompArrayNum[7] = 0;

	if ((iChoice == 1) || (iChoice == 2))
	{
		for (i = 0; i < 7; i++)
		{
			j = (rand() % 7);
			temp = iCompArrayNum[i];
			iCompArrayNum[i] = iCompArrayNum[j];

			if (iChoice == 1 && iChoice!=2 && iChoice!=3)
			{
				iCompArrayNum[j] = temp;
			}//if
		}//for
	}//if
	else if (iChoice == 3 && iChoice != 1 && iChoice != 2)
	{
		for (i = 0; i < 8; i++)
		{
			j = (rand() % 8);
			temp = iCompArrayNum[i];
			iCompArrayNum[i] = iCompArrayNum[j];
		}//for
	}//else

}//End RandomizeTheArray();

//   *Rules
void Rules()
{

	printf("\n\t\t\t   *************************\n");
	printf("    ***********************       GAME RULES        ***********************");
	printf("\n\t\t\t   *************************");
 
	printf("\n\nThe Computer has selected 4 Random colored pegs out of 7 Colours.");

	printf("\n\nThe object . . .\n"
		"Guess that combination in as many tries you set at the beginning to Win.");

	printf("\n\n\t\t\t\tHow To Play");

	printf("\n\nEnter your 4 number combinations when prompted \nfollowed by a space inbetween each number.\n\n"
		"Each Number corresponds to a colour: Eg: 1 5 6 3 = Red blue Indigo Yellow\n"
		" Num:1 = Red \n Num:2 = Orange \n Num:3 = Yellow \n Num:4 = Green \n"
		" Num:5 = Blue \n Num:7 = Indigo \n Num:7 = Violet \n Num:0 = Blank Space\n\n");

	system("PAUSE");

	printf("\nEach time you submit a guess by Hitting the (Enter Key)\nScore pegs will appear to give you Hints. Eg: B B - W "
		"\n\n'W' will appear if its the correct peg but in the Wrong place."
		"\n'B' will appear if its the Right colour in the Right place."
		"\n'-' will appear if the colours not there at all."
		"\n\nIf you get 4 correct colours in the correct place within 10 tries, You Win.");

	printf("\n\nOnce the game is Won or Lost, You will be brought back to the Main Menu");

	printf("\n\n\t\t\t    Good Luck!\n\n");
	system("PAUSE");
	ShowMenu();
}//End Rules();

//   *UserGuess
void UserGuess() 
{	
	do{
		printf("Guess: %d\t\t   ",iGuessNum);		
			fflush(stdin);	
			for (i = 0; i < 4; i++)
			{
				scanf_s("%d", &iUserArrayNum[i]);
			}

			printf("\t\t\t\t\t     ");
			ChkPosAndCmpArray();
			ChkAllPins();
			printf("\n");
			iGuessNum++;

	} while ((iGuessNum <= iNoOfGuesses) && (allMatchChk == false));
}//End UserGuess();
 
//   *ChkPosAndCmpArray 
void ChkPosAndCmpArray()
{
	for (i = 0; i < 4; i++)
	{
		int iPinVal=0;

		for (int p = 0; p < 4; p++)
		{
			if (iUserArrayNum[i] == iCompArrayNum[i])
			{
				iPinVal = 1;
			}
			else if (iUserArrayNum[i] == iCompArrayNum[p] && iPinVal != 1)
			{
				iPinVal = 2;
			}
			else if (iUserArrayNum[i] != iCompArrayNum[p] && iPinVal != 1 && iPinVal!=2)
			{
				iPinVal = 3;
			}//End ElseIf	

		}//End Inner For
		switch (iPinVal)
		{
			case 1:
			{
				printf("B ");
				break;
			}
			case 2:
			{
				printf("W ");
				break;
			}
			case 3:
			{
				printf("- ");
				break;
			}
			default:
			{
				printf(" ");
				break;
			}
		}//End Switch
	}//End Outer For
}//End ChkPosAndCmpArray 

//   * ChkAllPins 
void ChkAllPins()
{
	count = 0;
	allMatchChk = false;

	for (i = 0; i < 4; i++)
	{
		if (iUserArrayNum[i] == iCompArrayNum[i])
		{
			count++;
		}
	}
	if (count==4)
	{
		allMatchChk = true;
	}

	if (allMatchChk == true)
	{
		printf("\n\n    ***************************************************************************\n");
		printf("    ************************       YOU WIN!!       ***************************");
		printf("\n    ***************************************************************************\n\n");		
		
		iScores[0] = iWins + 1;//iScores[0] = Wins
		iScores[2] = iCntGamesPlayed + 1;//iScores[2] = iCntGamesPlayed
		WriteToFile();

		system("PAUSE");
		ShowMenu();
	}//End if

	if (iGuessNum == iNoOfGuesses && allMatchChk == false)
	{
		printf("\n\n    **************************************************************************\n");
		printf("    ************************       YOU LOSE!!       **************************");
		printf("\n    ************************     Answer:");
		
		//Prints out the Answer
		for (i = 0; i < 4; i++)
		{
			printf("%d ", iCompArrayNum[i]);
		}//End for

		printf("    **************************");
		printf("\n    **************************************************************************\n\n");

		iScores[1] = iLosses + 1;//iScores[1] = Losses
		iScores[2] = iCntGamesPlayed + 1;//iScores[2] = iCntGamesPlayed
		WriteToFile();

		system("PAUSE");
		ShowMenu();
	}//End if
}//End ChkAllPins

//   * ResetScores
void ResetScores()
{
	int IconfirmReset = 0;
	
	do {
		printf("\t   Type 1 to Reset: ");
		fflush(stdin);
		scanf_s("%d", &IconfirmReset);
		
		iCheckForInt = IconfirmReset;
		if (IconfirmReset == 1)
		{
			printf("\t   Scores Reset!\n\n");
			iScores[0] = 0;//iWins
			iScores[1] = 0;//iLosses
			iScores[2] = 0;//iCnt
			iScores[3] = 0;//%wins
			iScores[4] = 0;//%losses

			WriteToFile();
			system("PAUSE");
			ShowMenu();
		}
		else 
		{
			printf("\t   Invalid Input!\n\n");
			system("PAUSE");
		}
	} while ((IconfirmReset != iCheckForInt) && (IconfirmReset != 1));
}//End ResetScores();

//   * WriteToFile
void WriteToFile(void)
{
	FILE *fp = fopen(FILENAME, "w");// write mode!!!

	for (i = 0; i < 5; i++)
	{
		fprintf(fp, "%d ", iScores[i]);
	}
	if (fp == NULL)
	{
		printf("\nFile does not exist(or can't open)\n");
	}
	fclose(fp);
}//End WriteToFile()

//   * ReadFromFile
void ReadFromFile(int iScoresFill[]){

	FILE *fp = fopen(FILENAME, "r");// read mode!!!
	if (fp == NULL)
	{
		printf("\nFile does not exist(or can't open)\n");
	}
	do
	{
		for (i= 0; i < 5;i++)
		{
			fscanf(fp, "%d ", &iScoresFill[i]);
		}
	} while (!feof(fp)); //feof = File End of File
	fclose(fp);
}//End ReadFromFile()