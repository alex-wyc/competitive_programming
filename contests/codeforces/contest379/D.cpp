#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> KING_LOC;

typedef struct piece {
    char t;
    long long x;
    long long y;
    bool blocked;

    piece() {t = x = y = blocked = 0;}
    piece(char T, int xv, int yv) {
        t = T;
        x = xv;
        y = yv;
        blocked = false;
    }

    bool operator < (const piece & B) const {
        return ((abs(x - KING_LOC.first) + abs(y - KING_LOC.second)) < (abs(B.x - KING_LOC.first) + abs(B.y - KING_LOC.second)));
    }
} piece;

bool check_bishop(piece A, piece B) {
    return (A.x - B.x) == (A.y - B.y);
}

bool check_rook(piece A, piece B) {
    return (A.x == B.x) || (A.y == B.y);
}

bool check_queen(piece A, piece B) {
    return check_bishop(A, B) || check_rook(A, B);
}

string solve(vector<piece> pieces, piece k, int N) {
    bool blocked[8] = {0};
    for (int i = 0 ; i < N ; i++) {
        piece c = pieces[i];
        if (c.y == k.y) {
            if (c.x > k.x) {
                if (!blocked[0]) {
                    if (c.t == 'R' || c.t == 'Q') {
                        return "YES";
                    }
                    else {
                        blocked[0] = true;
                    }
                }
            }
            else {
                if (!blocked[1]) {
                    if (c.t == 'R' || c.t == 'Q') {
                        return "YES";
                    }
                    else {
                        blocked[1] = true;
                    }
                }
            }
        }
        else if(c.x == k.x) {
            if (c.y > k.y) {
                if (!blocked[2]) {
                    if (c.t == 'R' || c.t == 'Q') {
                        return "YES";
                    }
                    else {
                        blocked[2] = true;
                    }
                }
            }
            else {
                if (!blocked[3]) {
                    if (c.t == 'R' || c.t == 'Q') {
                        return "YES";
                    }
                    else {
                        blocked[3] = true;
                    }
                }
            }
        }

        else if ((c.x - k.x) == (c.y - k.y)) {
            if (c.x > k.x) {
                if (!blocked[4]) {
                    if (c.t == 'B' || c.t == 'Q') {
                        return "YES";
                    }
                    else {
                        blocked[4] = true;
                    }
                }
            }
            else {
                if (!blocked[5]) {
                    if (c.t == 'B' || c.t == 'Q') {
                        return "YES";
                    }
                    else {
                        blocked[5] = true;
                    }
                }
            }
        }

        else if ((c.x - k.x) == -(c.y - k.y)) {
            if (c.x > k.x) {
                if (!blocked[6]) {
                    if (c.t == 'B' || c.t == 'Q') {
                        return "YES";
                    }
                    else {
                        blocked[6] = true;
                    }
                }
            }
            else {
                if (!blocked[7]) {
                    if (c.t == 'B' || c.t == 'Q') {
                        return "YES";
                    }
                    else {
                        blocked[7] = true;
                    }
                }
            }
        }
    }
    return "NO";
}

int main(int argc, char *argv[]) {
    int N;
    long long x, y;
    char t;

    cin >> N;

    vector<piece> pieces(N);

    cin >> KING_LOC.first >> KING_LOC.second;

    for (int i = 0 ; i < N ; i++) {
        cin >> t >> x >> y;
        pieces[i] = piece(t, x, y);
    }

    sort(pieces.begin(), pieces.end());

    //for (int i = 0 ; i < N ; i++) {
    //    cout << pieces[i].t << ' ' << pieces[i].x << ' ' << pieces[i].y << '\n';
    //}
    
    piece king = piece('K', KING_LOC.first, KING_LOC.second);

    cout << solve(pieces, king, N) << '\n';

    return 0;
}
