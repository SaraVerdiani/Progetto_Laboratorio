//
// Created by sarav on 02/09/2024.
//

#ifndef GAMETILE_H
#define GAMETILE_H

#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>



class GameTile {

public:
    GameTile(const std::string &textureName,int rectLeft, int rectTop , int rectWidth, int rectHeight, sf::Vector2f scale);
    ~GameTile();

    void setUpSprite(std::string textureName);
    sf::Sprite& getSprite();
    sf::Texture getTexture() const;





private:
    sf::Sprite sprite;
    sf::Texture texture;


};



#endif //GAMETILE_H
