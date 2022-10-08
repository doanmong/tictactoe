#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

char box[3][3];     
int counter = 0;

void initialize_rdm(void); /*initializes random number generator*/
void initialize_grid(void); /*resets the array marks to numbers*/
void cpu(int n); /*randomly fills the grid, used as opponent for player*/
void creating_board(void);/*prints the grid and the array*/
int check_available(char c, int player); /*checks if the grid selected is available*/
void check_winner(void); /*checks if there is a winner and prints result*/
void new_game(void); /*after game finished, can call main function again*/
void singleplayer(int n); /*calls all funtion used to play alone, against computer*/
void multiplayer(void); /*calls all funtions used to play between to people*/


int main(void) {
  int op, x;
  initialize_rdm();
  initialize_grid();
  creating_board();
    
  printf("WELCOME TO TIC TAC TOE!\n");
  printf("1 --- person vs. person\n");
  printf("2 --- person vs. random computer\n");
  printf("Enter your choice (1 or 2): \n\n");
  

  for(;;){
    scanf("%d", &op);

    switch(op){
      case 1:
        multiplayer();

      case 2:
        for(;;) {
          cpu(1);
          check_winner();
          cpu(2);
          check_winner();
        }
      
      default:
      printf("\nselect a valid option");
    }
  }
}

void initialize_rdm(void){
  
  srand((unsigned) time(NULL));
}

void initialize_grid(void) {
  int i, j;
  char k = '1';

  for(i = 0; i <3; i++){
    for(j = 0; j < 3; j++){
      box[i][j] = k++;
    }
  }
}

void creating_board() {
    printf("The current status is:\n\n");
    printf("+------------+\n");
    printf("| %c | %c | %c |\n",box[0][0],box[0][1],box[0][2]);
    printf("+------------+\n");
    printf("| %c | %c | %c |\n",box[1][0],box[1][1],box[1][2]);
    printf("+------------+\n");
    printf("| %c | %c | %c |\n",box[2][0],box[2][1],box[2][2]);
    printf("+------------+\n");

}

int check_available(char c, int player){
  int i, j;

  if(c < '1' || c > '9'){
    printf("select a valid option: ");
    return 0;
  }

  for(i = 0; i < 3; i++) { 
    for(j = 0; j < 3; j++) {
      if(box[i][j] == c) {       
        switch(player) {
          case 1:
            counter++;
            box[i][j] = 'X';
            return 1;

          case 2:
            counter++;
            box[i][j] = 'O';
            return 1;
        }
      }
    }
  }
  printf("\nalready filled, select another option: ");
  return 0;
}
void check_winner(void) {
  float condition;
  int i, j, winner = 3;
  creating_board();

  for(i = 0; i < 3; i++) {
    for(j = 0, condition = 0; j < 3; j++) {
      if(box[i][j] == 'X' || box[i][j] == 'O') {
        condition += box[i][j];
      }
      if((condition / 'X') == 3.0) {
        winner = 1;
      }
      else if((condition / 'O') == 3.0) {
        winner = 2;
      }
    }
  }
  for(j = 0; j < 3; j++) {
    for(i = 0, condition = 0; i < 3; i++) {
      if(box[i][j] == 'X' || box[i][j] == 'O') {
        condition += box[i][j];
      }
      if((condition / 'X') == 3.0){
        winner = 1;
      }
      else if((condition / 'O') == 3.0) {
        winner = 2;
      }
    }
  }
  for(i = 0, j = 0, condition = 0; i < 3; i++, j++) {
    if(box[i][j] == 'X' || box[i][j] == 'O') {
      condition += box[i][j];
    }
    if((condition / 'X') == 3.0) {
      winner = 1;
    }
    else if((condition / 'O') == 3.0) {
      winner = 2;
    }
  }
  for(i = 2, j = 0, condition = 0; j < 3; i--, j++) {
    if(box[i][j] == 'X' || box[i][j] == 'O') {
      condition += box[i][j];
    }
    if((condition / 'X') == 3.0) {
      winner = 1;
    }
    else if((condition / 'O') == 3.0) {
      winner = 2;
    }
  }
  if(counter >= 9 && winner == 3)
    winner = 0;

  switch(winner){
    case 0:
    printf("\a\nDRAW!");
    new_game();

    case 1:
    printf("\aPLAYER 1 WINS!");
    new_game();

    case 2:
    printf("\aPLAYER 1 WINS!");
    new_game();

    default: return;
  }
} 

void new_game(void) {
  char c;
  counter = 0;
  printf("\n\nPlay another game?(Y/N): ");
  scanf("%c", &c);

  if(c == 'Y' || c == 'y') {
    main();
  }
  else {
    exit(EXIT_SUCCESS);
  }
}

void cpu(int n){
  int a, b, i;
  for(;;){
    a = rand() % 3;
    b = rand() % 3;

    if(box[a][b] != 'X' && box[a][b] != 'O') {
      switch(n) {
        case 1:
          box[a][b] = 'X';
          counter++;
          return;

        case 2:
          box[a][b] = 'O';
          counter++;
          return;
        
      }
    }
  }
}

void singleplayer(int n) {
  char c;
  creating_board();

  for(;;){
    if(n == 1) {
      printf("\n make a move: ");

      do{
        scanf(" %c", &c);
      } while(check_available(c, n) != 1);

      check_winner();
      cpu(2 / n);
    }
    else if(n == 2) {
      cpu(2 / n);
      check_winner();
      printf("\nmake a move: ");

      do{
        scanf(" %c", &c);
      } while(check_available(c, n) != 1);
    }
    check_winner();
  }
}

void multiplayer(void){  
  char c;
  creating_board();

  for(;;){ 
    printf("\nPlayer 1: make your move: ");
    

  do{
    scanf(" %c", &c);
  }
    while(check_available(c, 1) != 1);

check_winner();
printf("\nPlayer 2: make your move: ");

do{
scanf(" %c", &c);
} while(check_available(c, 2) != 1);
    check_winner();
    
}
}
