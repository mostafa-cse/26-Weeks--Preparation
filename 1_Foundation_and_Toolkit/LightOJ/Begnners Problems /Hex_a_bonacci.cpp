#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
const int mod = 10000007;
int dp[10005];
int fn(int n) {
    if (n < 0) return 0;
    if (n <= 5) return dp[n];
    if (dp[n] != -1) {
        return dp[n];
    }
    return dp[n] = (((((fn(n - 1) % mod + fn(n - 2)) % mod + fn(n - 3)) % mod + fn(n - 4)) % mod + fn(n - 5)) % mod + fn(n - 6)) % mod;
}
void solve() {
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < 6; i++) {
        cin >> dp[i];
    }

    int n;
    cin >> n;
    cout << fn(n) % mod << endl;
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
