#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    int ans = 0;
    map<int, int> cnt;
    cnt[0] = 1;
    for (int i = 0, sum = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;

        ans += cnt[sum - k];
        cnt[sum]++;
    }
    cout << ans << endl;
    return 0;
}
