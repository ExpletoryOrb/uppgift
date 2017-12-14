#ifndef NODE_H
#define NODE_H

#include "edge.h"
#include <string>
#include <vector>
#include <limits>

using std::string;

class Edge;

class Node{
	public:
		Node(const string& name);
		string getName() const;
		void setValue(int v);
		int getValue()const;
		void addEdge(Node* destination, int length);
		const std::vector<Edge>& getEdges() const;
		
	private:
		string node_name;
		int value;
		std::vector<Edge> edges;
};
#endif