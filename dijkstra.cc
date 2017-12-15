#include "dijkstra.h"
#include "node_set.h"
// #include "node.h"
// #include "edge.h"

#include <string>
#include <vector>
#include <deque>
#include <iostream>

using std::string;
using std::cout;
using std::cin;

string Dijkstra::dijkstra(Node* start, int alternative){
	NodeSet ns{};
	start->setValue(0);
	ns.add(start);
	std::vector<Edge> temp;
	int a;
	Node* start_backwards = 0; //null
	
	while (!ns.isEmpty()) {
		Node* n = ns.removeMin();
		temp = n->getEdges();
		for(unsigned int i = 0; i < temp.size(); ++i) {
				a = temp[i].getLength() + n->getValue();

			if(a < temp[i].getDestination()->getValue()) {
				temp[i].getDestination()->setValue(a);
				temp[i].getDestination()->setParent(n);
				ns.add(temp[i].getDestination());
				
				if(i == temp.size()-1){
					start_backwards = temp[i].getDestination();
				}
			}
		}
	}
	return print(start_backwards);
}

string Dijkstra::dijkstra(Node* start){
	NodeSet ns{};
	start->setValue(0);
	ns.add(start);
	std::vector<Edge> temp;
	int a;
	Node* start_backwards = 0; //null
	
	while (!ns.isEmpty()) {
		Node* n = ns.removeMin();
		temp = n->getEdges();
		for(unsigned int i = 0; i < temp.size(); ++i) {
			a = temp[i].getLength() + n->getValue();
			if(a < temp[i].getDestination()->getValue()) {
				temp[i].getDestination()->setValue(a);
				temp[i].getDestination()->setParent(n);
				ns.add(temp[i].getDestination());
				
				if(i == temp.size()-1){
					start_backwards = temp[i].getDestination();
				}
			}
		}
	}
	return print(start_backwards);
}

string Dijkstra::print(Node* start_backwards){
	Node* start;
	start = start_backwards;
	std::deque<Node*> backwards_log;
	string out{""};
	
	while( start -> getParent() != 0){
		backwards_log.push_front(start);
		start = start -> getParent();
	}
	
	backwards_log.push_front(start);
	
	for(unsigned int i = 0; i < backwards_log.size(); ++i){
		out.append(backwards_log[i] -> getName());
		out.append("\n");
	}
	return out;
}








