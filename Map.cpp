//
// Created by sarav on 02/09/2024.
//

#include "Map.h"

#include <array>

std::array<std::array<int, 30>, 16> lvl1 = {{

{0,1,1,1,1,1,1,11,11,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{9,9,9,9,9,9,9,12,12,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
{10,10,10,10,10,10,10,12,12,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10},
{3,4,4,4,4,4,4,11,11,4,4,4,4,13,14,4,4,4,4,13,14,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,15,15,15,15,13,14,15,15,15,16,13,14,15,15,15,15,15,15,15,15,15},
{3,4,4,4,4,4,4,11,11,4,4,4,4,13,14,4,4,4,16,13,14,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,15,15,15,15,13,14,15,15,15,16,13,14,15,15,15,15,15,15,15,15,15},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{6,8,8,8,8,8,8,11,11,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7},

}};


Map::Map() {

    grassLeftCorner = new GameTile("assets/textures/map.png",0.f,32.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    grassMiddleUp = new GameTile("assets/textures/map.png",32.f,32.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    grassRightCorner = new GameTile("assets/textures/map.png",64.f,32.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    grassMiddleLeft = new GameTile("assets/textures/map.png",0.f,64.f,32.f,32.f,sf::Vector2f(2.f,2.f));
    grassCenter = new GameTile("assets/textures/map.png",32.f,64.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    grassMiddleRight = new GameTile("assets/textures/map.png",64.f,64.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    grassLowCornerLeft = new GameTile("assets/textures/map.png",0.f,96.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    grassMiddleLow = new GameTile("assets/textures/map.png",32.f,96.f,32.f,32.f,sf::Vector2f(2.f,2.f));
    grassLowCornerRight = new GameTile("assets/textures/map.png",64.f,96.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    pathMiddleUp = new GameTile("assets/textures/map.png",128.f,160.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    pathMiddleLow = new GameTile("assets/textures/map.png",128.f,224.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    water = new GameTile("assets/textures/map.png",96.f,672.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    bridge = new GameTile("assets/textures/map.png",256.f,32.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    stairsLeft = new GameTile("assets/textures/map.png",352.f,192.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    stairsRight = new GameTile("assets/textures/map.png",384.f,192.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    brick = new GameTile("assets/textures/map.png",128.f,128.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    brick1 = new GameTile("assets/textures/map.png",160.f,96.f,32.f,32.f, sf::Vector2f(2.f,2.f));



    loadMap(lvl1);


}

Map::~Map() {

    delete grassLeftCorner;
    delete grassMiddleUp;
    delete grassRightCorner;
    delete grassMiddleLeft;
    delete grassCenter;
    delete grassMiddleRight;
    delete grassLowCornerLeft;
    delete grassMiddleLow;
    delete grassLowCornerRight;
    delete pathMiddleUp;
    delete pathMiddleLow;
    delete water;
    delete bridge;
    delete stairsLeft;
    delete stairsRight;
    delete brick;
    delete brick1;

}

void Map::loadMap(std::array<std::array<int, 30>, 16> arr) {

    for(int i = 0; i < 16; i++) {

        for(int j = 0; j < 30; j++) {

            map[i][j] = arr[i][j];
        }
    }


}

void Map::drawMap(sf::RenderTarget *target) {

    int type = 0;

    for (int i = 0; i < 16; i++) {

        for (int j = 0; j < 30; j++) {

            type = map[i][j];

            switch (type) {
                case 0:
                    grassLeftCorner->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, grassLeftCorner);
                break;
                case 1:
                    grassMiddleUp->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, grassMiddleUp);
                break;
                case 2:
                    grassRightCorner->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, grassRightCorner);
                break;
                case 3:
                    grassMiddleLeft->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, grassMiddleLeft);
                break;
                case 4:
                    grassCenter->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, grassCenter);
                break;
                case 5:
                    grassMiddleRight->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, grassMiddleRight);
                break;
                case 6:
                    grassLowCornerLeft->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, grassLowCornerLeft);
                break;
                case 7:
                    grassLowCornerRight->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, grassLowCornerRight);
                break;
                case 8:
                    grassMiddleLow->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, grassMiddleLow);
                break;
                case 9:
                    pathMiddleUp->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, pathMiddleUp);
                break;
                case 10:
                    pathMiddleLow->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, pathMiddleLow);
                break;
                case 11:
                    water->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, water);
                break;
                case 12:
                    bridge->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, bridge);
                break;
                case 13:
                    stairsLeft->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, stairsLeft);
                break;
                case 14:
                    stairsRight->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, stairsRight);
                break;
                case 15:
                    brick->getSprite().setPosition(j * 64.f , i * 64.f);
                drawTile(*target, brick);
                break;
                case 16:
                    brick1->getSprite().setPosition(j * 64.f, i * 64.f);
                drawTile(*target, brick1);
                break;

            }
        }
    }


}

void Map::drawTile(sf::RenderTarget &target, GameTile *tile) {

    target.draw(tile->getSprite());



}

std::array<std::array<int, 30>, 16> Map::getMap() const {

    return this->map;

}

GameTile * Map::getGrassLeftCorner() const {

    return this->grassLeftCorner;
}

GameTile * Map::getGrassMiddleUp() const {

    return this->grassMiddleUp;
}

GameTile * Map::getGrassRightCorner() const {

    return this->grassRightCorner;
}

GameTile * Map::getGrassMiddleLeft() const {

    return this->grassMiddleLeft;
}

GameTile * Map::getGrassCenter() const {

    return this->grassCenter;
}

GameTile * Map::getGrassMiddleRight() const {

    return this->grassMiddleRight;
}

GameTile * Map::getGrassLowCornerLeft() const {

    return this->grassLowCornerLeft;
}

GameTile * Map::getGrassMiddleLow() const {

    return this->grassMiddleLow;
}

GameTile * Map::getGrassLowCornerRight() const {

    return this->grassLowCornerRight;
}

GameTile * Map::getPathMiddleUp() const {

    return this->pathMiddleUp;
}

GameTile * Map::getPathMiddleLow() const {

    return this->pathMiddleLow;
}

GameTile * Map::getWater() const {

    return this->water;
}

GameTile * Map::getBridge() const {

    return this->bridge;
}

GameTile * Map::getStairsLeft() const {

    return this->stairsLeft;
}

GameTile * Map::getStairsRight() const {

    return this->stairsRight;
}

GameTile * Map::getBrick() const {

    return this->brick;
}

GameTile * Map::getBrick1() const {

    return this->brick1;
}


