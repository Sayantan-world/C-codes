/*
AUTHOR : Sayantan Pal
DATE : 01.01.2019
*/
#include <stdio.h> //standard input output
#include <stdlib.h> //standard libs
#include <time.h> //time()
#include <ctype.h> // isdigit() isalpha() etc
#define MAX_LIMIT 20 
/* ************************************OTHER FUNCTIONS INVOLVED************************************  */
int guessing_game()
        {
                    int iRandomNum = 0;int guess;
                     int i,score=0;
                     printf("\n      INSTRUCTIONS : Choose a number between 1-5(U get 5 attempts)\n");
                     srand(time(NULL));
                     for(i=1;i<=5;i++)
                    {   printf("\n      ATTEMPT %d :  ",i);
                        iRandomNum = (rand() % 5) + 1;
                        scanf("%d",  &guess);
                        if(guess>5 || guess <1)
                        {    printf("\n      PLZ READ THE INSTRUCTIONS CAREFULLY AND  CHOOSE A NUMBER IN GIVEN RANGE\n");i--;continue;}
                        if(iRandomNum==guess)
                        {    printf("\n      CORRECT  :)\n");score+=1;}
                        else
                            printf("\n      INCORRECT   :( \n      CORRECT was  %d \n",iRandomNum);
                    }
                    printf(" \n      THANK YOU FOR PLAYING THIS GAME.... YOUR SCORE = %d/5 \n",score);
        }//END OF GUESSING GAME
 /*---------------------------------------------------------------------------------------------------*/
int addition_game()
    {
        int x, iNumQuestions, iResponse, iRndNum1, iRndNum2,score=0;
        srand(time(NULL));
        printf("\n      Enter number of questions to ask:  ");
        scanf("%d", &iNumQuestions);
        for ( x = 0; x < iNumQuestions; x++ ) 
       {
            iRndNum1 = rand() % 100000 + 1;
            iRndNum2 = rand() % 100000 + 1;
            printf("\n      What is  %d + %d:  ", iRndNum1, iRndNum2);
            scanf("%d", &iResponse);
            if ( iResponse == iRndNum1 + iRndNum2 )
            {printf("\n      Correct!\n");score+=1;}
            else
            printf("\n      Wrong ...The correct answer was   %d \n", iRndNum1 + iRndNum2);
       }//end for loop
        printf("\n      YOUR FINAL SCORE IS  %d/%d \n",(score*10),(iNumQuestions*10));
    }   //END OF ADDITION GAME
 /*------------------------------------------------------------------------------------------------------------------------*/ 
 int mul_game()
    {
        int x, iNumQuestions, iResponse, iRndNum1, iRndNum2;int score=0;
        srand(time(NULL));
        printf("\n      Enter number of questions to ask:  ");
        scanf("%d", &iNumQuestions);
        for ( x = 0; x < iNumQuestions; x++ ) 
       {
            iRndNum1 = rand() % 100 + 1;
            iRndNum2 = rand() % 100 + 1;
            printf("\n      What is  %d x %d:  ", iRndNum1, iRndNum2);
            scanf("%d", &iResponse);
            if ( iResponse == iRndNum1 * iRndNum2 )
            {printf("\n      Correct!\n");score+=1;}
            else
            printf("\n      Wrong ...The correct answer was   %d \n", iRndNum1 * iRndNum2);
       }//end for loop
        printf("\n      YOUR FINAL SCORE IS  %d/%d \n",(score*10),(iNumQuestions*10));
}//END OF MULTIPLICATION GAME
/*---------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
        char name[MAX_LIMIT];int choice=0;
        printf("\n      ************************************************************\n"); 
        printf("\n      ENTER YOUR NAME : ");
        fgets(name, MAX_LIMIT, stdin); //string input to  get user name
        printf("\n      HIII!!!  %s \n      WELCOME TO FUN WITH MATHS VERSION 1.0 \n      AUTHOR :  SAYANTAN PAL \n ",name);
        printf("\n      ************************************************************\n"); 
        while(1)
        {
            /*DISPLAY OF MENU*/
            printf("\n      ************************************************************\n"); 
            printf("\n      Press 1 to play GUESSING GAME\n"); 
            printf("\n      Press 2 to play ADDITION GAME\n"); 
            printf("\n      Press 3 to play MULTIPLICATION GAME\n");
            printf("\n      Press 4 to QUIT\n");
            printf("\n      ************************************************************\n"); 
            printf("\n      ENTER YOUR CHOICE : ");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                {
                     guessing_game();break;
                }
                case 2:
                {
                    addition_game();break;
                }
                case 3:
                {
                    mul_game();break;
                }
                case 4:
                {
                    printf("\n      THANK YOU SO MUCH FOR TRYING THESE OUT .... HAVE A NICE DAY :)\n");exit(0);
                }
                default:
                {
                    printf("\n      WRONG CHOICE :(\n");break; // U MAY OMIT THE BREAK IN DEFAULT CASE
                }
            }
        }
}//END OF MAIN FUNCTION
