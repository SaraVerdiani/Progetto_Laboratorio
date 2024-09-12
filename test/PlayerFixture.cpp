#include "gtest/gtest.h"
#include "../Player.h"

class PlayerFixture : public ::testing::Test {
    public:
    virtual void SetUp() {
        p = new Player();
        window.create(sf::VideoMode(1920,1024),"TestWindow");
        p->setPosition(200.f,200.f);
        p->setMovementSpeed(1.5f);
        p->updateAnimations();

    }

    protected:

    Player *p = nullptr;
    sf::RenderWindow window;

};

TEST_F(PlayerFixture, TestMove) {

    p->move(-1.f,0.f);
    ASSERT_LT(p->getPosition().x, 200.f);       //Se il personaggio si muove verso sinistra la coordinata x diminuisce
    ASSERT_EQ(p->getPosition().y, 200.f);

    p->setPosition(200.f,200.f);

    p->move(1.f, 0.f);
    ASSERT_GT(p->getPosition().x, 200.f);     //Se il personaggio si muove verso destra la coordinata x aumenta
    ASSERT_EQ(p->getPosition().y, 200.f);

    p->setPosition(200.f,200.f);

    p->move(0.f, -1.f);
    ASSERT_LT(p->getPosition().y, 200.f);    //Se il personaggio si muove verso sopra la coordinata y diminuisce
    ASSERT_EQ(p->getPosition().x, 200.f);

    p->setPosition(200.f,200.f);

    p->move(0.f, 1.f);
    ASSERT_GT(p->getPosition().y, 200.f);   //Se il personaggio si muove giù la coordinata y aumenta
    ASSERT_EQ(p->getPosition().x, 200.f);


}

TEST_F(PlayerFixture, TestFindNodeSuccess) {


    sf::Vector2f startPos (0.f,0.f);
    sf::Vector2f endPos (128.f, 128.f);

   p->findNodeTest(startPos, endPos);

    ASSERT_FALSE(p->getPath().empty());
    EXPECT_EQ(p->getPath().front(), startPos);
    EXPECT_EQ(p->getPath().back(), endPos);


}

TEST_F(PlayerFixture, TestFindNodeFail) {

    sf::Vector2f startPos (0.f,0.f);
    sf::Vector2f endPos (448.f, 0.f);

    p->findNodeTest(startPos, endPos);

    ASSERT_TRUE(p->getPath().empty());

}

TEST_F(PlayerFixture, TestUpdateMovementLeft) {

    p->setPosition(256.f,0.f);

    p->setPath({sf::Vector2f(192.f,0.f), sf::Vector2f(128.f,0.f), sf::Vector2f(64.f,0.f)});

    while(p->getSprite().getPosition().x > 64.f) {
        p->updateMovement(window);

        if(p->getSprite().getPosition().x > 64.f) {

            EXPECT_EQ(p->getAnimState(), PLAYER_ANIMATION_STATES::MOVING_LEFT);

        }

    }

    EXPECT_FLOAT_EQ(p->getSprite().getPosition().x, 64.f);
    EXPECT_FLOAT_EQ(p->getSprite().getPosition().y, 0.f);


}

TEST_F(PlayerFixture, TestUpdateMovementUp) {

    p->setPosition(0.f, 192.f);

    p->setPath({sf::Vector2f(0.f, 128.f), sf::Vector2f(0.f,64.f), sf::Vector2f(0.f,0.f)});

    while(p->getSprite().getPosition().y > 0.f) {

        p->updateMovement(window);

        if(p->getSprite().getPosition().y > 0.f) {

            EXPECT_EQ(p->getAnimState(), PLAYER_ANIMATION_STATES::MOVING_UP);

        }


    }

    EXPECT_FLOAT_EQ(p->getSprite().getPosition().x, 0.f);
    EXPECT_FLOAT_EQ(p->getSprite().getPosition().y, 0.f);



}

