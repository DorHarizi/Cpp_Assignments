#pragma once

#include <string>
#include <vector>
#include "card.hpp"
using namespace std;
//using namespace ariel;

namespace ariel{

    class Player{
        private:
            string name;
            vector<Card> packet;
            bool isPlay;
            int currentCard;
            int num_of_cards_taken;

        public:
            Player();
            Player(string);
            string getName(){return name;}
            vector<Card> getPacket(){return packet;}
            int cardesTaken();
            int stacksize();
            bool getIsPlay();
            int getCurrentCard();
            int getNumOfCard();
            void setIsPlay(bool);
            void setCurrentCard(int);
            void setNumOfCards(int);
            void setName(string);
            void putCard(Card);
            string to_string();
    };
}