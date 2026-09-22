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

    map<int, int> cnt;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int ans = 1;
    for (auto [x, y] : cnt) {
        ans *= (y + 1);
        ans %= (1000000007);
    }
    cout << (ans + 1000000006) % 1000000007;
    return 0;
}
