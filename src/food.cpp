#include "food.h"

Food::Food(){
    init();
}
void Food::init(){
    srand(time(0));
    int min = 50;
    int max = 900;
    x = rand() % (max - min) + min;
    y = rand() % (max - min) + min;
    food.setSize(sf::Vector2f(20, 20));
    food.setFillColor(sf::Color::Red);
    food.setPosition(x, y);
}
void Food::generate_food(){
    srand(time(0));
    int min = 50;
    int max = 900;
    x = rand() % (max - min) + min;
    y = rand() % (max - min) + min;
    food.setSize(sf::Vector2f(20, 20));
    food.setPosition(x, y);
}
