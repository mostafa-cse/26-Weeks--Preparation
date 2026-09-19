#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
vector<vector<int>> a(3, vector<int>(3));
int zr, zc;
int isPossible() {
    vector<int> flat;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] > 0) {
                flat.push_back(a[i][j]);
            }
        }
    }
    int inv = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            inv += (flat[i] > flat[j]);
        }
    }
    // n is odd then only inversion matter : must be inversion even
    // n is even then inversion and empty cell will be matter : must be odd
    return !(inv & 1);
}
int getDistance(int x, int i, int j) {
    int vr = (x - 1) / 3;
    int vc = (x - 1) % 3;
    return abs(vr - i) + abs(vc - j);
}
int totalManhattan() {
    int dis = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 0) continue;
            dis += getDistance(a[i][j], i, j);
        }
    }
    return dis;
}
bool solved = false;
//                D  L
vector<int> dr = {1, 0, 0, -1};
vector<int> dc = {0, -1, 1, 0};
vector<int> opposite = {3, 2, 1, 0};
int IDA(int g, int h, int r, int c, int preDir, int curTarget) {
    int f = g + h;
    if (f > curTarget) {
        return f;
    }
    if (h == 0) {
        solved = true;
        return g;
    }

    int cur = 1e9;
    for (int dir = 0; dir < 4; dir++) {
        if (preDir == -1 or (preDir != -1 and dir != opposite[preDir])) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr >= 0 and nc >= 0 and nr <= 2 and nc <= 2) {
                int val = a[nr][nc];

                int old_h = getDistance(val, nr, nc);
                int new_h = getDistance(val, r, c);
                int next_h = h - old_h + new_h;

                a[r][c] = val;
                a[nr][nc] = 0;

                int res = IDA(g + 1, next_h, nr, nc, dir, curTarget);
                if (solved) return res;
                cur = min(cur, res);

                a[r][c] = 0;
                a[nr][nc] = val;
            }
        }
    }
    return cur;
}
void solve() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                zr = i;
                zc = j;
            }
        }
    }

    if (isPossible()) {
        int initial_distance = totalManhattan();
        solved = false;

        int target  = initial_distance;
        while (!solved) {
            int cur = IDA(0, initial_distance, zr, zc, -1, target);
            if (solved) {
                break;
            }
            target = cur;
        }
        cout << target << endl;
    } else {
        cout << "impossible" << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}

