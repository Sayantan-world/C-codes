/*
   AUTHOR : Sayantan Pal
   DATE : 04.01.2019
   NOTE : GAME 5 ONLY WORKS ON WINDOWS , IF U RUN IT IN LINUX PLEASE  REPLACE  "cls" with  "clear"  IN LINE 47
 */
#include <stdio.h> //standard input output
#include <stdlib.h> //standard libs
#include <time.h> //time()
#include <ctype.h> // isdigit() isalpha() etc
#define MAX_LIMIT 20
char a;
/* ************************************OTHER FUNCTIONS INVOLVED************************************  */

/* ************************************COLOURS******************************************************* */
void red () {
        printf("\033[1;31m");
}

void yellow() {
        printf("\033[1;33m");
}
void cyan () {
        printf("\033[1;36m");
}

void magenta() {
        printf("\033[1;35m");
}
void blue () {
        printf("\033[1;34m");
}

void green() {
        printf("\033[1;32m");
}


void reset () {
        printf("\033[0m");
}

/*---------------------------------------------------CONCENTRATION GAME---------------------------------------------------------------------*/
int conc_game()
{
        char cYesNo = '\0';
        int iResp[10];//user input array
        int iElaspedTime = 0;
        int iCurrentTime = 0;
        int iRandomNum = 0;
        int iNum[10];//random generated array
        int iCounter = 0;
        int i=0,j=0,score=0;
        srand(time(NULL));
        while(i<=9)
        {
                j=0;
/*Random numbers generated and stored in array for a certain level*/
                while(j<=i)
                {
                        iNum[j] = rand() % 100;
                        j+=1;
                }
/*--------------------------------------*/
/*Displaying the generated numbers*/
                cyan();
                printf("\n      Concentrate on the numbers (LVL %d):  \n",(i+1));
                j=0;
                printf("\n      ");
                while(j<=i)
                {
                        printf("%d ",iNum[j]); j+=1;
                }
                iCurrentTime = time(NULL);
                do {
                        iElaspedTime = time(NULL);
                } while ( (iElaspedTime - iCurrentTime) < (i+3) ); //end do while loop
                system ("cls");//Clearing the screen
                magenta();
                printf("\n      Enter each number separated with one space: ");
                cyan();
                switch(i+1)
                {
                case 1:
                {
                        scanf("%d", &iResp[0]); break;
                }
                case 2:
                {
                        scanf("%d%d", &iResp[0],&iResp[1]); break;
                }
                case 3:
                {
                        scanf("%d%d%d", &iResp[0],&iResp[1],&iResp[2]); break;
                }
                case 4:
                {
                        scanf("%d%d%d%d", &iResp[0],&iResp[1],&iResp[2],&iResp[3]); break;
                }
                case 5:
                {
                        scanf("%d%d%d%d%d", &iResp[0],&iResp[1],&iResp[2],&iResp[3],&iResp[4]); break;
                }
                case 6:
                {
                        scanf("%d%d%d%d%d%d", &iResp[0],&iResp[1],&iResp[2],&iResp[3],&iResp[4],&iResp[5]); break;
                }
                case 7:
                {
                        scanf("%d%d%d%d%d%d%d", &iResp[0],&iResp[1],&iResp[2],&iResp[3],&iResp[4],&iResp[5],&iResp[6]); break;
                }
                case 8:
                {
                        scanf("%d%d%d%d%d%d%d%d", &iResp[0],&iResp[1],&iResp[2],&iResp[3],&iResp[4],&iResp[5],&iResp[6],&iResp[7]); break;
                }
                case 9:
                {
                        scanf("%d%d%d%d%d%d%d%d%d", &iResp[0],&iResp[1],&iResp[2],&iResp[3],&iResp[4],&iResp[5],&iResp[6],&iResp[7],&iResp[8]); break;
                }
                case 10:
                {
                        scanf("%d%d%d%d%d%d%d%d%d%d", &iResp[0],&iResp[1],&iResp[2],&iResp[3],&iResp[4],&iResp[5],&iResp[6],&iResp[7],&iResp[8],&iResp[9]); break;
                }
                }
                j=0; int flag=0;
                while(j<=i)
                {
                        if(iNum[j]==iResp[j])
                        {
                                flag=1;
                        }
                        else
                        {
                                flag=0; break;
                        }
                        j+=1;
                }
                j=0;
                if(flag==1)
                {green(); printf("\n      Congratulations! U passed level %d\n",(i+1)); score+=1; cyan();}
                if(flag==0)
                {   red();
                    printf("\n      Sorry :(  correct numbers were : "); cyan();
                    while(j<=i)
                    {
                            printf("%d ",iNum[j]); j+=1;
                    }
                    yellow();
                    printf("\n\n      YOUR MEMORIZATION ABILITY IS %d/100\n",(score*10));

                    break;}
                i+=1;
        }
}//END OF CONCENTRATION GAME

