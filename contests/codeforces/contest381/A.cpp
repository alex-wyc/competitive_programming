#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    unsigned long long N, a, b, c;

    cin >> N >> a >> b >> c;

    switch (N % 4) {
        case 0:
            cout << 0;
            break;
        case 1:
            cout << min(3 * a, min(a + b, c));
            break;
        case 2:
            cout << min(2 * a, min(b, 2 * c));
            break;
        case 3:
            cout << min(a, min(b + c, 3 * c));
            break;
    }
    cout << '\n';
    return 0;
}
