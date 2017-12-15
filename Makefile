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
PROGS = test   

#simple_test test_nodeset test_dijkstra test_graph_nofile

#test_graph_small 

all: $(PROGS)

run:  test
	./test


#simple_test test_nodeset test_dijkstra test_graph_nofile
	#./simple_test
	#./test_nodeset
	#./test_dijkstra
	#./test_graph_nofile
		
#test_graph_small
#./test_graph_small
# test_graph_small: Node.o Edge.o test_graph_small.o


# Targets rely on implicit rules for compiling and linking

test: test.o node.o edge.o node_set.o graph.o dijkstra.o
#simple_test: node.o edge.o 
#test_nodeset: node_set.o node.o edge.o
#test_dijkstra: test_dijkstra.o node_set.o node.o edge.o dijkstra.o
#test_graph_nofile: test_graph_nofile.o node_set.o node.o edge.o graph.o

# Phony targets
.PHONY: all clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
