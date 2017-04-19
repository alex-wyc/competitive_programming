#include <bits/stdc++.h>

using namespace std;

#define INF 1000000008

class Graph {
    int V;
    vector<vector<int> > E;
    
  public:
    Graph(int _v) {
        V = _v;
        E.resize(V);
        for (int i = 0 ; i < V ; i++) {
            E[i].resize(V, 0);
        }
    }

    void add_edge(int from, int to, int weight) {
        E[from][to] = weight;
    };

    vector<int> dfs(int s, int t) {
        vector<int> pred(V, -1);
        vector<int> visited(V, 0);
        stack<int> frontier;
        frontier.push(s);
        visited[s] = 1;

        while (!frontier.empty()) {
            int v = frontier.top(); frontier.pop();

            for (int i = 0 ; i < V ; i++) {
                if (E[v][i] > 0 && !visited[i]) {
                    frontier.push(i);
                    visited[i] = true;
                    pred[i] = v;
                }
            }
        }

        if (pred[t] != -1) {
            return pred;
        }
        return {};
    }

    int ford_fulkerson(int s, int t) {
        int max_flow = 0;

        vector<int> path = dfs(s, t);

        while (path.size()) { // while we have a path
            int path_flow = INF;
            int v = t;
            while (v != s) {
                path_flow = min(path_flow, E[path[v]][v]);
                v = path[v];
            }

            max_flow += path_flow;

            v = t;
            int u;
            while (v != s) {
                u = path[v];
                E[u][v] -= path_flow;
                E[v][u] += path_flow;
                v = u;
            }

            path = dfs(s, t);
        }

        return max_flow;
    }
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

    int s, t;

    cin >> s >> t;

    cout << g.ford_fulkerson(s, t) << '\n';

    return 0;
}
