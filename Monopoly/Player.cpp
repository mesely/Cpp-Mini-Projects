//
// Created by Mehmet Selman Yilmaz on 12.05.2023.
//
#include "Player.h"
#include "Board.h"
#include <string>


int Player::move(int steps)
{
    int number = 0;
    for(int i = 0; i < steps; i++)
    {
        current = current->next;  // Move to the next node in the linked list

        // Check if the current node is the first node of the board
        if(current == board.getFirst())
        {
            number = 1;  // Set number to 1
        }
    }

    // Check again if the current node is the first node of the board
    if(current == board.getFirst())
    {
        number = 1;  // Set number to 1
    }

    return number;  // Return the value of number
}

Node* Player::where_am_I()
{
    return current;  // Return the current node where the player is located
}

void Player::pay_to_player(Player& otherPlayer, int money)
{
    balance -= money;             // Decrease the player's balance by the specified amount
    otherPlayer.balance += money; // Increase the other player's balance by the same amount
}

int Player::get_balance() const
{
    return balance;  // Return the player's balance
}

void Player::deposit_money(int money)
{
    balance += money;  // Increase the player's balance by the specified amount
}

void Player::buy_slot(int slotPrice)
{
    balance -= slotPrice;   // Decrease the player's balance by the slot price
    current->owner = name;  // Set the owner of the current slot to the player's name
}

bool Player::is_bankrupt() const
{
    if(balance < 0)
    {
        return true;  // The player is bankrupt if their balance is negative
    }
    return false;     // Otherwise, the player is not bankrupt
}

void Player::display()
{
    Node* spaceindicator = board.getFirst();
    while(current != spaceindicator)
    {
        if(spaceindicator->next == board.getFirst())
        {
            // Do nothing when the space indicator is back to the first node
        }
        cout << "      ";  // Output spaces to represent unoccupied slots
        spaceindicator = spaceindicator->next;
    }
    cout << name << " " << balance << endl;  // Output the player's name and balance
}
