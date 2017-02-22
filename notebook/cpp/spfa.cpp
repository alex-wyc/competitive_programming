#include <bits/stdc++.h>

using namespace std;

#define INF 1000000008

typedef pair<int, int> edge;

class Graph {
    int V;
    vector<vector<edge> > edges;

    public:
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
    void spfa(int s) {
        bool in_queue[V];
        memset(in_queue, V, false);

        queue<int> to_optimize;

        dist[s] = 0;
        to_optimize.push(s);
        in_queue[s] = true;

        while (!to_optimize.empty()) {
            int v = to_optimize.front(); to_optimize.pop();
            in_queue[v] = false;

            for (int i = 0 ; i < edges[v].size() ; i++) {
                int to = edges[v][i].second;
                int weight = edges[v][i].first;

                if (dist[v] + weight < dist[to]) {
                    dist[to] = dist[v] + weight;

                    if (!in_queue[to]) {
                        to_optimize.push(to);
                        in_queue[to] = true;
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

    g.spfa(0);

    for (int i = 0 ; i < v ; i++) {
        cout << g.dist[i] << '\n';
    }
    return 0;
}
