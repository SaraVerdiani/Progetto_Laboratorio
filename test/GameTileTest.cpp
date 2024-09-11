#include "gtest/gtest.h"
#include "../GameTile.h"

TEST(GameTile, Constructor) {

    std::string textureName = "assets/textures/map.png";

    GameTile t(textureName,0.f,32.f,32.f,32.f, sf::Vector2f(2.f,2.f));
    ASSERT_TRUE(t.getTexture().loadFromFile(textureName));
    ASSERT_EQ(t.getSprite().getTextureRect().left, 0.f);
    ASSERT_EQ(t.getSprite().getTextureRect().top, 32.f);
    ASSERT_EQ(t.getSprite().getTextureRect().width, 32.f);
    ASSERT_EQ(t.getSprite().getTextureRect().height, 32.f);
    ASSERT_EQ(t.getSprite().getScale(), sf::Vector2f(2.f,2.f));


}
