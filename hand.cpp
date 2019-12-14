//
// Created by Max A Crolla on 13/12/2019.
//

#include "hand.h"

Hand::Hand() {}

Hand::~Hand() {

}

int Hand::getNumOfCards() const {
    return num_of_cards;
}

std::vector<Card> Hand::get_hand() {
    return hand;
}

void Hand::deal_card(Card new_card) {
    hand.push_back(new_card);
    num_of_cards += 1;

}
