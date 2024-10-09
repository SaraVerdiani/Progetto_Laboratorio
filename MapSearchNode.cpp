//
// Created by sarav on 03/09/2024.
//

#include "MapSearchNode.h"
                                                 // 0 -> il personaggio può passare

                                                // 9 -> il personaggio non può passare

int GetMap( int x, int y )
{
	if( x < 0 ||
	    x >= MAP_WIDTH ||
		 y < 0 ||
		 y >= MAP_HEIGHT
	  )
	{
		return 9;
	}

	return world_map[x][y];
}

bool MapSearchNode::IsSameState( MapSearchNode &rhs )
{


	if( (x == rhs.x) &&
		(y == rhs.y) )
	{
		return true;
	}
	else
	{
		return false;
	}

}

size_t MapSearchNode::Hash()
{
	size_t h1 = hash<float>{}(x);
	size_t h2 = hash<float>{}(y);
	return h1 ^ (h2 << 1);
}

void MapSearchNode::PrintNodeInfo()
{
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


float MapSearchNode::GoalDistanceEstimate( MapSearchNode &nodeGoal )
{
	return abs(x - nodeGoal.x) + abs(y - nodeGoal.y);
}

bool MapSearchNode::IsGoal( MapSearchNode &nodeGoal )
{

	if( (x == nodeGoal.x) &&
		(y == nodeGoal.y) )
	{
		return true;
	}

	return false;
}

bool MapSearchNode::GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node )
{

	int parent_x = -1;
	int parent_y = -1;

	if( parent_node )
	{
		parent_x = parent_node->x;
		parent_y = parent_node->y;
	}


	MapSearchNode NewNode;


	if( (GetMap( x-1, y ) < 9)
		&& !((parent_x == x-1) && (parent_y == y))
	  )
	{
		NewNode = MapSearchNode( x-1, y );
		astarsearch->AddSuccessor( NewNode );
	}

	if( (GetMap( x, y-1 ) < 9)
		&& !((parent_x == x) && (parent_y == y-1))
	  )
	{
		NewNode = MapSearchNode( x, y-1 );
		astarsearch->AddSuccessor( NewNode );
	}

	if( (GetMap( x+1, y ) < 9)
		&& !((parent_x == x+1) && (parent_y == y))
	  )
	{
		NewNode = MapSearchNode( x+1, y );
		astarsearch->AddSuccessor( NewNode );
	}


	if( (GetMap( x, y+1 ) < 9)
		&& !((parent_x == x) && (parent_y == y+1))
		)
	{
		NewNode = MapSearchNode( x, y+1 );
		astarsearch->AddSuccessor( NewNode );
	}

	return true;
}

float MapSearchNode::GetCost( MapSearchNode &successor )
{
	return (float) GetMap( x, y );

}

