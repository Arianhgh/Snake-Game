#pragma once
#include "snake.h"
#include "food.h"
class GameManager{
    public:
        Snake snake;
        Food food;
        string direction = "right";
        int score;
        int highscore;
        bool gameOver;
        bool gameStarted;
        sf::RenderWindow* window;
        GameManager(sf::RenderWindow* _window);
        void init();
        void run();
        void update();
        void draw();
        void handleEvents();
        void handleCollisions();
};