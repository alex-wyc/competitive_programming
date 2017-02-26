#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    long k2 = 0, k3 = 0, k5 = 0, k6 = 0;
    unsigned long long max_sum = 0;

    cin >> k2 >> k3 >> k5 >> k6;

    long A = min(min(k2, k5), k6);

    k2 = k2 - A;

    long B = min(k2, k3);

    max_sum = A * 256 + B * 32;

    cout << max_sum << '\n';
}
