//
// Created by sarav on 02/09/2024.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>



class Game {

public:
    Game();
    ~Game();


    void run();
    void update();
    void render();

    void pollEvents();



private:
    sf::RenderWindow* window;
    sf::Event event;


    void initWindow();



};



#endif //GAME_H
