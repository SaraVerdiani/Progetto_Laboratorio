//
// Created by sarav on 02/09/2024.
//

#include "GameTile.h"


GameTile::GameTile(const std::string &textureName, int rectLeft, int rectTop , int rectWidth, int rectHeight, sf::Vector2f scale) {

    sprite.setTextureRect(sf::IntRect(rectLeft,rectTop, rectWidth, rectHeight));
    sprite.setScale(scale);


    this->setUpSprite(textureName);

}


GameTile::~GameTile() {
}

void GameTile::setUpSprite(std::string textureName) {

    if(!texture.loadFromFile(textureName)) {

        std::cout << "ERROR loading texture " << textureName << std::endl;
    }

    sprite.setTexture(texture);
    //sprite.setScale(3.f,3.f);

}

sf::Sprite& GameTile::getSprite() {

    return this->sprite;

}

sf::Texture  GameTile::getTexture() const {

    return this->texture;
}



