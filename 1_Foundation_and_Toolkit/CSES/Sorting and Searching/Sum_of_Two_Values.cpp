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

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(all(a));

    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l].first + a[r].first > k) {
            r--;
        } else if (a[l].first + a[r].first < k) {
            l++;
        } else if (a[l].first + a[r].first == k and l != r) {
            cout << a[l].second << " " << a[r].second << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
