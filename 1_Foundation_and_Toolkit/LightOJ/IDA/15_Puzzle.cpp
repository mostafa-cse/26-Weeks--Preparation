#include<bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
vector<vector<int>> a(4, vector<int> (4));
int inversions() {
    vector<int> flat;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == 0) continue;
            flat.push_back(a[i][j]);
        }
    }

    int cnt = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = i + 1; j < 15; j++) {
            cnt += flat[i] > flat[j];
        }
    }
    return cnt;
}
int calManhattan(int x, int r, int c) {
    int nr = (x - 1) / 4;
    int nc = (x - 1) % 4;
    return abs(nr - r) + abs(nc - c);
}
int manHattanDis() {
    int dis = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == 0) continue;
            dis += calManhattan(a[i][j], i, j);
        }
    }
    return dis;
}
bool solved = false;
char path[36];
vector<int> oppositeDir = {3, 2, 1, 0};
vector<int> dr = {1,  0, 0, -1};
vector<int> dc = {0, -1, 1, 0};
vector<char> dir = {'D', 'L', 'R', 'U'};
int dfs (int g, int h, int r,int c, int preDir, int bound) {
    int f = g + h;
    if (f > bound) {
        return f;
    }

    if (h == 0) {
        solved = true;
        path[g] = '\0';
        return g;
    }

    int next_min_h = 1e9;
    for (int i = 0; i < 4; i++) {
        if (preDir != -1 and i != oppositeDir[preDir] or preDir == -1) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 and nc >= 0 and nr <= 3 and nc <= 3) {
                int cur = a[nr][nc];

                int old_d = calManhattan(cur, nr, nc);
                int new_d = calManhattan(cur, r, c);
                int next_h = h - old_d + new_d;

                a[r][c] = cur;
                a[nr][nc] = 0;
                path[g] = dir[i];

                int res = dfs(g+1, next_h, nr, nc, i, bound);
                if (solved) return res;
                next_min_h = min(next_min_h, res);

                a[r][c] = 0;
                a[nr][nc] = cur;
            }
        }
    }
    return next_min_h;
}
void Solve() {
    int zr = -1, zc = -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                zr = i;
                zc = j;
            }
        }
    }

    int total = zr + inversions();
    int initial_distance = manHattanDis();
    if ((total % 2) and initial_distance <= 35) {
        int bound = initial_distance;
        solved = false;
        while (bound <= 35 && !solved) {
            int next_bound = dfs(0, initial_distance, zr, zc, -1, bound);
            if (solved) break;
            if (next_bound > 35) break;
            bound = next_bound;
        }

        if (solved) {
            cout << path << endl;
        } else {
            cout << "This puzzle is not solvable." << endl;
        }
    } else {
        cout << "This puzzle is not solvable." << endl;
    }
}
int32_t main() {
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}
