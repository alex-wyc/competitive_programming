#include <bits/stdc++.h>

using namespace std;

#define INF 1000000008

struct Graph {
    int V;
    int **E;

    public:
    int **dist;

    Graph(int _v) {
        V = _v;
        E = (int **)malloc(sizeof(int *) * V);
        dist = (int **)malloc(sizeof(int *) * V);
        for (int i = 0 ; i < V ; i++) {
            E[i] = (int *)malloc(sizeof(int) * V);
            dist[i] = (int *)malloc(sizeof(int) * V);
            memset(E[i], V, 0);
            memset(dist[i], V, INF);
            dist[i][i] = 0;
        }
    };

    void add_edge(int from, int to, int weight) {
        dist[from][to] = E[from][to] = weight;
    };

    void floyd_warshall() {
        for (int k = 0 ; k < V ; k++) {
            for (int j = 0 ; j < V ; j++) {
                for (int i = 0 ; i < V ; i++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    };
};
