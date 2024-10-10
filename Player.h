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

enum PLAYER_ANIMATION_STATES {NOT_MOVING = 0, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN};

class Player {

public:
    Player();
    ~Player();
    void render(sf::RenderTarget& target);
    virtual void findNode(sf::RenderWindow& target);
    void updateMovement(sf::RenderWindow& target);
    void updateAnimations();
    void move(const float dir_x, const float dir_y);
    float getMovementSpeed() const;
    sf::Sprite getSprite() const;
    sf::Texture getTexture() const;
    sf::Vector2f getPosition() const;
    void setCurrentNode(int node);
    sf::IntRect getCurrentFrame() const;
    void setMovementSpeed(const float movementSpeed);
    void setPosition(const float x, const float y);
    std::vector<sf::Vector2f> getPath() const;
    void setPath(const std::vector<sf::Vector2f>& path);
    short getAnimState() const;
    void setAnimState(const short animState);
    sf::Clock getAnimationTimer() const;

private:
    sf::Sprite sprite;
    sf::Texture texture;
    float movementSpeed;
    sf::IntRect currentFrame;
    sf::Clock animationTimer;
    short animState;
    std::vector<sf::Vector2f> path;
    int currentNode;
    void initTexture();
    void initSprite();
    void initVariables();
    void initAnimations();

};

#endif //PLAYER_H
