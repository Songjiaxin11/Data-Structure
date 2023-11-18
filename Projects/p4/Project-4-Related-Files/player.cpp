#include "player.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "rand.h"
using namespace std;
// Simple Player

class SimplePlayer : public Player
{
public:
    int bet(unsigned int bankroll, unsigned int minimum)
    {
        return minimum;
    }

    bool draw(Card dealer, const Hand &player)
    {
        HandValue playerValue = player.handValue();
        int playerCount = playerValue.count;
        bool isSoft = playerValue.soft;
        if (!isSoft) // hard count 模式
        {
            if (playerCount <= 11) // case 1
            {
                return true;
            }
            else if (playerCount == 12) // case 2
            {
                if (dealer.spot == FOUR || dealer.spot == FIVE || dealer.spot == SIX) // case 2,1
                {
                    return false;
                }
                else // case 2.2
                {
                    return true;
                }
            }
            else if (playerCount >= 13 && playerCount <= 16) // case 3
            {
                if (dealer.spot >= TWO && dealer.spot <= SIX) // case 3.1
                {
                    return false;
                }
                else
                {
                    return true; // case 3.2
                }
            }
            else if (playerCount >= 17)
            {
                return false;
            }
            else
            {
                assert("other cases in hard mode!");
            }
        } // if hard ends
        if (isSoft)
        {
            if (playerCount <= 17)
            {
                return true;
            }
            else if (playerCount == 18)
            {
                if (dealer.spot == TWO || dealer.spot == SEVEN || dealer.spot == EIGHT)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else if (playerCount >= 19)
            {
                return false;
            }
            else
            {
                assert("other cases in soft mode!");
            }
        }
    }

    void expose(Card c)
    {
        // Simple player does nothing for expose
    }

    void shuffled()
    {
        // Simple player does nothing for shuffled
    }
};

// Counting Player

class CountingPlayer : public Player
{
    int count; // Running count of cards
public:
    CountingPlayer() : count(0) {}

    int bet(unsigned int bankroll, unsigned int minimum)
    {
        if (count >= 2 && bankroll >= 2 * minimum)
        {
            return 2 * minimum;
        }
        else
        {
            return minimum;
        }
    }

    bool draw(Card dealer, const Hand &player)
    {
        SimplePlayer countingMode;
        countingMode.draw(dealer, player);
    }

    void expose(Card c)
    {
        if (c.spot >= TEN && c.spot <= ACE)
        {
            count--;
        }
        else if (c.spot >= TWO && c.spot <= SIX)
        {
            count++;
        }
    }

    void shuffled()
    {
        // Reset the count when the deck is shuffled
        this->count = 0;
    }
};

// Static instances of players

static SimplePlayer simple_player;
static CountingPlayer counting_player;

Player *get_Simple()
{
    return &simple_player;
}

Player *get_Counting()
{
    return &counting_player;
}
