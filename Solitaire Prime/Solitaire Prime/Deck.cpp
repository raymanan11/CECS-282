// Raymond An
// CECS 282-07
// Prog 1 - Solitaire Prime
// Due 2/12/2020

#include <iostream>
#include "Deck.hpp"
#include <stdlib.h>
#include <time.h>

// deck class for making an array of card objects representing a deck of cards
Deck:: Deck() {
    
    suitSize = sizeof(suits) / sizeof(*suits);
    rankSize = sizeof(rank) / sizeof(*rank);
    deckSize = sizeof(storage) / sizeof(*storage);
    
    currentCard = 0;
    int count = 0;
    
    // 2 dimensional for loops used to create deck of cards
    for (int i = 0; i < suitSize; i++) {
        for (int j = 0; j < rankSize; j++) {
            storage[count].setCard(rank[j], suits[i]);
            count++;
        }
    }
}

void Deck:: refreshDeck() {
    int count = 0;
    for (int i = 0; i < suitSize; i++) {
        for (int j = 0; j < rankSize; j++) {
            storage[count].setCard(rank[j], suits[i]);
            count++;
        }
    }
}

Card Deck:: deal(){
    if (currentCard == deckSize) {
        currentCard = 0;
    }
    return storage[currentCard++];
}

void Deck:: shuffle(){
    
    Card temp;
    
    srand(time(0));
    
    for (int nextCard = 0; nextCard < 10000; nextCard++) {
        int randomIndex1 = rand() % deckSize;
        int randomIndex2 = rand() % deckSize;
        
        temp = storage[randomIndex1];
        storage[randomIndex1] = storage[randomIndex2];
        storage[randomIndex2] = temp;
        
        //swap(storage[randomIndex1], storage[randomIndex2]);
    }
}

int Deck:: cardsLeft(){
    return deckSize - currentCard;
}

void Deck:: showDeck(){
    int thirteenCards = 0;
    for (int i = 0; i < deckSize; i++) {
        thirteenCards++;
        storage[i].showCard();
        if (thirteenCards == 13) {
            thirteenCards = 0;
            cout << endl;
        }
    }
}




