//
// Created by sarav on 03/09/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MapSearchNode.h"
#include "stlastar.h"
#include <cmath>



class Player {
public:
    Player();
    ~Player();

    void render(sf::RenderTarget& target);
    void findNode(sf::RenderWindow& target);
    void updateMovement(sf::RenderWindow& target);
    void move(const float dir_x, const float dir_y);







private:
    sf::Sprite sprite;
    sf::Texture texture;

    float movementSpeed;

    std::vector<sf::Vector2f> path;
    int currentNode;

    void initTexture();
    void initSprite();
    void initVariables();




};



#endif //PLAYER_H
