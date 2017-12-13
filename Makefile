# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS =   simple_test test_nodeset
		#test_graph_small test_graph_nofile  test_dijkstra

all: $(PROGS)

run:	simple_test test_nodeset
		./simple_test
		./test_nodeset
		
		#test_graph_small test_graph_nofile test_nodeset test_dijkstra
		#./test_graph_small
		# ./test_graph_nofile
		# 
		# ./test_dijkstra

# Targets rely on implicit rules for compiling and linking
# test_graph_small: Node.o Edge.o test_graph_small.o
# test_graph_small.o: test_graph_small.cc Node.h Edge.h

simple_test: Node.o Edge.o 

test_nodeset: NodeSet.o Node.o Edge.o

NodeSet: NodeSet.o
NodeSet.o: NodeSet.cc NodeSet.h

Node: Node.o
Node.o: Node.cc Node.h Edge.h

Edge: Edge.o
Edge.o: Edge.cc Edge.h Node.h


# Phony targets
.PHONY: all test clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
