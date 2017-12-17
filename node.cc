#include "edge.h"
#include "node.h"
#include <string>
#include <vector>
#include <limits>

using std::string;

/** Creates new node with the given name */
Node::Node(const string& name){
	node_name = name;
	parent = 0; //null
	value = std::numeric_limits<int>::max();
}

/** Returns the name */
string Node::getName() const{
	return node_name;	
}

/** Sets the Nodes value to the given one*/
void Node::setValue(int v){
	value = v;
}

/** Returns the value */
int Node::getValue() const{
	return value;
}

/** Adds new Edge from this node to the given destination with the given length */
void Node::addEdge(Node* destination, int length){
	Edge e(destination, length);
	edges.push_back(e);
}

/** Returns a vector with the Edges from this node */
const std::vector<Edge>& Node::getEdges() const{
	return edges;
}

/** Sets this node's parent to the given node */
void Node::setParent(Node*& node){
	parent = node;
}
	
/** Returns this node's parent */
Node* Node::getParent(){
	return parent;
}