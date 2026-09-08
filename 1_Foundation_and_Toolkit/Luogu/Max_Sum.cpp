#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
void solve() {
    int n;
    cin >> n;

    int ans = -1e18;
    int ansL = 0, ansR = 0;
    int l = 0;
    for (int i = 0, sum = 0; i < n; i++) {
        int x;
        cin >> x;

        sum += x;
        if (sum < x) {
            sum = x;
            l = i;
        }
        if (sum > ans) {
            ansL = l;
            ansR = i;
            ans = sum;
        }
    }
    cout << ans << " " << ansL + 1 << " " << ansR + 1 << endl;
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": \n";
        solve();
    }
    return 0;
}
