#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

bool can_finish(priority_queue<long, vector<long>, greater<long> > &parts, priority_queue<long> &engineers) {
    //cout << parts.size() << '\n';
    long can_look, req_look;

    while (!(engineers.empty() || parts.empty())) {
        can_look = engineers.top();
        engineers.pop();

        if (can_look > parts.size()) {
            can_look = parts.size();
        }

        for (long i = 0 ; i < can_look ; i++) {
            req_look = parts.top();
            parts.pop();
            if (req_look != 1) {
                parts.push(req_look - 1);
            }
        }
    }

    return parts.empty();
}

int main(int argc, char *argv[]) {
    long num_parts, num_eng, c, e;
    cin >> num_parts >> num_eng;

    while (num_parts != 0 && num_eng != 0) {
        priority_queue<long, vector<long>, greater<long> > to_examine;
        priority_queue<long> engineers;
        for (long i = 0 ; i < num_parts ; i++) {
            cin >> c >> e;

            for (long j = 0 ; j < c ; j++) {
                to_examine.push(e);
            }
        }

        for (long i = 0 ; i < num_eng ; i++) {
            cin >> c >> e;

            for (long j = 0 ; j < c ; j++) {
                engineers.push(e);
            }
        }

        cout << can_finish(to_examine, engineers) << '\n';
        cin >> num_parts >> num_eng;
    }

    return 0;
}
