# CppMiniProjects-Games-Utilities-More

## Overview

CppMiniProjects-Games-Utilities-More is a repository containing a variety of C++ programs that demonstrate different programming concepts and applications. From classic games to utility programs, each project is self-contained and showcases different aspects of C++ programming.

## Projects

### MathExpressionValidator

Validates and evaluates basic mathematical expressions provided by the user.

- **Features**:
  - Validates format of expressions.
  - Parses and evaluates addition and subtraction expressions.
  - Provides feedback on correct or incorrect answers.
  - Includes a "joker" option for retrying incorrect answers with penalties.

- **Usage**:
  1. Run the program.
  2. Enter a mathematical expression in the form `a+b=c` or `a-b=c`.
  3. The program checks the input format and calculates the result.
  4. Correct answers earn 25 points.
  5. Incorrect answers can be corrected using a "joker" with a penalty of 10 points.
  6. The program prompts for four expressions and displays the total points at the end.

### TicTacToeGame

A simple C++ implementation of the classic Tic-Tac-Toe game.

- **Features**:
  - Validates move format.
  - Displays the current game board.
  - Allows two players to take turns.
  - Checks for a winner or a draw.
  - Keeps track of scores across multiple games.

- **Usage**:
  1. Run the program.
  2. Enter the names of the two players.
  3. Players take turns to enter their moves in the format `row-column` (e.g., `1-1` for the top-left corner).
  4. The game continues until there's a winner or a draw.
  5. The scores are displayed, and a new game starts automatically.
  6. After two games, the overall winner is announced based on the scores.

### MovieRecommender

A simple C++ program to recommend movies based on genre or year.

- **Features**:
  - Reads a list of movies from a file.
  - Allows users to filter movies by genre or year.
  - Displays movies in the specified order.

- **Usage**:
  1. Run the program.
  2. Enter the movie list filename.
  3. Choose to filter movies by genre or year.
  4. The program displays the filtered list of movies.

### NumberGuessingGame

A C++ program where the user tries to guess a secret number based on feedback.

- **Features**:
  - Uses linked lists to track possible and impossible digits for each slot.
  - Provides feedback for each guess to narrow down the possible numbers.
  - Automatically updates the linked lists based on the feedback.

- **Usage**:
  1. Run the program.
  2. Enter a game ID.
  3. Enter a three-digit guess.
  4. The program provides feedback and updates the possible numbers.
  5. Continue guessing until the secret number is found.

### WeeklySchedule

A C++ class to manage a weekly schedule with operations for merging and comparing schedules.

- **Features**:
  - Supports creating schedules with specified time slots.
  - Provides deep copy constructor and assignment operator overload.
  - Allows marking specific days and time slots as busy.
  - Merges schedules using `+` and `*` operators.
  - Compares schedules using `<` operator.
  - Prints schedules with overloaded `<<` operator.

### Monopoly

A C++ implementation of a Monopoly board using a circular linked list.

- **Features**:
  - Uses a circular linked list to represent the board.
  - Supports dynamic board size.
  - Provides functions to display the board and check ownership.

- **Usage**:
  1. Run the program.
  2. Enter the initial settings:
     - Maximum number of rounds: An integer greater than 0.
     - Starting capital: An integer greater than 0.
     - Passing starting slot deposit: An integer greater than 0.
     - Slot price: An integer greater than 0.
     - Number of slots: An integer greater than or equal to 6.
     - Seed for random number generation: An integer greater than 0.
  3. Players take turns to roll the dice and move around the board.
  4. Players can buy unclaimed slots or pay rent when landing on opponent's slots.
  5. The game continues until one player goes bankrupt or the maximum number of rounds is reached.
  6. The winner is determined based on the remaining balance.

### MusicalChairsGame

A C++ implementation of the Musical Chairs game using threads to simulate players.

- **Features**:
  - Uses threads to simulate players capturing chairs.
  - Synchronizes threads with mutexes to ensure safe access to shared resources.
  - Eliminates players who fail to capture a chair in each round.
  - Displays the status of the game after each round.

- **Usage**:
  1. Run the program.
  2. Enter the number of players.
  3. The game will simulate players trying to capture chairs in each round.
  4. The game continues until only one player remains, who is declared the winner.

### Stackgammon

A C++ implementation of a Stackgammon game using a doubly linked list.

- **Features**:
  - Uses a doubly linked list to represent the board.
  - Supports dynamic board configuration.
  - Provides functions to move pieces, check for valid moves, and evaluate the game state.
  - Implements a custom random number generator for gameplay.

- **Usage**:
  1. Run the program.
  2. Enter a board configuration string (e.g., `3x/2o/1x`).
  3. Enter the number of rounds to play.
  4. Enter a seed for the random number generator.
  5. Players take turns to move their pieces based on the dice roll.
  6. The game ends after the specified number of rounds, and the winner is announced.

## Author

Mehmet Selman Yilmaz
