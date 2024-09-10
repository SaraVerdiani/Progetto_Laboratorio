//
// Created by sarav on 02/09/2024.
//

#include "Game.h"

Game::Game() {

    this->initVariables();
    this->initWindow();
    this->initMap();
    this->initPlayer();

}

Game::~Game() {

}

void Game::run() {

    while(this->window->isOpen()) {

        this->update();
        this->render();

    }

}

void Game::update() {

    this->pollEvents();
    this->player->updateMovement(*this->window);
    this->player->updateAnimations();

}

void Game::render() {

    this->window->clear();

    this->map->drawMap(this->window);

    this->player->render(*this->window);

    this->window->display();

}

void Game::pollEvents() {

    while(this->window->pollEvent(this->event)) {

        switch(this->event.type) {

            case sf::Event::Closed:
                this->window->close();
            break;
            case sf::Event::KeyPressed:
                if(this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
            break;


        }


        //this->pollEventsTest(this->event);   //TESTING
    }

}
/*

void Game::pollEventsTest(sf::Event &e) {

        switch(e.type) {

            case sf::Event::Closed:
                this->window->close();
            break;
            case sf::Event::KeyPressed:
                if(this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
            break;

        }

}
*/

sf::RenderWindow * Game::getWindow() const {

    return this->window;

}

int Game::getFrameRateLimit() const {

    return this->frameRateLimit;

}

bool Game::getVerticalSync() const {

    return this->isVerticalSyncEnabled;
}

Map * Game::getMap() const {

    return this->map;
}

Player * Game::getPlayer() const {

    return this->player;
}




void Game::initWindow() {

    this->window = new sf::RenderWindow(sf::VideoMode(1920,1024),"A* algorithm", sf::Style::Default);
    this->window->setFramerateLimit(frameRateLimit);
    this->window->setVerticalSyncEnabled(isVerticalSyncEnabled);

}

void Game::initMap() {

    this->map = new Map();

}

void Game::initPlayer() {

    this->player = new Player();
}

void Game::initVariables() {

    this->frameRateLimit = 144;
    this->isVerticalSyncEnabled = false;

}

