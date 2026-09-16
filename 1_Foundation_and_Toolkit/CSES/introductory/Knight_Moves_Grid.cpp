#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
int x[8] = {2, 2, 1, -1, -2, -2, 1, -1};
int y[8] = {1, - 1, 2, 2, 1, -1, -2, -2};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    vector<vector<int>> move(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    move[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();

        for (int dir = 0; dir < 8; dir++) {
            int nx = x[dir] + a;
            int ny = y[dir] + b;
            if (nx >= 0 and ny >= 0 and nx < n and ny < n and move[nx][ny] == -1) {
                move[nx][ny] = move[a][b] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << move[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
