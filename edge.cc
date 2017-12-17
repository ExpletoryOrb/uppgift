#include "edge.h"
#include "node.h"

/** Creates new Edge from current node to destination with the given length */
Edge::Edge(Node* destination, int length){
	pdestination = destination;
	edge_length = length;
}

/** Returns the destination Node* */ 
Node* Edge::getDestination(){
	return pdestination;
}

/** Returns length */
int Edge::getLength() const{
	return edge_length;
}

/** Sets the length to the given value */
void Edge::setLength(int length){
	edge_length = edge_length + length;
}