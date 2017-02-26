#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int N, M;
    cin >> N >> M;

    int min_mex = 0;

    for (int i = 0 ; i < M ; i++) {
        int l, r;
        cin >> l >> r;
        
        if (min_mex == 0) {
            min_mex = r - l + 1;
        }

        if (min_mex > r - l + 1) {
            min_mex = r - l + 1;
        }
    }

    cout << min_mex << '\n';

    for (int i = 0 ; i < N ; i++) {
        // we can do this because min_mex is the length of the shortest
        // inspection sequence, therefore for that segment it will cover all
        // numbers up to min_mex, and for all other inspection sequences, it
        // must contain at least a subsequence of length min_mex.
        cout << i % min_mex << ' ';
    }

    cout << '\n';

    return 0;
}
