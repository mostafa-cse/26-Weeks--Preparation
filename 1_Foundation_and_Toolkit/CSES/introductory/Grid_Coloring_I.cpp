#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - 'A';
        }
    }

    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int curr : {0, 1, 2, 3}) {
                if (curr ^ a[i][j]) {
                    int ok = true;
                    // left
                    if (i - 1 >= 0 and ans[i - 1][j] == curr)  ok = false;
                    // right
                    if (i + 1 < n and ans[i + 1][j] == curr) ok = false;
                    // upper
                    if (j - 1 >= 0 and ans[i][j - 1] == curr) ok = false;
                    // down
                    if (j + 1 < m and ans[i][j + 1] == curr) ok = false;

                    if (ok) {
                        ans[i][j] = curr;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << char('A' + ans[i][j]);
        }
        cout << endl;
    }
    return 0;
}
