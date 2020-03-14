// Raymond An
// CECS 282-07
// Prog 1 - Solitaire Prime
// Due 2/12/2020

#include <iostream>
#include "Deck.hpp"
#include "Card.hpp"

bool isPrime(int);

int main() {
    Deck myDeck;

    int userChoice = 0;
//    cout << "Welcome to Solitaire Prime!" << endl;
//    cout << endl;
//    cout << "What would you like to do?" << endl;
//    cout << "1.) New Deck" << endl;
//    cout << "2.) Display Deck"<< endl;
//    cout << "3.) Shuffle Deck" << endl;
//    cout << "4.) Play Solitaire Prime" << endl;
//    cout << "5.) Exit" << endl;
//    cout << endl;
//    cout << "Please enter your choice: ";
//    cin >> userChoice;
//    cout << endl;

    while (userChoice != 5) {
        cout << "Welcome to Solitaire Prime!" << endl;
        cout << endl;
        cout << "What would you like to do?" << endl;
        cout << "1.) New Deck" << endl;
        cout << "2.) Display Deck"<< endl;
        cout << "3.) Shuffle Deck" << endl;
        cout << "4.) Play Solitaire Prime" << endl;
        cout << "5.) Exit" << endl;
        cout << endl;
        cout << "Please enter your choice: ";
        cin >> userChoice;
        cout << endl;
        
        if (userChoice == 1) {
            myDeck.refreshDeck();
        }
        else if (userChoice == 2) {
            myDeck.showDeck();
            cout << endl;
        }
        else if (userChoice == 3) {
            myDeck.shuffle();
        }
        else if (userChoice == 4) {
            string status;
            int pile = 0;
            Card c1;
            int numPiles = 0;
            while(myDeck.cardsLeft() != 1) {
                numPiles++;
                //cout << "a ";
                c1 = myDeck.deal();
                pile = c1.getValue();
                c1.showCard();
                
                while (isPrime(pile) == false) {
                    if (myDeck.cardsLeft() == 1) {
                        //cout << "c ";
                        // if one card left and pile is prime then pile is 0 so that when drawing last card out of this while loop, it will be it's own pile
                        // but if one card left and pile is not prime, then pile stays same value so last card can be added to the pile and checked if prime or not
                        if (isPrime(pile) == true) {
                            cout << "Prime pile: Start Over." << endl;
                            pile = 0;
                        }
                        //cout << "hi" << endl;
                        break;
                    }
                    //cout << "b ";
                    c1 = myDeck.deal();
                    c1.showCard();
                    pile = pile + c1.getValue();
                }
                // if there is more than one card left in the deck then reset the pile whenever the pile is prime but if there is one card left don't reset the pile because still need to deal card out of the for loop to check if it's prime or not
                if (myDeck.cardsLeft() != 1) {
                    cout << "Prime is: " << pile << endl;
                    //cout << "Cards left is: " << myDeck.cardsLeft() << endl;
                    pile = 0;
                }
            }
            
            c1 = myDeck.deal();
            c1.showCard();
            pile = pile + c1.getValue();
            cout << endl;
            cout << "Final Pile Value is: " << pile << endl;
            //cout << "Cards left is: " << myDeck.cardsLeft() << endl;
            cout << endl;
            if (isPrime(pile)) {
                cout << "Winner in " << numPiles << " piles! Last Pile is prime!" << endl;
            }
            else {
                cout << "Loser! Last Pile is not prime!" << endl;
            }
            cout << endl;
        
        }

//        cout << endl;
//        cout << "Now what would you like to do?" << endl;
//        cout << "1.) New Deck" << endl;
//        cout << "2.) Display Deck"<< endl;
//        cout << "3.) Shuffle Deck" << endl;
//        cout << "4.) Play Solitaire Prime" << endl;
//        cout << "5.) Exit" << endl;
//        cout << endl;
//        cout << "Please enter another choice: ";
//        cin >> userChoice;
//        cout << endl;
    }
    return 0;
}

bool isPrime(int pileValue) {
    // true = prime = 1
    // false = not prime = 0
    bool prime = true;
    if (pileValue == 1) {
       prime = false;
    }
    for(int i = 2; i <= pileValue / 2; i++) {
       if(pileValue % i == 0) {
          prime = false;
          break;
       }
    }
    return prime;
}
