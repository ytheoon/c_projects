#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int answer;
int guess;
int answer_guessed = 0;

int get_Random_Number() {
  time_t t;
  srand((unsigned)time(&t));
  return rand() % 100 + 1;
}

int get_User_Input() {
  printf("\nGuess a number between 1 and 100: ");
  scanf("%d", &guess);
  return guess;
}

int check_Answer(const int answer, const int guess) {
  if (guess < answer) {
    printf("\nGuess higher\n");
    return 0;
  } else if (guess > answer) {
    printf("\nGuess lower\n");
    return 0;
  }
  printf("\n++++++++++++++++++++++++++++++++++++++++\n");
  printf("              You Won!");
  printf("\n++++++++++++++++++++++++++++++++++++++++\n");
  return 1;
}

int main(void) {
  answer = get_Random_Number();
  while (!answer_guessed) {
    guess = get_User_Input();
    answer_guessed = check_Answer(answer, guess);
  }
  return 0;
}