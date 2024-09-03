//
// Created by sarav on 03/09/2024.
//

#include "Player.h"

Player::Player() {

    this->initTexture();


}

Player::~Player() {



}

void Player::render(sf::RenderTarget &target) {

    target.draw(this->sprite);


}


void Player::initTexture() {

    if(!texture.loadFromFile("assets/textures/character.png")) {

        std::cout << "ERROR: COULD NOT LOAD PLAYER TEXTURE" << std::endl;
    }

}

void Player::initSprite() {

    this->sprite.setTexture(texture);

}

