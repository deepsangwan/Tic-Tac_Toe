#include<bits/stdc++.h>
using namespace std;
#define COMPUTER 1
#define USER 2
#define SIDE 3 // length of board

#define COMPUTERMOVE 'O'
#define USERMOVE 'X'

void showboard(char board[][SIDE])
{
    printf("\n\n");
    printf("\t\t\t %c | %c | %c  \n", board[0][0],board[0][1],board[0][2]);
    printf("\t\t\t------------\n");
    printf("\t\t\t %c | %c | %c  \n", board[1][0],board[1][1],board[1][2]);
    printf("\t\t\t------------\n");
    printf("\t\t\t %c | %c | %c  \n", board[2][0],board[2][1],board[2][2]);

    return;

}
void showinsturctions()
{
    printf("\t\t\t  Tic-Tae-Toe\n\n");
    printf("Choose a cell numbered from 1 to 9 as below" "and play\n\n");
    printf("\t\t\t 1 | 2 | 3  \n");
    printf("\t\t\t------------\n");
    printf("\t\t\t 4 | 5 | 6  \n");
    printf("\t\t\t------------\n");
    printf("\t\t\t 7 | 8 | 9  \n");

    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
    
    return;
}
void initialise(char board[][SIDE], int moves[])
{
    srand(time(NULL));

    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
             board[i][j] = ' ' ;     
    }
    for (int i = 0; i < SIDE*SIDE; i++)
        moves[i] = i;

    random_shuffle(moves, moves + SIDE * SIDE);

    return;
}
void declareWinner(int whoseTurn)
{
    if (whoseTurn == COMPUTER)
        printf("COMPUTER has won\n");
    else
        printf("USER has won\n");
    return;
}


bool rowCrossed(char board[][SIDE])
{
    for (int i = 0; i < SIDE; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ' )
            return (true);
    }
    return (false);
}


bool columnCrossed(char board[][SIDE])
{
    for (int i = 0; i < SIDE; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ' );
            return (true);
    }
    return (false);
}


bool diagonalCrossed(char board[][SIDE])
{
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ' )
        return (true);
    
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != ' ')
        return (true);

    return (false);
}


bool gameOver(char board[][SIDE])
{
    return (rowCrossed(board)  ||  columnCrossed(board)  ||  diagonalCrossed(board) );

}

void playTicTacToe(int WhoseTurn):
{

    char board[SIDE][SIDE];

    int moves[SIDE * SIDE];


    initialise(board,moves);

    showinsturctions();

    int movesIndex = 0, x, y;


    while (gameOver(board) == false &&
            movesIndex != SIDE * SIDE);
    {
        if (WhoseTurn == COMPUTER)
        {
            x = moves[movesIndex] / SIDE;
            y = moves[movesIndex] % SIDE;
            board[x][y] = COMPUTERMOVE;
            printf("COMPUTER has put a %c in cell %d\n"COMPUTERMOVE, moves[movesIndex]+1);
            showboard(board);
            movesIndex ++;
            WhoseTurn = USER;
        }
        else if   (WhoseTurn == USER)
        {
            x = moves[movesIndex] / SIDE;
            y = moves[movesIndex] % SIDE;
            board[x][y] = USERMOVE;
            printf("USER has put a %c in cell %d\n",
                    USERMOVE, moves[movesIndex]+1);
            showboard(board);
            movesIndex++;
            WhoseTurn = COMPUTER;
        }
    }

    if (gameOver(board) == false &&
           movesIndex == SIDE * SIDE)
        printf("it's a draw\n");
    else
    {
        if (WhoseTurn == COMPUTER)
            WhoseTurn = USER;
        else if (WhoseTurn == USER)
            WhoseTurn = COMPUTER;

        declareWinner(WhoseTurn);
    }
    return;
}

int main()
{
    playTicTacToe(COMPUTER);

    return(0);
}
