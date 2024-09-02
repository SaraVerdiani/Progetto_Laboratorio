//
// Created by sarav on 02/09/2024.
//

#include "Game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::run() {

}

void Game::update() {

}

void Game::render() {

}

void Game::initWindow() {

    this->window = new sf::RenderWindow(sf::VideoMode(1184,1024),"A* algorithm", sf::Style::Default);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);

}