/*--------------------------------21 BALL GAME------------------------------------------------------------------------------------------------------*/
int ball_game()
{
        cyan();
        printf("\n      Game Description: U can choose 1 or 2 balls in each turn\n");
        printf("\n      The computer also gets a turn after u choose... it also chooses 1 or 2 balls\n");
        printf("\n      One who has to pick the last ball left looses the game :D\n");
        int numSticks = 21;
        int numToTake = 0; int q=0;

        while (numSticks > 0)
        {
                q=0;
                yellow();
                printf("\n      Balls remaining  =  %d \n", numSticks);
                magenta();
                printf("      ");
                for(q=1; q<=numSticks; q++)
                {
                        printf("O ");
                }
                printf("\n");
                printf("\n      How many balls you choose ( 1 or 2) : ");
                scanf("%d", &numToTake);

                if (numToTake > 2)
                {
                        numToTake = 2;

                }

                else if (numToTake < 1)
                {
                        numToTake = 1;
                }
                numSticks = numSticks - numToTake;

                if (numSticks <= 0)
                {
                        red();
                        printf("\n      SORRY ,YOU LOST :(  KEEP TRYING \n");

                        magenta();
                }
                else {

                        if((numSticks - 2) % 3 == 0 || numSticks - 2 == 0)
                        {
                                numToTake = 1;
                        }
                        else
                        {
                                numToTake = 2;
                        }
                        printf("\n      The computer takes %d ball(s)\n", numToTake);
                        numSticks = numSticks - numToTake;

                        if (numSticks <= 0)
                        {
                                green();
                                printf("\n     CONGRATS!!!!!...... U CRACKED MY CODE ;)\n");


                        }
                }
        }

} //END OF 21 BALL GAME
  /*---------------------------------------------------------------------------------------------------------------------------------------------*/
  /*-----------------------------------------------------------GUESSING GAME---------------------------------------------------------*/
