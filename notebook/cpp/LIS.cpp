#include <bits/stdc++.h>

using namespace std;

vector<int> LIS(vector<int> a) {
    int endpoints[a.size() + 1]; // endpoints[j] is the index of the endpoint of lis of length j
    int predecessors[a.size()];
    int lis_len = 0;

    for (int i = 0 ; i < a.size() ; i++) {

        // binary search for the largest j such that the endpoint value is less
        // than the current value
        
        int lo = 1;
        int hi = lis_len;

        while (lo <= hi) {
            int mid = (lo + hi + 1) / 2;

            if (a[endpoints[mid]] < a[i]) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        // lo = length of longest prefix of a[i] + 1
        predecessors[i] = endpoints[lo - 1];
        endpoints[lo] = i;

        if (lo > lis_len) {
            lis_len = lo;
        }
    }

    vector<int> lis(lis_len);
    int k = endpoints[lis_len];

    for (int i = lis_len - 1 ; i >= 0 ; i--) {
        lis[i] = a[k];
        k = predecessors[k];
    }

    return lis;
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    vector<int> seq(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> seq[i];
    }

    vector<int> lis = LIS(seq);

    for (int i = 0 ; i < lis.size() ; i++) {
        cout << lis[i] << ' ';
    }
    cout << '\n';

    return 0;
}
