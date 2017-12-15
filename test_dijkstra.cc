#include <iostream>
#include <cassert>
//#include "graph.h"
#include "node_set.h"
//#include "dijkstra.h"

using namespace std;
using std::cout;
using std::endl;

void dijkstra(Node* start) {
	NodeSet ns{};//skapa och använd ett nodeset objekt
	start->setValue(0);
	ns.add(start);

	std::vector<Edge> temp;
	int a;
	Node* start_backwards;
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
	
	std::vector<Node*> backwards_log;
	backwards_log.push_back(start);
	while( start_backwards -> getParent() != 0){
		backwards_log.push_back(start_backwards); //push front?
		start_backwards = start_backwards -> getParent();
	}
	
	for(unsigned int i = 0; i < backwards_log.size(); ++i){
		cout << backwards_log[i] -> getName()  << endl;
	}
}


void test() {
	
    Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};

    lund.addEdge(&dalby,12);
    lund.addEdge(&sandby,12);
    dalby.addEdge(&sandby,12);
    dalby.addEdge(&veberod,11);
    dalby.addEdge(&hallestad,5);
    sandby.addEdge(&lund,12);
    sandby.addEdge(&flyinge,4);
    hallestad.addEdge(&veberod,8);
	
	
	
	
	
    dijkstra(&lund);	
	

    assert(lund.getValue() == 0);//assert om argumentet är true går man vidare till nästa
	//cout << "OKOK" << endl;
    assert(dalby.getValue() == 12);
    assert(sandby.getValue() == 12);
    assert(hallestad.getValue() == 17);
    assert(veberod.getValue() == 23);
    assert(flyinge.getValue() == 16);


#ifdef INFO
    cout << "----\nAll distances from Lund:\n";

    for(auto& t : {lund, dalby, sandby, hallestad, veberod, flyinge}) {
        cout << t.getName() << " : " << t.getValue() << " ";
        cout << endl;
    }
#endif
    cout << "test_dijkstra passed" << endl;

}


int main() {
    test();
    return 0;
}