int guessing_game()
{
        int iRandomNum = 0; int guess;
        int i,score=0;
        cyan();
        printf("\n      INSTRUCTIONS : Choose a number between 1-5(U get 5 attempts)\n");
        srand(time(NULL));
        for(i=1; i<=5; i++)
        {   printf("\n      ATTEMPT %d :  ",i);
            iRandomNum = (rand() % 5) + 1;
            scanf("%d",  &guess);
            if(guess>5 || guess <1)
            {
                    red();
                    printf("\n      PLZ READ THE INSTRUCTIONS CAREFULLY AND  CHOOSE A NUMBER IN GIVEN RANGE\n"); cyan(); i--; continue;
            }
            if(iRandomNum==guess)
            {    green(); printf("\n      CORRECT  :)\n"); cyan(); score+=1;}
            else
            {
                    red();
                    printf("\n      INCORRECT   :( \n      CORRECT was  %d \n",iRandomNum);
                    cyan();
            }}
        magenta();
        printf(" \n      THANK YOU FOR PLAYING THIS GAME.... YOUR SCORE = %d/5 \n",score);

}        //END OF GUESSING GAME
/*---------------------------------------------------------------------------------------------------*/
/*----------------------------------------------ADDITION GAME----------------------------*/
int addition_game()
{
        int x, iNumQuestions, iResponse, iRndNum1, iRndNum2,score=0;
        srand(time(NULL));
        cyan();
        printf("\n      Enter number of questions to ask:  ");
        scanf("%d", &iNumQuestions);
        for ( x = 0; x < iNumQuestions; x++ )
        {
                iRndNum1 = rand() % 100000 + 1;
                iRndNum2 = rand() % 100000 + 1;
                printf("\n      What is  %d + %d:  ", iRndNum1, iRndNum2);
                scanf("%d", &iResponse);
                if ( iResponse == iRndNum1 + iRndNum2 )
                {green(); printf("\n      Correct!\n"); cyan(); score+=1;}
                else
                {
                        red();
                        printf("\n      Wrong ...The correct answer was   %d \n", iRndNum1 + iRndNum2); cyan();
                }
        }//end for loop
        magenta();
        printf("\n      YOUR FINAL SCORE IS  %d/%d \n",(score*10),(iNumQuestions*10));

}       //END OF ADDITION GAME
/*------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------MULTIPLICATION GAME--------------------------------*/
int mul_game()
{
        int x, iNumQuestions, iResponse, iRndNum1, iRndNum2; int score=0;
        srand(time(NULL));
        blue();
        printf("\n      Enter number of questions to ask:  ");
        scanf("%d", &iNumQuestions);
        for ( x = 0; x < iNumQuestions; x++ )
        {
                iRndNum1 = rand() % 100 + 1;
                iRndNum2 = rand() % 100 + 1;
                cyan();
                printf("\n      What is  %d x %d:  ", iRndNum1, iRndNum2);
                scanf("%d", &iResponse);
                if ( iResponse == iRndNum1 * iRndNum2 )
                {
                        green();
                        printf("\n      Correct!\n"); score+=1; cyan();
                }
                else
                {
                        red();
                        printf("\n      Wrong ...The correct answer was   %d \n", iRndNum1 * iRndNum2);
                        cyan();
                }
        }//end for loop
        magenta();
        printf("\n      YOUR FINAL SCORE IS  %d/%d \n",(score*10),(iNumQuestions*10));

}//END OF MULTIPLICATION GAME
/*---------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
        char name[MAX_LIMIT]; int choice=0;
        cyan();
        printf("\n      ************************************************************\n");
        printf("\n      ENTER YOUR NAME : ");
        fgets(name, MAX_LIMIT, stdin); //string input to  get user name
        printf("\n      HIII!!!  %s \n      WELCOME TO FUN WITH MATHS VERSION 1.1 \n\n      AUTHOR :  SAYANTAN PAL \n ",name);
        printf("\n      ************************************************************\n");
        while(1)
        {
                green();
                /*DISPLAY OF MENU*/
                printf("\n      ************************************************************\n");
                printf("\n      Press 1 to play GUESSING GAME\n");
                printf("\n      Press 2 to play ADDITION GAME\n");
                printf("\n      Press 3 to play MULTIPLICATION GAME\n");
                printf("\n      Press 4 to play 21 BALL GAME\n");
                printf("\n      Press 5 to play CONCENTRATION GAME\n");
                red();
                printf("\n      Press 6 to QUIT\n");
                green();
                printf("\n      ************************************************************\n");
                magenta();
                printf("\n      ENTER YOUR CHOICE : ");
                scanf("%d", &choice);
                reset();
                switch(choice)
                {
                case 1:
                {
                        guessing_game(); break;
                }
                case 2:
                {
                        addition_game(); break;
                }
                case 3:
                {
                        mul_game(); break;
                }
                case 4:
                {
                        ball_game(); break;
                }
                case 5:
                {
                        conc_game(); break;
                }
                case 6:
                {
                        cyan();
                        printf("\n      THANK YOU SO MUCH FOR TRYING THESE OUT .... HAVE A NICE DAY :)\n\n"); reset(); exit(0);
                }
                default:
                {
                        red();
                        printf("\n      WRONG CHOICE :(\n"); break; // U MAY OMIT THE BREAK IN DEFAULT CASE
                }
                }//end of switch
                cyan();
                printf("\n      PRESS ENTER TO DISPLAY THE MENU AGAIN");
                scanf("%c",&a);//skip
                scanf("%c",&a);
        }//infinite loop
        reset();
}//END OF MAIN FUNCTION
