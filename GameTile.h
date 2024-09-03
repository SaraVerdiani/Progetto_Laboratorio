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
    GameTile(const std::string &textureName,int rectLeft, int rectTop , int rectWidth, int rectHeight, bool passable = true, bool exit = false);
    ~GameTile();

    void setUpSprite(std::string textureName);
    sf::Sprite& getSprite();



private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool isPassable;
    bool isExit;


};



#endif //GAMETILE_H
