// Created by Mehmet Selman Yilmaz on 9.04.2023.
//

#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor: Initialize the head and tail pointers to nullptr and counts to 0
Board::Board() {
    head = nullptr;
    tail = nullptr;
    x_count = 0;
    o_count = 0;
}

// Destructor: Clean up all dynamically allocated slots in the linked list
Board::~Board() {
    while (head != nullptr) {
        Slot *temp = head;
        head = head->next;
        delete temp;
    }
}

// Check if there are no valid moves for a given character and steps
bool Board::noMove(char chr, int steps) {
    Slot *rightptr = head;
    Slot *leftptr = tail;
    Slot *targetptr;
    char c;

    // Check moves to the right
    while (rightptr != nullptr) {
        targetptr = rightptr;
        for (int i = 0; i < steps; i++) {
            if (targetptr != nullptr) {
                targetptr = targetptr->next;
            }
        }
        if (targetptr != nullptr) {
            targetptr->stack.pop(c);
            if (c == 'o' || c == 'x') {
                targetptr->stack.push(c);
            }
        } else {
            c = 'a';
        }

        if ((c == chr && !targetptr->stack.isFull()) || c == '\0') {
            return false;
        }
        rightptr = rightptr->next;
    }

    // Check moves to the left
    while (leftptr != nullptr) {
        chr = '\0';
        targetptr = leftptr;
        for (int i = 0; i < steps; i++) {
            if (targetptr != nullptr) {
                targetptr = targetptr->prev;
            }
        }
        if (targetptr != nullptr) {
            targetptr->stack.pop(c);
            if (c == 'o' || c == 'x') {
                targetptr->stack.push(c);
            }
        } else {
            c = 'a';
        }

        if ((c == chr && !targetptr->stack.isFull()) || c == '\0') {
            return false;
        }
        leftptr = leftptr->prev;
    }

    return true;
}

// Validate if a move is possible
int Board::validMove(char chr, int start, int steps, int direction) {
    int count = 0;
    Slot* ptrsize = head;

    // Count the number of slots
    while (ptrsize != nullptr) {
        count++;
        ptrsize = ptrsize->next;
    }

    // Check if the start index is within bounds
    if (start < 0 || start >= count) {
        return 1; // Entered slot index is not within bounds.
    }

    Slot* ptr = head;
    for (int i = 0; i < start; i++) {
        ptr = ptr->next;
    }

    char slotCheck, targetCheck;
    ptr->stack.pop(slotCheck);
    if (slotCheck == 'o' || slotCheck == 'x') {
        ptr->stack.push(slotCheck);
    }

    if (chr != slotCheck) {
        return 4;
    }

    Slot* targetptr = ptr;
    if (direction == 1) {
        for (int i = 0; i < steps; i++) {
            if (targetptr->next == nullptr) {
                return 2; // Target slot index not within bounds.
            }
            targetptr = targetptr->next;
        }
    } else if (direction == 0) {
        for (int i = 0; i < steps; i++) {
            if (targetptr->prev == nullptr) {
                return 2; // Target slot index not within bounds.
            }
            targetptr = targetptr->prev;
        }
    }

    targetptr->stack.pop(targetCheck);
    if (targetCheck == 'o' || targetCheck == 'x') {
        targetptr->stack.push(targetCheck);
    }

    if (((targetCheck == 'o' || targetCheck == 'x') && targetCheck != chr) || targetptr->stack.isFull()) {
        return 3;
    }

    return 0;
}

// Move a piece from source index to target index
void Board::movePiece(int src, int target) {
    Slot* srcPtr = head;
    Slot* targetPtr = head;
    char chr;

    for (int i = 0; i < src; i++) {
        srcPtr = srcPtr->next;
    }

    for (int j = 0; j < target; j++) {
        targetPtr = targetPtr->next;
    }

    srcPtr->stack.pop(chr);
    if (chr == 'o' || chr == 'x') {
        targetPtr->stack.push(chr);
    }
}

