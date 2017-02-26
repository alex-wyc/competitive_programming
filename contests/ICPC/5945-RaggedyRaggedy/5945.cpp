#include <iostream>
#include <priority_queue>
#include <vector>
#include <sstream>
#include <string.h>

using namespace std;

#typedef pair<vector<int>, int> arrangement

#define make_arr(v, r) make_pair(v,r)

class compare_r {
  public:
    bool compare(arrangement a, arrangement b) {
        return a.second > b.second;
    }
}

arrangement generate_greedy(vector<int> lengths, int L, int l_of_l) {
    vector<int> breaks;
    int r = 0;
    int current_len = 0;

    for (int i = 0 ; i < l_of_l ; i++) {
        if(L - current_len < lengths[i]) {
            breaks.push_back(i);
            r += (l - current_len) ** (l - current_len);
            current_len = 0;
        }
        current_len += lengths[i] + 1;
    }

    return make_pair(breaks, r);
}

void print_words(vector<string> words, vector<int> breaks, int l_of_l) {
    for (int i = 0 ; i < l_of_l ; i++) {
        for (int j = breaks[i] ; j < breaks[i+1] ; j++) {
            cout << words[j] << " ";
        }
        cout << '\n';
    }
    cout << "===\n";
}

void solve(int L, vector<string> words, vector<int> lengths, int l_of_l) {
    priority_queue<arrangement, vector<arrangement>, compare_r> frontier;
    arrangement current_min;
    arrangement current;

    frontier.push(generate_greedy(lengths, L, l_of_l));

    while (!frontier.empty()) {
        current = frontier.pop();
        // TODO
    }

    print_words(words, current_min.first, l_of_l);
}

int main(int argc, char *argv[]) {
    int L, l_of_l, i;
    vector<string> paragraph;
    vector<int> lengths;
    string line;
    string tmp;

    getline(cin, line);

    while (getline(cin, line)) {
        if (line.compare("0") == 0) {
            break;
        }

        L = stoi(line);
        i = 0;
        l_of_l = 0;
        paragraph.clear();
        lengths.clear();

        while (getline(cin, line)) {
            if (line.empty())
                break;

            isstringstream words(line);
            
            while (words) {
                words >> tmp;
                paragraph[i] = tmp;
                lengths[i] = strlen(tmp);
                i++;
                l_of_l++;
            }
        }

        solve(L, paragraph, lengths, l_of_l);
    }

    return 0;
}
