//
// Created by sarav on 03/09/2024.
//

#ifndef MAPSEARCHNODE_H
#define MAPSEARCHNODE_H

#include "stlastar.h"


const int MAP_HEIGHT = 16;
const int MAP_WIDTH = 30;
inline int world_map[MAP_WIDTH][MAP_HEIGHT];

class MapSearchNode {

public:
    MapSearchNode();
    MapSearchNode( int px, int py );
    float goalDistanceEstimate( MapSearchNode &nodeGoal ) const;
    bool isGoal( MapSearchNode &nodeGoal ) const;
    bool getSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float getCost( MapSearchNode &successor ) const;
    bool isSameState( MapSearchNode &rhs ) const;
    size_t aStarHash();
    void printNodeInfo() const;
    int getX() const;
    int getY() const;
    void setX(int newX);
    void setY(int newY);

private:
    int x;
    int y;
};

#endif //MAPSEARCHNODE_H
