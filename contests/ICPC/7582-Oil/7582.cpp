#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

#define MAX_N 2000

pair<int, int> *endpoints;

int N;

// sort the array of endpoints first by y, then by x
// sorted by quicksort
void sort_by_y(pair<int, int> *endpoints, int left, int right) {
    int mininum = (left + right) / 2;

    int i = left;
    int r = right;
    int 
    return;
}

unsigned long calculate_max_deposits(int index) {
    pair<int, int> current = endpoints[index];
    return 0;
}

int main(int argc, char *argv[]) {

    int i = 0;
    unsigned long max_deposit, current_result;

    // process input

    cin >> N;

    endpoints = (pair<int, int> *)malloc(sizeof(pair<int, int>) * N * 2);

    for (i = 0 ; i < N ; i++) {
        cin >> endpoints[2 * i].first >> endpoints[2 * i + 1].first;
        cin >> endpoints[2 * i].second;
        endpoints[2 * i + 1].second = endpoints[2 * i].second;
    }

    max_deposit = 0;

    sort_by_y(endpoints, 0, N);

    for (i = 0 ; i < N * 2 ; i++) {
        current_result = calculate_max_deposits(i);
        if (current_result > max_deposit) {
            max_deposit = current_result;
        }
    }

    cout << max_deposit;

    return 0;
}
