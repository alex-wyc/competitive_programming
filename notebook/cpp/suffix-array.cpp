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

        for (int i = 0 ; i< n ; i++) {
            cout << suffixes[i] << " ";
        }
        cout << '\n';

        sorted_suffix = vector<int>(n);
        inverse_sorted_suffix = vector<int>(n);

        vector<vector<int> > buckets(ALPHABET_SIZE);
        int same_rank[n]; // this is a lookup table of where the sorted range ends

        for (int i = 0 ; i < n ; i++) {
            buckets[suffixes[i].at(0)].push_back(i);
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

        for (int i = 0 ; i < n ; i++) {
            cout << sorted_suffix[i] << " " << inverse_sorted_suffix[i] << " " << uncertain_range[i] << "\n";
        }

        char current;
        bool continuing = true;

        for (int step = 1 ; continuing && step < n ; step = step * 2) {
            cout << "*** " << step << " ***\n";
            continuing = false;
            int i = 0;
            while (i < n) {
                if (uncertain_range[i] != i + 1) { // this range is not yet sorted
                    continuing = true;
                    int endpt = uncertain_range[i];

                    cout << "---\n";
                    for (int j = i ; j < endpt ; j++)
                        cout << suffixes[sorted_suffix[j]] << ' ';
                    cout << "\n";

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

                    for (int j = 0 ; j < n ; j++) {
                        cout << sorted_suffix[j] << " ";
                    }
                    cout << "\n";
                    for (int j = 0 ; j < n ; j++) {
                        cout << inverse_sorted_suffix[j] << " ";
                    }
                    cout << "\n";
                    for (int j = 0 ; j < n ; j++) {
                        cout << uncertain_range[j] << " ";
                    }
                    cout << "\n";

                    cout << "---\n";
                    i = endpt; // we jump to the end eventually
                }
                i++;
            }
        }

        for (int i = 0 ; i < sorted_suffix.size() ; i++) {
            cout << suffixes[sorted_suffix[i]] << '\n';
        }
    };
};

int main(int argc, char *argv[]) {
    string blah;
    cin >> blah;
    suffix_array sa(blah);
    return 0;
}
