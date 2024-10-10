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