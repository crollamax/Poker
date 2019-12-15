//
// Created by Max A Crolla on 13/12/2019.
//

#ifndef POKER_CARD_H
#define POKER_CARD_H



class Card{
    int number;
    char suit;
public:
    explicit Card(int new_number = 0, char new_suit='N');

    virtual ~Card();

    char get_suit();

    int get_number();

    void print_card();
};

#endif //POKER_CARD_H