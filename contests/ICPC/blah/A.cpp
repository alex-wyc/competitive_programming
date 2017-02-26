#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int N, w, l, h, each_can, m, door_w, door_h;
    unsigned long long room_area;

    cin >> N >> w >> l >> h >> each_can >> m;

    while (N || w || l || h || each_can || m) {

        room_area = w * l + w * h * 2 + l * h * 2;

        for (int i = 0 ; i < m ; i++) {
            cin >> door_w >> door_h;
            room_area -= (door_w * door_h);
        }

        cout << (room_area * N + each_can - 1) / each_can << '\n';

        cin >> N >> w >> l >> h >> each_can >> m;
    }

    return 0;
}
