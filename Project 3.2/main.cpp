#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main() {

  int selection;
  int valC;
  int valU;
  int rounds = 1;
  Card temp;

  // 1. Create a deck of cards and shuffle it.
  Deck deckOfCards;
  deckOfCards.shuffle();
  
  // 2. Create two players, each one with 5 cards in their hand.
  Player user(deckOfCards, 5);
  Player computer(deckOfCards, 5);

  
  // 3. Play five rounds. In each round:
  while (rounds < 6) {
    cout << "Round " << rounds << endl << "-------" << endl;

    //    - Have computer deal a card from their hand.
    temp = computer.hand.dealCard(0);
    valC = temp.getValue();
    cout << "The computer plays: " << temp.printCard() << endl;

    //    - Show human their hand of cards so that they can make a selection.
    cout << "Your hand: " << user.hand.printHand() << endl;
    cout << "Which card do you want to play? "; 
    cin >> selection;
    
    // input validation, make sure user input a value within vector size
    while (selection < 1 || selection > user.hand.getHandSize()) {
      cout << "Invalid input." << endl;
      cout << "Which card do you want to play? ";
      cin >> selection; 
    }

    //    - Have human deal their card. 
    temp = user.hand.dealCard(selection - 1);
    valU = temp.getValue();
    cout << "You played: " << temp.printCard() << endl;

    //    - Determine who won the round and update points accordingly.
    if (valC > valU) {
      cout << "Computer wins!" << endl; 
      computer.score += (valC + valU);
    } else if (valC < valU) {
      cout << "You win!" << endl;
      user.score += (valC + valU);
    } else {
      cout << "Tie!" << endl;
    }

    //    - Print results for current round.
    cout << endl;
    cout << "Current Scores:" << endl; 
    cout << "Human: " << user.score << endl;
    cout << "Computer: " << computer.score << endl << endl;
    rounds++;
  }

  // 4. Print final game results.  
  cout << "FINAL SCORE:" << endl;
  cout << "Human: " << user.score << endl;
  cout << "Computer: " << computer.score << endl;

  if (user.score > computer.score) {
    cout << "Human has won!" << endl;
  } else if (user.score < computer.score) {
    cout << "Computer has won!" << endl;
  } else {
    cout << "It's a tie!" << endl;
  }
      
  
  return 0;
}
