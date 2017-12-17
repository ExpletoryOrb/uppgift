#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::string;

class Graph{
	public:
		Graph() : nodes() {};
		Graph(std::istream& in);
		void addNode(const string& name);
		Node* find(const string& name);
		void resetValues();
		bool contains(const string& name);

	private:
	std::vector<Node*> nodes;
};
#endif