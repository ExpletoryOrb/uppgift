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
		virtual ~Node(){};
		Node(const Node&) = default;
		Node(Node&&) = default;
		Node& operator=(const Node&)& = default;
		Node& operator=(Node&&)& = default;
		
		string getName() const;
		void setValue(int v);
		int getValue()const;
		void addEdge(Node* destination, int length);
		const std::vector<Edge>& getEdges() const;
		void setParent(Node*& node);
		Node* getParent();
		
	private:
		string node_name;
		int value;
		Node* parent;
		std::vector<Edge> edges;
		
};
#endif