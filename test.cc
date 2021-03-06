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
	
	std::vector<Edge> lund_edges = g.find("Lund") -> getEdges();
	std::vector<Edge> lomma_edges = g.find("Lomma") -> getEdges();
	
	assert(lund_edges[0].getLength() == 12);
	assert(lomma_edges[3].getLength() == 16);
	
	string test_string1{"Dalby"};
	string test_string2{"Lomma"};
	string test_string3{"Kavlinge"};
	
	string dest1 = lund_edges[0].getDestination() -> getName();
	string dest2 = lund_edges[2].getDestination() -> getName();
	string dest3 = lund_edges[4].getDestination() -> getName();
	
	assert(dest1.compare(test_string1) == 0);
	assert(dest2.compare(test_string2) == 0);
	assert(dest3.compare(test_string3) == 0);
	
	g.find("Lund") -> setValue(41);
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
	Node lulea{"Lulea"};
	Node boden{"Boden"};
	
	lund.addEdge(&dalby,10);
    lund.addEdge(&sandby,1);
	dalby.addEdge(&flyinge,20);
    sandby.addEdge(&hallestad,2);
	hallestad.addEdge(&flyinge,3);
	flyinge.addEdge(&boden, 1);
	boden.addEdge(&lulea, 1);
	flyinge.addEdge(&lulea, 5);
	
	Dijkstra ds{};
	string s = ds.dijkstraS(&lund, &lulea);
	// cout << endl << endl;
	// cout << s << endl;
	
	string test_string{"Lund\nSodra Sandby\nTorna Hallestad\nFlyinge\nBoden\nLulea\n8\n"};
	assert(s.compare(test_string) == 0);
	return true;
}

/** Test 4: Dijkstra antal hopp */
bool test4(){
	Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
	Node lulea{"Lulea"};
	Node boden{"Boden"};
	
	lund.addEdge(&dalby,10);
    lund.addEdge(&sandby,1);
	dalby.addEdge(&flyinge,20);
    sandby.addEdge(&hallestad,2);
	hallestad.addEdge(&flyinge,3);
	flyinge.addEdge(&boden, 1);
	boden.addEdge(&lulea, 1);
	flyinge.addEdge(&lulea, 5);
	
	Dijkstra* ds = new Dijkstra_jumps;
	string s = ds -> dijkstraS(&lund, &lulea);
	// cout << endl << endl;
	// cout << s << endl;
	
	string test_string{"Lund\nDalby\nFlyinge\nLulea\n3\n"};
	assert(s.compare(test_string) == 0);
	return true;
}

bool test5(){
	Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
	Node lulea{"Lulea"};
	Node boden{"Boden"};
	
	lund.addEdge(&dalby,10);
    lund.addEdge(&sandby,1);
	dalby.addEdge(&flyinge,20);
    sandby.addEdge(&hallestad,2);
	hallestad.addEdge(&flyinge,3);
	flyinge.addEdge(&boden, 1);
	boden.addEdge(&lulea, 1);
	flyinge.addEdge(&lulea, 5);
	
	Dijkstra ds{};
	string s = ds.dijkstraS(&lund, &flyinge);
	//cout << endl << endl;
	//cout << s << endl;
	
	string test_string{"Lund\nSodra Sandby\nTorna Hallestad\nFlyinge\n6\n"};
	assert(s.compare(test_string) == 0);
	return true;
}

bool test6(){
	Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
	Node lulea{"Lulea"};
	Node boden{"Boden"};
	
	lund.addEdge(&dalby,10);
    lund.addEdge(&sandby,1);
	dalby.addEdge(&flyinge,20);
    sandby.addEdge(&hallestad,2);
	hallestad.addEdge(&flyinge,3);
	flyinge.addEdge(&boden, 1);
	boden.addEdge(&lulea, 1);
	flyinge.addEdge(&lulea, 5);
	
	Dijkstra* ds = new Dijkstra_jumps;
	string s = ds -> dijkstraS(&lund, &flyinge);
	//cout << endl << endl;
	//cout << s << endl;
	
	string test_string{"Lund\nDalby\nFlyinge\n2\n"};
	assert(s.compare(test_string) == 0);
	return true;
}

int main(){
	if(test1()){
		cout << "test 1: Graph from file passed!" << endl;
	}
	if(test2()){
		cout << "test 2: NodeSet passed!" << endl;
	}
	if(test3()){
		cout << "test 3: Dijkstra normal algorithm passed!" << endl;
	}
	if(test4()){
		cout << "test 4: Dijkstra number of jumps passed!" << endl;
	}
	if(test5()){
		cout << "test 5: Dijkstra normal to destination passed!" << endl;
	}
	if(test6()){
		cout << "test 6: Dijkstra jump to destination passed!" << endl;
	}
}