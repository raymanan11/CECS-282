// Raymond An
// CECS 282-07
// Prog 1 - Solitaire Prime
// Due 2/12/2020

#include <iostream>
#include "Card.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

Card:: Card() {
    suit = 'A';
    rank = "";
    value = 0;
}

Card:: Card(string rank, char suit) {
    this->suit = suit;
    this->rank = rank;
    
    setValue(rank);
}

void Card:: setCard(string rank, char suit) {
    this->suit = suit;
    this->rank = rank;
    
    setValue(rank);
}

int Card:: getValue(){
    return value;
}

void Card:: showCard() {
    string card = rank + suit;
    cout << card << " ";
}

void Card:: setValue(string rank) {
    if (rank == "A") {
        value = 1;
    }
    else if (rank == "2") {
        value = 2;
    }
    else if (rank == "3") {
        value = 3;
    }
    else if (rank == "4") {
        value = 4;
    }
    else if (rank == "5") {
        value = 5;
    }
    else if (rank == "6") {
        value = 6;
    }
    else if (rank == "7") {
        value = 7;
    }
    else if (rank == "8") {
        value = 8;
    }
    else if (rank == "9") {
        value = 9;
    }
    else if(rank == "10") {
        value = 10;
    }
    else if (rank == "J") {
        value = 10;
    }
    else if (rank == "Q") {
        value = 10;
    }
    else if (rank == "K") {
        value = 10;
    }
}
