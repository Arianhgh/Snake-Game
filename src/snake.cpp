#include "snake.h"
Snake::Snake(){
    //initialize the game
    init();
}
void Snake::init(){
    int min = 30;
    int max = 1000;
    x = 500;
    y = 500;
    x_speed =20;
    y_speed = 0;
    length = 0;
    score = 0;
    gameOver = false;
    //create the snake
    for(int i = 0; i < 3; i++){
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(20, 20));
        rect.setPosition(x, y);
        body.push_back(rect);
        x -= 10;
        length++;
    }
}
void Snake::move(string direction){
    if(direction == "right"){
        //cout << "right" << endl;
        x_speed = 20;
        y_speed = 0;
    }
    else if(direction == "left"){
        x_speed = -20;
        y_speed = 0;
    }
    else if(direction == "up"){
        x_speed = 0;
        y_speed = -20;
    }
    else if(direction == "down"){
        x_speed = 0;
        y_speed = 20;
    }
    x = body[0].getPosition().x + x_speed;
    y = body[0].getPosition().y + y_speed;
    //move the snake
    for(int i = length-1; i >=0; i--){
        //cout << body[i].getPosition().x << " " << body[i].getPosition().y << endl;
        if (i == 0){
            body[i].setPosition(x, y);
        }
        else{
            body[i].setPosition(body[i-1].getPosition().x, body[i-1].getPosition().y);
        }
        //cout << body[i].getPosition().x << " " << body[i].getPosition().y << endl;
    }
    
}
void Snake::increase_length(string direction){
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(20, 20));
    if(direction == "right"){
        rect.setPosition(body[length-1].getPosition().x + 10, body[length-1].getPosition().y);
    }
    else if(direction == "left"){
        rect.setPosition(body[length-1].getPosition().x - 10, body[length-1].getPosition().y);
    }
    else if(direction == "up"){
        rect.setPosition(body[length-1].getPosition().x, body[length-1].getPosition().y - 10);
    }
    else if(direction == "down"){
        rect.setPosition(body[length-1].getPosition().x, body[length-1].getPosition().y + 10);
    }
    body.push_back(rect);
    length++;
}