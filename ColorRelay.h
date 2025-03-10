#ifndef COLOR_RELAY_H
#define COLOR_RELAY_H

#include <vector>
#include <string>

// Ball class representing a colored ball
class Ball {
private:
    std::string color;  // Ball color (Red, Blue, Green)
public:
    Ball(std::string color);
    std::string getColor() const;
};

// Player class representing a participant in the game
class Player {
private:
    std::string name;
    std::vector<Ball> selectedBalls;  // Balls picked by the player
public:
    Player(std::string name);
    void pickBall(const Ball& ball);
    std::vector<Ball> getSelectedBalls() const;
    std::string getName() const;
};

// Communication system between players
class TeamCommunication {
public:
    static void notifySelection(const Player& player, const Ball& ball);
};

// Game class handling the game logic
class Game {
private:
    std::vector<Player> players;
    std::vector<Ball> availableBalls;
    int currentPlayerIndex;

public:
    Game(std::vector<std::string> playerNames);
    void start();
    void nextTurn();
    bool isGameOver() const;
};

#endif // COLOR_RELAY_H