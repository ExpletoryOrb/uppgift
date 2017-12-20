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
		string dijkstraS(Node* start, Node* dest);
		virtual ~Dijkstra() = default;
		
	protected:
		string tempString;
	private:
		virtual int cost(Edge e);
		Node* start_backwards;
		bool tempToggle = false;
}; 

class Dijkstra_jumps : public Dijkstra{
	public:
		using Dijkstra::Dijkstra;
		using Dijkstra::dijkstraS;
		int cost(Edge e);
		
	private:	
};
#endif