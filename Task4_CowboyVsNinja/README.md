# Cowboy_Vs_Ninja_a Project

## Overview
This project creates a simulation for an exciting battle scenario between ninjas and cowboys.

## Part 1: Point Class
### Description
- The `Point` class helps in maintaining the positions of units on a game board.
- Positions are defined by two coordinates of the double type (x and y).

### Operations
- **Constructor**: Initializes a point with two coordinates.
- **distance()**: Calculates and returns the distance between two points.
- **print()**: Displays coordinates.
- **moveTowards()**: Returns a point nearest to the destination, but within a given distance from the source.

## Part 2: Character Class
### Description
- The `Character` class represents a game unit with attributes like location (Point type), health points (integer), and name (string).

### Functions
- **isAlive()**: Returns true if the character is alive (health points > 0).
- **distance()**: Computes distance between two characters.
- **hit(integer)**: Reduces health points by an integer value.
- **getName()**, **getLocation()**, **print()**: Retrieve name, location, and print character details respectively.

#### Additional for Cowboys
- Attribute: bullet count.
- Methods: **shoot()**, **hasBullets()**, **reload()**.

#### Ninjas
- Types: `YoungNinja`, `TrainedNinja`, `OldNinja` with varying speeds and initial health points.

## Part 3: Team Classes
### Description
- The `Team` class represents a group of up to ten fighters, either ninjas or cowboys, with a designated leader.

### Methods
- **add()**: Adds a cowboy or ninja to the team.
- **attack()**: The team attacks an enemy team following specified rules.
- **stillAlive()**: Returns the number of living team members.
- **print()**: Displays details of all team members.
- A destructor that frees allocated memory for team members.

### Variations
- `team2`: Like `Team`, but iterates over characters in the added order without distinguishing between cowboys and ninjas.
- `SmartTeam`: Flexible iteration over characters to maximize damage to the opponent.

## Part B: Implementation
Implement the project to pass all specified tests. Write necessary files so commands can run without errors. Additional commands for tidying code and checking for memory leaks are suggested. Only add new files; do not modify existing ones.

## Good Luck!
