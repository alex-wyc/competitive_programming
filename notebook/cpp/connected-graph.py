# mst tester, genrates a connected graph

import random

V = 1000
E = 100000
MAX_EDGE = 100

f = open('testfile', 'w')

f.write(str(V) + " " + str(E) + "\n")

edges = set([])

for i in range(1, V): # we generate a connected subgraph, then we add edges
    v = random.randrange(i) # before i is guarnateed to be added
    edges.add((i, v))
    w = random.randrange(MAX_EDGE)
    f.write("%d %d %d\n" % (i, v, w))

while len(edges) < E:
    while True:
        u = random.randrange(V)
        v = random.randrange(V)

        if (u != v and (u, v) not in edges and (v, u) not in edges):
            edges.add((u, v))
            break

    w = random.randrange(MAX_EDGE)
    f.write("%d %d %d\n" % (u, v, w))

f.close()
