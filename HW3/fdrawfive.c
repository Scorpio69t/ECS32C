#include <stdio.h>
#include <stdlib.h>

const char* suits[] = {"Clubs","Diamonds","Spades","Hearts"};
const char* ranks[] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

struct card { //card struct that is string values of the rank and suit of card
    char rank[7];
    char suit[9];
    int value;
};

struct card* head = NULL;


// prints an error message and exits returning an error to the OS
//
void fatal(char* msg){
    printf("Error: %s\n", msg);
    exit(1);
}

// instructs user how to use the program and exits returning an error to the os
//
void usage(){
    printf("drawfive <number of players> [list of cards]\n  The number of players must be greater than 2\n");
    exit(1);
}

// pushes a card onto the stack, exits with error if the stack is full
//
void push(int val){
    struct card* n = malloc(sizeof(struct card));
    n -> data = val;
    n -> next = head;
    head = n;
}

