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

    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }
    sort(all(a), [&](pair<int, int>&x, pair<int, int>&y){
        if (x.second == y.second) return x.first < y.first;
        return x.second < y.second;
    });

    int ans = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].first >= end) {
            ans++;
            end = a[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}
