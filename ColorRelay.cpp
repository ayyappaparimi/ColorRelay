#include "ColorRelay.h"
#include <iostream>

// Ball class implementation
Ball::Ball(std::string color) : color(color) {}

std::string Ball::getColor() const {
    return color;
}

// Player class implementation
Player::Player(std::string name) : name(name) {}

void Player::pickBall(const Ball& ball) {
    selectedBalls.push_back(ball);
    TeamCommunication::notifySelection(*this, ball);
}

std::vector<Ball> Player::getSelectedBalls() const {
    return selectedBalls;
}

std::string Player::getName() const {
    return name;
}

// TeamCommunication class implementation
void TeamCommunication::notifySelection(const Player& player, const Ball& ball) {
    std::cout << player.getName() << " picked a " << ball.getColor() << " ball.\n";
}

// Game class implementation
Game::Game(std::vector<std::string> playerNames) : currentPlayerIndex(0) {
    for (const auto& name : playerNames) {
        players.emplace_back(name);
    }
    availableBalls = { Ball("Red"), Ball("Blue"), Ball("Green") }; // Default sequence
}

void Game::start() {
    std::cout << "Game Started! Players take turns selecting balls in sequence.\n";
    nextTurn();
}

void Game::nextTurn() {
    if (isGameOver()) {
        std::cout << "Game Over! All players have played.\n";
        return;
    }

    Player& currentPlayer = players[currentPlayerIndex];
    std::cout << currentPlayer.getName() << ", it's your turn! Choose a ball: \n";

    // Display available balls
    for (size_t i = 0; i < availableBalls.size(); ++i) {
        std::cout << i + 1 << ". " << availableBalls[i].getColor() << "\n";
    }

    int choice;
    std::cin >> choice;

    if (choice >= 1 && choice <= availableBalls.size()) {
        currentPlayer.pickBall(availableBalls[choice - 1]);
    } else {
        std::cout << "Invalid choice, try again!\n";
        return;
    }

    currentPlayerIndex++; // Move to next player
    nextTurn();
}

bool Game::isGameOver() const {
    return currentPlayerIndex >= players.size();
}