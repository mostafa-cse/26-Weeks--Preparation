#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
vector<int> state;
int onePos;
bool isPossible() {
    vector<int> arr;
    for (int i = 0; i < state.size(); i++) {
        if (state[i] == 1) continue;
        arr.push_back(state[i]);
    }

    int inv = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            inv += arr[i] > arr[j];
        }
    }

    int oneRow = onePos / 4;
    return (inv + oneRow) & 1;
}
int calDistance(int val, int pos) {
    int row = pos / 4;
    int col = pos % 4;

    int t_row = (val - 1) / 4;
    int t_col = (val - 1) % 4;

    int rDis = abs(row - t_row);
    int cDis = abs(col - t_col);

    cDis = min(4 - cDis, cDis);
    return (rDis + cDis);
}
int getHeuristics() {
    int h = 0;
    for (int i = 0; i < state.size(); i++) {
        if (state[i] == 1) continue;
        h += calDistance(state[i], i);
    }
    return h;
}
bool solved = false;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int IDA(int g, int h, int onepos, int prevDir,int target) {
    int f = g + h;
    if (f > target) return f;
    if (h == 0) {
        solved = true;
        return g;
    }

    int mn_target = 1e9;
    int r = onepos / 4;
    int c = onepos % 4;
    for (int i = 0; i < 4; i++) {
        if (prevDir != -1 and abs(prevDir - i) == 2) continue;
        int nr = r + dx[i];
        int nc = (c + dy[i] + 4) % 4;

        if (nr >= 0 and nr < (state.size() / 4)) {
            int new_one_pos = nr * 4 + nc;

            int val = state[new_one_pos];
            int old_h = calDistance(val, new_one_pos);
            int new_h = calDistance(val, onepos);
            int next_h = h - old_h + new_h;
            swap(state[new_one_pos], state[onepos]);
            int res = IDA(g + 1, next_h, new_one_pos, i, target);
            if (solved) {
                return res;
            }
            mn_target = min(mn_target, res);
            swap(state[new_one_pos], state[onepos]);
        }
    }
    return mn_target;
}
void solve() {
    int n;
    cin >> n;

    state.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> state[i];
        if (state[i] == 1) {
            onePos = i;
        }
    }

    if (isPossible() == 0) {
        int heuristics = getHeuristics();
        int bound = heuristics;
        solved = false;
        while (bound <= 25) {
            int cur = IDA(0, heuristics, onePos, -1, bound);
            if (solved) {
                break;
            }
            bound = cur;
        }
        if (bound > 25) {
            cout << "impossible in 25 jumps" << endl;
        } else {
            cout << bound << endl;
        }
    } else {
        cout << "impossible" << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
