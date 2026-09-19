#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int n;
    cin >> n;

    if (n & 1) {
        cout << "Impossible" << endl;
    } else {
        int a = 1;
        while (n % 2 == 0) {
            a *= 2;
            n /= 2;
        }
        cout << n << " " << a << endl;
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

