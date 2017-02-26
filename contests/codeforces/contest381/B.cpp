#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int N, M;

    cin >> N >> M;

    int moods[N];
    int happiness = 0;

    for (int i = 0 ; i < N ; i++) {
        cin >> moods[i];
    }

    for (int i = 0 ; i < M ; i++) {
        int l, r;
        cin >> l >> r;
        int subarr_sum = 0;
        for (int j = l - 1 ; j < r ; j++) {
            subarr_sum += moods[j];
        }
        if (subarr_sum > 0) {
            happiness += subarr_sum;
        }
    }

    cout << happiness << '\n';
    return 0;
}
