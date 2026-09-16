#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m, c;
    int seq = 1;
    while (cin >> n >> m >> c) {
        if (n == 0 and m == 0 and c == 0) break;
        vector<int> wt(n + 1);
        for (int i = 1; i <= n; i++) cin >> wt[i];

        int mx = 0;
        vector<int> memo(n + 2, 0);
        for (int i = 0, cur = 0; i < m; i++) {
            int x;
            cin >> x;

            memo[x]++;
            if (memo[x] & 1) {
                cur += wt[x];
            } else {
                cur -= wt[x];
            }
            mx = max(cur, mx);
        }

        cout << "Sequence " << seq++ << endl;
        if (mx > c) {
            cout << "Fuse was blown." << endl;
        } else {
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << mx << " amperes." << endl;
        }
        cout << endl;
    }
    return 0;
}
