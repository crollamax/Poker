//
// Created by Max A Crolla on 14/12/2019.
//

#include <chrono>
#include <random>
#include "deck.h"

Deck::Deck(){}

Deck::~Deck(){}

std::vector<Card> Deck::get_fresh_deck() {
    std::vector<Card> fresh_deck;
    std::vector<char> suits = {'H', 'C', 'S', 'D'};

    for(int i = 1; i < 14; i++){
        for (int j=1; j < 4; j++){
            Card new_card(i, suits[j]);
            fresh_deck.push_back(new_card);
        }
    }

    return fresh_deck;
}

void Deck::shuffle_deck(std::vector<Card> &deck_to_shuffle){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle( deck_to_shuffle.begin(), deck_to_shuffle.end(),std::default_random_engine(seed));
}