#include "gtest/gtest.h"
#include "../Game.h"

TEST(Game, Constructor) {

    Game g;
    ASSERT_EQ(g.getWindow()->getSize().x, 1920);
    ASSERT_EQ(g.getWindow()->getSize().y, 1024);
    ASSERT_EQ(g.getFrameRateLimit(), 144);
    ASSERT_FALSE(g.getVerticalSync());
    ASSERT_NE(g.getMap(), nullptr);
    ASSERT_NE(g.getPlayer(), nullptr);
}