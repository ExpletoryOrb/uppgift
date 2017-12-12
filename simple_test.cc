#include "Edge.h"
#include "Node.h"
#include <string>
#include <vector>
#include <iostream>

#include <cassert>
#include <algorithm>
#include <utility>
#include <set>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main(){
	Node n_lund{"Lund"};
    Node n_dalby{"Dalby"};
    Node n_sandby{"Sodra Sandby"};
    Node n_hallestad{"Torna Hallestad"};
    Node n_flyinge{"Flyinge"};
    Node n_veberod{"Veberod"};

     n_lund.addEdge(&n_dalby,12);
     n_lund.addEdge(&n_sandby,12);
     n_dalby.addEdge(&n_veberod,11);
     n_dalby.addEdge(&n_hallestad,5);
     n_sandby.addEdge(&n_lund,12);
     n_sandby.addEdge(&n_flyinge,4);
     n_hallestad.addEdge(&n_veberod,8);
	 
	 
	cout << "Anslutningar från " << n_dalby.getName() << "(" << n_dalby.getValue() << "):\n";
	for(auto de : n_dalby.getEdges()){
		cout << de.getLength() << "to" << de.getDestination()->getName() << endl;
	}
}