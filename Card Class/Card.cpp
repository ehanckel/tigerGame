#include "Card.h"
#include <sstream>
#include <string>

string Card::printCard(){
    stringstream ss;
    if (getColor() == 0) {
        ss << "purple:" << getRank();
    } else if (getColor() == 1) {
        ss << "orange:" << getRank();
    }
    
    return ss.str();
}

int Card::getRank(){
    return rank;
}

Card::Color Card::getColor(){
    return color;
}

int Card::getValue(){
    if (color == purple) {
        value = rank;
        return value;
    } else {
        value = 2 * rank;
        return value;
    }
}
