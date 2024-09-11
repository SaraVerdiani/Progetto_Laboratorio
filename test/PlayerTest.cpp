#include "gtest/gtest.h"
#include "../Player.h"


TEST(Player, Constructor) {

    Player p;
    ASSERT_EQ(p.getMovementSpeed(), 1.5f);
    ASSERT_TRUE(p.getTexture().loadFromFile("assets/textures/character.png"));
    ASSERT_EQ(p.getPosition().x, 200.f);
    ASSERT_EQ(p.getPosition().y, 300.f);
    ASSERT_EQ(p.getCurrentFrame(), sf::IntRect(32.f, 72.f, 32.f, 36.f));
    ASSERT_EQ(p.getSprite().getScale(), sf::Vector2f(2.f,2.f));

}




