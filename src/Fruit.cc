// File: Fruit.cc
// Description: This file is part of Snakey game software project, distributed under the terms
// of the GNU General Public License version 3.0.
// Author: Abraham Gabrielyan

//Includes from this project
#include "Fruit.hpp"

//Includes from third party libraries

//Includes from standard library

void Snakey::Fruit::AssignToX(const int32_t value) noexcept {
  fruit_.x = value;
}

void Snakey::Fruit::AssignToY(const int32_t value) noexcept {
  fruit_.y = value;
}

int32_t Snakey::Fruit::GetX(void) const noexcept {
  return fruit_.x;
}

int32_t Snakey::Fruit::GetY(void) const noexcept {
  return fruit_.y;
}

int32_t Snakey::Fruit::GetW(void) const noexcept {
  return fruit_.w;
}

int32_t Snakey::Fruit::GetH(void) const noexcept {
  return fruit_.h;
}

void Snakey::Fruit::InitRandom() noexcept {
  fruit_ = {distance_(range_), distance_(range_), 10, 10};
}

const SDL_Rect& Snakey::Fruit::GetRawFruit(void) const noexcept {
  return fruit_;
} 

Snakey::Fruit::Fruit() : range_(device_()),
                         distance_(0, 990){}
