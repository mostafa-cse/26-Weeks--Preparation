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

    int ans = 0;
    for (int i = 5; i <= n; i *= 5) {
        ans += (n / i);
    }
    cout << ans << endl;
    return 0;
}
