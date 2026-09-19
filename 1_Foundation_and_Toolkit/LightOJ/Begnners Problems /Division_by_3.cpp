#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int l, r;
    cin >> l >> r;

    function<int(int)> qry = [](int x) -> int {
        return (x / 3) * 2 + ((x % 3) == 2);
    };
    cout << qry(r) - qry(l - 1) << endl;
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

