//
// Created by sarav on 02/09/2024.
//

#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "GameTile.h"


class Map {

public:
    Map();
    ~Map();

    void loadMap(int arr[30][35]);
    void drawMap(sf::RenderTarget* target);
    void drawTile(sf::RenderTarget &target, GameTile* tile);





private:
    int map[30][35];

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
