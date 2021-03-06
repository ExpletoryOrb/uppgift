#ifndef EDGE_H
#define EDGE_H

#include "node.h"
#include <string>

using std::string;

class Node;

class Edge{
	public:
		Edge(Node* destination, int length);
		Node* getDestination();
		int getLength() const;
		int getJump() const;
	
	private:
		Node* pdestination;
		int edge_length{0};
};
#endif