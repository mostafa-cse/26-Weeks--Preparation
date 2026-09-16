#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        a.push_back({x, +1});
        a.push_back({y, -1});
    }
    sort(all(a));

    int ans = 0;
    for (int i = 0, cur = 0; i < 2 * n; i++) {
        cur += a[i].second;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
