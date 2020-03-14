// Raymond An
// CECS 282-07
// Prog 1 - Solitaire Prime
// Due 2/12/2020

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include "Card.hpp"

class Deck {
    
private:
    Card storage[52];
    char suits[4] = {'S', 'H', 'D', 'C'};
    string rank[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    
    int suitSize;
    int rankSize;
    int deckSize;
    int currentCard;
    
public:
    Deck();
    void refreshDeck();
    Card deal();
    void shuffle();
    int cardsLeft();
    void showDeck();
    void playSolitairePrime();
};

#endif
