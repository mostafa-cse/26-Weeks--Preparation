#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int n;
    cin >> n;

    int val = ceil(sqrtl(n));

    int mid = powl(val - 1, 2) + val;
    // cout << n << " " << val << " " << mid << endl;

    int col = -1, row = -1;
    if (val & 1) { // increaseing -> complete
        if (mid < n) {
            row = val;
            col = val - n % mid;
        } else if (mid == n) {
            row = col = val;
        } else if (mid > n) {
            col = val;
            row = n % ((val - 1) * (val - 1));
        }
    } else { // decreasing -> queue
        if (mid < n) {
            col = val;
            row = val - n % mid;
        } else if (mid == n) {
            row = col = val;
        } else if (mid > n) {
            row = val;
            col = val - (mid - n);
        }
    }
    cout << col << " " << row << endl;
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
