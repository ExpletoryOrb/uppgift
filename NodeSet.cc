#include "NodeSet.h"

#include <string>
#include <vector>
#include <limits>
#include <iostream>

using std::cout;
using std::endl;


void NodeSet::add(Node* node){
	elements.push_back(node);
}

bool NodeSet::isEmpty(){
	bool res{false};
	if(elements.size() == 0){
		res = true;
	}
	return res;
}

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

/*

Node* temp;
	int smallest{std::numeric_limits<int>::max()};
	for(auto s : elements){
        if(s -> getValue() < smallest){
			temp = s;
		}
    }
	return temp;
	
*/