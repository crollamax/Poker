//
// Created by Max A Crolla on 15/12/2019.
//

#ifndef POKER_TABLE_H
#define POKER_TABLE_H


#include "player.h"
#include "card.h"

class Table {

    int pot = 0;
    std::vector<Player> players_at_table;
    std::vector<Card> table_cards;

public:
    Table();
    ~Table();

    int get_pot();

    void add_player(Player &new_player);

    void add_to_pot(int money);

    void reset_pot();

    void print_table_status(std::string turn_name);

    void deal_card(Card dealt_card, int player_number);

    void table_card(Card dealt_card);

    void print_table_cards(std::string turn_name);

    void get_user_input();

    void raise(int raise_amount, int player_number);

    void cpu_bet();
};


#endif //POKER_TABLE_H
