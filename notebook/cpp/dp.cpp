/*******************************************************************************
 * Dynamic Programming Problems                                                *
 *                                                                             *
 * Authors                                                                     *
 *  Yicheng Wang                                                               *
 *                                                                             *
 * Description                                                                 *
 *  Various Dynamic Programming problems taken from CLRS and cf                *
 *                                                                             *
 ******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

// cut rod example from clrs
int cut_rod(int n, int *prices) {
    vector<int> results(n + 1, -1);
    results[0] = 0;
    int q;
    for (int i = 1 ; i <= n ; i++) {
        q = -1;
        for (int j = 1 ; j <= i ; j++) {
            q = max(q, prices[j - 1] + results[i - j]);
        }
        results[i] = q;
    }
    return results[n];
}

// give a list of int of where parenthesis lies
vector<int> matrix_chain_multiplication(vector<int> dimensions) {

}

int main(int argc, char *argv[]) {
    int prices[]{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    cout << cut_rod(10, prices) << '\n';
    return 0;
}
