#include "node.h"
#include "edge.h"
#include "node_set.h"
#include "graph.h"
#include "dijkstra.h"

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <deque>
#include <cassert>
#include <limits>
//#include <>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::ifstream;


/** Test 1: Graph från fil */
bool test1(){
	ifstream infile("graf.txt");
	
	Graph g(infile);
	assert(g.find("Dalby") != 0);
	assert(g.find("Lomma") != 0);
	
	string dalby = "Dalby";
	std::vector<Edge> v = g.find("Lund") -> getEdges();
	
	/** förmodligen ett fel här när vi läser in från grafen, assert(test_edge) ger ett fel */
	
	bool test_edge{false};
	for(Edge e : v){
		if((e.getLength() == 12) && (dalby.compare(e.getDestination() -> getName()) == 0)){
			test_edge = true;
		}
	}
	assert(test_edge);
	
	g.find("Lund") -> setValue(12);
	g.resetValues();
	assert(g.find("Lund") -> getValue() == std::numeric_limits<int>::max());
	return true;
}

/** Test 2: NodeSet */
bool test2(){
	NodeSet ns{};

    Node a("A");
    a.setValue(10);
    Node b("B");
    b.setValue(20);
    Node c("C");
    c.setValue(30);

    ns.add(&a);
    ns.add(&b);
    ns.add(&c);

    assert(ns.removeMin() == &a);
    assert(ns.removeMin() == &b);
    assert(ns.removeMin() == &c);

    assert(ns.isEmpty());

    ns.add(&a);
    assert(!ns.isEmpty());

    ns.add(&b);
    assert(!ns.isEmpty());

    ns.add(&c);
    assert(!ns.isEmpty());
	
	return true;
}

/** Test 3: Dijkstra vanlig */
bool test3(){
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
	
	Dijkstra ds;
	
    string s{""};
	s = ds.dijkstra(&lund);	
	//cout << s;
	
	assert(lund.getValue() == 0);
    assert(dalby.getValue() == 12);
    assert(sandby.getValue() == 12);
    assert(hallestad.getValue() == 17);
    assert(veberod.getValue() == 23);
    assert(flyinge.getValue() == 16);
	return true;
}

/** Test 4: Dijkstra antal hopp */
bool test4(){
	return true;
}

bool test5(){
	return true;
}

bool test6(){
	return true;
}



int main(){
	if(test1()){
		cout << "test 1: passed" << endl;
	}
	
	if(test2()){
		cout << "test 2: passed" << endl;
	}
	
	if(test3()){
		cout << "test 3: passed" << endl;
	}
	
	if(test4()){
		cout << "test 4: passed" << endl;
	}
	
	if(test5()){
		cout << "test 5: passed" << endl;
	}
	
	if(test6()){
		cout << "test 6: passed" << endl;
	}
}











