#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int N;
    cin >> N;

    int w = (int)sqrt(N);

    while (N % w != 0) {
        w--;
    }

    cout << w << ' ' <<  N / w << '\n';

    return 0;
}
