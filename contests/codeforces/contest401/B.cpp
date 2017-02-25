#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    char a;
    vector<int> sherlock(n);
    multiset<int> moriarty1;
    multiset<int> moriarty2;

    for (int i = 0 ; i < n ; i++) {
        cin >> a;
        sherlock[i] = a - '0';
    }

    for (int i = 0 ; i < n ; i++) {
        cin >> a;
        moriarty1.insert(a - '0');
        moriarty2.insert(a - '0');
    }

    int get_min = 0;
    int give_max = 0;

    for (int digit: sherlock) {
        auto itlow = moriarty1.lower_bound(digit);
        if (itlow == moriarty1.end()) {
            // nothing is before digit
            get_min++;
            moriarty1.erase(moriarty1.begin());
        }
        else {
            moriarty1.erase(itlow);
        }

        itlow = moriarty2.lower_bound(digit + 1); // beat sherlock!
        if (itlow == moriarty2.end()) {
            moriarty2.erase(moriarty2.begin());
        }
        else {
            give_max++;
            moriarty2.erase(itlow);
        }
    }

    cout << get_min << '\n';
    cout << give_max << '\n';

    return 0;
}
