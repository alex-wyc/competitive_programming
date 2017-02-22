all:
	for 

test-sssp: sssp
	time ./dijkstra.out < testfile > dijkstraoutput
	time ./spfa.out < testfile > spfaoutput
	time ./bellman-ford.out < testfile > bellmanfordoutput
	diff dijkstraoutput spfaoutput
	diff dijkstraoutput bellmanfordoutput

sssp: sssp.py dijkstra spfa bellman-ford
	python sssp.py

dijkstra: dijkstra.cpp
	g++ -std=c++11 dijkstra.cpp -o dijkstra.out

spfa: spfa.cpp
	g++ -std=c++11 spfa.cpp -o spfa.out

bellman-ford: bellman-ford.cpp
	g++ -std=c++11 bellman-ford.cpp -o bellman-ford.out

floyd-warshall: floyd-warshall.cpp
	g++ -std=c++11 floyd-warshall.cpp -o floyd-warshall.out

test-mst: mst
	time ./prims.out < testfile > primsoutput
	time ./kruskals.out < testfile > kruskalsoutput
	diff primsoutput kruskalsoutput

mst: mst.py
	python mst.py

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
