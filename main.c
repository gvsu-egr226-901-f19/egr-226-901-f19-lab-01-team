#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

void welcome(int* credits);
void bet(int* betnum, int* credits);
void contest(int* betnum, int* credits);

int main()
{
    int credits, betnum;
    char response;

    welcome(&credits);
     do{
    bet(&betnum, &credits);
    contest(&betnum, &credits);
    if(credits <= 0){
        break;
    };
    printf("Play again? (Y/N)");
    fflush(stdin);
    scanf("%c",&response);
    if(response == 'N' ){
        break;
    };
    }while(1);
    return 0;
}

void welcome (int*credits){
    printf("Welcome to the Dice Game!\n");
    float floatCR;
    int num;
do{
printf("Please enter credits(positive integer): ");
fflush(stdin);
num = scanf("%f", &floatCR);
if ((floatCR == (int)floatCR) && floatCR > 0 && num == 1){
*credits = (int)floatCR;
    break;
}
}while(1);
};

void bet(int* betnum, int* credits){
float floatbet;
    int num;
do{
printf("Please enter bet(positive integer less than or equal to credits): ");
fflush(stdin);
num = scanf("%f", &floatbet);
if ((floatbet == (int)floatbet) && floatbet > 0 && num == 1 && floatbet <= *credits){

*betnum = (int)floatbet;
    break;
}

}while(1);
};

void contest(int* betnum, int* credits){
int AINum;
int userNum;
srand(time(NULL));
AINum = (rand() % 6)+1;
userNum = (rand() % 6) +1;
printf("AI roll: %d, User Roll: %d\n", AINum, userNum);

if(AINum > userNum){
        *credits -= *betnum;
    printf("You Lose!\nCredits: %d\n", *credits);
}
else if(AINum == userNum){
    printf("Draw!\nCredits: %d\n", *credits);
}
else if(AINum < userNum){
        *credits += *betnum;
    printf("You Win!\nCredits: %d\n", *credits);
}
}
