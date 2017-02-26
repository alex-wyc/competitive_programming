#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>

#define R 1.0

using namespace std;

typedef pair<double, double> coordinate;

coordinate get_forth_coor(coordinate v1, coordinate v2, coordinate v3) {
    // given three coordinates of a parallogram, find the forth one
    // v1 is the bottom one, v2 is to the left, v3 is to the right, v4 is on top
    double x = v2.first - v1.first + v3.first;
    double y = v2.second - v1.second + v3.second;
    return make_pair(x, y);
}

coordinate get_second_row_coor(coordinate v1, coordinate v2) {
    // specifically designed to get second row coordinate, the y values should
    // equal to R
    double x = (v1.first + v2.first) / 2;
    double y = v1.second + sqrt(4 * R * R - pow(x - v1.first, 2));
    return make_pair(x, y);
}

coordinate calculate_final_position(vector<coordinate> init_positions) {
    // main method for calculating final position
    // first calculate second row, then use past two rows to caculate next row
    // using parallograms
    int i;

    // edge case: 1 ball to begin with
    if (init_positions.size() == 1) {
        return init_positions[0];
    }

    vector<coordinate> last_row; // second row

    for (int i = 0 ; i < init_positions.size() - 1 ; i++) {
        last_row.push_back(get_second_row_coor(init_positions[i], init_positions[i+1]));
    }

    // edge case: 2 balls to begin with
    if (last_row.size() == 1) {
        return last_row[0];
    }

    // else
    vector<coordinate> last_two_rows(init_positions.begin(), init_positions.end());
    vector<coordinate> current;

    while (current.size() != 1) {
        current.clear();
        for (i = 0 ; i < last_row.size() - 1 ; i++) {
            current.push_back(get_forth_coor(last_two_rows[i + 1],
                                             last_row[i],
                                             last_row[i + 1]));
        }

        last_two_rows = last_row;
        last_row = current;
    }

    return current[0];
}

int main(int argc, char *argv[]) {
    int N, i;
    double current;
    coordinate result;

    vector<coordinate> init_positions;

    // set percision
    cout << setiosflags(ios::fixed) << setprecision(4);

    cin >> N;

    do { // input scanning
        for (i = 0 ; i < N ; i++) {
            cin >> current;
            init_positions.push_back(make_pair(current, R));
        }

        result = calculate_final_position(init_positions);

        cout << result.first << ' ' << result.second << '\n';

        init_positions.clear();

        cin >> N;
    } while (N != 0);

    return 0;
}
