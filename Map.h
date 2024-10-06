//
// Created by sarav on 02/09/2024.
//

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "GameTile.h"
#include <array>


class Map {

public:
    Map();
    ~Map();

    void drawMap(sf::RenderTarget* target);
    void drawTile(sf::RenderTarget &target, GameTile* tile);

    std::array<std::array<int, 30>, 16> getMap() const;

    GameTile* getGrassLeftCorner() const;
    GameTile* getGrassMiddleUp() const;
    GameTile* getGrassRightCorner() const;
    GameTile* getGrassMiddleLeft() const;
    GameTile* getGrassCenter() const;
    GameTile* getGrassMiddleRight() const;
    GameTile* getGrassLowCornerLeft() const;
    GameTile* getGrassMiddleLow() const;
    GameTile* getGrassLowCornerRight() const;
    GameTile* getPathMiddleUp() const;
    GameTile* getPathMiddleLow() const;
    GameTile* getWater() const;
    GameTile* getBridge() const;
    GameTile* getStairsLeft() const;
    GameTile* getStairsRight() const;
    GameTile* getBrick() const;
    GameTile* getBrick1() const;



private:

    GameTile* grassLeftCorner;
    GameTile* grassMiddleUp;
    GameTile* grassRightCorner;
    GameTile* grassMiddleLeft;
    GameTile* grassCenter;
    GameTile* grassMiddleRight;
    GameTile* grassLowCornerLeft;
    GameTile* grassMiddleLow;
    GameTile* grassLowCornerRight;
    GameTile* pathMiddleUp;
    GameTile* pathMiddleLow;
    GameTile* water;
    GameTile* bridge;
    GameTile* stairsLeft;
    GameTile* stairsRight;
    GameTile* brick;
    GameTile* brick1;



};



#endif //MAP_H
