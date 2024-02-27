// File: Game.hpp
// Description: This file is part of Snakey game software project, distributed under the terms
// of the GNU General Public License version 3.0.
// Author: Abraham Gabrielyan

#pragma once

//Includes from this project
#include "Snake.hpp"
#include "Fruit.hpp"

//Includes from third party libraries
#include <SDL2/SDL.h> 

//Includes from standard library
#include <cstdint>
#include <random>    
#include <stdexcept>
#include <list>

namespace Snakey {
    class Game;
}

/**
 * @brief The Game class represents the main game logic and rendering.
 */
class Snakey::Game final {
public:
    /**
     * @brief Displays the losing screen when the game is over.
     */
    void ShowLosingScreen(void);

    /**
     * @brief Handles user input for changing the snake's direction.
     */
    void HandleDirection(void);

    /**
     * @brief Handles the movement of the snake.
     */
    void HandleMovement(void);

    /**
     * @brief Handles collision with game borders.
     */
    void HandleBordersCollision(void);

    /**
     * @brief Handles the event when the snake eats a fruit.
     */
    void HandleEatingEvent(void);

    /**
     * @brief Handles collision with parts of the snake's body.
     */
    void HandleSnakePartCollision(void);

    /**
     * @brief Resizes the snake after eating a fruit.
     */
    void ResizeSnake(void);

    /**
     * @brief Renders all game objects on the screen.
     */
    void RenderObjects(void);

    /**
     * @brief Runs the main game loop.
     */
    void Run(void);

    /**< Constructor */
    Game();

    /**< Deleted copy constructor */
    Game(const Game&) = delete;

    /**< Deleted move constructor */
    Game(Game&&) = delete;

    /**< Deleted copy assignment operator */
    Game& operator=(const Game&) = delete;

    /**< Deleted move assignment operator */
    Game& operator=(Game&&) = delete;

    /**< Default destructor */
    ~Game() = default;

private:
    enum class Direction_ : Uint8 {
        DOWN,
        LEFT,
        RIGHT,
        UP
    };

    Snakey::Snake snake_;
    Snakey::Fruit fruit_;
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Event event_;
    Direction_ direction_;
    bool running_state_;
};
