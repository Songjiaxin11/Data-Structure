#include "deck.h"
#include "card.h"
#include <iostream>
using namespace std;
/**
 * @brief Construct a new Deck:: Deck object
 *
 */
Deck::Deck()
{
    reset();
}

void Deck::reset()
{
    int cardIndex = 0;
    for (int suit = SPADES; suit <= DIAMONDS; suit++)
    {
        for (int spot = TWO; spot <= ACE; spot++)
        {
            deck[cardIndex].suit = static_cast<Suit>(suit);
            deck[cardIndex].spot = static_cast<Spot>(spot);
            cardIndex++;
        }
    }
    //   The first card dealt should be the 2 of Spades.
    next = 0;
    // cout << "next spot: " << SuitNames[deck[next].suit] << endl;
    // cout << "next suit: " << SpotNames[deck[next].spot] << endl;
}

void Deck::shuffle(int n)
{
    Card tempDeck[DeckSize];
    // 初始化tempDeck
    for (int i = 0; i < DeckSize; i++)
    {
        tempDeck[i].suit = deck[i].suit;
        tempDeck[i].spot = deck[i].spot;
    }
    int leftIndex = 0;
    int rightIndex = n;
    int tempIndex = 0;
    while (leftIndex < n && rightIndex < DeckSize)
    {
        tempDeck[tempIndex++] = deck[rightIndex++];
        tempDeck[tempIndex++] = deck[leftIndex++];
    }
    while (leftIndex < n) // 右边牌堆已经用完, 左边全部加进去
    {
        tempDeck[tempIndex++] = deck[leftIndex++];
    }
    while (rightIndex < DeckSize) // 左边牌堆已经用完, 右边全部加进去
    {
        tempDeck[tempIndex++] = deck[rightIndex++];
    }
    for (int i = 0; i < DeckSize; i++) // 把tempDeck复制到deck
    {
        deck[i] = tempDeck[i];
    }
    next = 0;
    // cout << "next spot: " << SuitNames[deck[next].suit] << endl;
    // cout << "next suit: " << SpotNames[deck[next].spot] << endl;
}

Card Deck::deal()
{
    if (next > DeckSize)
    {
        throw DeckEmpty();
    }
    else
    {
        // int nextDeal = ++next;
        // cout << "next spot: " << SuitNames[deck[nextDeal].suit] << endl;
        // cout << "next suit: " << SpotNames[deck[nextDeal].spot] << endl;
        return deck[next++]; // 处理并返回这张牌
    }
}

int Deck::cardsLeft()
{
    // cout << DeckSize - next << endl;
    return DeckSize - next;
}
