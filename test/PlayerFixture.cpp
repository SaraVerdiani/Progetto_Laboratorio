#include "gtest/gtest.h"
#include "../Player.h"
#include "../GameTile.h"

class PlayerFunctionTest : public Player {
public:

    PlayerFunctionTest() {

        currentNode = 0;
    }

    void findNode(sf::RenderWindow& target) override {

        AStarSearch<MapSearchNode> astarsearch;

        MapSearchNode nodeStart;
        MapSearchNode nodeEnd;

        nodeStart.setX(startPos.x / 64);
        nodeStart.setY(startPos.y / 64);


        nodeEnd.setX(endPos.x / 64);
        nodeEnd.setY(endPos.y / 64);

        astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

        unsigned int SearchState;
        unsigned int SearchStep = 0;

        do {

            SearchState = astarsearch.SearchStep();
            SearchStep++;

            cout << "Steps: " << SearchStep << endl;


        } while(SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);

        if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED ) {
            cout << "Search found goal state\n";

            MapSearchNode *node = astarsearch.GetSolutionStart();

            this->path.clear();
            this->currentNode = 0;

            this->path.push_back(startPos);

            int steps = 0;

            node->PrintNodeInfo();
            for( ;; )
            {
                node = astarsearch.GetSolutionNext();

                if( !node )
                {
                    break;
                }

                node->PrintNodeInfo();

                sf::Vector2f nextPos(node->getX() * 64.0f, node->getY() * 64.0f);

                this->path.push_back(nextPos);

                steps ++;

            };

            cout << "Solution steps " << steps << endl;


            astarsearch.FreeSolutionNodes();

        }

        if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED)
            cout << "Search failed\n";


    }

    void setStartPos(float x, float y) {

        startPos.x = x;
        startPos.y = y;


    }

    void setEndPos(float x, float y) {

        endPos.x = x;
        endPos.y = y;

    }

    void setTileCost(int x, int y, int cost) {

        world_map[x][y] = cost;
    }

    sf::Vector2f startPos;
    sf::Vector2f endPos;
    std::vector<sf::Vector2f> path;
    int currentNode;

};

class PlayerFixture : public ::testing::Test {

    public:
    virtual void SetUp() {
        p = new Player();
        pTest = new PlayerFunctionTest();
        window.create(sf::VideoMode(1920,1024),"TestWindow");
        p->setPosition(256.f,192.f);
        p->setMovementSpeed(1.5f);
    }
    protected:
    Player *p = nullptr;
    PlayerFunctionTest* pTest = nullptr;
    sf::RenderWindow window;

};

TEST_F(PlayerFixture, TestMove) {

    p->move(-1.f,0.f);
    ASSERT_LT(p->getPosition().x, 256.f);       //Se il personaggio si muove verso sinistra la coordinata x diminuisce
    ASSERT_EQ(p->getPosition().y, 192.f);

    p->setPosition(256.f,192.f);

    p->move(1.f, 0.f);
    ASSERT_GT(p->getPosition().x, 256.f);     //Se il personaggio si muove verso destra la coordinata x aumenta
    ASSERT_EQ(p->getPosition().y, 192.f);

    p->setPosition(256.f,192.f);

    p->move(0.f, -1.f);
    ASSERT_LT(p->getPosition().y, 192.f);    //Se il personaggio si muove verso sopra la coordinata y diminuisce
    ASSERT_EQ(p->getPosition().x, 256.f);

    p->setPosition(256.f,192.f);

    p->move(0.f, 1.f);
    ASSERT_GT(p->getPosition().y, 192.f);   //Se il personaggio si muove giù la coordinata y aumenta
    ASSERT_EQ(p->getPosition().x, 256.f);


}

