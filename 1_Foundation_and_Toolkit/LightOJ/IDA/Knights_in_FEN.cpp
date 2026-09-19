#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
vector<string> a(5);
const string target[5] = {
    "11111",
    "01111",
    "00 11",
    "00001",
    "00000"
};
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int getHeuristic() {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (target[i][j] == ' ') continue;
            cnt += (target[i][j] != a[i][j]);
        }
    }
    return cnt;
}
bool IDA(int g, int r, int c, int preX, int preY, int limit) {
    int h = getHeuristic();
    if (h == 0) return true;

    // this is main of heuristics
    if (h + g > limit) return false;

    for (int dir = 0; dir < 8; dir++) {
        int nx = r + dx[dir];
        int ny = c + dy[dir];

        if (nx >= 0 and ny >= 0 and nx < 5 and ny < 5) {
            if (nx == preX and ny == preY) continue;
            swap(a[r][c], a[nx][ny]);
            if (IDA(g + 1, nx, ny, r, c, limit)) {
                return true;
            }
            swap(a[r][c], a[nx][ny]);
        }
    }
    return false;
}
void solve() {
    int er = 0, ec = 0;
    for (int i = 0; i < 5; i++) {
        getline(cin, a[i]);
        for (int j = 0; j < 5; j++) {
            if (a[i][j] == ' ') {
                er = i;
                ec = j;
            }
        }
    }

    int ans = -1;
    bool solved = false;
    for (int limit = 0; limit <= 15; limit++) {
        if (IDA(0, er, ec, -1, -1, limit)) {
            solved = true;
            ans = limit;
            break;
        }
    }

    if (solved) {
        cout << "Solvable in " << ans << " move(s)." << endl;
    } else {
        cout << "Unsolvable in less than 16 move(s).\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
