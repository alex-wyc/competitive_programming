#include <bits/stdc++.h>

using namespace std;

#define ALPHABET_SIZE 128 // default to ascii

class suffix_array {
    public:
    suffix_array(string text) {
        int n = text.size();
        vector<string> suffixes(n);
        for (int i = n - 1; i >= 0 ; i--) {
            suffixes.push_back(text.substr(i, n - i));
        }

        vector<pair<char, int> > to_sort(n);

        for (int i = 0 ; i < n ; i++) {
            // lol...
        }
    };
};
