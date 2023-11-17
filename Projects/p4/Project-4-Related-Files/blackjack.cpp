#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "rand.h"

int main()
{
    // Implement the main simulation driver
    Deck deck1;
    Hand hand;
    Card c1, c2, c3, c4, c5;
    c1.spot = ACE;
    c2.spot = TWO;
    c3.spot = ACE;
    c4.spot = KING;
    Deck();
    deck1.shuffle(50);
    deck1.deal();
    deck1.deal();
    deck1.cardsLeft();
    Hand();
    hand.addCard(c1);
    hand.addCard(c2);
    hand.addCard(c3);
    hand.addCard(c4);
    hand.handValue();
    return 0;
}
