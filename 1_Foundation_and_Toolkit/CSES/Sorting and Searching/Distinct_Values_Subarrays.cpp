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

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, int> cnt;
    int ans = 0;
    for (int i = 1, l = 0; i <= n; i++) {
        l = max(cnt[a[i]] + 1, l);
        cnt[a[i]] = i;
        ans += (i - l + 1);
    }
    cout << ans << endl;
    return 0;
}
