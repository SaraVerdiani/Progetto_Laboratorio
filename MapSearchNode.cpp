//
// Created by sarav on 03/09/2024.
//

#include "MapSearchNode.h"

std::array<std::array<int, 16>, 30> MapSearchNode::nodeMap = {};

int MapSearchNode::getMapNode( int x, int y ) const {
	if( x < 0 ||
	    x >= 30 ||
		 y < 0 ||
		 y >= 16
	  ) {
		return 9;
	}

	return nodeMap[x][y];
}

bool MapSearchNode::isSameState( MapSearchNode &rhs ) const {

	if( (x == rhs.x) &&
		(y == rhs.y) ) {
		return true;
	}
	else {
		return false;
	}
}

size_t MapSearchNode::aStarHash() {
	size_t h1 = hash<float>{}(x);
	size_t h2 = hash<float>{}(y);
	return h1 ^ (h2 << 1);
}

void MapSearchNode::printNodeInfo() const {
  const int strSize = 100;
	char str[strSize];
	snprintf( str, strSize, "Node position : (%d,%d)\n", x,y );

	cout << str;
}

int MapSearchNode::getX() const {

	return x;
}

int MapSearchNode::getY() const {

	return y;
}

void MapSearchNode::setX(int newX) {

	x = newX;
}

void MapSearchNode::setY(int newY) {

	y = newY;
}

void MapSearchNode::setNodeCost(int x, int y, int cost) {

	nodeMap[x][y] = cost;
}


MapSearchNode::MapSearchNode() {

	x = y = 0;
}

MapSearchNode::MapSearchNode(int px, int py) {

	x=px;
	y=py;
}

float MapSearchNode::goalDistanceEstimate( MapSearchNode &nodeGoal ) const{

	return abs(x - nodeGoal.x) + abs(y - nodeGoal.y);
}

bool MapSearchNode::isGoal( MapSearchNode &nodeGoal ) const {

	if( (x == nodeGoal.x) &&
		(y == nodeGoal.y) ) {
		return true;
	}

	return false;
}

bool MapSearchNode::getSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node ) const {

	int parent_x = -1;
	int parent_y = -1;

	if( parent_node ) {
		parent_x = parent_node->x;
		parent_y = parent_node->y;
	}

	MapSearchNode NewNode;

	if( (getMapNode( x-1, y ) < 9)
		&& !((parent_x == x-1) && (parent_y == y))
	  ) {
		NewNode = MapSearchNode( x-1, y );
		astarsearch->AddSuccessor( NewNode );
	}

	if( (getMapNode( x, y-1 ) < 9)
		&& !((parent_x == x) && (parent_y == y-1))
	  ) {
		NewNode = MapSearchNode( x, y-1 );
		astarsearch->AddSuccessor( NewNode );
	}

	if( (getMapNode( x+1, y ) < 9)
		&& !((parent_x == x+1) && (parent_y == y))
	  ) {
		NewNode = MapSearchNode( x+1, y );
		astarsearch->AddSuccessor( NewNode );
	}

	if( (getMapNode( x, y+1 ) < 9)
		&& !((parent_x == x) && (parent_y == y+1))
		) {
		NewNode = MapSearchNode( x, y+1 );
		astarsearch->AddSuccessor( NewNode );
	}

	return true;
}

float MapSearchNode::getCost( MapSearchNode &successor ) const {

	return (float) getMapNode( x, y );
}

