#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
const int M = 1e12;
void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if ((x1 + y1) % 2 != (x2 + y2) % 2) {
        cout << "impossible" << endl;
    } else {
        if (x1 == x2 and y1 == y2) {
            cout << 0 << endl;
        } else if ((y1 - x1) == (y2 - x2) or M - (x1 + y1) == M - (x2 + y2)) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}

