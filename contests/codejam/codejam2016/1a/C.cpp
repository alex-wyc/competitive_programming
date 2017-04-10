#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

pair<int, int> dfs_cycle(int s, vector<vector<int> > &graph) {
    // finds the length of cycle in a graph
    stack<pair<int, int> > to_visit;
    to_visit.push({s, 0});
    vector<int> pred(graph.size());
    pred[s] = -1;

    while (!to_visit.empty()) {
        pair<int, int> v_step = to_visit.top(); to_visit.pop();
        int v = v_step.first;
        int d = v_step.second;

        for (int u : graph[v]) {
            if (u == s) {
                int p = v;
                while (p != -1) {
                    //cout << p << '\n';
                    graph[p].erase(find(graph[p].begin(), graph[p].end(), u));
                    u = p;
                    p = pred[u];
                }
                return {d + 1, v};
            }
            to_visit.push({u, d+1});
            pred[u] = v;
        }
    }

    return {0, -1};
}

int dfs_chain(int s, vector<vector<int> > &graph) {
    vector<bool> visited(graph.size());
    fill(visited.begin(), visited.end(), false);
    stack<pair<int, int> > to_visit;
    to_visit.push({s, 0});

    int max_d = -1;

    while (!to_visit.empty()) {
        pair<int, int> v_step = to_visit.top(); to_visit.pop();
        int v = v_step.first;
        int d = v_step.second;

        visited[v] = true;

        if (d > max_d) {
            max_d = d;
        }

        for (int u : graph[v]) {
            if (!visited[u]) {
                to_visit.push({u, d+1});
            }
        }
    }

    return max_d;
}

int main(int argc, char *argv[]) {
    int T;

    cin >> T;

    for (int i = 0 ; i < T ; i++) {
        int N;
        cin >> N;

        //vector<vector<int> > graph(N);
        vector<vector<int> > inverse_graph(N);
        vector<pair<int, int> > cycle_length(N);
        vector<int> chain_length(N);

        for (int j = 0 ; j < N ; j++) {
            int a;
            cin >> a;
            a = a - 1;
            //graph[j].push_back(a);
            inverse_graph[a].push_back(j);
        }

        for (int j = 0 ; j < N ; j++) {
            cycle_length[j] = dfs_cycle(j, inverse_graph);
            chain_length[j] = dfs_chain(j, inverse_graph);
        }

        int max_seat_no_cycles = 2;
        int max_seat_2_cycles = 0;

        for (int j = 0 ; j < N ; j++) {
            if (cycle_length[j].first == 2) {
                int seats = 2 + chain_length[j] + chain_length[cycle_length[j].second];
                max_seat_2_cycles += seats;
                //cout << seats << '\n';
            }
            else {
                if (max_seat_no_cycles < cycle_length[j].first) {
                    max_seat_no_cycles = cycle_length[j].first;
                }
            }
        }

        int max_seat = max(max_seat_no_cycles, max_seat_2_cycles);

        cout << "Case #" << (i + 1) << ": " << max_seat << '\n';
    }
    
    return 0;
}
