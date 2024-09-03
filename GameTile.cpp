//
// Created by sarav on 02/09/2024.
//

#include "GameTile.h"


GameTile::GameTile(const std::string &textureName, int rectLeft, int rectTop , int rectWidth, int rectHeight, bool passable, bool exit) {

    isPassable = passable;
    isExit = exit;
    sprite.setTextureRect(sf::IntRect(rectLeft,rectTop, rectWidth, rectHeight));


    this->setUpSprite(textureName);

}


GameTile::~GameTile() {
}

void GameTile::setUpSprite(std::string textureName) {

    if(!texture.loadFromFile(textureName)) {

        std::cout << "ERROR loading texture " << textureName << std::endl;
    }

    sprite.setTexture(texture);

}

sf::Sprite GameTile::getSprite() const {

    return this->sprite;

}

