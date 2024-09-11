#include "gtest/gtest.h"
#include "../Game.h"

class GameFixture : public ::testing::Test {

public:

    virtual void SetUp() {

        g = new Game();

    }

protected:
    Game* g = nullptr;

};

TEST_F(GameFixture, TestPollEventsClosed) {

    sf::Event event;
    event.type = sf::Event::Closed;
    g->pollEventsTest(event);

    ASSERT_FALSE(g->getWindow()->isOpen());


}

TEST_F(GameFixture, TestPollEventsKeyPressed) {

    sf::Event event;
    event.key.code = sf::Keyboard::Escape;

    g->pollEventsTest(event);

    ASSERT_FALSE(g->getWindow()->isOpen());

}