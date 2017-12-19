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

string Dijkstra::dijkstraS(Node* start) {
	NodeSet ns{};
	start->setValue(0);
	ns.add(start);

	std::vector<Edge> temp;
	int a;
	Node* start_backwards;
	
	/** Main algorithm, explained in detail on each row. */
	while (!ns.isEmpty()) {//runs for all nodes
		Node* n = ns.removeMin();//returns node and removes it in nodeset
		temp = n->getEdges();//vector with all edges for a node
		for(unsigned int i = 0; i < temp.size(); ++i) {//runs for all edges on the node
			temp[i].setLength(0);// 0 == shortest distance in (km), 10000 (high value) == shortest distance in number of nodes passed
			a = temp[i].getLength() + n->getValue();//set the value of current node
			if(a < temp[i].getDestination()->getValue()) {//if current node is less then the next node(destination)
				temp[i].getDestination()->setValue(a);//set destiantion_value -> length + value
				temp[i].getDestination()->setParent(n);//set parent node
				ns.add(temp[i].getDestination());//add new node to the nodeset
				if(i == temp.size()-1){
					start_backwards = temp[i].getDestination(); //save last node, used later
				}
			}
		}
	}
	
	/** Adds all parents to log */
	std::deque<Node*> backwards_log;
	while( start_backwards -> getParent() != 0){
		backwards_log.push_front(start_backwards);
		start_backwards = start_backwards -> getParent();
	}
	backwards_log.push_front(start_backwards);
	
	/** Iterate over log and add to output string */
	for(unsigned int i = 0; i < backwards_log.size(); ++i){
		tempString.append(backwards_log[i] -> getName());
		tempString.append("\n");
	}
	/**
	return the number of jumps to destination or the string with which
	route was taken depending on what mode the user chose 
	*/
	return tempString;
}

//val == 0 ? tempString : std::to_string(backwards_log.size()-1);

int Dijkstra::cost(){
	return 0;
}

int Dijkstra_dist::cost(){
	return 0;
}

int Dijkstra_jumps::cost(){
	return 0;
}


















