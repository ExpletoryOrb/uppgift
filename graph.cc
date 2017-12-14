#include "graph.h"
#include "edge.h"
#include "node.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <limits>

using std::string;
using std::cout;
using std::endl;

Graph::Graph(std::istream& in){
	string words, temp, a, b, c;
	char delimiter1(':');
	char delimiter2(' ');

	while(getline(in, words)) {
		a = words.substr(0, words.find(delimiter1));
		temp = words.substr(words.find(delimiter1)+2);
		b = temp.substr(0, temp.find(delimiter2));
		c = temp.substr(temp.find(delimiter2)+1);
		cout << a << "  ";
		cout << b << "  ";
		cout << c << endl;
	}
}

void Graph::addNode(const string& name){
	/**
	FIX
	*/
}

Node* Graph::find(const string& name){
	Node* temp = 0; // set to null
	
	for(unsigned int i = 0; i < nodes.size(); ++i){
		cout << "name: " << name << " nodes[i]-> get Name(): " << nodes[i]->getName() << std::endl;
		if(name.compare(nodes[i] -> getName())){
			temp = nodes[i];
		}
	}
	return temp;
}

void Graph::resetValues(){
	for(unsigned int i = 0; i < nodes.size(); ++i){
		nodes[i] -> setValue(std::numeric_limits<int>::max());
	}
}










