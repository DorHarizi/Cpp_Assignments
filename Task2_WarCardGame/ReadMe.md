# War Game

This program is a War card game for two players.

## Rules

- It uses a standard deck of 52 cards, which is shuffled (randomly) at the beginning of the game and divided equally between the two players.
- In each turn, the players draw one card from the top of their respective decks. The player with the highest card value wins both cards (2 cards if the winning card is an Ace).
- If the players draw two identical cards, they place one card face down and one card face up. The player with the higher face-up card takes all six cards. If another tie occurs, they continue with a face-down card followed by a face-up card until one player wins. The game continues until one player collects all the cards or the cards run out.
- If the cards run out during a tiebreaker, each player takes back the cards they threw into the pot (splitting them evenly).

## Demo

Examples of the class's functionality can be found in [Demo.cpp](Cpp_Assignments/Task2_WarCardGame/Task2_Test/Demo.cpp)
.

## Unit Tests

In [Task2_Test](Task2_Test) there are comprehensive unit test files.

## How to Run

To check the implementation, make sure the following commands run without errors:

```
  make demo && ./demo
  make test && ./test
```

It is also recommended to run:

```
  make tidy
  make valgrind
```

