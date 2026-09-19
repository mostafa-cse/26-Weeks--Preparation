#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
void solve() {
    int n, k;
    cin >> n >> k;

    map<int, int> cnt;
    for (int i = 0; i < k; i++) {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
    }

    int ans = n;
    for (auto [x, y] : cnt) {
        if (y == k) {
            ans = x;
        }
    }

    cout << ans << " meter(s)" << endl;
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
