#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    priority_queue<pair<int, int>> pq;
    cout << 0 << endl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        pq.push({-x, i});
        while (pq.top().second <= i - m) pq.pop();
        if (i != n - 1)
            cout << -pq.top().first << "\n";
    }
    return 0;
}
