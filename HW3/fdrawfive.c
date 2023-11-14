#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* suits[] = {"Clubs","Diamonds","Spades","Hearts"};
const char* ranks[] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

struct card { //card struct that is string values of the rank and suit of card
    char rank[7]; //Rank is achieved by getting int value % 13
    char suit[9]; //Suit is achieved by gettin in value / 13, it will always round down
    int value;
};

struct node* head = NULL; //intialize the head node

struct node {
    struct card* pointedCard; //the data for each node will just be a pointer to a card struct
    struct node* next;
};
//GLOBAL DEFINES
int* playerScores;
int maxStack;
int currStackCount = 0;
int* highScoreindex;
int nMaxScore = 0; //counts how many players have this same max score

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

void push(int val) {
    if (val > 52 || val < 1) {
        char* msg = "Invalid card index";
        fatal(msg);
    } else if (currStackCount == maxStack) {
        char* msg = "Stack is full!";
        fatal(msg);
    }
    struct card* pointedCard = malloc(sizeof(struct card));
    struct node* n = malloc(sizeof(struct node));
    int suitIndex = (val - 1) / 13;
    int rankIndex = (val - 1) % 13;
    int cardValue;
    if (val % 13 == 0) {
        cardValue = 13;
    } else {
        cardValue = val % 13;
    }
    strncpy(pointedCard -> rank, ranks[rankIndex], sizeof(pointedCard -> rank) - 1); //Assign rank to card struct
    pointedCard -> rank[sizeof(pointedCard->rank) - 1] = '\0';
    strncpy(pointedCard -> suit, suits[suitIndex], sizeof(pointedCard -> suit) - 1); //Assign suit to card struct
    pointedCard -> suit[sizeof(pointedCard -> suit) - 1] = '\0';
    pointedCard -> value = cardValue; //Will just use rankIndex to assign value which is same as rank
    n -> pointedCard = pointedCard;
    n -> next = head;
    head = n;   
    currStackCount++;
}

struct card* pop(){ //Will return the pointer to a card struct
    if (head) {
        struct node* n = head;
        struct card* pointedCard = n -> pointedCard; //gets the pointed card
        head = n -> next;
        free(n);
        return pointedCard;
    } else {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
}

void fillStack(int argc, char** argv){
    for (int i = 2; i < argc; i++) {
        int val = atoi(argv[i]);
        push(val);
    }
}

void fillStackWithRandomNumbers(int nPlayers){
    int totalCards = nPlayers * 5;
    for (int i = 0; i < totalCards; i++){
        int randNum = (rand() % 52) + 1; //generates random numbers between 1 and 52
        push(randNum);
    }
}

void showStack(){
    struct node* tempnode = head;
    while (tempnode -> next != NULL) {
        struct card* pointedCard = tempnode -> pointedCard;
        printf("%s of %s, ", pointedCard -> rank, pointedCard -> suit);
        tempnode = tempnode -> next;
    }
    printf("\n");
}

void showScores(int nPlayers) {
    for (int i = 0; i < nPlayers; i++) {
        int currPlayerScore = playerScores[i];
        int currPlayer = i + 1;
        printf("Player %d scored %d\n", currPlayer, currPlayerScore);
    }
    printf("\n");
}

void runGame(int nPlayers) {
//REMEMEBR TO FREE THE CARD STRUCTS
//Player 1 draws Five of Clubs with value 5 as 1 of 5 cards
    int nDraws = nPlayers * 5;
    int playerNum = 1;
    int nCardsDrawn = 1;
    for (int i = 1; i <= nDraws; i++){
        struct card* pointedCard = pop();
        char cardRank[7];
        char cardSuit[9];
        strcpy(cardRank, pointedCard->rank); 
        strcpy(cardSuit, pointedCard->suit);
        playerScores[playerNum - 1] += pointedCard -> value;
        printf("Player %d draws %s of %s with value %d as %d of 5 cards\n", playerNum, cardRank, cardSuit, pointedCard -> value, nCardsDrawn);
        if (i % nPlayers == 0) {
            playerNum = 1;
            nCardsDrawn++;
        } else {
            playerNum++;
        }
        free(pointedCard);
    }
    printf("\n");
}

void showWinners(int nPlayers) {
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
        printf("\n");
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