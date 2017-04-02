#include <bits/stdc++.h>

using namespace std;

struct Graph {
    int V;
    int **E;
    int scc_count; // total number of scc's
    vector<int> SCC; // SCC[i] == shows which scc vertex i is in

    Graph(int _v) {
        V = _v;
        E = (int **)malloc(sizeof(int *) * V);
        for (int i = 0 ; i < V ; i++) {
            E[i] = (int *)malloc(sizeof(int) * V);
            memset(E[i], V, 0); // set them as unconnected
        }
        SCC.resize(V, -1);
    };

    void add_edge(int from, int to) {
        E[from][to] = 1;
    };

    void dfs(int i, vector<bool> &visited, stack<int> &ordering) {
        if (!visited[i]) {
            visited[i] = true;
            for (int j = 0 ; j < V ; j++) {
                if (E[i][j]) {
                    dfs(j, visited, ordering);
                }
            }
            ordering.push(i);
        }
    };

    bool assign(int i, int scc_i) {
        if (SCC[i] == -1) {
            SCC[i] = scc_i;
            for (int j = 0 ; j < V ; j++) {
                if (E[j][i]) {
                    assign(j, scc_i);
                }
            }
            return true;
        }
        return false;
    }

    void kosaraju() {
        // computes *SCC and scc_count
        stack<int> ordering;

        vector<bool> visited(V);
        fill(visited.begin(), visited.end(), false);

        for (int i = 0 ; i < V ; i++) {
            dfs(i, visited, ordering);
        }

        scc_count = 0;

        while (!ordering.empty()) {
            int i = ordering.top(); ordering.pop();
            if (assign(i, scc_count)) {
                scc_count++;
            }
        }
    };
};

int main(int argc, char *argv[]) {
    int V, E;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0 ; i < E ; i++) {
        int from, to;
        cin >> from >> to;
        g.add_edge(from, to);
    }

    g.kosaraju();

    cout << g.scc_count << '\n';
    for (int i = 0 ; i < g.scc_count ; i++) {
        cout << i << ": ";
        for (int v = 0 ; v < g.V ; v++) {
            if (g.SCC[v] == i) {
                cout << v << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
