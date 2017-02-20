#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
    int N;
    cin >> N;

    if (N % 4 != 0) {
        cout << "===" << '\n';
        return 0;
    }

    int per_genome = N / 4;
    int a = 0, g = 0, c = 0, t = 0;

    char *sequence = (char *)malloc(N);
    vector<int> holes;

    for (int i = 0 ; i < N ; i++) {
        char ch;
        cin >> ch;

        sequence[i] = ch;

        switch (ch) {
            case 'A':
                a++;
                break;
            case 'G':
                g++;
                break;
            case 'C':
                c++;
                break;
            case 'T':
                t++;
                break;
            case '?':
                holes.push_back(i);
                break;
        }
    }

    if (a > per_genome || g > per_genome || c > per_genome || t > per_genome) {
        cout << "===" << '\n';
        return 0;
    }

    while (a < per_genome) {
        sequence[holes.back()] = 'A';
        holes.pop_back();
        a++;
    }

    while (g < per_genome) {
        sequence[holes.back()] = 'G';
        holes.pop_back();
        g++;
    }

    while (c < per_genome) {
        sequence[holes.back()] = 'C';
        holes.pop_back();
        c++;
    }

    while (t < per_genome) {
        sequence[holes.back()] = 'T';
        holes.pop_back();
        t++;
    }

    for (int i = 0 ; i < N ; i++) {
        cout << sequence[i];
    }
    cout << '\n';
    return 0;
}
