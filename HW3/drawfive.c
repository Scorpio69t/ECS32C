#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// global defines (constants) go here
struct node {
    int data;
    struct node* next;
};
// global variables go here
struct node* head = NULL;
int maxStack;
int currStackCount = 0;
int* playerScores;
int* highScoreindex;
int nMaxScore = 0; //counts how many players have this same max score

// write these functions. This is a requirement. Your code must include the following functions and you must
// invoke them to execute the stated behavior. 

// prints an error message and exits returning an error to the OS
//
void fatal(char* msg){
    printf("Error: %s\n", msg);
    exit(1);
}

// instructs user how to use the program and exits returning an error to the os
//
void usage(){
    printf("drawfive <number of players> [list of cards]\n         The number of players must be greater than 2\n");
    exit(1);
}

// pushes an integer onto the stack, exits with error if the stack is full
//
void push(int val){
    if (currStackCount == maxStack){
        char* msg = "Stack is full";
        fatal(msg);
    } else {
        struct node* n = malloc(sizeof(struct node));
        n -> data = val;
        n -> next = head;
        head = n;
        currStackCount++;
    }
}

// returns an integer from the stack, exits with error if the stack is empty
//
int pop(){
    if (head) {
        struct node* n = head;
        head = head -> next;
        int ret = n -> data; 
        free(n);
        return ret;
    } else {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
}

// fills stack with parameters provided from the command line
//
void fillStack(int argc, char** argv){
    for (int i = 2; i < argc; i++) {
        if (atoi(argv[i]) < 1 || atoi(argv[i]) > 10){
            char* msg = "Invalid card number given";
            fatal(msg);
        } else {
            int val = atoi(argv[i]);
            push(val);
        }
    }
}

// fills stack with random numbers
//
void fillStackWithRandomNumbers(int nPlayers){
    int totalCards = nPlayers * 5;
    for (int i = 0; i < totalCards; i++){
        int randNum = (rand() % 10) + 1; //This will ensure that there are no 0s
        push(randNum);
    }
}

// displays the stack in a space separated list. Use this for debugging. 
// It's not necessary to call this function in a normally running program
//
void showStack(){
    struct node* tempnode = head;
    while (tempnode -> next != NULL) {
        printf("%d ", tempnode -> data);
        tempnode = tempnode -> next;
    }
    printf("\n");
}

// displays scores for all players
//
void showScores(int nPlayers){
    for (int i = 0; i < nPlayers; i++) {
        int currPlayerScore = playerScores[i];
        int currPlayer = i + 1;
        printf("Player %d scored %d\n", currPlayer, currPlayerScore);
    }
    printf("\n");
}

// runs one game for the provided number of players reporting each card
// drawn by each player
//
void runGame(int nPlayers){
    int nDraws = nPlayers * 5;
    int playerNum = 1;
    int nCardsDrawn = 1;
    for (int i = 1; i <= nDraws; i++){
        int drawnCard = pop();
        playerScores[playerNum - 1] += drawnCard;
        printf("Player %d draws %d as %d of 5 cards\n", playerNum, drawnCard, nCardsDrawn);
        if (i % nPlayers == 0) {
            playerNum = 1;
            nCardsDrawn++;
        } else {
            playerNum++;
        }
    }
    printf("\n");
}

// computes the winning player and shows the results, pay careful
// attention to the output, the detail does matter
//
void showWinners(int nPlayers){
    highScoreindex = calloc(nPlayers, sizeof(int));
    int currMaxScore = 0;  
    for (int i = 0; i < nPlayers; i++) {
        if (playerScores[i] > currMaxScore) {
            currMaxScore = playerScores[i];
            highScoreindex[0] = i;
            nMaxScore = 1;
        } else if (playerScores[i] == currMaxScore) {
            highScoreindex[nMaxScore] = i;
            nMaxScore++;
        }
    }
    if (nMaxScore == 1) {
        int playerNum = highScoreindex[0] + 1;
        printf("Player %d won with a score of %d\n", playerNum, currMaxScore);
    } else if (nMaxScore == 2) {
        printf("Players %d and %d tied with a score of %d\n", highScoreindex[0] + 1, highScoreindex[1] + 1, currMaxScore);
    } else {
        printf("Players %d", highScoreindex[0] + 1);
        for (int j = 1; j < nMaxScore; j++) {
            if (highScoreindex[j] == nMaxScore - 1) {
                printf(" and %d tied with a score of %d\n", highScoreindex[j] + 1, currMaxScore);
            } else {
                printf(", %d", highScoreindex[j] + 1);
            }
        }
    }
    free(highScoreindex);
}

int main(int argc, char** argv){
    srand(time(NULL));
    int nPlayers = atoi(argv[1]);
    maxStack = nPlayers * 5;
    if (nPlayers < 2) {
        usage();
    }
    if (argc > 2) {
        fillStack(argc, argv);
    } else {
        fillStackWithRandomNumbers(nPlayers);
    }
    playerScores = calloc(nPlayers, sizeof(int));
    runGame(nPlayers);
    showScores(nPlayers);
    showWinners(nPlayers);
    free(playerScores);
}
