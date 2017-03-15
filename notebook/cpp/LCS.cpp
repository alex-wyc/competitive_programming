#include <bits/stdc++.h>

using namespace std;

vector<int> longest_common_subsequence(vector<int> &a,vector<int> &b) {

    int lcs_lookup[a.size()][b.size()];

    for (int i = 0 ; i < a.size() ; i++) {
        lcs_lookup[i][0] = 0; // nothing matches w/ empty string
    }

    for (int i = 0 ; i < b.size() ; i++) {
        lcs_lookup[0][i] = 0; // nothing matches w/ empty string
    }

    for (int i = 1 ; i < a.size() ; i++) {
        for (int j = 1 ; j < b.size() ; j++) {
            if (a[i] == b[j]) {
                lcs_lookup[i][j] = lcs_lookup[i-1][j-1] + 1;
            }
            else {
                lcs_lookup[i][j] = max(lcs_lookup[i-1][j], lcs_lookup[i][j-1]);
            }
        }
    }

    // return lcs_lookup[a.size() - 1][b.size() - 1]; <- stop here to return length only
    
    // backtrack to find actual sequence
    int val, i, j;
    vector<int> lcs;
    i = a.size() - 1;
    j = b.size() - 1;

    val = lcs_lookup[i][j];

    while (val) {
        if (lcs_lookup[i - 1][j - 1] == val) {
            i--; j--;
        }
        else if (lcs_lookup[i - 1][j] < val && lcs_lookup[i][j - 1] < val) {
            lcs.push_back(a[i]);
            i--; j--;
        }
        else if (lcs_lookup[i - 1][j] < val) {
            j--;
        }
        else {
            i--;
        }
        val = lcs_lookup[i][j];
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main(int argc, char *argv[]) {
    vector<int> a;
    vector<int> b;
    int alen, blen;
    int x;

    cin >> alen >> blen;

    for (int i = 0 ; i < alen ; i++) {
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0 ; i < blen ; i++) {
        cin >> x;
        b.push_back(x);
    }

    vector<int> lcs = longest_common_subsequence(a, b);
    for (int i = 0 ; i < lcs.size() ; i++) {
        cout << lcs[i] << " ";
    }
    cout << '\n';

    // cout << longest_common_subsequence(a, b) << '\n';

    return 0;
}
