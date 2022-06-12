#include "gamemanager.h"
int main(){
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake");
    GameManager game(&window);
    //game.init();
    game.run();
    return 0;
}