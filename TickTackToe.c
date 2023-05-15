#include <stdio.h>
#include <stdlib.h>

int gameOver = 0;
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void drawBoard();

int getUserInput(int userInput){
    printf("Enter your choice:> ");
    scanf("%d", &userInput);
    return userInput;
}

void menu(){
    int userInput;

    printf("------MENU------\n");
    printf("1: Play with X\n");
    printf("2: Play with O\n");
    printf("3: Exit\n");    
    
    while(!gameOver){
        userInput = getUserInput(userInput);
        int row = (int) (userInput-1)/3;
        int col = (userInput-1)%3;
        if(board[row][col] != 'O') board[row][col] = 'O';
        else board[row][col] = 'X';
        drawBoard();
        printf("You chose: (%d, %d)\n", row, col);
    }    
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

int main(){
    menu(); 
}