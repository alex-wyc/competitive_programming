// http://codeforces.com/problemset/problem/822/C

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<pair<int, int>, long> voucher;

int get_duration(voucher v) {
    return v.first.second - v.first.first + 1;
}

int main(int argc, char *argv[]) {
    int n, x;
    cin >> n >> x;

    vector<voucher> vouchers_sort_start(n);
    vector<voucher> vouchers_sort_finish(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> vouchers_sort_start[i].first.first;
        cin >> vouchers_sort_start[i].first.second;
        cin >> vouchers_sort_start[i].second;

        vouchers_sort_finish[i] = vouchers_sort_start[i];
    }

    sort(vouchers_sort_start, [](const voucher &v1, const voucher &v2) -> bool {
        if (v1.first.first != v2.first.first)
            return v1.first.first < v2.first.first;
        return v1.first.second <
    })

    return 0;
}
