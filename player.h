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
    int money_bet;
    bool is_AI;
    bool has_folded;
    bool has_checked;
    std::string status;
    std::string blind;

public:
    explicit Player(std::string input_name="na");

    virtual ~Player();

    std::string get_name();

    std::vector<Card> get_hand();

    int getNumOfCards();

    void deal_card(const Card& new_card);

    void print_hand();

    int get_money();

    void raise(int bet);

    void check();

    void call(int call_amount);

    void fold();

    void add_money(int money_won);

    std::string get_status();

    std::string get_blind();

    bool get_AI_status();

};


#endif //POKER_PLAYER_H
