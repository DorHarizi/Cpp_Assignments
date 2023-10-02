#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel {

    class Game {
    private:
        Player p1;
        Player p2;
        string lastTurn;
        string logGame;
        string status;
        vector<Card> package;
        vector<string> gameProcess; 
        bool finish;
        string winner;

    public:
        // Constructor for the Game class, initializes two players.
        Game(Player &player1, Player &player2);

        // Simulate a single turn in the game.
        void playTurn();

        // Print the details of the last turn.
        void printLastTurn();

        // Simulate the entire game until completion.
        void playAll();

        // Print the winner of the game.
        void printWinner(); // Fixed typo "printWiner" to "printWinner"

        // Print the game log.
        void printLog();

        // Print game statistics.
        void printStats();
    };
}
