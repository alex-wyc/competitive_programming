#include <bits/stdc++.h>

using namespace std;

#define INF 1000000008

typedef pair<int, int> edge;

struct Graph {
    int V;
    vector<vector<edge> > edges;
    vector<int> dist;

    Graph(int _v) {
        V = _v;
        edges = vector<vector<edge> >(V);
        dist = vector<int> (V, INF);
    };

    void add_edge(int from, int to, int weight) {
        edges[from].push_back({weight, to});
    };

    // populates the dist array
    void bellman_ford(int s) {
        dist[s] = 0;

        for (int i = 0 ; i < V ; i++) {
            for (int j = 0 ; j < V ; j++) {
                for (int k = 0 ; k < edges[j].size() ; k++) {
                    int to = edges[j][k].second;
                    int weight = edges[j][k].first;

                    if (dist[j] + weight < dist[to]) {
                        dist[to] = dist[j] + weight;
                    }
                }
            }
        }
    };
};

int main(int argc, char *argv[]) {
    int v, e;
    cin >> v >> e;

    Graph g(v);

    for (int i = 0 ; i < e ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }

    g.bellman_ford(0);

    for (int i = 0 ; i < v ; i++) {
        cout << g.dist[i] << '\n';
    }

    return 0;
}
