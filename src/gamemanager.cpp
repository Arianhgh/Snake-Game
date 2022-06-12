#include "gamemanager.h"
GameManager::GameManager(sf::RenderWindow* _window){
     window = _window;
     window->setFramerateLimit(25);
    init();
}
void GameManager::init(){
    gameOver = false;
    gameStarted = true;
    score = 0;
    font.loadFromFile("fonts/arial.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setPosition(10, 10);
    scoreText.setString("Score: 0");
    scoreText.setFillColor(sf::Color::White);
    highscore = 0;

}
void GameManager::run(){
    init();
    //run the game
    window->display();
    while(window->isOpen()){
        //handle the events
        handleEvents();
        //update the game
        update();
        //draw the game
        draw();
    }
}
void GameManager::handleEvents(){
    //handle the events
    sf::Event event;
    while(window->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window->close();
        }
        if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Right){
                if(direction != "left"){
                    direction = "right";
                }
            }
            if(event.key.code == sf::Keyboard::Left){
                if(direction != "right"){
                    direction = "left";
                }
            }
            if(event.key.code == sf::Keyboard::Up){
                if(direction != "down"){
                    direction = "up";
                }
            }
            if(event.key.code == sf::Keyboard::Down){
                if(direction != "up"){
                    direction = "down";
                }
            }
            if(event.key.code == sf::Keyboard::Space){
                if(gameStarted){
                    gameStarted = false;
                }
                else{
                    gameStarted = true;
                }
            }
        }

    }

}
void GameManager::update(){
    //update the game
    if(gameStarted){
        snake.move(direction);
        handleCollisions();
        if(gameOver){
            //cout << "Game Over" << endl;
            exit(0);
        }
    }
};
void GameManager::handleCollisions(){
    int window_width = window->getSize().x;
    int window_height = window->getSize().y;
    //handle the collisions
    if(snake.body[0].getGlobalBounds().intersects(food.food.getGlobalBounds())){
        snake.increase_length(direction);
        score++;
        scoreText.setString("Score: " + std::to_string(score));
        food.generate_food();
        //check if the food is on the snake
        for(int i = 0; i < snake.body.size(); i++){
            if(snake.body[i].getGlobalBounds().intersects(food.food.getGlobalBounds())){
                food.generate_food();
            }
        }
        score++;
    }
    //check if the snake has collided with itself
    for(int i = 1; i < snake.body.size(); i++){
        if(snake.body[0].getGlobalBounds().intersects(snake.body[i].getGlobalBounds())){
            gameOver = true;
            cout << "Game Over" << endl;
        }
    }
    //check if the snake has collided with the wall
    if(snake.body[0].getPosition().x < 0 || snake.body[0].getPosition().x > window_width - snake.body[0].getGlobalBounds().width || snake.body[0].getPosition().y < 0 || snake.body[0].getPosition().y > window_height - snake.body[0].getGlobalBounds().height){
        gameOver = true;
        //cout << "Game Over" << endl;
    }
}
void GameManager::draw(){
    //draw the game
    window->clear();
    window->draw(food.food);
    for(int i = 0; i < snake.body.size(); i++){
        window->draw(snake.body[i]);
    }
    window->draw(scoreText);
    window->display();
}