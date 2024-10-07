#include "gtest/gtest.h"
#include "../Game.h"

class GameFunctionTest : public Game {
public:

    GameFunctionTest() {

        window.create(sf::VideoMode(1920,1024),"TestWindow");
    }

    void pollEvents() override {

        sf::Event closeEvent;
        closeEvent.type = sf::Event::Closed;

        sf::Event escapeEvent;
        escapeEvent.type = sf::Event::KeyPressed;
        escapeEvent.key.code = sf::Keyboard::Escape;

        handleEvent(closeEvent);
        handleEvent(escapeEvent);

    }

    void handleEvent(const sf::Event& event) {

        switch (event.type) {
            case sf::Event::Closed:
                this->window.close();
            break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    this->window.close();
            break;
        }
    }

    sf::RenderWindow window;
};

class GameFixture : public ::testing::Test {

public:

    virtual void SetUp() {

        gameTest = new GameFunctionTest();

    }

protected:
    GameFunctionTest* gameTest = nullptr;
    sf::RenderWindow window;
};

TEST_F(GameFixture, TestPollEvents) {


    gameTest->pollEvents();

    ASSERT_FALSE(gameTest->window.isOpen());


}