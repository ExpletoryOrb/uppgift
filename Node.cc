#include "Edge.h"
#include "Node.h"
#include <string>
#include <vector>

using std::string;

Node::Node(const string& name){
	node_name = name;
}

string Node::getName() const{
	return node_name;	
}

void Node::setValue(int v){
	value = v;
}

int Node::getValue() const{
	return value;
}


void Node::addEdge(Node* destination, int length){
	Edge e(destination, length);
	edges.push_back(e);
}

const std::vector<Edge>& Node::getEdges() const{
	return edges;
}