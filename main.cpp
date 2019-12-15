#include <ctime>
#include <iostream>
#include <algorithm>
#include <random>

#include "card.h"
#include "hand.h"
#include "player.h"
#include "deck.h"
#include "table.h"

void print_table_cards(std::vector<Card> card_list);

int main() {

    int num_of_players = 6;
    int turn_number = 0;
    std::string player_name;

    std::vector<Player> player_list(num_of_players);
    Table table;


    std::cout << "Please enter your name: \n";
    std::cin >> player_name;
    Player user(player_name);

    table.add_player(user);

    std::vector<std::string> player_names = {"Jef", "Big", "Jez", "Jet", "Liz"};

    for (int i = 0; i < 5; i++) {

        Player cpu(player_names[i]);
        table.add_player(cpu);
    }

//
    // most/all of the below will need to go into some kind of loop, atm just do one hand


    // create and shuffle deck
    Deck deck_obj;
    std::vector<Card> deck = deck_obj.get_fresh_deck();
    deck_obj.shuffle_deck(deck);

    // deal every player two cards
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < num_of_players; j++){
            Card dealt_card = deck.back();
            table.deal_card(dealt_card, j);
            deck.pop_back();
        }
    }

    table.print_table_status("");

    // Need to add big/small blinds and some sort of money system

    std::string skip;

    table.get_user_input();
    table.cpu_bet();

   // burn a card
    deck.pop_back();

    // the flop
    for(int i = 0; i < 3; i++) {
        Card dealt_card = deck.back();
        table.table_card(dealt_card);
        deck.pop_back();
    }

    table.print_table_status("The flop");

    table.get_user_input();
    table.cpu_bet();


    // burn a card
    deck.pop_back();

    Card turn_card = deck.back();
    table.table_card(turn_card);
    deck.pop_back();

    table.print_table_status("The turn");

    table.get_user_input();

    Card river_card = deck.back();
    table.table_card(river_card);
    deck.pop_back();

    table.print_table_status("The river");

    
}