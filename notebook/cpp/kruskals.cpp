#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> edge;
typedef pair<int, edge> weighted_edge;

class Graph {
    int V;
    priority_queue<weighted_edge, vector<weighted_edge>, greater<weighted_edge> > edges;
    vector<int> parents;
    vector<int> ranks;

    int find_root(int a) {
        if (parents[a] == a) {
            return a;
        }
        else {
            return find_root(parents[a]);
        }
    };

    void make_union(int a, int b) {
        int a_root = find_root(a);
        int b_root = find_root(b);

        if (ranks[a_root] > ranks[b_root]) {
            parents[b_root] = a_root;
        }
        else if (ranks[a_root] < ranks[b_root]) {
            parents[a_root] = b_root;
        }
        else {
            parents[b_root] = a_root;
            ranks[a_root]++;
        }
    };

  public:
    Graph(int _v) {
        V = _v;
        parents = vector<int>(V);
        for (int i = 0 ; i < V ; i++) {
            parents[i] = i;
        }
        ranks = vector<int>(V, 0);
    };

    void add_edge(int a, int b, int weight) {
        edges.push({weight, {a, b}});
    };

    int get_mst() {
        int mst_weight = 0;

        while (!edges.empty()) {
            weighted_edge e = edges.top(); edges.pop();
            int u = e.second.first;
            int v = e.second.second;

            if (find_root(u) != find_root(v)) {
                make_union(u, v);
                mst_weight += e.first;
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
