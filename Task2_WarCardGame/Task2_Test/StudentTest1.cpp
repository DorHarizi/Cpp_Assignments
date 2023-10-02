#include "doctest.h"
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;
using namespace ariel;

// This test checks the initial amount of cards for each player before starting a game.
TEST_CASE("The amount of cards before starting a game")
{
    Player p1("Alice");
    Player p2("Bob");

    CHECK(p1.stacksize() == 0); // Checks if player 1 has no cards initially.
    CHECK(p2.stacksize() == 0); // Checks if player 2 has no cards initially.
    CHECK(p1.cardesTaken() == 0); // Checks if player 1 has not taken any cards initially.
    CHECK(p2.cardesTaken() == 0); // Checks if player 2 has not taken any cards initially.
}

// This test checks the amount of cards for each player after starting a game.
TEST_CASE("The amount of cards after starting a game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK(p1.stacksize() == 26); // Checks if player 1 has 26 cards after starting a game.
    CHECK(p2.stacksize() == 26); // Checks if player 2 has 26 cards after starting a game.
    CHECK(p1.cardesTaken() == 0); // Checks if player 1 has not taken any cards initially.
    CHECK(p2.cardesTaken() == 0); // Checks if player 2 has not taken any cards initially.
}

// This test checks the card scheme at the end of the game.
TEST_CASE("The card scheme at the end of the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll(); // Play the entire game.
    int sum = p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken();
    CHECK(sum == 52); // Checks if the total number of cards in both players' hands and stacks is 52.
}

// This test checks that no errors are thrown from the functions.
TEST_CASE("Throwing errors from the functions")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i = 0; i < 5; i++)
    {
        game.playTurn();
    }
    CHECK_NOTHROW(game.printLastTurn()); // Checks if no error is thrown when printing the last turn.
    CHECK_NOTHROW(game.printLog()); // Checks if no error is thrown when printing the log.
    CHECK_NOTHROW(game.printStats()); // Checks if no error is thrown when printing statistics.
    CHECK_NOTHROW(game.printWiner()); // Checks if no error is thrown when printing the winner.
}

// This test checks if another turn can be activated after the game is over.
TEST_CASE("Activating another turn after the game is over")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll(); // Play the entire game.
    CHECK(p1.stacksize() == 0); // Checks if player 1 has no cards left.
    CHECK(p2.stacksize() == 0); // Checks if player 2 has no cards left.
    CHECK_THROWS(game.playTurn()); // Checks if an error is thrown when trying to play another turn.
}

// This test checks if the game throws an error when there is only one player.
TEST_CASE("One player")
{
    Player p1("Alice");
    Game game(p1, p1); // Only one player, same player twice.
    CHECK_THROWS(game.playTurn()); // Checks if an error is thrown when trying to play a turn.
}

// This test checks if the game ends after at most 26 turns.
TEST_CASE("The game ends after at most 26 turns")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    int maxTurns = 26;
    int i = 0;
    for (; i < 26 && p1.stacksize() > 0; i++)
    {
        game.playTurn();
    }
    CHECK(maxTurns >= i); // Checks if the number of turns played is at most 26.
    CHECK(p1.stacksize() == 0); // Checks if player 1 has no cards left.
    CHECK(p2.stacksize() == 0); // Checks if player 2 has no cards left.
}
