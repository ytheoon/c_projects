
#define true 1
#define false 0

typedef struct {
  int nRows = 3, nCols = 3;
  int gameOver = false;
  int board[9] = {0};
  int turn = 0;
} game;