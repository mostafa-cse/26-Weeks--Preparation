#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int n;
    cin >> n;

    if (n >= 10) {
        cout << 10 << " " << n - 10 << endl;
    } else {
        cout << 0 << " " << n << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
