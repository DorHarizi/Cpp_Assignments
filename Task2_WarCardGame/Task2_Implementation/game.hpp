#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "card.hpp"
using namespace std;
//using namespace ariel;

namespace ariel{
    class Game{
    private:
        Player p1;
        Player p2;
        string lastTurn;
        string logGame;
        string status;
        vector<Card> package;
        vector<string> gameProsess;
        bool finish;
        string winner;

    public:
        Game(Player &player1, Player &player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}