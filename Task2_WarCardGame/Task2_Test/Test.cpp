#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <string.h>
#include <stdexcept>
#include <iostream>
using namespace ariel;
using namespace std;

TEST_CASE("Checking Card class constructor"){
    // CHECK_NOTHROW(Card c1());
    CHECK_NOTHROW(Card c2(9,"dor","dor"));
}

TEST_CASE("Checking Card class"){
    // Card c1 = Card();
    Card c2(9,"dor","dor");
    // CHECK(c1.getName().compare("")==0);
    // CHECK(c1.getType().compare("")==0);
    // CHECK(c1.getValue()==0);
    CHECK(c2.getName().compare("dor")==0);
    CHECK(c2.getType().compare("dor")==0);
    CHECK(c2.getValue()==9);
    // c1.setName("dor");
    // c1.setType("dor");
    // c1.setValue(9);
    // CHECK(c1.getName().compare("dor")==0);
    // CHECK(c1.getType().compare("dor")==0);
    // CHECK(c1.getValue()==9);
}

TEST_CASE("Checking Player class constructor"){
    CHECK_NOTHROW(Player p1(""));
    CHECK_NOTHROW(Player p2("dor"));
}

TEST_CASE("Checking Player class"){
    Player p1 = Player();
    Player p2("dor");
    CHECK(p1.getName().compare("")==0);
    CHECK(p1.stacksize() == 0);
    CHECK(p1.cardesTaken()==0);
    CHECK(p2.getName().compare("dor")==0);
    CHECK(p2.stacksize()==0);
    CHECK(p2.cardesTaken()==0);
    p1.setName("dor");
    CHECK(p1.getName().compare("dor")==0);
}

TEST_CASE("Checking Game class constructor"){
    Player p1("dor");
    Player p2("yuval");
    CHECK_NOTHROW(Game(p1, p2));
}

TEST_CASE("Checking Game class"){
    Player p1("dor");
    Player p2("yuval");
    Player p3("dor");
    Player p4("yuval");
    Game g = Game(p1, p2);
    Game g2 = Game(p3, p4);
    CHECK_NOTHROW(g.playAll());
    CHECK_NOTHROW(g2.playTurn());
    CHECK_NOTHROW(g2.printLastTurn());
    g2.playAll();
    CHECK((p3.cardesTaken() <= 26 || p4.cardesTaken() <= 26));
    CHECK_NOTHROW(g.printLog());
    CHECK_NOTHROW(g.printStats());
    CHECK_NOTHROW(g.printWiner());
}