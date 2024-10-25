#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include <array>

constexpr size_t kRowSize = 4;
constexpr size_t kColSize = 4;

void show_map(sf::RenderWindow& window, std::array<char, kRowSize* kColSize> map);

int convert_to_index(int x, int y);
#endif // MAP_H
