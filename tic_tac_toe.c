/*
AUTHOR : Sayantan Pal
DATE : 05.01.2019
*/

#include <stdio.h> //standard input output
#include <stdlib.h> //standard libs
#include <time.h> //time()
#include <ctype.h> // isdigit() isalpha() etc
/********************************
function prototypes
********************************/
void displayBoard();
int verifySelection(int, int);
void checkForWin();
/******************
global variables
******************/
char board[8];
char cWhoWon = ' ';
int iCurrentPlayer = 0;
int count = 0;
/********************************************************
begin main function
*********************************************************/
int main()
{
    int x;
    int iSquareNum = 0;
    for ( x = 0; x < 9; x++ )
    board[x] = ' ';
    displayBoard();
    while ( cWhoWon == ' ') 
    {
        printf("\n%c\n", cWhoWon);
        if ( iCurrentPlayer == 1 || iCurrentPlayer == 0 ) 
            {
                printf("\nPLAYER X\n");
                printf("Enter an available square number (1-9): ");
                scanf("%d", &iSquareNum);count+=1;
                if ( verifySelection(iSquareNum, iCurrentPlayer) == 1 )
                iCurrentPlayer = 1;
                else
                iCurrentPlayer = 2;
            }
            else 
            {
                printf("\nPLAYER O\n");
                printf("Enter an available square number (1-9): ");
                scanf("%d", &iSquareNum);count+=1;
                if ( verifySelection(iSquareNum, iCurrentPlayer) == 1 )
                iCurrentPlayer = 2;
                else
                iCurrentPlayer = 1;
            }
    displayBoard();
    checkForWin();
    if(count==9)
        {
            printf("\nDRAW\n");exit(0);
        }
    }
}

//end loop
//end main function
/*********************************************************
begin function definition
*********************************************************/
void displayBoard() {
system("clear");
printf("       |       |       \n");
printf("   %c   |   %c   |   %c  \n", board[0], board[1], board[2]);
printf("       |       |       \n");
printf("-------|-------|-------\n");
printf("       |       |       \n");
printf("   %c   |   %c   |   %c  \n", board[3], board[4], board[5]);
printf("       |       |       \n");
printf("-------|-------|-------\n");
printf("       |       |       \n");
printf("   %c   |   %c   |   %c  \n", board[6], board[7], board[8]);
printf("       |       |       \n");
} //end function definition
/********************************************************
begin function definition
********************************************************/
int verifySelection(int iSquare, int iPlayer) {
if ( board[iSquare - 1] == ' ' && (iPlayer == 1 || iPlayer == 0) ) {
board[iSquare - 1] = 'X';
return 0;
}
else if ( board[iSquare - 1] == ' ' && iPlayer == 2 ) {
board[iSquare - 1] = 'O';
return 0;
}
else
return 1;
}
//end function definition
/********************************************************
begin function definition
********************************************************/
void checkForWin() {
int catTotal;
int x;
if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
cWhoWon = 'X';
else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
cWhoWon = 'X';
else if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
cWhoWon = 'X';
else if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
cWhoWon = 'X';
else if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
cWhoWon = 'X';
else if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
cWhoWon = 'X';
else if (board[0] == 'X' && board[5] == 'X' && board[8] == 'X')
cWhoWon = 'X';
else if (board[2] == 'X' && board[5] == 'X' && board[6] == 'X')
cWhoWon = 'X';
else if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
cWhoWon = 'O';
else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
cWhoWon = 'O';
else if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
cWhoWon = 'O';
else if (board[0] == 'O' && board[3] == 'O' && board[7] == 'O')
cWhoWon = 'O';
else if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
cWhoWon = 'O';
else if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
cWhoWon = 'O';
else if (board[0] == 'O' && board[5] == 'O' && board[8] == 'O')
cWhoWon = 'O';
else if (board[2] == 'O' && board[5] == 'O' && board[6] == 'O')
cWhoWon = 'O';
if (cWhoWon == 'X') {
printf("\nX Wins!\n");
}
if (cWhoWon == 'O') {
printf("\nO Wins!\n");
return;
}
} //end function definition
