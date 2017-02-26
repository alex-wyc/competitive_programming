#include <cstdlib>
#include <map>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

#define pii pair<int, int>

map<pii, pii> cache;
int N, K, L;
vector<pii> steps;

pii generate_optimal_output(int start_step, int current_d) {
    cout << start_step << " " << current_d << "\n\n";
    pii starting_condition = make_pair(start_step, current_d);

    if (cache.count(starting_condition)) {
        return cache[starting_condition];
    }

    else {
        pii ret_val;
        if (start_step == N - 1) { // terminating condition
            if (current_d + steps[start_step].second < L) {
                ret_val.first = steps[start_step].first;
                ret_val.second = current_d + steps[start_step].second;
            }
            else {
                ret_val.first = 0;
                ret_val.second = current_d - K;
            }
        }
        else {
            pii fun_now = generate_optimal_output(start_step + 1, current_d + steps[start_step].second);
            pii fun_later = generate_optimal_output(start_step + 1, current_d - K);

            fun_now.first += steps[start_step].first;

            if (fun_now.second < K) {
                ret_val = (fun_now.first > fun_later.first) ? fun_now : fun_later;
            }
            else {
                ret_val = fun_later;
            }
        }

        cache[starting_condition] = ret_val;

        return ret_val;
    }
}

int main(int argc, char *argv[]) {
    int i;
    pii current;

    cin >> N >> K >> L;

    while (N != 0) {
        for (i = 0 ; i < N ; i++) {
            cin >> current.first >> current.second;
            steps.push_back(current);
        }

        cout << generate_optimal_output(0, 0).first;

        steps.clear();
        cache.clear();
        cin >> N >> K >> L;
    }
    return 0;
}
