//
// Created by Max A Crolla on 13/12/2019.
//

#ifndef POKER_HAND_H
#define POKER_HAND_H


#include <vector>
#include "card.h"

class Hand{
    std::vector<Card> hand;
    int num_of_cards;

public:
    Hand();

    virtual ~Hand();

    std::vector<Card> get_hand();

    int getNumOfCards() const;

    void deal_card(Card new_card);

};




#endif //POKER_HAND_H

