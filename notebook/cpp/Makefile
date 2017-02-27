test-sssp: dijkstra spfa bellman-ford random-graph
	time ./dijkstra.out < testfile > dijkstra.output
	time ./spfa.out < testfile > spfa.output
	time ./bellman-ford.out < testfile > bellmanford.output

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
	time ./prims.out < testfile > prims.output
	time ./kruskals.out < testfile > kruskals.output

prims: prims.cpp
	g++ -std=c++11 prims.cpp -o prims.out

kruskals: kruskals.cpp
	g++ -std=c++11 kruskals.cpp -o kruskals.out

trie: trie.cpp
	g++ -std=c++11 trie.cpp -o trie.out

test-string-matching: rabin-karp
	python stringmatching.py
	time ./rabin-karp.out < testfile > rk.output

rabin-karp: rabin-karp.cpp
	g++ -std=c++11 rabin-karp.cpp -o rabin-karp.out

clean:
	rm *.out
	rm testfile
	rm *.output
