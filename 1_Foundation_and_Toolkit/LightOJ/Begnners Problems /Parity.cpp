#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
void solve() {
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < 64; i++) {
        cnt += (n >> i & 1);
    }
    cout << ((cnt & 1) ? "odd" : "even") << endl;
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
