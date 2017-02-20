#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
    int n, m;

    cin >> n >> m;

    char empty_row[m] = {'.'};
    string empty_row();

    set<string> rows;

    for (int i = 0 ; i < n ; i++) {
        string line;
        get_line(cin, line);

        rows.insert(line);
    }

    switch (rows.size()) {
        case 1: // empty board or full board
            cout << "YES" << '\n';
            break;
        case 2: // empty board + pattern OR mismatched patterns
            if (rows.count)
                break;
        default: // at least 2 diff patterns
            cout << "NO" << '\n';
            break;
    }

    return 0;
}
