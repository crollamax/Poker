//
// Created by Max A Crolla on 14/12/2019.
//

#ifndef POKER_DECK_H
#define POKER_DECK_H


#include <vector>
#include "card.h"

class Deck {

public:
    Deck();
    ~Deck();

    std::vector<Card> get_fresh_deck();

    void shuffle_deck(std::vector<Card> &deck_to_shuffle);

};


#endif //POKER_DECK_H
