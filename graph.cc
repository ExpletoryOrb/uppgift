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
using std::numeric_limits;

/** Creates new graph from infile */
Graph::Graph(std::istream& in){
	string words, city1, distance, city2;
	char delimiter1(':');
	char delimiter2(' ');
	
	while(getline(in, words)){
		city1 = words.substr(0, words.find(delimiter1));
		words = words.substr(words.find(delimiter1)+2);
		distance = words.substr(0, words.find(delimiter2));
		city2 = words.substr(words.find(delimiter2)+1, (words.length() - words.find(delimiter2)-2));
		
		addNode(city1);
		addNode(city2);
		
		Node* city_from_node = find(city1);
		Node* city_destination = find(city2);

		city_from_node -> addEdge(city_destination, std::stoi(distance));
	}
}

Graph::~Graph(){
	for(Node* n : nodes){
		delete n;
	}
}

/** Add node with the given name to nodes if it does not yet exist */
void Graph::addNode(const string& name){
	if(!(contains(name))){
		nodes.push_back(new Node(name));
	}
}

/** Finds Node* with the given name if it exists in nodes. */
Node* Graph::find(const string& name){
	Node* temp = 0; // set to null
	for(unsigned int i = 0; i < nodes.size(); ++i){
		if(!name.compare(nodes[i] -> getName())){
			temp = nodes[i];
		}
	}
	return temp;
}

/** Reset all Node*'s values in nodes to <int>Max */
void Graph::resetValues(){
	for(unsigned int i = 0; i < nodes.size(); ++i){
		nodes[i] -> setValue(numeric_limits<int>::max());
	}
}

/** Returns true if nodes contains a Node* with the given name */
bool Graph::contains(const string& name){
	bool result{false};
	for(unsigned int i = 0; i < nodes.size(); ++i){
		if(name.compare(nodes[i] -> getName()) == 0){
			result = true;
		}
	}
	return result;
}