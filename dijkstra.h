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
		string dijkstraS(Node* start);
		int cost();
		
	protected:
		string tempString;
}; 

class Dijkstra_dist : public Dijkstra{
	public:
		using Dijkstra::Dijkstra;
		using Dijkstra::dijkstraS;
		int cost();
	
	private:
		
};

class Dijkstra_jumps : public Dijkstra{
	public:
		using Dijkstra::Dijkstra;
		using Dijkstra::dijkstraS;
		int cost();
		
	private:
		
};
#endif