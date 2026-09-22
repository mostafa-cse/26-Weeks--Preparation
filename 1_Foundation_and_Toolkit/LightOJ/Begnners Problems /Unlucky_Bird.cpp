#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
void solve() {
    double v1, v2, v3, a1, a2;
    cin >> v1 >> v2 >> v3 >> a1 >> a2;

    double d = v1 * v1 / (2 * a1) + v2 * v2 / (2 * a2);

    double t1 = v1 / a1;
    double t2 = v2 / a2;

    cout << fixed << setprecision(10) << d << " " << max(t1, t2) * v3 << endl;
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
