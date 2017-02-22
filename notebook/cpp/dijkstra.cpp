#include <bits/stdc++.h>

using namespace std;

#define INF 1000000008

typedef pair<int, int> vertex_priority;

class Graph {
    int V;
    vector<vector<vertex_priority> > edges;

    public:
    vector<int> dist;

    Graph(int _v) {
        V = _v;
        edges = vector<vector<vertex_priority> >(V);
        dist = vector<int> (V, INF);
    };

    void add_edge(int from, int to, int weight) {
        edges[from].push_back({weight, to});
    };

    // this will populate the dist array
    void dijkstra(int s) {
        bool visited[V];
        memset(visited, V, false);

        priority_queue<vertex_priority, vector<vertex_priority>, greater<vertex_priority> > frontier;

        visited[s] = true;
        dist[s] = 0;

        for (int i = 0 ; i < edges[s].size() ; i++) {
            int to = edges[s][i].second;
            int weight = edges[s][i].first;

            if (dist[s] + weight < dist[to]) {
                dist[to] = dist[s] + weight;
                frontier.push({dist[to], to});
            }
        }

        while (!frontier.empty()) {
            vertex_priority vp = frontier.top(); frontier.pop();

            int v = vp.second;

            if (visited[v])
                continue;

            visited[v] = true;

            for (int i = 0 ; i < edges[s].size() ; i++) {
                int to = edges[s][i].second;
                int weight = edges[s][i].first;

                if (dist[s] + weight < dist[to]) {
                    dist[to] = dist[s] + weight;
                    frontier.push({dist[to], to});
                }
            }
        }
    };

    int dijkstra(int s, int d) {
        bool visited[V];
        memset(visited, V, false);

        priority_queue<vertex_priority, vector<vertex_priority>, greater<vertex_priority> > frontier;

        visited[s] = true;
        dist[s] = 0;

        for (int i = 0 ; i < edges[s].size() ; i++) {
            int to = edges[s][i].second;
            int weight = edges[s][i].first;

            if (dist[s] + weight < dist[to]) {
                dist[to] = dist[s] + weight;
                frontier.push({dist[to], to});
            }
        }

        while (!frontier.empty()) {
            vertex_priority vp = frontier.top(); frontier.pop();

            int v = vp.second;

            if (visited[v])
                continue;

            if (v == d) {
                return dist[v];
            }

            visited[v] = true;

            for (int i = 0 ; i < edges[s].size() ; i++) {
                int to = edges[s][i].second;
                int weight = edges[s][i].first;

                if (dist[s] + weight < dist[to]) {
                    dist[to] = dist[s] + weight;
                    frontier.push({dist[to], to});
                }
            }
        }

        return dist[d];
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

    g.dijkstra(0);

    for (int i = 0 ; i < v ; i++) {
        cout << g.dist[i] << '\n';
    }
    return 0;
}
