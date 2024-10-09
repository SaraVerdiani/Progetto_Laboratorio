#include "gtest/gtest.h"
#include "../Map.h"

TEST(Map, Constructor) {

    Map map;

    ASSERT_NE(map.getBridge(), nullptr);
    ASSERT_NE(map.getWater(), nullptr);
    ASSERT_NE(map.getGrassLeftCorner(), nullptr);



}
