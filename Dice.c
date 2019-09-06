#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
/*
Name: Dice Game
Authors: Joel Linden, Caleb Kender
Purpose: To accept a number of credits from user properly (no letters,floats, or negative numbers),
prompt the user for a wager bet correctly (no letters,floats, negative numbers, or amount above the credits),
then roll a "dice"(random number between 1 and 6) to determine whether the user gains the wager amount of credits,
loses that amount, or neither in case of a draw
Date: 9/9/19
*/
void welcome(int* credits);     //Welcome function - welcomes user to game, then asks for number of credits and passes credits by reference
void bet(int* betnum, int* credits);        // Prompts for a wager, and makes sure wager is positive integer below number of credits
void contest(int* betnum, int* credits);

int main()
{
    int credits, betnum;
    char response;

    welcome(&credits);  // Welcome and take in credits

     do{
    bet(&betnum, &credits);     // Pass credits in, and return with wager number
    contest(&betnum, &credits);     // Commence contest
    if(credits <= 0){           // If no credits zero then exit out of game
        break;
    };
    printf("Play again? (Y/N)");
    fflush(stdin);
    scanf("%c",&response);      // Scan for character (Assuming Y and N are only things that will be entered, not checking that they are)
    if(response == 'N' ){       // If no, break out of loop
        break;
    };
    }while(1);                  // If not no, repeat wager amount and contest
    return 0;
}

void welcome (int*credits){
    printf("Welcome to the Dice Game!\n");
    float floatCR;
    int num;
do{
printf("Please enter credits(positive integer): ");
fflush(stdin);
num = scanf("%f", &floatCR);                // Attempts to scan in a float/ integer as a float
if ((floatCR == (int)floatCR) && floatCR > 0 && num == 1){          // If it does scan in float, and the float is a positive integer, then continue
*credits = (int)floatCR;        // Set credits equal to integer of float
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
num = scanf("%f", &floatbet);       // Scans for a number as a float
if ((floatbet == (int)floatbet) && floatbet > 0 && num == 1 && floatbet <= *credits){       // Checks that a number is scanned in, given number is a positive integer, and that the number is lower than the number of credits
*betnum = (int)floatbet;        // Set the bet amount to float typecast as integer
    break;
}

}while(1);
};

void contest(int* betnum, int* credits){
int AINum;
int userNum;
srand(time(NULL));
AINum = (rand() % 6)+1;     // Generates random number between 1 and 6 for AI
userNum = (rand() % 6) +1;  // Generates random number between 1 and 6 for User
printf("AI roll: %d, User Roll: %d\n", AINum, userNum);

if(AINum > userNum){                    // The if/ else if statements determine who wins by comparing the numbers
        *credits -= *betnum;            // Loss means credits reduced by wager amount
    printf("You Lose!\nCredits: %d\n", *credits);
}
else if(AINum == userNum){
    printf("Draw!\nCredits: %d\n", *credits);   // Draw means no change in credits
}
else if(AINum < userNum){
        *credits += *betnum;                    // // Win means credits increased by wager amount
    printf("You Win!\nCredits: %d\n", *credits);
}
}

