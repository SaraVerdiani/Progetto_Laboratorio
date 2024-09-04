//
// Created by sarav on 03/09/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MapSearchNode.h"
#include "stlastar.h"



class Player {
public:
    Player();
    ~Player();

    void render(sf::RenderTarget& target);
    void findNode(sf::RenderWindow& target);
    void updateMovement(sf::RenderWindow& target);







private:
    sf::Sprite sprite;
    sf::Texture texture;

    void initTexture();
    void initSprite();



};



#endif //PLAYER_H
