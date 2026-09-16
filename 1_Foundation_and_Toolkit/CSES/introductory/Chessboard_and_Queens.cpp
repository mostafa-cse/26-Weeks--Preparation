#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> grid(8, vector<int>(8, 0));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            grid[i][j] = (c == '*');
        }
    }

    vector<int> row(8, 0), col(8, 0), upper(20, 0), lower(20, 0);
    function<int(int x)> rec = [&](int x) -> int {
        if (x == 8) {
            return 1;
        }
        int ans = 0;
        for (int y = 0; y < 8; y++) {
            if (row[x] == 0 and col[y] == 0 and upper[x - y + 8] == 0 and lower[x + y] == 0 and grid[x][y] == 0) {
                row[x] = 1;
                col[y] = 1;
                upper[x - y + 8] = 1;
                lower[x + y] = 1;

                ans += rec(x + 1);

                row[x] = 0;
                col[y] = 0;
                upper[x - y + 8] = 0;
                lower[x + y] = 0;
            }
        }
        return ans;
    };
    cout << rec(0) << endl;
    return 0;
}
