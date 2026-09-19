#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
const int M = 1e6;
vector<long double> lnVal(M + 1);
void solve() {
    int n, base;
    cin >> n >> base;

    cout << (int)(lnVal[n] / log(base) + 1) << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;
    for (int i = 1; i <= M; i++) {
        lnVal[i] = lnVal[i - 1] + log(i);
    }
    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
