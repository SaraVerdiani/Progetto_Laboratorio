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

    GameTile* grass;



};



#endif //MAP_H
