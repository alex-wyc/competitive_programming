# SPFA algorithm

The SPFA algorithm is an optimized version of Bellman-Ford that only makes visit
it absolutely needs to. The algorithm runs in O(|V| + k|E|) for some constant k
between 1 and V that is not determined by |V| or |E| but by the shape of the
graph. Experimental evidence, however, show that on average k is approximately
2, which makes the algorithm linear.

## Algorithm

The algorithm relies on the fact that if we have an edge (i, j) that is not a part
of the optimal path to j, then that edge won't be included in any shortest path to
k that goes through j. Therefore we only need to further optimize any vertex j
if one of the nodes that points to it has just been optimized.

## Pseudocode

```
for v in V:
    in_queue[v] = false
    distance[v] = infinity

Queue <- source
in_queue[source] = true
distance[source] = 0

while Queue is not empty:
    v <- Queue
    in_queue[v] = false

    for each edge (v, u) with weight w:
        if distance[u] > distance[v] + w:
            distance[u] = distance[v] + w

            if not in_queue[u]:
                Queue <- u
                in_queue[u] = true

```

## Analysis

The initialization state takes |V| operations. The bulk of the algorithm is in
the `while` loop. In the loop we iterate through all the edges coming out of
`v`. On average this is happens |E| / |V| times per vertex. The runtime of this
step is |E| / |V| if we are using an adjacency list, but if we are using an
adjacency matrix then the step would take |V| operations. Note that each
vertex is in the queue at least once, so the number of times the while loop runs
is at least |V|. The exact runtime of the algorithm depends on the number of
times each vertex is added into the queue, k. Note that k is independent of both
|E| and |V| but is rather a result of the specific geometry of the graph. We do know,
however, that k is capped at |V| - 1. But empirical evidence shows that k is on
average about 2, which makes the runtime of this algorithm as a whole O(|V| + (k |V| * |E| /
|V|)) = O(|V| + k|E|) if we are using an adjacency list, but O(|V| + (k |V| *
|V|)) = O(k|V|^2) if we are using an adjacency matrix.

Do note, however, that if there were a negative edge cycle within the graph,
spfa will keep going forever as `Queue` would never be empty. A slight
modification, however, could count the number of times vertices are visited and
break out as soon as that number exceeds |V| - 1. But this gives spfa the same
runtime as Bellman-Ford in the worst case.

## Original Paper

The original paper is here: http://en.cnki.com.cn/Article_en/CJFDTOTAL-XNJT402.015.htm

It is in Chinese, but it is free.
