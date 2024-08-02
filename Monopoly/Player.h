// Created by Mehmet Selman Yilmaz on 12.05.2023.

#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <string>
#include <iostream>

class Player {
private:
    Board& board; // Reference to the board object
    std::string name;
    int balance;
    Node* current;

public:
    Player(Board & myboard, std::string player_name, int capital)
            : board(myboard), name(player_name), balance(capital), current(board.getFirst()) {}

    int move(int steps); // Move the player on the board
    Node* where_am_I(); // Get the current position of the player
    void pay_to_player(Player& otherPlayer, int money); // Pay money to another player
    int get_balance() const; // Get the player's balance
    void deposit_money(int money); // Deposit money to the player's balance
    void buy_slot(int slotPrice); // Buy a slot on the board
    bool is_bankrupt() const; // Check if the player is bankrupt
    void display(); // Display player information
};

#endif
