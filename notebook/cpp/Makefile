all:
	for 

test-sssp: dijkstra spfa bellman-ford random-graph
	time ./dijkstra.out < testfile > dijkstraoutput
	time ./spfa.out < testfile > spfaoutput
	time ./bellman-ford.out < testfile > bellmanfordoutput

random-graph: random-graph.py
	python random-graph.py

dijkstra: dijkstra.cpp
	g++ -std=c++11 dijkstra.cpp -o dijkstra.out

spfa: spfa.cpp
	g++ -std=c++11 spfa.cpp -o spfa.out

bellman-ford: bellman-ford.cpp
	g++ -std=c++11 bellman-ford.cpp -o bellman-ford.out

floyd-warshall: floyd-warshall.cpp
	g++ -std=c++11 floyd-warshall.cpp -o floyd-warshall.out

test-mst: prims kruskals random-graph
	time ./prims.out < testfile > primsoutput
	time ./kruskals.out < testfile > kruskalsoutput

prims: prims.cpp
	g++ -std=c++11 prims.cpp -o prims.out

kruskals: kruskals.cpp
	g++ -std=c++11 kruskals.cpp -o kruskals.out

trie: trie.cpp
	g++ -std=c++11 trie.cpp -o trie.out

clean:
	rm *.out
	rm testfile
	rm *output
