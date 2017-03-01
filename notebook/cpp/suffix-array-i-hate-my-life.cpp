#include <bits/stdc++.h>

using namespace std;

#define ALPHABET_SIZE 128 // default to ascii

class suffix_array {
    public:
    suffix_array(string text) {
        int n = text.size();
        vector<string> suffixes;
        for (int i = n - 1 ; i >= 0 ; i--) {
            suffixes.push_back(text.substr(i, n - i));
        }

        for (int i = 0 ; i< n ; i++) {
            cout << suffixes[i] << " ";
        }
        cout << '\n';

        // we can do a default sort on lexigraphical order, but there is a
        // better way

        vector<vector<int> > buckets(ALPHABET_SIZE);

        for (int i = 0 ; i < n ; i++) {
            buckets[suffixes[i].at(0)].push_back(i);
        }

        vector<int> sorted_suffix(n);
        vector<int> inverse_sorted_suffix(n); // iss[i] = j iff ss[j] = i
        vector<int> bundle(n);

        int x = 0;
        for (int i = 0 ; i < ALPHABET_SIZE ; i++) {
            if (buckets[i].size() > 1) {
                sort(buckets[i].begin(), buckets[i].end());
            }
            for (int j = 0 ; j < buckets[i].size() ; j++) {
                sorted_suffix[x] = buckets[i][j];
                inverse_sorted_suffix[buckets[i][j]] = x; // iss == rankings
                x++;
            }
        }

        for (int i = 0 ; i < sorted_suffix.size() ; i++) {
            cout << suffixes[sorted_suffix[i]] << '\n';
        }

        for (int i = 0 ; i < n ; i++) {
            cout << sorted_suffix[i] << " " << inverse_sorted_suffix[i] << "\n";
        }

        cout << "============\n";

        char current;
        bool continuing = true;

        for (int step = 1 ; continuing && step < n ; step = step * 2) {
            cout << "***" << step << "***\n";
            x = 0;
            current = -1; //suffixes[sorted_suffix[0]].at(step - 1);
            continuing = false;
            for (int i = 0 ; i < n ; i++) {
                if (current == -1) {
                    if (suffixes[sorted_suffix[i]].size() <= step) {
                        x++;
                        continue;
                    }
                    current = suffixes[sorted_suffix[i]].at(step - 1);
                }

                if (suffixes[sorted_suffix[i]].size() <= step ||
                    suffixes[sorted_suffix[i]].at(step - 1) != current) {

                    if (suffixes[sorted_suffix[i]].size() <= step) {
                        current = -1;
                    }
                    else {
                        current = suffixes[sorted_suffix[i]].at(step - 1);
                    }

                    if (x == i - 1) { x++; continue; }

                    cout << "---\n";
                    for (int m = x ; m < i ; m++) {
                        cout << suffixes[sorted_suffix[m]] << " ";
                    }
                    cout << '\n';

                    // we are in a new range
                    // sort!
                    // range is [x, i-1]
                    // note that the second letter and above are also in the suffix
                    // array, and we can access their index via the iss
                    vector<int> bucketss(n, -1);
                    for (int j = x ; j < i ; j++) {
                        bucketss[inverse_sorted_suffix[sorted_suffix[j] - step]] = j;
                    }

                    for (int j = 0 ; j < n ; j++) {
                        cout << bucketss[j] << ' ';
                    }
                    cout << '\n';

                    vector<int> tmp(sorted_suffix.begin() + x, sorted_suffix.begin() + i);

                    for (int k = 0 ; k < tmp.size() ; k++) {
                        cout << suffixes[tmp[k]] << " ";
                    }
                    cout << '\n';

                    int o = x;

                    for (int k = 0 ; k < n ; k++) {
                        if (bucketss[k] != -1) {
                            cout << bucketss[k] - o << ' ';
                            sorted_suffix[x] = tmp[bucketss[k] - o];
                            inverse_sorted_suffix[tmp[bucketss[k] - o]] = x;
                            x++;
                            //cout << suffixes[sorted_suffix[x]] << " ";
                            continuing = true;
                        }
                    }
                    cout << "\n";
                    cout << "---\n";
                }
            }
            for (int i = 0 ; i < sorted_suffix.size() ; i++) {
                cout << suffixes[sorted_suffix[i]] << '\n';
            }
            cout << "============\n";
        }

        for (int i = 0 ; i < sorted_suffix.size() ; i++) {
            cout << suffixes[sorted_suffix[i]] << '\n';
        }
    };

    int search(string pattern) {
        return 0;
    };
};

int main(int argc, char *argv[]) {
    suffix_array sa("cabages");
    //int N;
    //cin >> N;

    //for (int i = 0 ; i < N ; i++) {
    //    string text, pattern;
    //    cin >> text >> pattern;
    //    suffix_array sa(text);
    //    cout << sa.search(pattern) << '\n';
    //}
    return 0;
}
