// File: Snake.cc
// Description: This file is part of Snakey game software project, distributed under the terms
// of the GNU General Public License version 3.0.
// Author: Abraham Gabrielyan

//Includes from this project
#include "Snake.hpp"

//Includes from third party libraries

//Includes from standard library

const SDL_Rect& Snakey::Snake::GetSnakeHead(void) const noexcept {
  return head_;
}

SDL_Rect Snakey::Snake::GetSnakeHead(void) noexcept {
  return head_;
}

const std::list<SDL_Rect>& Snakey::Snake::GetSnakeBody(void) const noexcept {
  return snake_body_;
}

std::list<SDL_Rect> Snakey::Snake::GetSnakeBody(void) noexcept {
  return snake_body_;
}

const Uint64 Snakey::Snake::GetSize(void) const noexcept {
  return snake_size_;
}

const Uint64 Snakey::Snake::GetBodySize(void) const noexcept {
  return snake_body_.size();
}

void Snakey::Snake::AddPart() noexcept {
  snake_body_.push_front(head_);
}

void Snakey::Snake::RemovePart(void) noexcept {
  snake_body_.pop_back();
}

void Snakey::Snake::IncreaseSize(const Uint64 value) noexcept {
  snake_size_ += value;
}

void Snakey::Snake::AddToHeadX(const int32_t value) noexcept {
  head_.x += value;
}

void Snakey::Snake::AddToHeadY(const int32_t value) noexcept {
  head_.y += value;
}

void Snakey::Snake::AddToHeadW(const int32_t value) noexcept {
  head_.w += value;
}

void Snakey::Snake::AddToHeadH(const int32_t value) noexcept {
  head_.h += value;
}

void Snakey::Snake::SubFromHeadX(const int32_t value) noexcept {
  head_.x -= value;
}

void Snakey::Snake::SubFromHeadY(const int32_t value) noexcept {
  head_.y -= value;
}

void Snakey::Snake::SubFromHeadW(const int32_t value) noexcept {
  head_.w -= value;
}

void Snakey::Snake::SubFromHeadH(const int32_t value) noexcept {
  head_.h -= value;
}

Snakey::Snake::Snake() : head_(500, 500, 10, 10), snake_size_(1) {}
