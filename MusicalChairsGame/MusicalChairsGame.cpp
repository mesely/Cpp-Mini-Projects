//Mehmet Selman Yilmaz CS204 Homework 6
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <ctime>
#include "IntQueueHW6.h"
#include <vector>
#include <mutex>

using namespace std;

// Global values to be shared by threads
int number_of_players;
int number_of_chairs;
IntQueueHW6 Queue();

mutex myMutex;

// Function to get the local time
struct tm* getLocalTime()
{
    time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now()); // Gets the current time
    struct tm* ptm = new struct tm; // Creating the time struct to be used in the thread
    localtime_r(&tt, ptm); // Converting the time structures
    return ptm;
}

// Function representing a player's round
void playRound(vector<int>& IDs, int ID, IntQueueHW6& Queue, struct tm* ptm)
{
    // Wait until the specified time
    this_thread::sleep_until(chrono::system_clock::from_time_t(mktime(ptm)));

    // Acquire the lock to access shared resources
    myMutex.lock();

    if (!Queue.isFull())
    {
        // Enqueue the player's ID and add it to the vector
        Queue.enqueue(ID);
        IDs.push_back(ID);
        struct tm* ptm = getLocalTime();
        cout << "Player " << ID << " captured a chair at " << put_time(ptm, "%X") << "." << endl;
    }
    else
    {
        //If queue is full that means player is eliminated and couldnt capture any chair.
        cout << "Player " << ID << " couldn't capture a chair." << endl;
    }

    myMutex.unlock();
}
//Function that delete all elements of vector.
template <typename T>
void Clear(vector<T>& vector)
{
    vector.clear();
}

int main()
{
    int eliminated;
    // Create a vector to store players' IDs
    vector<int> IDs;

    //Get number of players from user.
    cout << "Welcome to the Musical Chairs game!" << endl;
    cout << "Enter the number of players in the game: ";
    cin >> number_of_players;

    // The initial number of chairs must be 1 less than the number of players
    number_of_chairs = number_of_players - 1;

    thread threads[number_of_players]; // Create a thread for each player



    struct tm* ptm = getLocalTime();

    //Start the game and display the time.
    cout << "Game Start!" << endl;
    cout << "Time is now " << put_time(ptm, "%X") << endl;

    while (true)
    {
        ptm->tm_sec = ptm->tm_sec + 2; // Update the time for each round
        IntQueueHW6 Queue(number_of_chairs); // Create the corresponding queue

        for (int i = 0; i < number_of_players; i++)
        {
            // Start a thread for each player to play a round
            threads[i] = thread(&playRound, ref(IDs), i, ref(Queue), ptm);
        }

        for (int i = 0; i < number_of_players; i++)
        {
            // Wait for all threads to finish
            threads[i].join();
        }

        //Display the remaining players that is stored in vector.
        for (int i = 0; i < IDs.size(); i++)
        {
            if (i == 0)
            {
                cout << "Remaining players are as follows: ";
            }
            cout << IDs[i] << " ";
        }

        cout << endl;

        // Update the game state
        Queue.dequeue(eliminated);
        Queue.clear();
        number_of_players--;
        number_of_chairs--;
        Clear(IDs);

        //If number of players is 1, End the game.
        if (number_of_players == 1)
        {
            cout << endl << endl << "Game Over!" << endl;
            cout << "Winner is Player " << IDs[0] << endl;
            break;
        }

        //Display the time for eah round.
        cout << endl << endl << "Time is now " << put_time(ptm, "%X") << endl;
    }

    return 0;
}
