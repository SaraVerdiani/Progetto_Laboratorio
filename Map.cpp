//
// Created by sarav on 02/09/2024.
//

#include "Map.h"

Map::Map() {

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
