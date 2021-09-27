# Introduction

This application implements Keno, a popular gambling game. Players place a bet on up to 15 integer numbers from 1 to 80. Afterwards, the game generates 20 unique and random numbers also from 1 to 80, then players receive a payoff based on the intersection of their bet and the values drawn.

The bet must be passed to the program as an argument to the main function via an ASCII file. A valid file contains a real or an integer value indicating the credits, an integer value indicating the number of turns the player wants to participate in, and 1 to 15 integer numbers referring to the bet. Only this disposition makes up a valid file. Between values there can be only blank spaces.

Example of data file:

![Example of input](/img/expected-input.png)

# Author(s)

Rita de Cássia Chagas da Cruz

Victor Vieira Tagino

# Problems found or limitations

For future releases, it is expected to reorganize the project into two classes, as there are two perceived entities: Keno_Bet and Keno_GM. This division would mainly optimize maintenance.

# Grading

Preencha os itens que você implementou.

- [X] Receives input data via command line (5 credits);
- [X] Correctly handles the input bet file, treating both regular and problematic cases accordingly (20 credits);
- [X] Codes correctly the KenoBet class, according to the description provided in Code 1 (25 credits);
- [X] Executes correctly the amount of rounds defined in the input bet file (15 credits);
- [X] Identifies correctly the hits and the player’s payoff for every round (20 credits);
- [X] Displays correctly the information requested in Section 2.2 (15 credits).


# Compiling and Runnig

To compile the project is necessary to have g++ installed, this is a example of how to compile the project and execute the game with the player information inside the file "example.dat"

```
g++ source/core/main.cpp source/core/keno_bet.cpp source/core/keno_common.h -o a
./a example.dat
```
