#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
void solve() {
    struct info {
        string name;
        int vol;
        bool operator<(const info other)  {
            return vol < other.vol;
        }
    };

    int n;
    cin >> n;

    vector<info> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].name;

        int x, y, z;
        cin >> x >> y >> z;
        a[i].vol = x * y * z;
    }
    sort(all(a));

    if (a[0].vol == a.back().vol) {
        cout << "no thief" << endl;
    } else {
        cout << a.back().name << " took chocolate from " << a[0].name << endl;
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
