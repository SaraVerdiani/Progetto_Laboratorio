//
// Created by sarav on 03/09/2024.
//

#include "Player.h"

Player::Player() {

    initTexture();
    initSprite();
    initVariables();
    initAnimations();
}

Player::~Player() {

}



void Player::render(sf::RenderTarget &target) const {

    target.draw(sprite);
}


void Player::findNode(sf::RenderWindow &target) {

    AStarSearch<MapSearchNode> astarsearch;

    MapSearchNode nodeStart;
    MapSearchNode nodeEnd;

    nodeStart.setX(sprite.getPosition().x / 64);
    nodeStart.setY(sprite.getPosition().y / 64);

    std::cout << sprite.getPosition().x << " " << sprite.getPosition().y << std::endl;

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        sf::Vector2i pixelPos = sf::Mouse::getPosition(target);
        sf::Vector2f worldPos = target.mapPixelToCoords(pixelPos);

        nodeEnd.setX(worldPos.x / 64);
        nodeEnd.setY(worldPos.y / 64);

    }

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
        path.clear();
        currentNode = 0;
        path.push_back(this->sprite.getPosition());
        int steps = 0;
        node->printNodeInfo();

        for( ;; )
        {
            node = astarsearch.GetSolutionNext();

            if( !node )
            {
                break;
            }

            node->printNodeInfo();
            sf::Vector2f nextPos(node->getX() * 64.f, node->getY() * 64.0f);
            path.push_back(nextPos);
            steps ++;

        };

        cout << "Solution steps " << steps << endl;
        astarsearch.FreeSolutionNodes();
    }

    if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED)
        cout << "Search failed\n";

}

void Player::updateMovement(sf::RenderWindow &target) {

    static bool mouseWasPressed = false;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        if (!mouseWasPressed) {

            findNode(target);
            mouseWasPressed = true;
        }

    } else {

        mouseWasPressed = false;
    }

        if (!path.empty() && currentNode < path.size()) {

            sf::Vector2f currentPos = sprite.getPosition();
            sf::Vector2f targetPosition = path[currentNode];
            sf::Vector2f direction = targetPosition - currentPos;
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

            if (length > 1.5f) {

                direction /= length;
                this->move(movementSpeed * direction.x, movementSpeed * direction.y);

                if (std::fabs(direction.x) > std::fabs(direction.y)) {
                    if (direction.x > 0) {
                        animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
                    } else {
                        animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
                    }
                } else {
                    if (direction.y > 0) {
                        animState = PLAYER_ANIMATION_STATES::MOVING_DOWN;
                    } else {
                        animState = PLAYER_ANIMATION_STATES::MOVING_UP;
                    }
                }

            } else {
                sprite.setPosition(targetPosition);
                currentNode++;

                if (currentNode >= path.size()) {

                    animState = PLAYER_ANIMATION_STATES::NOT_MOVING;
                }
            }
        }
    }

void Player::updateAnimations() {

    if(animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT) {

        if(animationTimer.getElapsedTime().asSeconds() >= 0.15f) {
            currentFrame.top = 36.f;
            currentFrame.left += 32.f;

            if(currentFrame.left >= 96.f)
                currentFrame.left = 0.f;

            animationTimer.restart();
            sprite.setTextureRect(this->currentFrame);
        }
    }

    if(animState == PLAYER_ANIMATION_STATES::MOVING_LEFT) {

        if(animationTimer.getElapsedTime().asSeconds() >= 0.15f) {

            currentFrame.top = 108.f;
            currentFrame.left += 32.f;

            if(currentFrame.left >= 96.f)
                currentFrame.left = 0.f;


            animationTimer.restart();
            sprite.setTextureRect(currentFrame);
        }
    }

    if(animState == PLAYER_ANIMATION_STATES::MOVING_DOWN) {

        if(animationTimer.getElapsedTime().asSeconds() >= 0.15f) {

            currentFrame.top = 72.f;
            currentFrame.left += 32.f;

            if(currentFrame.left >= 96.f)
                currentFrame.left = 0.f;

            animationTimer.restart();
            sprite.setTextureRect(this->currentFrame);
        }
    }

    if(animState == PLAYER_ANIMATION_STATES::MOVING_UP) {

        if(animationTimer.getElapsedTime().asSeconds() >= 0.15f) {

            currentFrame.top =0.f;
            currentFrame.left += 32.f;

            if(currentFrame.left >= 96.f)
                currentFrame.left = 0.f;

            animationTimer.restart();
            sprite.setTextureRect(this->currentFrame);
        }
    }
}


void Player::move(const float dir_x, const float dir_y) {

    sprite.move(movementSpeed * dir_x, movementSpeed * dir_y);
}


float Player::getMovementSpeed() const {

    return movementSpeed;
}

sf::Sprite Player::getSprite() const {

    return sprite;
}

sf::Texture Player::getTexture() const {

    return texture;
}

sf::Vector2f Player::getPosition() const {

    return sprite.getPosition();
}

void Player::setCurrentNode(int node) {

    currentNode = node;
}

sf::IntRect Player::getCurrentFrame() const {

    return currentFrame;
}

void Player::setMovementSpeed(const float newMovementSpeed) {

    movementSpeed = newMovementSpeed;
}

void Player::setPosition(const float x, const float y) {

    sprite.setPosition(x, y);
}

std::vector<sf::Vector2f> Player::getPath() const {

    return path;
}

void Player::setPath(const std::vector<sf::Vector2f> &newPath) {

    path = newPath;
}

short Player::getAnimState() const {

    return animState;
}

void Player::setAnimState(const short newAnimState) {

    animState = newAnimState;
}

sf::Clock Player::getAnimationTimer() const {

    return animationTimer;
}


void Player::initTexture() {

    if(!texture.loadFromFile("assets/textures/character.png")) {

        std::cout << "ERROR: COULD NOT LOAD PLAYER TEXTURE" << std::endl;
    }
}

void Player::initSprite() {

    sprite.setTexture(texture);
    sprite.setPosition(200.f,300.f);
    currentFrame = sf::IntRect(32.f, 72.f, 32.f, 36.f);
    sprite.setTextureRect(this->currentFrame);
    sprite.setScale(2.f, 2.f);
}

void Player::initVariables() {

    movementSpeed = 1.5f;
    currentNode = 0;
    animState = NOT_MOVING;
}

void Player::initAnimations() {

    animationTimer.restart();
}