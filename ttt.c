#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define false 0
#define true 1

void printMenu() {
    printf("------MENU------\n");
    printf("1: Play with X\n");
    printf("2: Play with O\n");
    printf("3: Exit\n");
}

void drawBoard(const int *board, const int nRows, const int nCols) {
    printf("\n\n\n\n\n");
    for (int i = 0; i < nRows * nCols; i++) {
        char c;
        switch (board[i]) {
            case 1:
                c = 'X';
                break;

            case -1:
                c = 'O';
                break;

            default:
                c = ' ';
                break;
        }
        printf(" %c ", c);
        if ((i + 1) % 3)
            printf("|");
        else if (i != 8)
            printf("\n-----------\n");
    }
    printf("\n");
}

int getRandomMove(int *board) {
    time_t t;
    srand((unsigned)time(&t));
    int spot = rand() % 9 + 1;
    int moveMade = false;
    for (int i = 0; !moveMade; i = ((i + 1) % 9)) {
        if (!board[i]) {
            if (--spot == 0) return i;
        }
    }
    return -1;
}

void makeMove(int *board, int player, int user) {
    int move;
    if (player == user) {
        int validMove = false;
        while (!validMove) {
            printf("\n Enter a position: ");
            scanf("%d", &move);
            if (move <= 9 && move > 0)
                if (board[move - 1] == 0) validMove = true;
        }
        move--;
    } else {
        move = getRandomMove(board);
    }
    board[move] = player;
}

int checkWin(int *board, int player) {
    int winCriteria = player * 3;
    int i = 0;

    int posDiagWin = winCriteria == (board[0] + board[4] + board[8]);
    int negDiagWin = winCriteria == (board[2] + board[4] + board[6]);
    if (posDiagWin || negDiagWin) return true;

    for (int i = 0; i < 3; i++) {
        int colWin = winCriteria == (board[i] + board[i + 3] + board[i + 6]);
        if (colWin) return true;
    }

    for (int i = 0; i < 9; i += 3) {
        int rowWin = winCriteria == (board[i] + board[i + 1] + board[i + 2]);
        if (rowWin) return true;
    }

    return false;
}

int main() {
    int nRows = 3, nCols = 3;
    int board[9] = {0};
    int gameOver = false;
    int user = 0;
    int currentPlayer = 1;
    int turn = 0;

    while (user > 3 || user <= 0) {
        printMenu();
        printf("Choose mode: ");
        scanf("%d", &user);
    }
    // startGame(gameMode);
    user = user == 2 ? -1 : user;
    if (user == 3)
        gameOver = true;
    else
        drawBoard(board, nRows, nCols);
    while (!gameOver) {
        makeMove(board, currentPlayer, user);

        drawBoard(board, nRows, nCols);

        if (checkWin(board, currentPlayer)) {
            printf("\n+++++++++++++++++++++++++++++++++++++++++++\n");
            if (currentPlayer == user)
                printf("\n\t\tYou Won!\n");
            else
                printf("\n\t\tYou Lost!\n");
            printf("\n+++++++++++++++++++++++++++++++++++++++++++\n");
            gameOver = true;
            break;
        } else if (turn++ >= 8) {
            printf("\n++++++++++++++++++++++++++++++++++++++++\n");
            printf("\n\t\tGame Tied\n");
            printf("\n++++++++++++++++++++++++++++++++++++++++\n");
            gameOver = true;
            break;
        }

        currentPlayer = -currentPlayer;
    }
}