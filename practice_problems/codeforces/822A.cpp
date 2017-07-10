// http://codeforces.com/problemset/problem/822/A

#include <iostream>
#include <fstream>

using namespace std;

int fact(int n) {
    int product = 1;
    for (int i = 1 ; i <= n ; i++) {
        product *= i;
    }
    return product;
}

int main(int argc, char *argv[]) {
    int a, b;

    cin >> a >> b;

    if (a <= b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    // b is the smaller number
    
    cout << fact(b) << '\n';
    return 0;
}
