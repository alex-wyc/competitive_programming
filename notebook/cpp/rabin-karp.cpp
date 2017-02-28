#include <bits/stdc++.h>

using namespace std;

#define P 2147483647 // random large prime number... (2^31 - 1 actually)
#define B 127 // chosen because asici... also prime
// redefine to be the number of diff characters present in string

long long mod(long long a, long long b) {
    return (a % b + b) % b; // correctly calculates mod if a < b
}

long long hash_val(vector<char> &to_hash, int s, int n) {
    // calculates the hash value of the substring of length n starting at s
    long long hv = 0;
    for (int i = 0 ; i < n ; i++) {
        hv = mod(mod(hv * B, P) + to_hash[s + i], P);
    }
    return hv;
}

bool check_equal_range(vector<char> &text, vector<char> &to_search, int s) {
    // checks if the two are actually equal
    int sz = to_search.size();
    for (int i = 0 ; i < sz ; i++) {
        if (text[s + i] != to_search[i]) {
            return false;
        }
    }
    return true;
}

int rabin_karp(vector<char> &text, vector<char> &to_search) {
    int n = text.size();
    int m = to_search.size();

    if (n < m) {
        return -1;
    }

    long long hash_pattern = hash_val(to_search, 0, m);
    long long hash_text = hash_val(text, 0, m);

    if (hash_pattern == hash_text) {
        //if (check_equal_range(text, to_search, 0)) {
            return 0;
        //}
    }

    long long leading_exp = 1;
    for (int i = 0 ; i < m - 1 ; i++) {
        leading_exp = mod(leading_exp * B, P);
    }


    for (int i = m ; i < n ; i++) {
        hash_text = mod(hash_text - mod(text[i - m] * leading_exp, P), P);
        hash_text = mod(hash_text * B, P);
        hash_text = mod(hash_text + text[i], P);

        if (hash_text == hash_pattern) {
            //if (check_equal_range(text, to_search, i - m + 1)) {
                return i - m + 1;
            //}
        }
    }

    return -1; // no match
}

int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    for (int i = 0 ; i < N ; i++) {
        string text, pattern;
        cin >> text >> pattern;

        vector<char> v_text(text.begin(), text.end());
        vector<char> v_pat(pattern.begin(), pattern.end());

        cout << rabin_karp(v_text, v_pat) << '\n';
    }
    return 0;
}
