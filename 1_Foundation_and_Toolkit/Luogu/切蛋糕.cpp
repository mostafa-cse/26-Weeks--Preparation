#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define min_heap priority_queue<pi, vector<pi>, greater<pi>>
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    min_heap pq;
    pq.push({0, 0});
    int ans = -1e18;
    for (int i = 1, sum = 0; i <= n; i++) {
        sum += a[i];
        while (!pq.empty() and pq.top().second < i - k) {
            pq.pop();
        }
        ans = max(ans, sum - pq.top().first);
        pq.push({sum, i});
    }
    cout << ans << endl;
    return 0;
}
