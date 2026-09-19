#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;

        if (x >= x1 and x <= x2 and y >= y1 and y <= y2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Case " << i << ": \n";
        solve();
    }
    return 0;
}

