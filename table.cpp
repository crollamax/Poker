//
// Created by Max A Crolla on 15/12/2019.
//

#include <iostream>
#include <ctime>

#include "table.h"
#include "player.h"

Table::Table() {
}

Table::~Table() = default;

int Table::get_pot() {
    return pot;
}

void Table::add_player(Player &new_player){
    players_at_table.push_back(new_player);
}

void Table::add_to_pot(int money){
    pot += money;
}

void Table::reset_pot(){
    pot = 0;
}

void Table::print_table_status(std::string turn_name) {
    std::cout << "\n\n";

    std::cout << "Name  Money  Status Pot\n";


    for(int i=0, n = players_at_table.size(); i < n; i++){
        Player player = players_at_table[i];
        if (i == 0) {
            std::cout << player.get_name() << "   " << player.get_money() << "    " << player.get_status() << "        " << pot << "\n";
        } else {
            std::cout << player.get_name() << "   " << player.get_money() << "    " << player.get_status()<< "\n";
        }
    }
    std::cout << "\n";

    Player user = players_at_table[0];
    std::cout << "Your hand: ";
    user.print_hand();

    if(turn_name != "") {
        print_table_cards(turn_name);
    }

}

void Table::deal_card(Card dealt_card, int player_number){
    players_at_table[player_number].deal_card(dealt_card);
}

void Table::table_card(Card dealt_card){
    table_cards.push_back(dealt_card);
}

void Table::print_table_cards(std::string turn_name) {
    std::cout << turn_name << ": ";
    for(Card card: table_cards){
        card.print_card();
    }
    std::cout << "\n";
}

void Table::raise(int raise_amount, int player_number) {
    players_at_table[player_number].raise(raise_amount);
    pot += raise_amount;


}

void Table::get_user_input() {
    char char_input = 'z';
    while(char_input != 'r' && char_input != 'c' && char_input != 'k' && char_input != 'f' ) {
        std::cout << "What's your decision? (r/raise, c/call, k/check, f/fold)\n";
        std::cin >> char_input;
    }
    if (char_input == 'r'){
        int raise_amount;
        std::cout << "How much?\n";
        std::cin >> raise_amount;
        raise(raise_amount, 0);

    }
    else if(char_input == 'c'){

    }
    else if(char_input == 'k'){

    }
    else{
        players_at_table[0].fold();
    }
}

void Table::cpu_bet(){
    srand(time(nullptr));
    for(int i = 1; i < 6; i++){

        if(players_at_table[i].get_status() == "Folded"){
            continue;
        }

        double r = ((double) rand() / (RAND_MAX));
        if(r < 0.33333){
            int raise_amount = (int) rand() % players_at_table[i].get_money();
            raise(raise_amount, i);
        }
        else if(r < 0.66666){
            //check or call
        }
        else{
            players_at_table[i].fold();
        }

    }
}
//    std::cout << "\nMoney: ";
//
//    for(Player player: players_at_table){
//        std::cout << player.get_money() << "  ";
//    }
//
//    std::cout << "\nStatus: ";
//
//    std::cout << "\n\n\n";


