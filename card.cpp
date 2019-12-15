//
// Create a Card class, with a suit and a number
//
#include "card.h"

#include <iostream>

Card::Card(int new_number, char new_suit)
    : number(new_number), suit(new_suit) {}

Card::~Card() = default;

int Card::get_number(){
    return number;
}

char Card::get_suit(){
    return suit;
}

void Card::print_card(){

    std::cout << number << suit << " ";
}