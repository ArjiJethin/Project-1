//TITLE:                             SIMPLE TICTACTOE GAME USING C
//                                  ````````````````````````````````

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

//-----------------------------------------------------------------------------------------------------------
//                                           GlOBAL-DECLARATION
//-----------------------------------------------------------------------------------------------------------

char Board[3][3];
char player,comp;

//-----------------------------------------------------------------------------------------------------------
//                                          FUNCTION-PROTOTYPING
//-----------------------------------------------------------------------------------------------------------

void resetboard();
void printboard();
int checkfreespaces();
void playermove();
void compmove();
char checkwinner();
void printwinner();

//-----------------------------------------------------------------------------------------------------------
//                                          MAIN-PROGRAM
//-----------------------------------------------------------------------------------------------------------

int main()
{   
    char replay;

    while (replay != 'N')
    {
        char winner = ' ';

    printf("Choose a symbol (X/O):-");
    scanf(" %c",&player);
    if (player == 'X')
    {
        comp = 'O';
    }
    else
    {
        comp = 'X';
    }

    resetboard();

    while (winner == ' ' && checkfreespaces() != 0)
    {

        printboard();

        playermove();
        winner = checkwinner();

        if(winner == player)
        {
            printboard();
            printf("The Game is won by '%c'!!\n",winner);
            break;
        }

        compmove();
        winner = checkwinner();

        if(winner == comp)
        {
            printboard();
            printf("The Game is won by '%c'!!\n",winner);
            break;
        }

    }

    if(checkfreespaces() == 0 && winner == ' ')
    {
        printboard();
        printf("The Match is a Tie!!\n");
    }

    printf("Would you like to play again?(Y/N):");
    scanf(" %c",&replay);

    }

    return 0;    
  
}

//-----------------------------------------------------------------------------------------------------------
//                                        SUB - PROGRAMS
//-----------------------------------------------------------------------------------------------------------



//---------------------------------------Reset Board Function--------------------------------------------------

void resetboard()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Board[i][j] = ' ';
        }
        
    }
}

//-----------------------------------------Print Board Function--------------------------------------------------

void printboard()
{
    printf(" %c | %c | %c \n",Board[0][0],Board[0][1],Board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",Board[1][0],Board[1][1],Board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",Board[2][0],Board[2][1],Board[2][2]);
}

//--------------------------------------Free Spaces Checking Functions--------------------------------------------------

int checkfreespaces()
{
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] != ' ')
            {
                freeSpaces--;
            }    
        }
    }

    return freeSpaces;
}

//---------------------------------------Player Move Function--------------------------------------------------

void playermove()
{
    int x,y;
    do
    {
    printf("Enter the row and column repsectively(row(space)column):");
    scanf("%d %d", &x, &y);
    x--,y--;

    if (Board[x][y] != ' ')
    {
        printf("Invalid Move\n");
    }

    else
    {
        Board[x][y] = player;
        break;
    }
    } while (Board[x][y] != ' ');
    
}   

//---------------------------------------Computer Move Function--------------------------------------------------

void compmove()
{
    //printf("Hehe\n");

    int X, Y;

    if (checkfreespaces() != 0)
    {
        do
        {
            srand(time(0));
            X = rand() % 3;
            Y = rand() % 3;
        } while (Board[X][Y] != ' ');

        Board[X][Y] = comp;
    }
}

//---------------------------------------Winner Checking Function--------------------------------------------------

char checkwinner()
{
    for(int i=0;i<3;i++)
    {
        if(Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2])
        {
            return Board[i][0];
        }

        if(Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i])
        {
            return Board[0][i];
        }
    }
 
    if(Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2])
    {
        return Board[0][0];
    } 

    if(Board[2][0] == Board[1][1] && Board[2][0] == Board[0][2])
    {
        return Board[2][0]; 
    }     

    else return ' ';
}

//-----------------------------------------------------------------------------------------------------------
//                                          END OF THE PROGRAM
//-----------------------------------------------------------------------------------------------------------

//by Arji Jethin Naga Sai Eswar :)