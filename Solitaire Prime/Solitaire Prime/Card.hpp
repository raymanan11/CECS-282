// Raymond An
// CECS 282-07
// Prog 1 - Solitaire Prime
// Due 2/12/2020

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Card {

private:
    char suit;
    string rank;
    int value;
    int div13;
    
public:
    Card();
    Card(string rank, char suit);
    void setCard(string rank, char suit);
    int getValue();
    void showCard();
    void setValue(string rank);
};

#endif /* Card_hpp */
