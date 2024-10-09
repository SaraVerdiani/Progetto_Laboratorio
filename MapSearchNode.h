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

    MapSearchNode() { x = y = 0; }
    MapSearchNode( int px, int py ) { x=px; y=py; }

    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );
    size_t Hash();
    void PrintNodeInfo();
    int getX() const;
    int getY() const;
    void setX(int newX);
    void setY(int newY);


private:
    int x;
    int y;



};
#endif //MAPSEARCHNODE_H
