#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <string.h>
#include <stdexcept>
#include <iostream>
using namespace ariel;
using namespace std;

// This test checks the constructor of the Card class.
TEST_CASE("Checking Card class constructor"){
    CHECK_NOTHROW(Card c2(9,"dor","dor")); // Checks if no error is thrown when creating a Card object.
}

// This test checks the functions of the Card class.
TEST_CASE("Checking Card class"){
    Card c2(9,"dor","dor");
    CHECK(c2.getName().compare("dor")==0); // Checks if the getName() function returns the correct name.
    CHECK(c2.getType().compare("dor")==0); // Checks if the getType() function returns the correct type.
    CHECK(c2.getValue()==9); // Checks if the getValue() function returns the correct value.
}

// This test checks the constructors of the Player class.
TEST_CASE("Checking Player class constructor"){
    CHECK_NOTHROW(Player p1("")); // Checks if no error is thrown when creating a Player object with an empty name.
    CHECK_NOTHROW(Player p2("dor")); // Checks if no error is thrown when creating a Player object with a name.
}

// This test checks the functions of the Player class.
TEST_CASE("Checking Player class"){
    Player p1 = Player();
    Player p2("dor");
    CHECK(p1.getName().compare("")==0); // Checks if the getName() function returns an empty name.
    CHECK(p1.stacksize() == 0); // Checks if the stacksize() function returns 0 for an empty player stack.
    CHECK(p1.cardesTaken()==0); // Checks if the cardesTaken() function returns 0 for an empty player stack.
    CHECK(p2.getName().compare("dor")==0); // Checks if the getName() function returns the correct name.
    CHECK(p2.stacksize()==0); // Checks if the stacksize() function returns 0 for a player with no cards.
    CHECK(p2.cardesTaken()==0); // Checks if the cardesTaken() function returns 0 for a player with no cards.
    p1.setName("dor");
    CHECK(p1.getName().compare("dor")==0); // Checks if the setName() function sets the correct name.
}

// This test checks the constructor of the Game class.
TEST_CASE("Checking Game class constructor"){
    Player p1("dor");
    Player p2("yuval");
    CHECK_NOTHROW(Game(p1, p2)); // Checks if no error is thrown when creating a Game object.
}

// This test checks the functions of the Game class.
TEST_CASE("Checking Game class"){
    Player p1("dor");
    Player p2("yuval");
    Player p3("dor");
    Player p4("yuval");
    Game g = Game(p1, p2);
    Game g2 = Game(p3, p4);
    CHECK_NOTHROW(g.playAll()); // Checks if no error is thrown when playing the entire game.
    CHECK_NOTHROW(g2.playTurn()); // Checks if no error is thrown when playing a single turn.
    CHECK_NOTHROW(g2.printLastTurn()); // Checks if no error is thrown when printing the last turn.
    g2.playAll(); // Play the entire game.
    CHECK((p3.cardesTaken() <= 26 || p4.cardesTaken() <= 26)); // Checks if the total number of cards taken by both players is less than or equal to 26.
    CHECK_NOTHROW(g.printLog()); // Checks if no error is thrown when printing the log.
    CHECK_NOTHROW(g.printStats()); // Checks if no error is thrown when printing statistics.
    CHECK_NOTHROW(g.printWiner()); // Checks if no error is thrown when printing the winner.
}
