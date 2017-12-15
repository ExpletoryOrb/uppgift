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
	
		string dijkstra(Node* start);
		string dijkstra(Node* start, int alternative);
		string print(Node* start_backwards);
	private:
}; 
#endif