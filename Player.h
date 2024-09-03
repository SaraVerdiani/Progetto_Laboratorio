//
// Created by sarav on 03/09/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>



class Player {
public:
    Player();
    ~Player();




private:
    sf::Sprite sprite;
    sf::Texture texture;

    void initTexture();
    void initSprite();



};



#endif //PLAYER_H
