#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
int solve_knights(int n, int m) {
    int max_knights = 0;
    if (m == 1 || n == 1)  max_knights = max(m, n);
    else if (m == 2 || n == 2) {
        int x = max(m, n);
        max_knights = (x / 4) * 4 + min(2ll, x % 4) * 2;
    }
    else  max_knights = (m * n + 1) / 2;
    return max_knights;
}
void solve() {
    int n, m;
    cin >> n >> m;
    cout << solve_knights(n, m) << endl;
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
