//
// Created by sarav on 02/09/2024.
//

#include "Map.h"

int lvl1[30][35] = {

{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
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
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5},
{6,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7},

};


Map::Map() {

    grassLeftCorner = new GameTile("assets/textures/map.png",0.f,32.f,32.f,32.f, true,false);
    grassMiddleUp = new GameTile("assets/textures/map.png",32.f,32.f,32.f,32.f, true,false);
    grassRightCorner = new GameTile("assets/textures/map.png",64.f,32.f,32.f,32.f, true,false);
    grassMiddleLeft = new GameTile("assets/textures/map.png",0.f,64.f,32.f,32.f, true,false);
    grassCenter = new GameTile("assets/textures/map.png",32.f,64.f,32.f,32.f, true,false);
    grassMiddleRight = new GameTile("assets/textures/map.png",64.f,64.f,32.f,32.f, true,false);
    grassLowCornerLeft = new GameTile("assets/textures/map.png",0.f,96.f,32.f,32.f, true,false);
    grassMiddleLow = new GameTile("assets/textures/map.png",32.f,96.f,32.f,32.f, true,false);
    grassLowCornerRight = new GameTile("assets/textures/map.png",64.f,96.f,32.f,32.f, true,false);



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
                    grassLeftCorner->getSprite().setPosition(j * 32.f, i * 32.f);
                drawTile(*target, grassLeftCorner);
                break;
                case 1:
                    grassMiddleUp->getSprite().setPosition(j * 32.f, i * 32.f);
                drawTile(*target, grassMiddleUp);
                break;
                case 2:
                    grassRightCorner->getSprite().setPosition(j * 32.f, i * 32.f);
                drawTile(*target, grassRightCorner);
                break;
                case 3:
                    grassMiddleLeft->getSprite().setPosition(j * 32.f, i * 32.f);
                drawTile(*target, grassMiddleLeft);
                break;
                case 4:
                    grassCenter->getSprite().setPosition(j * 32.f, i * 32.f);
                drawTile(*target, grassCenter);
                break;
                case 5:
                    grassMiddleRight->getSprite().setPosition(j * 32.f, i * 32.f);
                drawTile(*target, grassMiddleRight);
                break;
                case 6:
                    grassLowCornerLeft->getSprite().setPosition(j * 32.f, i * 32.f);
                drawTile(*target, grassLowCornerLeft);
                break;
                case 7:
                    grassLowCornerRight->getSprite().setPosition(j * 32.f, i * 32.f);
                drawTile(*target, grassLowCornerRight);
                break;
                case 8:
                    grassMiddleLow->getSprite().setPosition(j * 32.f, i * 32.f);
                drawTile(*target, grassMiddleLow);
                break;
            }
        }
    }


}

void Map::drawTile(sf::RenderTarget &target, GameTile *tile) {

    target.draw(tile->getSprite());


}
