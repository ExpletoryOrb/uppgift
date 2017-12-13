#ifndef NODESET_H
#define NODESET_H

#include "Node.h"
#include <string>
#include <vector>

class NodeSet{
	public:
		NodeSet() : elements() {};
		void add(Node* node);
		bool isEmpty();
		Node* removeMin();
		
	private:
	std::vector<Node*> elements;
};
#endif