// Print the board state
void Board::printBoard() {
    Slot* ptr = head;

    // Create a copy of the list
    Slot* copyHead = nullptr;
    Slot* copyTail = nullptr;

    while (ptr != nullptr) {
        Slot* copy = new Slot(*ptr);
        if (copyHead == nullptr) {
            copyHead = copy;
            copyTail = copy;
        } else {
            copyTail->next = copy;
            copy->prev = copyTail;
            copyTail = copy;
        }
        ptr = ptr->next;
    }

    // Print the board using the copy
    ptr = copyHead;
    char c;
    string boardline, board;
    int count = 0;
    Slot* ptrcheck = copyHead;

    while (ptrcheck != nullptr) {
        count++;
        boardline += "^";
        ptrcheck = ptrcheck->next;
    }

    int ctr = 0;

    for (int i = 0; i < count; i++) {
        if (ptr == nullptr) {
            ptr = copyHead;
        }

        while (ctr != count) {
            ptrcheck = copyHead;
            board = boardline + "\n" + board;
            boardline = "";
            for (int i = 0; i < count; i++) {
                if (ptr == nullptr) {
                    ptr = copyHead;
                }
                if (!ptr->stack.isEmpty()) {
                    ptr->stack.pop(c);
                    boardline += c;
                } else {
                    boardline += " ";
                }
                ptr = ptr->next;
                while (ptrcheck != nullptr) {
                    if (ptrcheck->stack.isEmpty()) {
                        ctr++;
                    }
                    ptrcheck = ptrcheck->next;
                }

                if (ctr != count) {
                    ctr = 0;
                }
            }
        }
    }
    cout << endl << board;

    // Delete the copy of the list
    ptr = copyHead;
    while (ptr != nullptr) {
        Slot* temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

// Evaluate the game state to determine the winner
int Board::evaluateGame() {
    Slot* ptr = head;
    char c;
    int x_ctr = 0;
    int o_ctr = 0;

    string board;
    int count = 0;
    Slot* ptrsize = head;

    // Count the number of slots
    while (ptrsize != nullptr) {
        count++;
        ptrsize = ptrsize->next;
    }

    // Collect all characters in the board
    for (int i = 0; i < count; i++) {
        if (ptr == nullptr) {
            ptr = head;
        }
        ptr->stack.pop(c);
        if (c == 'o' || c == 'x') {
            ptr->stack.push(c);
        }
        board += c;
        ptr = ptr->next;
    }

    // Count the number of 'x' and 'o'
    for (char m : board) {
        if (m == 'x') {
            x_ctr++;
        } else if (m == 'o') {
            o_ctr++;
        }
    }

    if (x_ctr == o_ctr) {
        return 3; // Tie
    } else if (x_ctr > o_ctr) {
        return 2; // 'x' wins
    } else if (x_ctr < o_ctr) {
        return 1; // 'o' wins
    }

    return 1; // Default to 'o' wins
}

// Check if the target slot is full
bool Board::targetSlotFull(int index) {
    Slot* ptr = head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    return ptr->stack.isFull();
}

// Destroy a slot at the given index
void Board::destroySlot(int index) {
    Slot* ptr = head;

    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }

    Slot* prevptr = ptr->prev;
    Slot* nextptr = ptr->next;

    char c;
    while (!ptr->stack.isEmpty()) {
        ptr->stack.pop(c);
    }

    if (prevptr == nullptr) {
        head = nextptr;
        if (head != nullptr) {
            head->prev = nullptr;
        }
    } else {
        prevptr->next = nextptr;
    }

    if (nextptr == nullptr) {
        tail = prevptr;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
    } else {
        nextptr->prev = prevptr;
    }

    delete ptr;
}

// Create a slot at the beginning with a specified character and count
void Board::createSlotBegin(char chr, int num) {
    Slot* newSlot = new Slot;
    for (int i = 0; i < num; ++i) {
        newSlot->stack.push(chr);
    }

    newSlot->next = head;
    if (head != nullptr) {
        head->prev = newSlot;
    }
    head = newSlot;

    if (tail == nullptr) {
        tail = newSlot;
    }
}

// Create a slot at the end with a specified character and count
void Board::createSlotEnd(char chr, int num) {
    Slot* newSlot2 = new Slot;
    for (int i = 0; i < num; ++i) {
        newSlot2->stack.push(chr);
    }

    if (tail == nullptr) {
        head = newSlot2;
        tail = newSlot2;
    } else {
        tail->next = newSlot2;
        newSlot2->prev = tail;
        tail = newSlot2;
    }
}

// Create an empty slot at the end
void Board::createEmptySlotEnd() {
    Slot* newSlot = new Slot;

    if (tail == nullptr) {
        head = newSlot;
        tail = newSlot;
    } else {
        tail->next = newSlot;
        newSlot->prev = tail;
        tail = newSlot;
    }
}

// Clear the board by deleting all slots
void Board::clearBoard() {
    Slot* temp = head;
    while (temp != nullptr) {
        Slot* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
    tail = nullptr;
}
