//
// Created by sarav on 02/09/2024.
//

#include "Map.h"
#include <array>

std::array<std::array<int, 30>, 16> gameMap = {{

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

void Map::drawMap(sf::RenderTarget *target) const {

    int type = 0;

    for (int i = 0; i < 16; i++) {

        for (int j = 0; j < 30; j++) {
            type = gameMap[i][j];
            switch (type) {
                case 0:
                    grassLeftCorner->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, grassLeftCorner);
                break;
                case 1:
                    grassMiddleUp->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, grassMiddleUp);
                break;
                case 2:
                    grassRightCorner->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, grassRightCorner);
                break;
                case 3:
                    grassMiddleLeft->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, grassMiddleLeft);
                break;
                case 4:
                    grassCenter->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, grassCenter);
                break;
                case 5:
                    grassMiddleRight->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, grassMiddleRight);
                break;
                case 6:
                    grassLowCornerLeft->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, grassLowCornerLeft);
                break;
                case 7:
                    grassLowCornerRight->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, grassLowCornerRight);
                break;
                case 8:
                    grassMiddleLow->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, grassMiddleLow);
                break;
                case 9:
                    pathMiddleUp->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, pathMiddleUp);
                break;
                case 10:
                    pathMiddleLow->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, pathMiddleLow);
                break;
                case 11:
                    water->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, water);
                break;
                case 12:
                    bridge->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, bridge);
                break;
                case 13:
                    stairsLeft->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, stairsLeft);
                break;
                case 14:
                    stairsRight->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, stairsRight);
                break;
                case 15:
                    brick->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, brick);
                break;
                case 16:
                    brick1->setSpritePosition(j * 64.f, i * 64.f);
                drawTile(*target, brick1);
                break;
            }
        }
    }
}

void Map::drawTile(sf::RenderTarget &target, GameTile *tile) const {

    target.draw(tile->getSprite());
}

void Map::initNodeMap() {

    int type = 0;

    for (int i = 0; i < 30; i ++) {
        for (int j = 0; j < 16; j ++) {

            type = gameMap[j][i];
            switch (type) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 12:
                case 13:
                case 14:
                MapSearchNode::setNodeCost(i, j, 0);
                break;
                case 11:
                case 15:
                case 16:
                MapSearchNode::setNodeCost(i, j, 9);
                break;
            }
        }
    }
}

std::array<std::array<int, 30>, 16> Map::getMap() const {

    return gameMap;
}

GameTile * Map::getGrassLeftCorner() const {

    return grassLeftCorner;
}

GameTile * Map::getWater() const {

    return water;
}

GameTile * Map::getBridge() const {

    return bridge;
}



