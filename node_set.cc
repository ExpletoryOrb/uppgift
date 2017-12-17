#include "node_set.h"

#include <string>
#include <vector>
#include <limits>
#include <iostream>

using std::cout;
using std::endl;

/** Add new Node* to the set */
void NodeSet::add(Node* node){
	elements.push_back(node);
}

/** Returns true if the set is empty */
bool NodeSet::isEmpty(){
	bool res{false};
	if(elements.size() == 0){
		res = true;
	}
	return res;
}

/** Returns the node in the set with the smallest value and removes it from the set */
Node* NodeSet::removeMin(){
	if(elements.size() == 0){
		return 0; // return null;
	}else{
		int smallest{std::numeric_limits<int>::max()};
		Node* temp = 0; //null 
		unsigned int j = 0;
		for(unsigned int i = 0; i < elements.size(); ++i){
			if(elements[i] -> getValue() < smallest){
				temp = elements[i];
				smallest = elements[i] -> getValue();
				j = i;
			}
		}
	elements.erase(elements.begin()+j);
	return temp;
	}
}