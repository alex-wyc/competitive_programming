#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int P, K, i = 0, j;

    unsigned long long N;
    unsigned long long a;

    cin >> P;

    while (i < P) {
        N = 0;
        cin >> i >> K;

        // we can separate the left and right leg strides
        K /= 2;

        // count of two stide steps is at least half
        int count2 = K / 2, count1 = K - (count2 * 2);

        while (count2 >= count1) {
            a = 1;

            // num steps choose a
            for (j = 0 ; j < count1 ; j++) {
                a *= (count2 + count1 - j);
                a /= (j + 1);
            }

            // all rearrangements of the single and double strides
            N += (a * a);

            count2--;
            count1+=2;
        }

        cout << i << ' ' << N << '\n';
    }

    return 0;
}
