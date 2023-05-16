#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int gameWon = FALSE,turns = FALSE, draw = FALSE, userIsX = FALSE, won = FALSE;
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int takenCells[9];

void drawBoard();

int getUserInput(int userInput){
    while(TRUE){
        drawBoard();
        printf("\nEnter your choice:> ");
        scanf("%d", &userInput);
        if(board[(int) (userInput-1)/3][(userInput-1)%3]==' ')
            return userInput;
    }
}

int menu(){
    printf("------MENU------\n");
    printf("1: Play with X\n");
    printf("2: Play with O\n");
    printf("3: Exit\n");
}


void drawBoard(){
    system("CLS");
    printf("\r %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\r-----------\n");
    printf("\r %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\r-----------\n");
    printf("\r %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    fflush(stdout);
}

int checkWin(){
    char winner;
    int i=0;
    int pos_diag_won = board[0][0]==board[1][1] && board[1][1]==board[2][2];
    int neg_diag_won = board[0][2]==board[1][1] && board[1][1]==board[2][0];
    if((pos_diag_won||neg_diag_won) && board[1][1]!=' '){
            won=TRUE;
            winner = board[1][1];  
    }
    while(i<3 && !won){
        int row_win = board[i][0]==board[i][1] && board[i][1]==board[i][2];
        int col_win = board[0][i]==board[1][i] && board[1][i]==board[2][i];
        if((row_win && board[i][1]!=' ') || (col_win && board[1][i]!=' ')){
            won=TRUE;
            winner = board[i][2];  
        }
        i++;
    }
    
    return won;
}

int checkDraw(){
    if(turns>=9 && !checkWin())
        return TRUE;
    return FALSE;
}


int randomMove(){
    int moveMade = FALSE;
    while(!moveMade){
        time_t t;
        srand((unsigned) time(&t));
        int move = rand() % 9;
        int free[9-turns];
        if(board[(int) (move-1)/3][(move-1)%3]==' '){
            moveMade=TRUE;
            return move;
        }
    }
}

void startGame(){
    while(!gameWon){
        int move;
        if(turns%2==0){
            if(userIsX)
                move = getUserInput(move);
            else
                move = randomMove();
            int row = (int) (move-1)/3;
            int col = (move-1)%3;
            board[row][col] = 'X';      
            drawBoard();
            takenCells[turns++]=row*2+col;
            gameWon = checkWin();
        }
        else{
            if(userIsX)
               move = randomMove(); 
            else
                move = getUserInput(move);
            int row = (int) (move-1)/3;
            int col = (move-1)%3;
            board[row][col] = 'O';      
            drawBoard();
            takenCells[turns++]=row*2+col;
            gameWon = checkWin();
        }
    } 
    printf("\nCongrats!");
}

int main(){
    int userInput;  
    menu(); 
    switch (scanf("%d", &userInput)){
    case 1:
        userIsX=TRUE;
        drawBoard();
        startGame();
        break;
    case 2:
        userIsX=FALSE;
        drawBoard();
        startGame();
        break;
    case 3:
        exit(0);
        break;
    
    default:
        break;
    }

}