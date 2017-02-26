#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    long long N, X, S, a, b, c, d;
    long m, k;

    cin >> N >> m >> k;

    cin >> X >> S;

    unsigned long long result1, result2, result3, result4;

    result1 = result2 = result3 = result4 = N * X;
    // don't use, spell1 only, spell1 and spell2, spell2 only

    vector<pair<long long, long long>> spell1(m);

    for (long i = 0 ; i < m ; i++) {
        cin >> a;
        spell1[i] = {0, a};
    }

    long long savings1;
    long long min_a = LLONG_MAX;

    for (long i = 0 ; i < m ; i++) {
        cin >> b;
        if (b < S && spell1[i].second < min_a) {
            min_a = spell1[i].second;
        }
        spell1[i].first = b;
    }

    result2 = min_a * N;

    sort(spell1.begin(), spell1.end());

    long long savings2 = 0, savings3;

    vector<pair<long long, long long>> spell2(k);

    for (int i = 0 ; i < k ; i++) {
        cin >> c;
        spell2[i] = {0, c * X};
    }

    for (int i = 0 ; i < k ; i++) {
        long long tsaving;
        cin >> d;
        if (d > S) {
            break;
        }
        pair <long long, long long> benchmark = {S - d, 0};
        pair<long long, long long> matchingsp1 = *(upper_bound(spell1.begin(), spell1.end(), benchmark));
        tsaving = (X - matchingsp1.second) * (N - spell2[i].second) + spell2[i].second * X;
        if (tsaving > savings2) {
            savings2 = tsaving;
        }
        savings3 = spell2[i].second * X;
    }

    result3 = result1 - savings2;

    result4 = result1 - savings3;

    cout << min(result1, min(result2, min(result3, result4))) << '\n';

    return 0;
}
