// Created by Mehmet Selman Yilmaz on 12.05.2023.
#include "Board.h"

Node::Node(string o, Node *p)
{
    owner = o;
    next = p;
}

Node::Node()
{
    owner = "None";
    next = nullptr;
}

Board::Board(int board_size)
{
    // Creates the first node.
    first = new Node("None", nullptr);
    first->next = first;

    // Creates a prev node for circular linked list.
    Node *prev = first;

    // Creates other nodes for circular linked list.
    for (int i = 1; i < board_size; i++) {
        Node *current = new Node("None", first);
        prev->next = current;
        prev = current;
    }
}

Board::Board()
{
    // Creates the first node.
    first = new Node("None", nullptr);
    first->next = first;
}

Board::~Board()
{
    // Traverse the circular linked list and deallocate memory for each node
    if (first != nullptr)
    {
        Node* current = first->next;
        while (current != first)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete first;
    }
}

string Board::who_owns(Node *slot)
{
    // Finds the node that owns the given slot.
    Node* mySlot = first;
    while(mySlot != slot)
    {
        mySlot = mySlot->next;
    }
    return mySlot->owner;
}


//Displays the board as a circle shape.
void Board::display()
{
    if (first == nullptr) {
        return;
    }
    string firstrow,secondrow,thirdrow;

    Node* current = first;
    do {
        //If owner is none shape must be like this.
        if(current->owner == "None") {
            //creates shape for first node
            if (current == first)
            {
                firstrow += current->owner + "->";
                secondrow += "^    ";
                thirdrow += "|----";
            }
            //creates shape for last node
            else if(current->next == first)
            {
                firstrow += current->owner;
                secondrow += "    |";
                thirdrow += "<---v";
            }
            //creates shape for other nodes
            else
            {
                firstrow += current->owner + "->";
                secondrow += "      ";
                thirdrow += "<-----";
            }
        }
        else{
            //If land is claimed, shape must be like this.
            //creates shape of first node
            if (current == first)
            {
                firstrow += current->owner + "->";
                secondrow += "^    ";
                thirdrow += "|----";
            }
            //creates shape of last node
            else if(current->next == first)
            {
                firstrow += current->owner;
                secondrow += "    |";
                thirdrow += "<---v";
            }
            //creates shape of other nodes.
            else
            {
                firstrow += current->owner + " ->";
                secondrow += "      ";
                thirdrow += "<-----";
            }
        }
        current = current->next;
    } while (current != first);
    cout << firstrow << endl << secondrow << endl << thirdrow << endl;


}

Node *Board::getFirst()
{
    return first;
}





