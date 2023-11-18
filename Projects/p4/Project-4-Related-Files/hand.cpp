#include "hand.h"
#include <iostream>
using namespace std;
Hand::Hand()
{
    discardAll();
}

void Hand::discardAll()
{
    this->curValue.count = 0;
    this->curValue.soft = false;
}

void Hand::addCard(Card c)
{
    if (c.spot == ACE)
    {
        if (!this->curValue.soft && this->curValue.count <= 10)
        {
            this->curValue.count += 11;
            this->curValue.soft = true;
        }
        else
        {
            this->curValue.count += 1;
            this->curValue.soft = false;
        }
    }
    else if ((c.spot == JACK) || (c.spot == QUEEN) || (c.spot == KING))
    {
        this->curValue.count += 10;
    }
    else if (c.spot >= TWO && c.spot <= TEN)
    {
        this->curValue.count += static_cast<int>(c.spot) + 2;
    }
    if(this->curValue.count >21&&this->curValue.soft)
    {
        this->curValue.soft = false;
        this->curValue.count-=10;
    }
}

HandValue Hand::handValue() const
{
    // cout<<"count: "<<this->curValue.count<<endl;
    return this->curValue;
}
