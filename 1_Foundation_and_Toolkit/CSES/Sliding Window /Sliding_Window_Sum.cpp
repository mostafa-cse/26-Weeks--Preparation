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

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> ar = {x};
    for (int i = 1; i < n; i++) {
        int val = (ar[i - 1] * a + b) % c;
        ar.push_back(val);
    }
    dout(ar);

    int ans = 0;
    for (int i = 0, cur = 0; i < n; i++) {
        cur += ar[i];
        if (i + 1 >= k) {
            ans ^= cur;
            cur -= ar[i - k + 1];
        }
    }
    cout << ans << endl;
    return 0;
}
