#include "Hand.h"

string Hand::printHand(){
    stringstream bb;
    for (int i = 0; i < hand.size(); i++) {
        bb << "[" << i + 1 << "] " << hand.at(i).printCard() << " ";
    }
    return bb.str();
}

Card Hand::dealCard(int num){
    Card temp;
    temp = hand.at(num);
    hand.erase(hand.begin() + num);
    return temp;
}

int Hand::getHandSize(){
    return hand.size();
}

