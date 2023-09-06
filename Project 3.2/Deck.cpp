#include "Deck.h"

void Deck::shuffle(){
    srand(unsigned(time(0)));
    random_shuffle(deck.begin(), deck.end());
}

Card Deck::drawCard(){
    Card temp;
    temp = deck.at(0);
    deck.erase(deck.begin());
    return temp;
}

int Deck::getDeckSize(){
    return deck.size();
}





