#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    vector<int> a(n);
    int ans = -1e18;
    for (int i = 0, sum = 0; i < n; i++) {
        cin >> a[i];
        sum = max(sum + a[i], a[i]);
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
