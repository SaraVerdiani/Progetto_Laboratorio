//
// Created by sarav on 03/09/2024.
//

#ifndef MAPSEARCHNODE_H
#define MAPSEARCHNODE_H

#include "stlastar.h"



class MapSearchNode {

public:

    int x;	 // the (x,y) positions of the node
    int y;

    MapSearchNode() { x = y = 0; }
    MapSearchNode( int px, int py ) { x=px; y=py; }

    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );
    size_t Hash();

    void PrintNodeInfo();



};



#endif //MAPSEARCHNODE_H
