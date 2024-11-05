//
// Created by sarav on 02/09/2024.
//

#include "GameTile.h"

GameTile::GameTile(const std::string &textureName, int rectLeft, int rectTop , int rectWidth, int rectHeight, sf::Vector2f scale) {

    sprite.setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
    sprite.setScale(scale);
    setUpSprite(textureName);

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

    return sprite;
}

sf::Texture  GameTile::getTexture() const {

    return texture;
}

void GameTile::setSpritePosition(float x, float y) {

    sprite.setPosition(x, y);
}



