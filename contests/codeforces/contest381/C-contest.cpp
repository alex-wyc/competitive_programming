#include <bits/stdc++.h>

using namespace std;

struct interval {
    int l;
    int len;
    int mex;
    int min, max;
};

auto cmp_intervals = [](const interval &A, const interval &B) {
    return A.len > B.len;
};

typedef priority_queue<interval, vector<interval>, decltype(cmp_intervals)> interval_queue;

int main(int argc, char *argv[]) { 
    int N, M;
    cin >> N >> M;

    vector<int> arr(N, -1);
    interval_queue chosen(cmp_intervals);
    map<int, vector<interval> > overlaps;

    for (int i = 0 ; i < N ; i++) {
        vector<interval> to_ins;
        overlaps.insert({i, to_ins});
    }

    for (int i = 0 ; i < M ; i++) {
        int l, r;
        interval current;
        
        cin >> l >> r;

        for (int j = l - 1 ; j < r ; j++) {
            overlaps[j].push_back(current);
        }

        current.l = l - 1;
        current.len = r - l + 1;
        current.mex = 0;

        chosen.push(current);
    }

    int max_mex = chosen.top().len;

    cout << max_mex << '\n';

    int filled_count = 0;
    while (filled_count < N && !chosen.empty()) {
        interval curr = chosen.top();
        chosen.pop();

        if (curr.mex != max_mex) {
            vector<int> covered(curr.len);

            for (int i = 0 ; i < curr.len ; i++) {
                covered[i] = curr.l + i;
            }

            sort(covered.begin(), covered.end(), [&overlaps](const int &A, const int &B) {
                    return overlaps[A].size() > overlaps[B].size();
            });

            for (int i : covered) {
                if (arr[i] == -1) { // have not been filled
                    arr[i] = curr.mex;
                    for (interval j : overlaps[i]) {
                        if (curr.mex == j.mex + 1) {
                            j.mex = curr.mex;
                        }
                    }
                    curr.mex++;
                    filled_count++;
                }
            }
        }
    }

    for (int i = 0 ; i < N ; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}
