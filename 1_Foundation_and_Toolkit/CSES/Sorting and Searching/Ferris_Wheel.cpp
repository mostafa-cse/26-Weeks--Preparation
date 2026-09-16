#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    multiset<int> wt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        wt.insert(x);
    }

    int ans = 0;
    int curr = k, cnt = 0;
    while (!wt.empty()) {
        auto it = wt.upper_bound(curr);
        if (it != wt.begin()) --it;

        if (*it > curr) {
            ans++;
            curr = k - *it;
            cnt = 1;
        } else {
            cnt++;
            curr -= *it;
        }

        if (cnt == 2) {
            ans++;
            curr = k;
            cnt = 0;
        }
        wt.erase(it);
    }
    if (cnt) ans++;
    cout << ans << endl;
    return 0;
}
