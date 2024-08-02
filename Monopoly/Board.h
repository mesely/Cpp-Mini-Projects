//
// Created by Mehmet Selman Yilmaz on 12.05.2023.
//
#ifndef BOARD_H
#define BOARD_H



#include <string>
#include <iostream>

using namespace std;

//Node structure for circular linked list. (In order to create a board)
struct Node {
    string owner;
    Node* next;
    Node ();
    Node (string o, Node * p);
};

class Board
{
private:
    Node* first; //Points the first node

public:
    Board();
    Board(int board_size); //Parametric constructor
    ~Board(); //Destructor
    //MEMBER FUNCTIONS
    void display(); //Displays the content of board.
    string who_owns(Node* slot); //Returns a string that corresponds to the owner of that slot.
    Node * getFirst(); //Returns a first node on the board.



};
#endif