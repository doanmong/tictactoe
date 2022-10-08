#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

char box[3][3];     
int counter = 0;

void random_move(void);
void creating_board(void);
void marking_board(int, char);
int check_available(char c, int player);
void check_winner(void);

int main() {
    creating_board();

    return 0;
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