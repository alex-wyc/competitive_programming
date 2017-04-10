#include <iostream>
#include <queue>
#include <set>
#include <utility>

using namespace std;

pair<long, long> solve(long n, long k) {
    set<pair<long, long> > blocks;
    blocks.insert(make_pair(n, 1));

    while (k > 0) {
        //auto it = blocks.begin();
        //while (it != blocks.end()) {
        //    cout << "(" << (*it).first << ", " << (*it).second << ") ";
        //    it++;
        //}
        //cout << '\n';


        pair<long, long> a = *blocks.rbegin();
        blocks.erase(--blocks.end());

        long insert_count = a.second;

        if (insert_count >= k) {
            //cout << a.first << "\n";
            if (a.first % 2 == 1) {
                return make_pair(a.first / 2, a.first / 2);
            }
            else {
                return make_pair(a.first / 2, a.first / 2 - 1);
            }
        }

        k = k - insert_count;

        //if (a.second > 1) {
        //    blocks.insert(make_pair(a.first, a.second-1));
        //}

        if (a.first % 2 == 1) {
            long to_insert = a.first / 2;
            set<pair<long, long> >::iterator it = blocks.upper_bound(make_pair(to_insert, 0));
            if ((*it).first == to_insert) {
                pair<long, long> new_element = make_pair(to_insert, (*it).second+2 * insert_count);
                blocks.erase(it);
                blocks.insert(new_element);
            }
            else {
                pair<long, long> new_el = make_pair(to_insert, 2 * insert_count);
                blocks.insert(new_el);
            }
        }
        else {
            long to_insert = a.first / 2;
            set<pair<long, long> >::iterator it = blocks.upper_bound(make_pair(to_insert, 0));
            if ((*it).first == to_insert) {
                pair<long, long> new_element = make_pair(to_insert, (*it).second+insert_count);
                blocks.erase(it);
                blocks.insert(new_element);
            }
            else {
                pair<long, long> new_el = make_pair(to_insert, insert_count);
                blocks.insert(new_el);
            }

            to_insert = a.first / 2 - 1;
            it = blocks.upper_bound(make_pair(to_insert, 0));
            if ((*it).first == to_insert) {
                pair<long, long> new_element = make_pair(to_insert, (*it).second+insert_count);
                blocks.erase(it);
                blocks.insert(new_element);
            }
            else {
                pair<long, long> new_el = make_pair(to_insert, insert_count);
                blocks.insert(new_el);
            }
            //blocks.insert(make_pair(a.first / 2, insert_count));
            //blocks.insert(make_pair(a.first / 2 - 1, insert_count));
        }
    }

    //long a = (*blocks.rbegin()).first;
    ////cout << a << '\n';
    //if (a % 2 == 1) {
    //    return make_pair(a / 2, a / 2);
    //}
    //else {
    //    return make_pair(a / 2, a / 2 - 1);
    //}

    //priority_queue<long> pq;
    //pq.push(n);

    //for (int i = 0 ; i < k - 1 ; i++) {
    //    long a = pq.top(); pq.pop();

    //    if (a % 2 == 1) {
    //        pq.push(a / 2);
    //        pq.push(a / 2);
    //    }
    //    else {
    //        pq.push(a / 2);
    //        pq.push(a / 2 - 1);
    //    }
    //}

    //long a = pq.top();
    //if (a % 2 == 1) {
    //    return make_pair(a / 2, a / 2);
    //}
    //else {
    //    return make_pair(a / 2, a / 2 - 1);
    //}
}

int main(int argc, char *argv[]) {
    long n, k;
    int t;

    cin >> t;

    for (int i = 0 ; i < t ; i++) {
        cin >> n >> k;
        pair<long, long> result = solve(n, k);
        cout << "Case #" << (i + 1) << ": " << result.first << " " << result.second << '\n';
    }
    return 0;
}
