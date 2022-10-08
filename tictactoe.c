#include <stdio.h> 

char box[10]={'0','1','2','3','4','5','6','7','8','9'};
void creating_board();
void marking_board(int, char);
int check_winner();

int main() {
    creating_board();

    return 0;
}
void creating_board() {
    printf("The current status is:\n\n");
    printf("+------------+\n");
    printf("| %c | %c | %c |\n",box[1],box[2],box[3]);
    printf("+------------+\n");
    printf("| %c | %c | %c |\n",box[4],box[5],box[6]);
    printf("+------------+\n");
    printf("| %c | %c | %c |\n",box[7],box[8],box[9]);
    printf("+------------+\n");

}