//
// Created by sarav on 02/09/2024.
//

#include "Game.h"

Game::Game() {

    this->initWindow();

}

Game::~Game() {

}

void Game::run() {

}

void Game::update() {

    this->pollEvents();

}

void Game::render() {

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
    }

}

void Game::initWindow() {

    this->window = new sf::RenderWindow(sf::VideoMode(1184,1024),"A* algorithm", sf::Style::Default);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);

}

