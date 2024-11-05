//
// Created by sarav on 02/09/2024.
//

#include "Game.h"

Game::Game() {

    initVariables();
    initWindow();
    initMap();
    initPlayer();
}

Game::~Game() {

    delete map;
    delete player;
    delete window;
}

void Game::run() {

    while(window->isOpen()) {
        update();
        render();
    }
}

void Game::update() {

    pollEvents();
    player->updateMovement(*window);
    player->updateAnimations();
}

void Game::render() const {

    window->clear();
    map->drawMap(window);
    player->render(*window);
    window->display();
}

void Game::pollEvents() {

    while(window->pollEvent(event)) {

        switch(event.type) {

            case sf::Event::Closed:
                window->close();
            break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape)
                    window->close();
            break;
        }
    }
}

sf::RenderWindow * Game::getWindow() const {

    return window;
}

int Game::getFrameRateLimit() const {

    return frameRateLimit;
}

bool Game::getVerticalSync() const {

    return isVerticalSyncEnabled;
}

Map * Game::getMap() const {

    return map;
}

Player * Game::getPlayer() const {

    return player;
}

void Game::initWindow() {

    window = new sf::RenderWindow(sf::VideoMode(1920,1024),"A* algorithm", sf::Style::Default);
    window->setFramerateLimit(frameRateLimit);
    window->setVerticalSyncEnabled(isVerticalSyncEnabled);
}

void Game::initMap() {

    map = new Map();
    map->initNodeMap();
}

void Game::initPlayer() {

    player = new Player();
}

void Game::initVariables() {

    frameRateLimit = 144;
    isVerticalSyncEnabled = false;
}

