#include "gtest/gtest.h"
#include "../Map.h"

TEST(Map, Constructor) {

    Map map;

    ASSERT_NE(map.getBrick(), nullptr);
    ASSERT_NE(map.getBrick1(), nullptr);
    ASSERT_NE(map.getBridge(), nullptr);
    ASSERT_NE(map.getWater(), nullptr);
    ASSERT_NE(map.getGrassCenter(), nullptr);
    ASSERT_NE(map.getStairsLeft(), nullptr);
    ASSERT_NE(map.getStairsRight(), nullptr);
    ASSERT_NE(map.getGrassLeftCorner(), nullptr);
    ASSERT_NE(map.getGrassRightCorner(), nullptr);
    ASSERT_NE(map.getGrassMiddleLeft(), nullptr);
    ASSERT_NE(map.getGrassMiddleRight(), nullptr);
    ASSERT_NE(map.getGrassMiddleLow(), nullptr);
    ASSERT_NE(map.getGrassMiddleUp(), nullptr);
    ASSERT_NE(map.getPathMiddleLow(), nullptr);
    ASSERT_NE(map.getPathMiddleUp(), nullptr);
    ASSERT_NE(map.getGrassLowCornerLeft(), nullptr);
    ASSERT_NE(map.getGrassLowCornerRight(), nullptr);



}
