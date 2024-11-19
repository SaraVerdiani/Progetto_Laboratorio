//
// Created by sarav on 03/09/2024.
//

#ifndef MAPSEARCHNODE_H
#define MAPSEARCHNODE_H

#include <array>
#include "stlastar.h"

class MapSearchNode {

public:
    MapSearchNode();
    MapSearchNode( int px, int py );
    float goalDistanceEstimate( MapSearchNode &nodeGoal ) const;
    bool isGoal( MapSearchNode &nodeGoal ) const;
    int getMapNode(int x, int y) const;
    bool getSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node ) const;
    float getCost( MapSearchNode &successor ) const;
    bool isSameState( MapSearchNode &rhs ) const;
    size_t aStarHash();
    void printNodeInfo() const;
    int getX() const;
    int getY() const;
    void setX(int newX);
    void setY(int newY);
    static void setNodeCost(int x, int y, int cost);

private:
    static std::array<std::array<int, 16>, 30> nodeMap;
    int x;
    int y;
};

#endif //MAPSEARCHNODE_H
