#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int get_problem_index(char c) {
    return c - 'A';
}

int main(int argc, char **argv) {
    int t;
    char problem;
    string result;
    char res;
    cin >> t;
    int total_time = 0;
    int total_penalty = 0;
    vector<int> penalty_time;
    
    while (t != -1) {
        cin >> problem >> result;
        res = result[0];
        if (res == 'r') { // correct
            total_time += t;
            int i = get_problem_index(problem);

            if (i < penalty_time.size()) {
                total_penalty += penalty_time[i];
            }
        }
        else { // incorrect
            int i = get_problem_index(problem);
            if (i > penalty_time.size()) {
                penalty_time.resize(i + 1);
            }

            penalty_time[i] += 20;
        }
        cin >> t;
    }
    
    cout << total_time << ' ' << total_penalty << '\n';
}
