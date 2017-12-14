#include "edge.h"
#include "node.h"

Edge::Edge(Node* destination, int length){
	pdestination = destination;
	edge_length = length;
}

Node* Edge::getDestination(){
	return pdestination;
}

int Edge::getLength() const{
	return edge_length;
}