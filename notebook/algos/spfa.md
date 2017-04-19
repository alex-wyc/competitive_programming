<style TYPE="text/css">
code.has-jax {font: inherit; font-size: 100%; background: inherit; border: inherit;}
</style>
<script type="text/x-mathjax-config">
MathJax.Hub.Config({
    tex2jax: {
        inlineMath: [['$','$'], ['\\(','\\)']],
        skipTags: ['script', 'noscript', 'style', 'textarea', 'pre'] // removed 'code' entry
    }
});
MathJax.Hub.Queue(function() {
    var all = MathJax.Hub.getAllJax(), i;
    for(i = 0; i < all.length; i += 1) {
        all[i].SourceElement().parentNode.className += ' has-jax';
    }
});
</script>
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>

# SPFA algorithm

The SPFA algorithm is an optimized version of Bellman-Ford that only makes visit
it absolutely needs to. The algorithm runs in $O(|V| + k|E|)$ for some constant $k$
between 1 and V that is not determined by |V| or |E| but by the shape of the
graph. Experimental evidence, however, show that on average k is approximately
2, which makes the algorithm linear.

## Algorithm

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
