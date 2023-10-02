
#pragma once

#include <string>
#include<iostream>
using namespace std;


namespace ariel{

    class Card{
        private:
            int value;
            string type;
            string name;

        public:
            Card();
            Card(int, string, string);

            int getValue();
            string getType();
            string getName();
            
            void setValue(int);
            void setType(string);
            void setName(string);

            string to_string();

            bool operator<(const Card &Crad2);
            bool operator==(const Card &Crad2);
    };
}