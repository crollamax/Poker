//
// Created by Max A Crolla on 14/12/2019.
//

#include "player.h"

#include <iostream>
#include <string>
#include <vector>

 Player::Player(std::string input_name)
        :name(input_name){
    num_of_cards = 0;
    money = 100;
    money_bet = 0;
}

Player::~Player() = default;

std::string Player::get_name() {
    return name;
}

int Player::getNumOfCards() {
    return num_of_cards;
}

std::vector<Card> Player::get_hand() {
    return hand;
}

void Player::deal_card(Card const& new_card) {
    if(num_of_cards<2){
        hand.push_back(new_card);
        num_of_cards += 1;
    }
    else{
        std::cout << name << " already has two cards!\n";
    }


}

void Player::print_hand() {

    if(num_of_cards == 0){
        std::cout << "No cards have been dealt yet.\n";
    }
    else {
        for (Card card_ : hand) {
            std::cout << card_.get_number() << card_.get_suit() << " ";
        }
        std::cout << "\n";
    }
}

int Player::get_money(){
    return money;
}

void Player::raise(int bet){

    money -= bet;
    money_bet += bet;
}

void Player::call(int call_amount){

    money -= call_amount;
}

void Player::check(){

}

void Player::fold(){
    status = "Folded";
}


void Player::add_money(int money_won){
    money += money_won;
}

std::string Player::get_status() {
    return status;
}

std::string Player::get_blind() {
    return blind;
}

bool Player::get_AI_status() {
    return is_AI;
}


