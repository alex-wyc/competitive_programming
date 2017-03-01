#include <bits/stdc++.h>

using namespace std;

#define ALPHABET_SIZE 128 // default to ascii

class suffix_array {
    vector<string> suffixes;
    vector<int> sorted_suffix;
    vector<int> inverse_sorted_suffix;

  public:
    suffix_array(string text) {
        int n = text.size();

        for (int i = n - 1; i >= 0 ; i--) {
            suffixes.push_back(text.substr(i, n - i));
        }

        sorted_suffix = vector<int>(n);
        inverse_sorted_suffix = vector<int>(n);

        vector<vector<int> > buckets(ALPHABET_SIZE); // change for other keysets
        int same_rank[n]; // this is a lookup table of where the sorted range ends

        for (int i = 0 ; i < n ; i++) {
            buckets[suffixes[i].at(0)].push_back(i); // change for other keysets
        }

        vector<int> uncertain_range(n);

        int x = 0;
        int o;
        for (int i = 0 ; i < ALPHABET_SIZE ; i++) {
            o = x;
            if (buckets[i].size() > 1) {
                sort(buckets[i].begin(), buckets[i].end());
            }
            for (int j = 0 ; j < buckets[i].size() ; j++) {
                sorted_suffix[x] = buckets[i][j];
                inverse_sorted_suffix[buckets[i][j]] = x;
                x++;
            }
            for (; o < x ; o++) {
                uncertain_range[o] = x;
            }
        }

        char current;
        bool continuing = true;

        for (int step = 1 ; continuing && step < n ; step = step * 2) {
            continuing = false;
            int i = 0;
            while (i < n) {
                if (uncertain_range[i] != i + 1) { // this range is not yet sorted
                    continuing = true;
                    int endpt = uncertain_range[i];

                    vector<int> bucketss(n, -1);
                    for (int j = i ; j < endpt ; j++) {
                        // we sort this range based on what we know
                        bucketss[inverse_sorted_suffix[sorted_suffix[j] - step]] = sorted_suffix[j];
                    }

                    int x = 0;
                    vector<int> correct_order(endpt - i);
                    vector<int> uncertain_suffix_range(endpt - i);
                    for (int j = 0 ; j < n ; j++) {
                        if (bucketss[j] != -1) {
                            correct_order[x] = bucketss[j];
                            uncertain_suffix_range[x] = uncertain_range[j];
                            x++;
                        }
                    }

                    int last_uncertain_range = uncertain_suffix_range[0];
                    int last_uncertain_index = i;
                    for (int j = i ; j < endpt ; j++) {
                        // update everything this is scary
                        sorted_suffix[j] = correct_order[j - i];
                        inverse_sorted_suffix[correct_order[j - i]] = j;

                        if (uncertain_suffix_range[j - i] != last_uncertain_range) {
                            for (int k = j - 1 ; k >= last_uncertain_index ; k--) {
                                uncertain_range[k] = j;
                            }
                            last_uncertain_range = uncertain_suffix_range[j - i];
                            last_uncertain_index = j;
                        }
                    }

                    i = endpt; // we jump to the end eventually
                }
                i++;
            }
        }
    };

    int search_first(string pattern) {
        // because sorted_suffix exists, we can do a binary search
        int l = 0, r = sorted_suffix.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (suffixes[sorted_suffix[m]].compare(pattern) > 0) {
                r = m - 1;
            }
            else if (suffixes[sorted_suffix[m]].compare(pattern) == 0) {
                return suffixes.size() - sorted_suffix[m] - 1;
            }
            else {
                l = m + 1;
            }
        }

        //if (suffixes[sorted_suffix[l]].compare(pattern) == 0) {
        //    return suffixes.size() - sorted_suffix[l] - 1;
        //}
        return -1;
    };

    vector<int> search(string pattern) {
        // because sorted_suffix exists, we can search for *all* occurences via
        // two binary searches
    };
};

int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    for (int i = 0 ; i < N ; i++) {
        string text, pattern;
        cin >> text >> pattern;

        suffix_array sa(text);

        cout << sa.search_first(pattern) << '\n';
    }
    return 0;
}
