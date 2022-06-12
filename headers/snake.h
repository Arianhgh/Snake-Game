#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
using namespace std;
class Snake{
    public:
        int x, y;
        int x_speed, y_speed;
        int length;
        int score;
        bool gameOver;
        vector<sf::RectangleShape> body;
        Snake();
        void init();
        void move(string direction);
        void increase_length(string direction);
};