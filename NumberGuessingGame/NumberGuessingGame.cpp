//Mehmet Selman Yilmaz CS204 Homework2
#include <iostream>
#include <string>
#include "feedback.h"


using namespace std;

struct node
{
    int digit;
    node *next;

    //default constructor
    node ()
            :digit(0), next(nullptr)
    {}

    //constructor
    node (int i,node *n)
            :digit(i), next(n)
    {}
};
//Prints the linked lists.
void Print(node *nodePtr)
{
    if (nodePtr != nullptr)
    {
        cout << nodePtr->digit << " ";
        Print(nodePtr->next);
    }
}
/* Begin: code taken from linkedList.cpp */
void ClearList(node *head)
{
    node *ptr;
    while(head!=nullptr)
    {
        ptr=head;
        head=head->next;
        delete ptr;
    }
}
/* End: code taken from linkedList.cpp */

//Checks the guess input (Guess must be between 012 and 987, It assumes all of its digits are different than each other.
bool guessInputCheck(string guess)
{
    int intguess;
    if (guess.length() !=3)
    {
        return false;
    }
    else {
        intguess = atoi(guess.c_str());
        if (12 > intguess || 987< intguess)
            return false;
    }
    return true;
}
//returns a length of linked list
int length(node* head) {
    int count = 0;
    node* ptr = head;
    if (head == nullptr){return 0;}
    else {
        while (ptr != nullptr) {
            count++;
            ptr = ptr->next;
        }
        return count;
    }}
/* Begin: code taken from linkedList.cpp */
bool SearchList(node *head, int searchValue)
{
    if(head ==nullptr)
    {
        return false;
    }
    while (head != nullptr)
    {
        if(head->digit == searchValue) //If the node with the given ID is found
            return true;
        head = head->next;
    }
    //If the code proceeds from here, it means that the whole list is traversed
    //and a node with ID == searchValue could not be found.
    return false;
}
/* End: code taken from linkedList.cpp */
//Delete n from linked list.
void DeleteFromList(node *&head, int n) {
    if (SearchList(head, n)) {
        node *ptr = head;

        if (head != nullptr && head->digit == n) {
            node *temp;
            temp = head;
            head = head->next;
            delete temp;
        } else {
            node *prev = nullptr;
            node *ptr2 = head;

            while (ptr2 != nullptr && ptr2->digit != n) {
                prev = ptr2;
                ptr2 = ptr2->next;
            }
            if (ptr2 == nullptr) {
                return;
            }
            prev->next = ptr2->next;
            delete ptr2;
        }
    }
}


//Instert a number to the list
void InsertheList(node *&head, int n) {
    node *newNode = new node(n, nullptr);

    if (head == nullptr || n < head->digit) {
        newNode->next = head;
        head = newNode;
    }else if (!SearchList(head, n))  {
        node *ptr = head;
        while (ptr-> next != nullptr && (ptr->next->digit < n) ) {
            ptr = ptr->next;
        }

        newNode->next = ptr->next;
        ptr->next = newNode;

    }
}

//Prints the secret number (parameters are linked lists of impossibles.)
void printSecretNumber(node *head1, node *head2, node* head3)
{
    for(int i=0; i<10; i++){if(!SearchList(head1,i))cout<<i;}
    for(int i=0; i<10; i++){if(!SearchList(head2,i))cout<<i;}
    for(int i=0; i<10; i++){if(!SearchList(head3,i))cout<<i;}
}


