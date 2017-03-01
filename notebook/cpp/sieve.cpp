#include <bits/stdc++.h>

using namespace std;

vector<int> sieve(int n) {
    int marked[n];
    memset(marked, 0, sizeof(marked));
    vector<int> primes;

    for (int i = 2 ; i * i < n ; i++) {
        if (!marked[i]) {
            primes.push_back(i);
            for (int j = i * i ; j < n ; j += i) {
                marked[j] = 1;
            }
        }
    }

    return primes;
}
