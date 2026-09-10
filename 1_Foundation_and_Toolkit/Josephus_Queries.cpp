#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
long long josephus_query(long long n, long long k) {
    if (n == 1) return 1;
    if (k <= n / 2) return 2 * k;
    long long c = n / 2;
    long long idx = josephus_query(n - c, k - c);
    if (n % 2 == 0) return 2 * idx - 1;
    else return (idx == 1) ? n : 2 * idx - 3;
}
void solve() {
    int n, k;
    cin >> n >> k;
    cout << josephus_query(n, k) << endl;
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
