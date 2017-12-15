#include "edge.h"
#include "node.h"
#include <string>
#include <vector>
#include <limits>

using std::string;

Node::Node(const string& name){
	node_name = name;
	parent = 0; //null
	value = std::numeric_limits<int>::max();
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

void Node::setParent(Node*& node){
	parent = node;
}
	
Node* Node::getParent(){
	return parent;
}