TEST_F(PlayerFixture, TestUpdateMovementDown) {

    p->setPosition(0.f, 0.f);

    p->setPath({sf::Vector2f(0.f, 64.f), sf::Vector2f(0.f,128.f), sf::Vector2f(0.f,192.f)});

    while(p->getSprite().getPosition().y < 192.f) {

        p->updateMovement(window);

        if(p->getSprite().getPosition().y < 192.f) {
            EXPECT_EQ(p->getAnimState(), PLAYER_ANIMATION_STATES::MOVING_DOWN);
        }


    }

    EXPECT_FLOAT_EQ(p->getSprite().getPosition().x, 0.f);
    EXPECT_FLOAT_EQ(p->getSprite().getPosition().y, 192.f);


}

TEST_F(PlayerFixture, TestUpdateAnimationsRight) {

    p->setAnimState(PLAYER_ANIMATION_STATES::MOVING_RIGHT);

    if(p->getAnimationTimer().getElapsedTime().asSeconds() >= 0.15f) {

        EXPECT_EQ(p->getCurrentFrame().top, 36.f);
        EXPECT_EQ(p->getCurrentFrame().left, 32.f);

        if(p->getCurrentFrame().left >=  96.f) {
            EXPECT_EQ(p->getCurrentFrame().left, 0.f);
            EXPECT_EQ(p->getCurrentFrame().top, 36.f);
        }

    EXPECT_NEAR(p->getAnimationTimer().getElapsedTime().asSeconds(), 0.f, 0.2f);
    EXPECT_EQ(p->getSprite().getTextureRect(), p->getCurrentFrame());

    }





}

TEST_F(PlayerFixture, TestUpdateAnimationsLeft) {

    p->setAnimState(PLAYER_ANIMATION_STATES::MOVING_LEFT);

    if(p->getAnimationTimer().getElapsedTime().asSeconds() >= 0.15f) {

        EXPECT_EQ(p->getCurrentFrame().top, 108.f);
        EXPECT_EQ(p->getCurrentFrame().left, 32.f);

        if(p->getCurrentFrame().left >=  96.f) {
            EXPECT_EQ(p->getCurrentFrame().left, 0.f);
            EXPECT_EQ(p->getCurrentFrame().top, 32.f);
        }

        EXPECT_NEAR(p->getAnimationTimer().getElapsedTime().asSeconds(), 0.f, 0.2f);
        EXPECT_EQ(p->getSprite().getTextureRect(), p->getCurrentFrame());

    }

}

TEST_F(PlayerFixture, TestUpdateAnimationsDown) {

    p->setAnimState(PLAYER_ANIMATION_STATES::MOVING_DOWN);

    if(p->getAnimationTimer().getElapsedTime().asSeconds() >= 0.15f) {

        EXPECT_EQ(p->getCurrentFrame().top, 72.f);
        EXPECT_EQ(p->getCurrentFrame().left, 32.f);

        if(p->getCurrentFrame().left >=  96.f) {
            EXPECT_EQ(p->getCurrentFrame().left, 0.f);
            EXPECT_EQ(p->getCurrentFrame().top, 72.f);
        }

        EXPECT_NEAR(p->getAnimationTimer().getElapsedTime().asSeconds(), 0.f, 0.2f);
        EXPECT_EQ(p->getSprite().getTextureRect(), p->getCurrentFrame());

    }


}

TEST_F(PlayerFixture, TestUpdateAnimationsUp) {

    p->setAnimState(PLAYER_ANIMATION_STATES::MOVING_UP);

    if(p->getAnimationTimer().getElapsedTime().asSeconds() >= 0.15f) {

        EXPECT_EQ(p->getCurrentFrame().top, 0.f);
        EXPECT_EQ(p->getCurrentFrame().left, 32.f);

        if(p->getCurrentFrame().left >=  96.f) {
            EXPECT_EQ(p->getCurrentFrame().left, 0.f);
            EXPECT_EQ(p->getCurrentFrame().top, 0.f);
        }

        EXPECT_NEAR(p->getAnimationTimer().getElapsedTime().asSeconds(), 0.f, 0.2f);
        EXPECT_EQ(p->getSprite().getTextureRect(), p->getCurrentFrame());

    }

}







