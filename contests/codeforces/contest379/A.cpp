#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    unsigned long long N;
    unsigned long long ACount = 0, DCount = 0;
    char c;
    cin >> N;

    for (unsigned long long i = 0 ; i < N ; i++) {
        cin >> c;
        if (c == 'A') {
            ACount++;
        }
        else {
            DCount++;
        }
    }

    if (ACount == DCount) {
        cout << "Friendship\n";
    }
    else if (ACount > DCount) {
        cout << "Anton\n";
    }
    else {
        cout << "Danik\n";
    }

    return 0;
}
