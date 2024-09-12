#include "gtest/gtest.h"
#include "../Map.h"

class MapFixture : public ::testing::Test {

public:
    virtual void SetUp() {

        map = new Map();
        window.create(sf::VideoMode(1920,1024),"TestWindow");



    }

    protected:

    Map* map = nullptr;
    sf::RenderWindow window;


};

TEST_F(MapFixture, TestLoadMap) {

    std::array<std::array<int, 30>, 16> testLvl;

 for (int i = 0; i < 16; i++) {

        for (int j = 0; j < 30; j++) {

            testLvl[i][j] = i + j;
        }
    }
    map->loadMap(testLvl);

    for (int i = 0; i < 16; i++) {

        for (int j = 0; j < 30; j++) {

            ASSERT_EQ(map->getMap()[i][j], testLvl[i][j]);

        }
    }


}