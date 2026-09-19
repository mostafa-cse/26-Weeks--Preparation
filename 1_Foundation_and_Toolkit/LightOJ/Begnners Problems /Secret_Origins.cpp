#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
void solve() {
    int n;
    cin >> n;

    vector<int> pos;
    for (int i = 0; i < 32; i++) {
        if (n >> i & 1) {
            pos.push_back(i);
        }
    }

    if (pos.size() == 1) {
        cout << n * 2 << endl;
    } else {
        if ()
    }
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
