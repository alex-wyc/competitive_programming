#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    string line;

    getline(cin, line);

    set<string> uniques;

    uniques.insert(line);

    int len = line.size();

    for (int i = 0 ; i < len ; i++) {
        rotate(line.begin(), line.end() - 1, line.end());
        if (uniques.count(line) == 0) {
            uniques.insert(line);
        }
    }

    cout << uniques.size() << '\n';
    return 0;
}
