#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Card.h"

class Deck
{
    vector<Card> deck;

    public:
        Deck() {
            for (int i = 1; i < 11; i++) {
                deck.push_back(Card(i, Card::purple));
                
            }
            for (int i = 1; i < 11; i++) {
                deck.push_back(Card(i, Card::orange));
            }
        }
        void shuffle();
        Card drawCard();
        int getDeckSize();

};
  

#endif // DECK_H_
