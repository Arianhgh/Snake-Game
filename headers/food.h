#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
using namespace std;
//a class for snake food
class Food{
    public:
    int x;
    int y;
    sf::RectangleShape food;
    Food();
    void init();
    void generate_food();
};