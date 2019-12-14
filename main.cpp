#include <ctime>
#include <iostream>
#include <algorithm>
#include <random>

#include "card.h"
#include "hand.h"
#include "player.h"
#include "deck.h"

void print_table_cards(std::vector<Card> card_list);

int main() {



    int num_of_players = 2;
    std::vector<Player> player_list(num_of_players);


    // creates players with names and a boolean value for whether they are AI or not
    for(int i=0; i<num_of_players; i++){

        std::string player_name;
        std::string AI_;
        std::cout << "Insert Player " << i + 1 << "'s name here: \n";
        std::cin >> player_name;

        do {
            std::cout << "AI? (y/n)";
            std::cin >> AI_;
        }
        while(AI_ != "y" and AI_ != "n");

        bool AI;
        AI = AI_ == "y";

        Player new_player(player_name, AI);
        player_list[i] = (new_player);
    }


    // create and shuffle deck
    Deck deck_obj;
    std::vector<Card> deck = deck_obj.get_fresh_deck();
    deck_obj.shuffle_deck(deck);

    // deal every player two cards
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < num_of_players; j++){
            Card dealt_card = deck.back();
            deck.pop_back();
            player_list[j].deal_card(dealt_card);
        }
    }

    // Need to add big/small blinds and some sort of money system

    std::string skip;
    std::cout << "The cards have been dealt, place your bets.\n";
    std::cin >> skip;

    // burn a card
    deck.pop_back();

    // create list of all dealt cards
    std::vector<Card> table_cards;

    // the flop
    std::cout << "The flop: \n";
    for(int i = 0; i < 3; i++){
        Card dealt_card = deck.back();
        table_cards.push_back(dealt_card);
        deck.pop_back();
    }

    print_table_cards(table_cards);

    std::cout << "Place your bets \n";
    std::cin >> skip;

    // burn a card
    deck.pop_back();

    Card turn_card = deck.back();
    table_cards.push_back(turn_card);
    deck.pop_back();

    std::cout << "The turn: \n";
    print_table_cards(table_cards);

    std::cout << "Place your bets \n";
    std::cin >> skip;

    Card river_card = deck.back();
    table_cards.push_back(river_card);
    deck.pop_back();

    std::cout << "The river: \n";
    print_table_cards(table_cards);

    std::cout << "Place your bets \n";
    std::cin >> skip;


}

void print_table_cards(std::vector<Card> card_list){

    for(Card card: card_list){
        card.print_card();
    }

    std::cout << "\n";


}