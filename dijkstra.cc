#include "dijkstra.h"
#include "node_set.h"

#include <string>
#include <vector>
#include <deque>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

string Dijkstra::dijkstraS(Node* start, Node* dest) {
	NodeSet ns{};
	start->setValue(0);
	ns.add(start);
	std::vector<Edge> temp;
	int a;
	
	/** Main algorithm, explained in detail on each row. */
	while (!ns.isEmpty()) {	//runs for all nodes
		Node* n = ns.removeMin(); //returns node and removes it in nodeset
		temp = n->getEdges(); //vector with all edges for a node
		for(unsigned int i = 0; i < temp.size(); ++i) {	//runs for all edges on the node
			a = cost(temp[i]) + n->getValue(); //assignt value depending on cost-function
			if(a < temp[i].getDestination()->getValue()) { //if current node is less then the next node(destination)
				temp[i].getDestination()->setValue(a); //set the value of current node
				temp[i].getDestination()->setParent(n);	//set parent node				
				ns.add(temp[i].getDestination()); //add new node to the nodeset	
				
				if(i == temp.size()-1){
					start_backwards = temp[i].getDestination(); //save last node, used later
				}
			}
		}
	}

	 /** Adds all parents to log */
	std::deque<Node*> backwards_log;
	while(start_backwards->getParent() != 0){
		if(start_backwards->getName()==dest->getName()){
			tempToggle = true;
		}
		if(tempToggle){
			backwards_log.push_front(start_backwards);
		}
		start_backwards = start_backwards -> getParent();
	}
	backwards_log.push_front(start_backwards);
	
	/** Iterate over log and add to output string */
	for(unsigned int i = 0; i < backwards_log.size(); ++i){
		tempString.append(backwards_log[i] -> getName());
		tempString.append("\n");
	}
	if(dest != 0){
		tempString.append(std::to_string(dest->getValue()));
		tempString.append("\n");
	}
	
	/**
	return the number of jumps to destination or the string with which
	route was taken depending on what mode the user chose 
	*/
	return tempString;
}

int Dijkstra::cost(Edge e){
	return e.getLength();
}

int Dijkstra_jumps::cost(Edge e){
	return e.getJump();
}