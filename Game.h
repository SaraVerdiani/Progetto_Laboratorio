//
// Created by sarav on 02/09/2024.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Map.h"
#include "Player.h"

class Game {

public:
    Game();
    ~Game();
    void run();
    void update();
    void render() const;
    virtual void pollEvents();
    sf::RenderWindow* getWindow() const;
    int getFrameRateLimit() const;
    bool getVerticalSync() const;
    Map* getMap() const;
    Player* getPlayer() const;

private:
    sf::RenderWindow* window;
    sf::Event event;
    int frameRateLimit;
    bool isVerticalSyncEnabled;
    Map* map;
    Player* player;
    void initWindow();
    void initMap();
    void initPlayer();
    void initVariables();

};

#endif //GAME_H
