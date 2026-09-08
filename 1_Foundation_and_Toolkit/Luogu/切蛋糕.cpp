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

    int ans = -1e18;
    int sum = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        sum += x;
        q.push(x);
        while (!q.empty() and (q.front() <= 0 or q.size() > m)) {
            sum -= q.front();
            q.pop();
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
