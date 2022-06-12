#include "gamemanager.h"
int main(){
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Snake");
    GameManager game(&window);
    game.init();
    game.run();
    return 0;
}