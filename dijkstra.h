#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "node.h"
#include <string>
#include <vector>

using std::string;

class Node;
class Edge;

class Dijkstra{
	public:
		Dijkstra(){};
		string dijkstraS(Node* start, int val);
		
	private:
		string tempString;
}; 
#endif