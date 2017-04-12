#include <bits/stdc++.h>

using namespace std;

struct Graph {
    int V;
    vector<vector<int> > E;
    vector<int> in_degrees;

    public:
    Graph(int _v) {
        V = _v;
        E.resize(V);
        in_degrees.resize(V, 0);
    };

    void add_edge(int from, int to) {
        E[from].push_back(to);
        in_degrees[to]++;
    };

    vector<int> top_sort() {
        vector<int> sorted_vertices;
        queue<int> candidates;

        for (int i = 0 ; i < V ; i++) {
            if (in_degrees[i] == 0) {
                candidates.push(i);
            }
        }

        while (!candidates.empty()) {
            int u = candidates.front(); candidates.pop();
            sorted_vertices.push_back(u);

            for (int v : E[u]) {
                in_degrees[v]--;

                if (in_degrees[v] == 0) {
                    candidates.push(v);
                }
            }
        }

        if (sorted_vertices.size() != V) {
            return {}; // empty list, error
        }

        return sorted_vertices;
    };
};
