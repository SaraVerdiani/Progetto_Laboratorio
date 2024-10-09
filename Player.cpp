//
// Created by sarav on 03/09/2024.
//

#include "Player.h"

Player::Player() {

    this->initTexture();
    this->initSprite();
    this->initVariables();
    this->initAnimations();


}

Player::~Player() {

}



void Player::render(sf::RenderTarget &target) {

    target.draw(this->sprite);

}


void Player::findNode(sf::RenderWindow &target) {

    AStarSearch<MapSearchNode> astarsearch;

    MapSearchNode nodeStart;
    MapSearchNode nodeEnd;

    nodeStart.setX(this->sprite.getPosition().x / 64);
    nodeStart.setY(this->sprite.getPosition().y / 64);

    std::cout << this->sprite.getPosition().x << " " << this->sprite.getPosition().y << std::endl;


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

        this->path.clear();
        this->currentNode = 0;

        this->path.push_back(this->sprite.getPosition());

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

            this->path.push_back(nextPos);

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

            this->findNode(target);
            mouseWasPressed = true;

        }

    } else {
        mouseWasPressed = false;
    }

        if (!path.empty() && currentNode < path.size()) {

            sf::Vector2f currentPos = this->sprite.getPosition();
            sf::Vector2f targetPosition = path[currentNode];

            sf::Vector2f direction = targetPosition - currentPos;
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);


            if (length > 1.5f) {

                direction /= length;
                this->move(this->movementSpeed * direction.x, this->movementSpeed * direction.y);

                if (std::fabs(direction.x) > std::fabs(direction.y)) {
                    if (direction.x > 0) {
                        this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
                    } else {
                        this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
                    }
                } else {

                    if (direction.y > 0) {
                        this->animState = PLAYER_ANIMATION_STATES::MOVING_DOWN;
                    } else {
                        this->animState = PLAYER_ANIMATION_STATES::MOVING_UP;
                    }
                }

            } else {

                this->sprite.setPosition(targetPosition);
                currentNode++;

                if (currentNode >= path.size()) {

                    this->animState = PLAYER_ANIMATION_STATES::NOT_MOVING;

                }
            }
        }
    }

void Player::updateAnimations() {

    if(this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT) {

        if(this->animationTimer.getElapsedTime().asSeconds() >= 0.15f) {
            this->currentFrame.top = 36.f;
            this->currentFrame.left += 32.f;

            if(this->currentFrame.left >= 96.f)
                this->currentFrame.left = 0.f;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }

    if(this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT) {

        if(this->animationTimer.getElapsedTime().asSeconds() >= 0.15f) {

            this->currentFrame.top = 108.f;
            this->currentFrame.left += 32.f;

            if(this->currentFrame.left >= 96.f)
                this->currentFrame.left = 0.f;


            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);


        }
    }

    if(this->animState == PLAYER_ANIMATION_STATES::MOVING_DOWN) {

        if(this->animationTimer.getElapsedTime().asSeconds() >= 0.15f) {

            this->currentFrame.top = 72.f;
            this->currentFrame.left += 32.f;

            if(this->currentFrame.left >= 96.f)
                this->currentFrame.left = 0.f;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }

    if(this->animState == PLAYER_ANIMATION_STATES::MOVING_UP) {

        if(this->animationTimer.getElapsedTime().asSeconds() >= 0.15f) {

            this->currentFrame.top =0.f;
            this->currentFrame.left += 32.f;

            if(this->currentFrame.left >= 96.f)
                this->currentFrame.left = 0.f;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }
}


void Player::move(const float dir_x, const float dir_y) {

    this->sprite.move(this->movementSpeed * dir_x, this->movementSpeed * dir_y);

}


float Player::getMovementSpeed() const {

    return this->movementSpeed;
}

sf::Sprite Player::getSprite() const {

    return this->sprite;
}

sf::Texture Player::getTexture() const {

    return this->texture;
}

sf::Vector2f Player::getPosition() const {

    return this->sprite.getPosition();
}

void Player::setCurrentNode(int node) {

    currentNode = node;
}

sf::IntRect Player::getCurrentFrame() const {

    return this->currentFrame;
}

void Player::setMovementSpeed(const float movementSpeed) {

    this->movementSpeed = movementSpeed;
}

void Player::setPosition(const float x, const float y) {

    this->sprite.setPosition(x, y);
}

std::vector<sf::Vector2f> Player::getPath() const {

    return this->path;
}

void Player::setPath(const std::vector<sf::Vector2f> &path) {

    this->path = path;

}

short Player::getAnimState() const {

    return this->animState;
}

void Player::setAnimState(const short animState) {

    this->animState = animState;
}

sf::Clock Player::getAnimationTimer() const {

    return this->animationTimer;
}


void Player::initTexture() {

    if(!texture.loadFromFile("assets/textures/character.png")) {

        std::cout << "ERROR: COULD NOT LOAD PLAYER TEXTURE" << std::endl;
    }

}

void Player::initSprite() {

    this->sprite.setTexture(texture);
    this->sprite.setPosition(200.f,300.f);
    this->currentFrame = sf::IntRect(32.f, 72.f, 32.f, 36.f);
    this->sprite.setTextureRect(this->currentFrame);  //!
    this->sprite.setScale(2.f, 2.f);

}

void Player::initVariables() {

    this->movementSpeed = 1.5f;
    this->currentNode = 0;
    this->animState = NOT_MOVING;

}

void Player::initAnimations() {

    this->animationTimer.restart();

}