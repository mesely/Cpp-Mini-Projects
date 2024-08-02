//
// Created by Mehmet Selman Yılmaz on 9.04.2023.
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "CharStack.h"

using namespace std;

class Board {
private:
    // Private member variables
    struct Slot {
        CharStack stack;
        Slot* next;
        Slot* prev;
        Slot ()
        {}

    };


    Slot* head;
    Slot* tail;
    int x_count;
    int o_count;



public:
    // Constructors and destructor
    Board();
    ~Board();



    // Public member functions
    bool noMove(char chr, int steps);
    int validMove(char chr, int start, int steps, int direction);
    void movePiece(int src, int target);
    void printBoard();
    int evaluateGame();
    bool targetSlotFull(int index);
    void destroySlot(int index);
    void createSlotBegin(char chr, int num);
    void createSlotEnd(char chr, int num);
    void createEmptySlotEnd();
    void clearBoard();




};

#endif

/*
1. Default constructor: There will be a default constructor for the Board class that will not
take any parameters. It will create an empty Board object with no slots in it by setting
the head and tail pointers to null. Moreover, x and o counts will be set to zero.
2. noMove: This function takes two parameters, a character for the player and an integer for
the steps to move. It returns true, if there is no possible valid move of that player; returns
false otherwise (i.e. if there is at least one possible move). To do so, all slots and all move
possibilities with the given number of steps are to be tried for that player. However, no
        movement is done in this function; its task is to check move possibility.
3. validMove: This function takes four parameters, (i) a character for the player, (ii) an
        integer for the starting index of the player's slot, (iii) an integer for the amount of steps to
move, (iv) an integer for the direction of move (0 for left, 1 for right; no need for input
        check). The function returns a code (0, 1, 2, 3, or 4) as explained in the Program Flow
section above. This function does not make the actual move.
The indexing mechanism is not explicit for linked lists; thus, you will not keep any index
        value in the slot nodes. You will just count the slots starting zero, which is assumed to be
the leftmost slot.
4. movePiece: This function takes the source and the target indices as parameters and
completes the move operation via pop and push operations on the corresponding slot's
stacks. It does not return anything. Indexing is explained in the previous function. Since
        we call this function after doing all validity controls, you do not need to make any extra
        checks.
© Sabancı University, unauthorized reproduction, usage, posting are strictly prohibited

5. printBoard: This function does not take any parameter and does not return anything. It
        displays the board as explained before. You may also check out the sample runs for the
        format of display.
Hint for implementation: You have to display the content of the stacks line by line. So for
each line, each slot's stack will contribute one character to the line. To accumulate these
characters, you can utilize strings (but usage of strings is allowed for printing purposes
only in this function; nowhere else in the code that you will write).
6. evaluateGame: This function does not take any parameters. It returns 1 if x has less
        pieces than o; returns 2 if o has less pieces than x; returns 3 if both have the same amount
        of pieces.
7. targetSlotFull: This function takes a slot index as parameter and returns true if the
        slot is full (i.e. slot's stack is full); returns false otherwise. Indexing logic is explained
previously. You can assume that a valid index has been given as parameter.
8. destroySlot: This function takes a slot index as parameter and deletes that slot from
the linked list. It also updates the piece counts accordingly. Here be careful about the
        linked list connections and special conditions of updating the head and tail of the Board
class. Indexing logic is explained previously. You can assume that a valid index has been
        given as parameter.
9. createSlotBegin: This function takes two parameters. First one is the player
        character, say ch, and the second one is the number of characters, say num. The function
does not return anything but creates a slot at the head of the linked list. This slot's stack
contains num counts of ch. This function also updates the piece counts accordingly. Here,
assume that num is 1, 2 or 3, and ch is either x or o; in other words, parameter values are
not needed to be checked.
10. createSlotEnd: This function takes two parameters. First one is the player character,
        say ch, and the second one is the number of characters, say num. The function does not
return anything but creates a slot at the tail of the linked list. This slot's stack contains
num counts of ch. This function also updates the piece counts accordingly. Here, assume
        that num is 1, 2 or 3, and ch is either x or o; in other words, parameter values are not
needed to be checked.
11. createEmptySlotEnd: This function does not take any parameter and does not return
anything. It just adds an empty slot node at the end (tail) of the Board's linked list.
12. clearBoard: This function does not take any parameter and does not return anything. It
        deletes all of the slot nodes in the list.
        */