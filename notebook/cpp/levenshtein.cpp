#include <bits/stdc++.h>

using namespace std;

int levenshtein_distance(string &a, string &b) {
    // computes the levenshtein edit distance (insertion, deletion and
    // substitution) of two strings
    int dist_lookup[a.size()][b.size()];

    for (int i = 0 ; i < a.size() ; i++) {
        dist_lookup[i][0] = i;
    }

    for (int j = 0 ; j < b.size() ; j++) {
        dist_lookup[0][j] = j;
    }

    for (int i = 1 ; i < a.size() ; i++) {
        for (int j = 1 ; j < b.size() ; j++) {
            int sub_cost = (a[i] == b[j]) ? 0 : 1;
            dist_lookup[i][j] = min(min(dist_lookup[i - 1][j] + 1, // deletion
                                        dist_lookup[i][j - 1] + 1), // insertion
                                        dist_lookup[i - 1][j - 1] + sub_cost);
        }
    }

    return dist_lookup[a.size() - 1][b.size() - 1];
}

int main(int argc, char *argv[]) {
    string a, b;
    cin >> a;
    cin >> b;
    cout << levenshtein_distance(a, b) << '\n';
    return 0;
}