int main() {
    int id, number;
    bool endgame = false, sCheck1=false, sCheck2 =false, sCheck3= false, nCheck1=false, nCheck2 =false, nCheck3= false;
    string guess, guessnumberstr;
    node *pSlot1 = nullptr, *pSlot2 = nullptr, *pSlot3 = nullptr, *imSlot1 = nullptr, *imSlot2 = nullptr, *imSlot3 = nullptr;
    //Get the id from player.
    cout << "Please enter a game ID.\n";
    cin >> id;
    //Get the guess from user.
    cout << "Enter your guess." << endl;
    cin >> guess;
    while(!guessInputCheck(guess))
    {
        cout << "Invalid guess. Enter your guess." << endl;
        cin >> guess;
    }

    while (!endgame) {
        string feedback = get_the_feedback(guess, id);

        //Update the linked lists according to guess.
        for (int i = 0; i < 3; i++) {
            guessnumberstr = guess.at(i);
            number = atoi(guessnumberstr.c_str());
            if (feedback[i] == 'G') {
                if (i == 0 && !sCheck1) {
                    sCheck1 = true;
                    if(SearchList(pSlot1,number) && length(pSlot1) == 1)
                    {
                        DeleteFromList(pSlot2, number);
                        DeleteFromList(pSlot3, number);
                        InsertheList(imSlot2, number);
                        InsertheList(imSlot3, number);
                    }
                    else {
                        ClearList(pSlot1);
                        DeleteFromList(pSlot2, number);
                        DeleteFromList(pSlot3, number);
                        InsertheList(pSlot1, number);
                        InsertheList(imSlot2, number);
                        InsertheList(imSlot3, number);
                    }
                    for (int j = 0; j < 10; j++) {
                        if (j != number && !SearchList(imSlot1,j)) {
                            InsertheList(imSlot1, j);
                        }
                    }
                } else if (i == 1 && !sCheck2) {

                    sCheck2 = true;
                    if(SearchList(pSlot2,number) && length(pSlot2) == 1)
                    {
                        DeleteFromList(pSlot1, number);
                        DeleteFromList(pSlot3, number);
                        InsertheList(imSlot1, number);
                        InsertheList(imSlot3, number);
                    }
                    else {
                        ClearList(pSlot2);
                        DeleteFromList(pSlot3, number);
                        DeleteFromList(pSlot1, number);
                        InsertheList(pSlot2, number);
                        InsertheList(imSlot1, number);
                        InsertheList(imSlot3, number);
                    }
                    for (int j = 0; j < 10; j++) {
                        if (j != number&& !SearchList(imSlot2,j)) {
                            InsertheList(imSlot2, j);
                        }

                    }
                } else if (i == 2 && !sCheck3) {
                    sCheck3 = true;
                    if(SearchList(pSlot3,number) && length(pSlot3) == 1)
                    {
                        DeleteFromList(pSlot2, number);
                        DeleteFromList(pSlot2, number);
                        InsertheList(imSlot2, number);
                        InsertheList(imSlot2, number);
                    }
                    else {
                        ClearList(pSlot3);
                        DeleteFromList(pSlot2, number);
                        DeleteFromList(pSlot1, number);
                        InsertheList(pSlot3, number);
                        InsertheList(imSlot2, number);
                        InsertheList(imSlot1, number);
                    }
                    for (int j = 0; j < 10; j++) {
                        if (j != number && !SearchList(imSlot3,j)) {
                            InsertheList(imSlot3, j);
                        }

                    }

                }
            }
            else if (feedback[i] == 'Y')
            {
                if (i == 0)
                {

                    if(!(sCheck2) && !(SearchList(imSlot2,number))){InsertheList(pSlot2, number);}
                    if(!(sCheck3) && !(SearchList(imSlot3,number))){InsertheList(pSlot3, number);}
                    if(!sCheck1){
                        InsertheList(imSlot1, number);
                        if(SearchList(pSlot1,number)){ DeleteFromList(pSlot1,number);}
                    }

                }
                else if (i == 1)
                {

                    if(!(sCheck1) && !(SearchList(imSlot1,number))){InsertheList(pSlot1, number);}
                    if(!(sCheck3) && !(SearchList(imSlot3,number))){InsertheList(pSlot3, number);}
                    if(!sCheck2){
                        InsertheList(imSlot2, number);
                        if(SearchList(pSlot2,number)){ DeleteFromList(pSlot2,number);}
                    }

                }
                else if (i == 2)
                {

                    if(!(sCheck2) && !(SearchList(imSlot2,number))){InsertheList(pSlot2, number);}
                    if(!(sCheck1) && !(SearchList(imSlot1,number))){InsertheList(pSlot1, number);}
                    if(!sCheck3){
                        InsertheList(imSlot3, number);
                        if(SearchList(pSlot3,number)){ DeleteFromList(pSlot3,number);}
                    }

                }


            }

            else if (feedback[i] == 'R') {
                if(!sCheck1){InsertheList(imSlot1, number);}
                if(!sCheck2)InsertheList(imSlot2, number);
                if(!sCheck3)InsertheList(imSlot3, number);
            }


        }

//Display the linked lists
        cout << "Linked lists: \n" << "Slot: 1 \n" << "Impossibles: ";
        Print(imSlot1);
        cout << "\nPossibles: ";
        Print(pSlot1);
        cout << "\n\nSlot: 2" << "\nImpossibles: ";
        Print(imSlot2);
        cout << "\nPossibles: ";
        Print(pSlot2);
        cout << "\n\nSlot: 3" << "\nImpossibles: ";
        Print(imSlot3);
        cout << "\nPossibles: ";
        Print(pSlot3);
        cout << "\n\n";


//If all the impossible linked lists are full terminate the game
        if(length(imSlot1) == 9 && length(imSlot2) == 9 &&  length(imSlot3) == 9)
        {
            endgame = true;
            cout << "The secret number is: ";

            printSecretNumber(imSlot1,imSlot2,imSlot3);
            cout << endl << "Congrats! Now, deleting the lists...";
            //Clearing all the linked lists
                ClearList(pSlot1);
                ClearList(pSlot2);
                ClearList(pSlot3);
                ClearList(imSlot1);
                ClearList(imSlot2);
                ClearList(imSlot3);

        }
        else {

//Otherwise keep getting input from the user and check the validity
            cout << "Enter your guess." << endl;
            cin >> guess;
            while(!guessInputCheck(guess))
            {
                cout << "Invalid guess. Enter your guess." << endl;
                cin >> guess;
            }
        }

    }


    return 0;
}


