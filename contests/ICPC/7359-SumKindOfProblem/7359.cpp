#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned int sum(unsigned int n) {
    // the sum of the first n #'s
    return (1 + n) * n / 2;
}

unsigned int sum_odd(unsigned int n) {
    // the sum of the first n odd #'s
    // funzie little fact first n odd number is n^2
    return n * n;
}

unsigned int sum_even(unsigned int n) {
    // the sum of the first n even #'s
    // it's acutlaly a bit harder, so... subtraction!
    return 2 * sum(n);
}

int main() {
    unsigned int N;
    int P, K, i, n;
    
    cin >> P;

    for (i = P ; i ; i--) {
        cin >> n >> N;
        cout << n << ' ' << sum(N) << ' ' << sum_odd(N) << ' ' << sum_even(N) << '\n';
    }

    return 0;
}
