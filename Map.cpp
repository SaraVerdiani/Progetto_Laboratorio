//
// Created by sarav on 02/09/2024.
//

#include "Map.h"

int lvl1[30][35] = {

{0,1,1,1,1,1,1,11,11,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{9,9,9,9,9,9,9,12,12,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,4,4,4,4,5},
{10,10,10,10,10,10,10,12,12,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,13,14,4,4,4,4,13,14,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,15,15,15,15,13,14,15,15,15,16,13,14,15,15,15,15,15,15,15,15,15,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,13,14,4,4,4,16,13,14,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,15,15,15,15,13,14,15,15,15,16,13,14,15,15,15,15,15,15,15,15,15,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{6,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7},

};


Map::Map() {

    grassLeftCorner = new GameTile("assets/textures/map.png",0.f,32.f,32.f,32.f, sf::Vector2f(2.f,2.f), true,false);
    grassMiddleUp = new GameTile("assets/textures/map.png",32.f,32.f,32.f,32.f, sf::Vector2f(2.f,2.f), true,false);
    grassRightCorner = new GameTile("assets/textures/map.png",64.f,32.f,32.f,32.f, sf::Vector2f(2.f,2.f), true,false);
    grassMiddleLeft = new GameTile("assets/textures/map.png",0.f,64.f,32.f,32.f,sf::Vector2f(2.f,2.f),  true,false);
    grassCenter = new GameTile("assets/textures/map.png",32.f,64.f,32.f,32.f, sf::Vector2f(2.f,2.f), true,false);
    grassMiddleRight = new GameTile("assets/textures/map.png",64.f,64.f,32.f,32.f, sf::Vector2f(2.f,2.f), true,false);
    grassLowCornerLeft = new GameTile("assets/textures/map.png",0.f,96.f,32.f,32.f, sf::Vector2f(2.f,2.f),  true,false);
    grassMiddleLow = new GameTile("assets/textures/map.png",32.f,96.f,32.f,32.f,sf::Vector2f(2.f,2.f),  true,false);
    grassLowCornerRight = new GameTile("assets/textures/map.png",64.f,96.f,32.f,32.f, sf::Vector2f(2.f,2.f), true,false);
    pathMiddleUp = new GameTile("assets/textures/map.png",128.f,160.f,32.f,32.f, sf::Vector2f(2.f,2.f), true, false);
    pathMiddleLow = new GameTile("assets/textures/map.png",128.f,224.f,32.f,32.f, sf::Vector2f(2.f,2.f), true, false);
    water = new GameTile("assets/textures/map.png",96.f,672.f,32.f,32.f, sf::Vector2f(2.f,2.f), false, false);
    bridge = new GameTile("assets/textures/map.png",256.f,32.f,32.f,32.f, sf::Vector2f(2.f,2.f), true, false);
    stairsLeft = new GameTile("assets/textures/map.png",352.f,192.f,32.f,32.f, sf::Vector2f(2.f,2.f), true, false);
    stairsRight = new GameTile("assets/textures/map.png",384.f,192.f,32.f,32.f, sf::Vector2f(2.f,2.f), true, false);
    brick = new GameTile("assets/textures/map.png",128.f,128.f,32.f,32.f, sf::Vector2f(2.f,2.f), true, false);
    brick1 = new GameTile("assets/textures/map.png",160.f,96.f,32.f,32.f, sf::Vector2f(2.f,2.f), true, false);



    loadMap(lvl1);

}

Map::~Map() {

}

void Map::loadMap(int arr[30][35]) {

    for (int i = 0; i < 30; i++) {

        for (int j = 0; j < 35; j++) {

            map[i][j] = arr[i][j];

        }
    }


}

void Map::drawMap(sf::RenderTarget *target) {

    int type = 0;

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 35; j++) {
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
