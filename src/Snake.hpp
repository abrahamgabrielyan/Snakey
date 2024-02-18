// File: Snake.hpp
// Description: This file is part of Snakey game software project, distributed under the terms
// of the GNU General Public License version 3.0.
// Author: Abraham Gabrielyan

#pragma once

//Includes from this project

//Includes from third party libraries
#include <SDL2/SDL.h> 

//Includes from standard library
#include <list>       
#include <cstdint>    

namespace Snakey {
    class Snake;
}

/**
 * @brief The Snake class represents the snake entity in the game.
 */
class Snakey::Snake final {
public:

    /**
     * @brief Retrieves the head of the snake.
     * @return The head of the snake as a constant reference to an SDL_Rect.
     */
    [[nodiscard]] const SDL_Rect& GetSnakeHead(void) const noexcept;

    /**
     * @brief Retrieves the head of the snake.
     * @return The head of the snake as an SDL_Rect (non-constant version).
     */
    [[nodiscard]] SDL_Rect GetSnakeHead(void) noexcept;

    /**
     * @brief Retrieves the body of the snake.
     * @return The body of the snake as a constant reference to a list of SDL_Rect.
     */
    [[nodiscard]] const std::list<SDL_Rect>& GetSnakeBody(void) const noexcept;

    /**
     * @brief Retrieves the body of the snake.
     * @return The body of the snake as a list of SDL_Rect (non-constant version).
     */
    [[nodiscard]] std::list<SDL_Rect> GetSnakeBody(void) noexcept;

    /**
     * @brief Retrieves the size of the snake.
     * @return The size of the snake.
     */
    const Uint64 GetSize(void) const noexcept;

    /**
     * @brief Retrieves the size of the snake's body.
     * @return The size of the snake's body.
     */
    const Uint64 GetBodySize(void) const noexcept;

    /**
     * @brief Adds a new part to the snake.
     */
    void AddPart() noexcept;

    /**
     * @brief Removes the last part from the snake.
     */
    void RemovePart(void) noexcept;

    /**
     * @brief Increases the size of the snake.
     * @param size The amount by which to increase the size of the snake.
     */
    void IncreaseSize(const Uint64 size) noexcept;

    /**
     * @brief Moves the head of the snake along the x-axis.
     * @param amount The amount to add to the x-coordinate of the head.
     */
    void AddToHeadX(const int32_t amount) noexcept;

    /**
     * @brief Moves the head of the snake along the y-axis.
     * @param amount The amount to add to the y-coordinate of the head.
     */
    void AddToHeadY(const int32_t amount) noexcept;

    /**
     * @brief Increases the width of the head of the snake.
     * @param amount The amount by which to increase the width of the head.
     */
    void AddToHeadW(const int32_t amount) noexcept;

    /**
     * @brief Increases the height of the head of the snake.
     * @param amount The amount by which to increase the height of the head.
     */
    void AddToHeadH(const int32_t amount) noexcept;

    /**
     * @brief Moves the head of the snake along the x-axis in the negative direction.
     * @param amount The amount to subtract from the x-coordinate of the head.
     */
    void SubFromHeadX(const int32_t amount) noexcept;

    /**
     * @brief Moves the head of the snake along the y-axis in the negative direction.
     * @param amount The amount to subtract from the y-coordinate of the head.
     */
    void SubFromHeadY(const int32_t amount) noexcept;

    /**
     * @brief Decreases the width of the head of the snake.
     * @param amount The amount by which to decrease the width of the head.
     */
    void SubFromHeadW(const int32_t amount) noexcept;

    /**
     * @brief Decreases the height of the head of the snake.
     * @param amount The amount by which to decrease the height of the head.
     */
    void SubFromHeadH(const int32_t amount) noexcept;

    /**< Constructor */
    Snake();

    /**< Deleted copy constructor */
    Snake(const Snake&) = delete;

    /**< Deleted move constructor */
    Snake(Snake&&) = delete;

    /**< Deleted copy assignment operator */
    Snake& operator=(const Snake&) = delete;

    /**< Deleted move assignment operator */
    Snake& operator=(Snake&&) = delete;

    /**< Default destructor */
    ~Snake() = default;

private:
    SDL_Rect head_;
    std::list<SDL_Rect> snake_body_;
    Uint64 snake_size_;
};
