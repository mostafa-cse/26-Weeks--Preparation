#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
void solve() {
    vector<int> a(3);
    for (int i = 0; i < 3; ++i) cin >> a[i];
    sort(all(a));
    function<int(int)> sq = [](int x) -> int {
        return x * x;
    };
    if (sq(a[0]) + sq(a[1]) == sq(a[2])) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
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
