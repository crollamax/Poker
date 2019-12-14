//
// Created by Max A Crolla on 14/12/2019.
//


#ifndef POKER_PLAYER_H
#define POKER_PLAYER_H

#include <vector>
#include <string>
#include "card.h"
#include "hand.h"

class Player{

    std::vector<Card> hand;
    std::string name;
    int num_of_cards;
    int money;
    bool is_AI;

public:
    Player(std::string input_name="na", bool AI=false);

    virtual ~Player();

    std::string get_name();

    std::vector<Card> get_hand();

    int getNumOfCards();

    void deal_card(Card new_card);

    void print_hand();

    int get_money();

};


#endif //POKER_PLAYER_H
