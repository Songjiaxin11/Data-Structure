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

int main() {
    // Implement the main simulation driver
    Deck deck1;
    Deck();
    deck1.shuffle(50);
    deck1.deal();
    deck1.deal();
    deck1.cardsLeft();
    return 0;
}
