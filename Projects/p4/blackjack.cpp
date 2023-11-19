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
using namespace std;
void multiple_shuffle(Player *player, Deck &deck)
{
    // cout << "Shuffling the deck\n";
    cout << "Shuffling the deck" << endl;
    for (int i = 0; i < 7; ++i)
    {
        int cut = get_cut();
        cout << "cut at " << cut << endl;
        deck.shuffle(cut);
    }
    player->shuffled();
}

Card deal_four(Hand &hand, Player *player, Deck &deck, bool faceup, bool myplayer)
{
    Card card = deck.deal();
    hand.addCard(card);
    if (faceup)
    {
        player->expose(card);
        if (myplayer)
        {
            cout << "Player dealt " << SpotNames[card.spot] << " of " << SuitNames[card.suit] << endl;
        }
        if (!myplayer) // dealer
        {
            cout << "Dealer dealt " << SpotNames[card.spot] << " of " << SuitNames[card.suit] << endl;
        }
    }
    return card;
}

int main(int argc, char *argv[])
{
    Deck deck;
    Player *player = NULL;
    Hand hand_Player;
    Hand hand_Dealer;
    int minimum_bet = 5;
    int current_hand = 0;
    int bankroll = atoi(argv[1]);
    int hands = atoi(argv[2]);
    string mode = argv[3];
    if (mode == "simple")
    {
        player = get_Simple();
    }
    else if (mode == "counting")
    {
        player = get_Counting();
    }

    multiple_shuffle(player, deck); // 洗牌
    while (bankroll >= minimum_bet && current_hand < hands)
    {
        int cur_hand = ++current_hand;
        cout << "Hand " << cur_hand << " bankroll " << bankroll << endl;
        hand_Dealer.discardAll();
        hand_Player.discardAll();
        if (deck.cardsLeft() < 20)
        {
            multiple_shuffle(player, deck);
        }
        int wager = player->bet(bankroll, minimum_bet);
        cout << "Player bets " << wager << endl;
        deal_four(hand_Player, player, deck, true, true);
        Card up_card = deal_four(hand_Dealer, player, deck, true, false);
        deal_four(hand_Player, player, deck, true, true);
        Card hole_card = deal_four(hand_Dealer, player, deck, false, false);
        if (hand_Player.handValue().count == 21)
        {
            cout << "Player dealt natural 21" << endl;
            bankroll = bankroll + 1.5 * wager;
            continue;
        }
        while (player->draw(up_card, hand_Player))
        {
            deal_four(hand_Player, player, deck, true, true);
        }

        cout << "Player's total is " << hand_Player.handValue().count << endl;
        if (hand_Player.handValue().count > 21) // player busts
        {
            cout << "Player busts" << endl;
            bankroll = bankroll - wager;
        }
        else
        { // player not busts
            cout << "Dealer's hole card is " << SpotNames[hole_card.spot] << " of " << SuitNames[hole_card.suit] << endl;
            player->expose(hole_card);
            while (hand_Dealer.handValue().count < 17)
            {
                deal_four(hand_Dealer, player, deck, true, false);
            }
            cout << "Dealer's total is " << hand_Dealer.handValue().count << endl;
            if (hand_Dealer.handValue().count > 21) // dealer busts
            {
                cout << "Dealer busts" << endl;
                bankroll = bankroll + wager;
            }
            else
            {
                if (hand_Dealer.handValue().count > hand_Player.handValue().count) // dealer win
                {
                    cout << "Dealer wins" << endl;
                    bankroll = bankroll - wager;
                }

                else if (hand_Dealer.handValue().count < hand_Player.handValue().count) // player win
                {
                    cout << "Player wins" << endl;
                    bankroll = bankroll + wager;
                }
                else if (hand_Dealer.handValue().count == hand_Player.handValue().count) // tie
                {
                    cout << "Push" << endl;
                }
            }
        }
    } // end of hands
    cout << "Player has " << bankroll << " after " << current_hand << " hands\n";
    return 0;
}
