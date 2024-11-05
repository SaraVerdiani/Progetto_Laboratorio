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
    void drawMap(sf::RenderTarget* target) const;
    void drawTile(sf::RenderTarget &target, GameTile* tile) const;
    void initNodeMap();
    std::array<std::array<int, 30>, 16> getMap() const;
    GameTile* getGrassLeftCorner() const;
    GameTile* getWater() const;
    GameTile* getBridge() const;

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
