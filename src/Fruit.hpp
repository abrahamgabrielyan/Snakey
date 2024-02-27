// File: Fruit.hpp
// Description: This file is part of Snakey game software project, distributed under the terms
// of the GNU General Public License version 3.0.
// Author: Abraham Gabrielyan

#pragma once

//Includes from this project

//Includes from third party libraries
#include <SDL2/SDL.h> 

//Includes from standard library
#include <cstdint>
#include <random>    

namespace Snakey {
    class Fruit;
}

/**
 * @brief The Fruit class represents a fruit in the game.
 */
class Snakey::Fruit final {
public:
    /**
     * @brief Assigns the fruit's x-coordinate.
     * @param x The x-coordinate to assign.
     */
    void AssignToX(const int32_t x) noexcept;

    /**
     * @brief Assigns the fruit's y-coordinate.
     * @param y The y-coordinate to assign.
     */
    void AssignToY(const int32_t y) noexcept;

    /**
     * @brief Retrieves the fruit's x-coordinate.
     * @return The fruit's x-coordinate.
     */
    int32_t GetX(void) const noexcept;

    /**
     * @brief Retrieves the fruit's y-coordinate.
     * @return The fruit's y-coordinate.
     */
    int32_t GetY(void) const noexcept;

    /**
     * @brief Retrieves the fruit's width.
     * @return The fruit's width.
     */
    int32_t GetW(void) const noexcept;

    /**
     * @brief Retrieves the fruit's height.
     * @return The fruit's height.
     */
    int32_t GetH(void) const noexcept;

    /**
     * @brief Initializes the fruit's position randomly.
     */
    void InitRandom(void) noexcept;

    /**
     * @brief Retrieves the raw SDL_Rect representing the fruit's position.
     * @return The SDL_Rect representing the fruit's position.
     */
    const SDL_Rect& GetRawFruit(void) const noexcept;

    /**< Constructor */
    Fruit();
    /**< Deleted copy constructor */
    Fruit(const Fruit&) = delete;
    /**< Deleted move constructor */
    Fruit(Fruit&&) = delete;
    /**< Deleted copy assignment operator */
    Fruit& operator=(const Fruit&) = delete;
    /**< Deleted move assignment operator */
    Fruit& operator=(Fruit&&) = delete;
    /**< Default destructor */
    ~Fruit() = default;

private:
    SDL_Rect fruit_;
    std::random_device device_;
    std::mt19937 range_;
    std::uniform_int_distribution<int32_t> distance_;
};