TEST_F(PlayerFixture, TestFindNode) {

    //Success

    pTest->setTileCost(0,0,0);
    pTest->setTileCost(2,0,0);


    pTest->setStartPos(0.f,0.f);
    pTest->setEndPos(128.f,0.f);

    pTest->findNode(window);

    ASSERT_FALSE(pTest->path.empty());
    EXPECT_EQ(pTest->path.front(), sf::Vector2f(0.f, 0.f));
    EXPECT_EQ(pTest->path.back(), sf::Vector2f(128.f, 0.f));

    //Fail

    pTest->path.clear();

    pTest->setTileCost(0,0,0);
    pTest->setTileCost(8,0,9);

    pTest->setStartPos(0.f,0.f);
    pTest->setEndPos(512.f,0.f);

    pTest->findNode(window);

    ASSERT_TRUE(pTest->path.empty());


}

TEST_F(PlayerFixture, TestUpdateMovement) {

    //Left movement

    p->setPath({sf::Vector2f(192.f,192.f), sf::Vector2f(128.f,192.f), sf::Vector2f(64.f,192.f)});

    while(p->getSprite().getPosition().x > 64.f) {

        p->updateMovement(window);
        std::cout << p->getSprite().getPosition().x << std::endl;

        if(p->getSprite().getPosition().x > 64.f) {

            EXPECT_EQ(p->getAnimState(), PLAYER_ANIMATION_STATES::MOVING_LEFT);

        }

    }

    EXPECT_FLOAT_EQ(p->getSprite().getPosition().x, 64.f);
    EXPECT_FLOAT_EQ(p->getSprite().getPosition().y, 192.f);

    //Right movement

    p->setPosition(256.f,192.f);
    p->setCurrentNode(0);

    p->setPath({sf::Vector2f(320.f, 192.f), sf::Vector2f(384.f,192.f)});

    while(p->getSprite().getPosition().x < 384.f) {

        p->updateMovement(window);

        if(p->getSprite().getPosition().x < 384.f) {

            EXPECT_EQ(p->getAnimState(), PLAYER_ANIMATION_STATES::MOVING_RIGHT);

        }


    }

    EXPECT_FLOAT_EQ(p->getSprite().getPosition().x, 384.f);
    EXPECT_FLOAT_EQ(p->getSprite().getPosition().y, 192.f);

    //Up movement

    p->setPosition(256.f,192.f);
    p->setCurrentNode(0);

    p->setPath({sf::Vector2f(256.f, 128.f), sf::Vector2f(256.f,64.f), sf::Vector2f(256.f,0.f)});

    while(p->getSprite().getPosition().y > 0.f) {

        p->updateMovement(window);

        std::cout << p->getSprite().getPosition().y << std::endl;

        if(p->getSprite().getPosition().y > 0.f) {

            EXPECT_EQ(p->getAnimState(), PLAYER_ANIMATION_STATES::MOVING_UP);

        }


    }

    EXPECT_FLOAT_EQ(p->getSprite().getPosition().x, 256.f);
    EXPECT_FLOAT_EQ(p->getSprite().getPosition().y, 0.f);

    //Down movement

    p->setPosition(256.f,192.f);
    p->setCurrentNode(0);

    p->setPath({sf::Vector2f(256.f, 256.f), sf::Vector2f(256.f,320.f), sf::Vector2f(256.f,384.f)});

    while(p->getSprite().getPosition().y < 384.f) {

        p->updateMovement(window);

        std::cout << p->getSprite().getPosition().y << std::endl;

        if(p->getSprite().getPosition().y < 384.f) {
            EXPECT_EQ(p->getAnimState(), PLAYER_ANIMATION_STATES::MOVING_DOWN);
        }


    }

    EXPECT_FLOAT_EQ(p->getSprite().getPosition().x, 256.f);
    EXPECT_FLOAT_EQ(p->getSprite().getPosition().y, 384.f);


}

TEST_F(PlayerFixture, TestUpdateAnimations) {

    //Moving right animation

    p->setAnimState(PLAYER_ANIMATION_STATES::MOVING_RIGHT);
    p->updateAnimations();

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

    //Moving left animation

    p->setAnimState(PLAYER_ANIMATION_STATES::MOVING_LEFT);
    p->updateAnimations();

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

    //Moving down animation

    p->setAnimState(PLAYER_ANIMATION_STATES::MOVING_DOWN);
    p->updateAnimations();

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

    //Moving up animation


    p->setAnimState(PLAYER_ANIMATION_STATES::MOVING_UP);
    p->updateAnimations();

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







