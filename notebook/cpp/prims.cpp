#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> vertex_priority;

class Graph {
    int V;
    vector<vector<vertex_priority> > edges;

  public:
    Graph(int _v) {
        V = _v;
        edges = vector<vector<vertex_priority> >(V);
    };

    void add_edge(int a, int b, int weight) {
        edges[a].push_back({weight, b});
        edges[b].push_back({weight, a});
    };

    int get_mst() {
        bool visited[V];
        memset(visited, V, false);
        int mst_weight = 0;
        visited[0] = true;
        int span = 1;

        priority_queue<vertex_priority, vector<vertex_priority>, greater<vertex_priority> > frontier;

        for (int i = 0 ; i < edges[0].size() ; i++) {
            frontier.push(edges[0][i]);
        }

        while (!frontier.empty() && span != V) {
            vertex_priority vp = frontier.top(); frontier.pop();
            int weight = vp.first;
            int v = vp.second;

            if (visited[v])
                continue;

            visited[v] = true;
            mst_weight += weight;
            span++;

            for (int i = 0 ; i < edges[v].size() ; i++) {
                if (!visited[edges[v][i].second]) {
                    frontier.push(edges[v][i]);
                }
            }
        }

        return mst_weight;
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

    cout << g.get_mst() << '\n';
    return 0;
}
