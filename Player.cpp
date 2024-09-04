//
// Created by sarav on 03/09/2024.
//

#include "Player.h"

Player::Player() {

    this->initTexture();
    this->initSprite();
    this->initVariables();


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

    nodeStart.x = this->sprite.getPosition().x / 96 ;
    nodeStart.y = this->sprite.getPosition().y / 96;

    std::cout << this->sprite.getPosition().x << " " << this->sprite.getPosition().y << std::endl;



    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        sf::Vector2i pixelPos = sf::Mouse::getPosition(target);
        sf::Vector2f worldPos = target.mapPixelToCoords(pixelPos);


        nodeEnd.x = worldPos.x / 96;
        nodeEnd.y = worldPos.y / 96;


    }

    astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

    cout << "Start: " << nodeStart.x << " , " << nodeStart.y << endl;
    cout << "Goal: " << nodeEnd.x << " , " << nodeEnd.y << endl;

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

        node->PrintNodeInfo();
        for( ;; )
        {
            node = astarsearch.GetSolutionNext();

            if( !node )
            {
                break;
            }

            node->PrintNodeInfo();

            sf::Vector2f nextPos(node->x * 96.0f, node->y * 96.0f);

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

           /* std::cout << "Target pos: " << targetPosition.x << ", " << targetPosition.y << std::endl;
            std::cout << "Current pos: " << currentPos.x << ", " << currentPos.y << std::endl;
            std::cout << "Length: " << length << std::endl;
*/

            if (length > 1.5f) {

                direction /= length;
                this->move(this->movementSpeed * direction.x, this->movementSpeed * direction.y);

            } else {

                currentNode++;
            }
        }
    }


void Player::move(const float dir_x, const float dir_y) {

    this->sprite.move(this->movementSpeed * dir_x, this->movementSpeed * dir_y);

}



void Player::initTexture() {

    if(!texture.loadFromFile("assets/textures/character.png")) {

        std::cout << "ERROR: COULD NOT LOAD PLAYER TEXTURE" << std::endl;
    }

}

void Player::initSprite() {

    this->sprite.setTexture(texture);
    this->sprite.setPosition(200.f,300.f);
    this->sprite.setTextureRect(sf::IntRect(32.f, 72.f, 32.f, 36.f));
    this->sprite.setScale(2.f, 2.f);

}

void Player::initVariables() {

    this->movementSpeed = 1.5f;

}

