#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, int> ps; // prefix sum -- index

int main(int argc, char *argv[]) {
    int n, k;

    cin >> n >> k;
    long long max_pos = 0;
    long long max_neg = 0;

    vector<ps> prefix_sums(n + 1);

    prefix_sums[0] = {0, -1};

    for (int i = 0 ; i < n ; i++) {
        long long a;
        cin >> a;
        if (a > 0) {
            max_pos += a;
        }
        if (a < 0) {
            max_neg += a;
        }

        prefix_sums[i + 1] = {prefix_sums[i].first + a, i};
    }

    sort(prefix_sums.begin(), prefix_sums.end());

    long long max_val = max(max_pos, -1 * max_neg);
    vector<long long> kpows;

    long long tmp = 1;
    if (abs(k) != 1) {
        while (tmp <= max_val) {
            kpows.push_back(tmp);
            tmp = tmp * k;
        }
    }
    else if (k == 1){
        kpows.push_back(k);
    }
    else if (k == -1) {
        kpows.push_back(k);
        kpows.push_back(-1 * k);
    }

    //for (int i = 0 ; i < kpows.size() ; i++) {
    //    cout << kpows[i] << ' ';
    //}
    //cout << '\n';

    long long ans = 0;

    for (int i = 0 ; i < n + 1 ; i++) {
        for (int j = 0 ; j < kpows.size() ; j++) {
            long long to_search = prefix_sums[i].first + kpows[j];
            ps ulimit = {to_search + 1, -1};
            ps llimit = {to_search, prefix_sums[i].second};
            //cout << to_search << " ";
            auto upper = lower_bound(prefix_sums.begin(), prefix_sums.end(), ulimit);
            auto lower = lower_bound(prefix_sums.begin(), prefix_sums.end(), llimit);
            ans += upper - lower;
        }
    }

    //cout << '\n';

    cout << ans << '\n';
    return 0;
}
