#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct state {
    int gov;
    set<int> cities;
};

int main(int argc, char *argv[]) {
    int n, m, k;

    cin >> n >> m >> k;

    vector<state> states;

    set<int> marked;
    vector<int> govs;

    for (int i = 0 ; i < k ; i++) {
        int c;
        cin >> c;

        state new_state;
        new_state.gov = c;
        new_state.cities.insert(c);

        states.push_back(new_state);

        govs.push_back(c);
        marked.insert(c);
    }

    for (int i = 0 ; i < m ; i++) {
        int j, k;
        cin >> j >> k;

        auto it = find_if(govs.begin(), govs.end(), [j, k](int a) {return a == j || a == k;});

        if (it != govs.end()) {
            if (*it == j) {
                states[it - govs.begin()].cities.insert(k);
                marked.insert(k);
            }
            else {
                states[it - govs.begin()].cities.insert(j);
                marked.insert(j);
            }
        }
    }

    int remaining = n - marked.size();

    sort(states.begin(), states.end(), [](state a, state b) {return a.cities.size() > b.cities.size();});

    int max_cities = states[0].cities.size() + remaining;

    cout << (max_cities * (max_cities - 1)) / 2 - m << '\n';
    return 0;
}
