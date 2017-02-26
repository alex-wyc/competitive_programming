#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <queue>

using namespace std;

#define EMPTY 0
#define VISITED 1
#define BLOCKED 2

typedef pair<int, int> coor;

int N, M;

typedef struct step {
    coor current;
    step *last;
} step;

bool in_bounds(int x, int y) {
    return (x >= 0) &&
           (x < N) &&
           (y >= 0) &&
           (y < M);
}

void print(queue<step> &s,int num)
{
    if(!num)
    {
        cout << endl;
        return;
    }
    step x= s.front();
    s.pop();
    cout << x.current.first << " " << x.current.second << ", ";
    s.push(x);
    print(s,--num);
}

bool do_not_intersect(step s1, step s2) {
    return true;
}

string solve(int **board, coor init, coor target) {
    queue<step> frontier;
    step initial;
    initial.current = init;
    initial.last = 0;

    frontier.push(initial);
    step *solution = 0;

    board[init.first][init.second] = VISITED;

    while (!frontier.empty()) {

        step current = frontier.front();
        frontier.pop();
        int x = current.current.first;
        int y = current.current.second;

        if (in_bounds(x + 2, y + 1)) {
            step to_push;
            to_push.current = make_pair(x + 2, y + 1);
            if (to_push.current == target) {
                if (solution) {
                    if (do_not_intersect(current, *solution)) {
                        return "No";
                    }
                }
                else {
                    solution = &current;
                }
            }
            to_push.last = &current;
            if (board[x + 2][y + 1] == EMPTY) {
                frontier.push(to_push);
                board[x + 2][y + 1] = VISITED;
            }
        }
        if (in_bounds(x + 2, y - 1)) {
            coor to_push = make_pair(x + 2, y - 1);
            if (to_push == target) {
                if (solved) {
                    return "No";
                }
                solved = true;
            }
            if (board[x + 2][y - 1] == EMPTY) {
                frontier.push(to_push);
                board[x + 2][y - 1] = VISITED;
            }
        }
        if (in_bounds(x - 2, y + 1)) {
            coor to_push = make_pair(x - 2, y + 1);
            if (to_push == target) {
                if (solved) {
                    return "No";
                }
                solved = true;
            }
            if (board[x - 2][y + 1] == EMPTY) {
                frontier.push(to_push);
                board[x - 2][y + 1] = VISITED;
            }
        }
        if (in_bounds(x - 2, y - 1)) {
            coor to_push = make_pair(x - 2, y - 1);
            if (to_push == target) {
                if (solved) {
                    return "No";
                }
                solved = true;
            }
            if (board[x - 2][y - 1] == EMPTY) {
                frontier.push(to_push);
                board[x - 2][y - 1] = VISITED;
            }
        }
        if (in_bounds(x + 1, y + 2)) {
            coor to_push = make_pair(x + 1, y + 2);
            if (to_push == target) {
                if (solved) {
                    return "No";
                }
                solved = true;
            }
            if (board[x + 1][y + 2] == EMPTY) {
                frontier.push(to_push);
                board[x + 1][y + 2] = VISITED;
            }
        }
        if (in_bounds(x + 1, y - 2)) {
            coor to_push = make_pair(x + 1, y - 2);
            if (to_push == target) {
                if (solved) {
                    return "No";
                }
                solved = true;
            }
            if (board[x + 1][y - 2] == EMPTY) {
                frontier.push(to_push);
                board[x + 1][y - 2] = VISITED;
            }
        }
        if (in_bounds(x - 1, y + 2)) {
            coor to_push = make_pair(x - 1, y + 2);
            if (to_push == target) {
                if (solved) {
                    return "No";
                }
                solved = true;
            }
            if (board[x - 1][y + 2] == EMPTY) {
                frontier.push(to_push);
                board[x - 1][y + 2] = VISITED;
            }
        }
        if (in_bounds(x - 1, y - 2)) {
            coor to_push = make_pair(x - 1, y - 2);
            if (to_push == target) {
                if (solved) {
                    return "No";
                }
                solved = true;
            }
            if (board[x - 1][y - 2] == EMPTY) {
                frontier.push(to_push);
                board[x - 1][y - 2] = VISITED;
            }
        }
    }

    return "Yes";
}

int main(int argc, char **argv) {
    int i, j, k, l, c;
    
    cin >> N >> M >> i >> j >> k >> l >> c;

    do {
        int **board = new int*[N]();
        for (int a = 0 ; a < N ; a++) {
            board[a] = new int[M]();
        }

        int x, y;
        for (int a = 0 ; a < c ; a++) {
            cin >> x >> y;
            board[x - 1][y - 1] = BLOCKED;
        }

        cout << solve(board, make_pair(i - 1, j - 1), make_pair(k - 1, l - 1)) << endl;

        cin >> N >> M >> i >> j >> k >> l >> c;
    } while (N);
}
