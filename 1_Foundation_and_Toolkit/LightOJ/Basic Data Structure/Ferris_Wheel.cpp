#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> p;
    for (int i = 1; i <= n; i++) {
        p.push_back(i);
    }

    int ans = 0;
    int total_ride = 0;
    vector<int> seat(m + 1, 0);
    vector<int> ride_cnt(n + 1, 0);
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    int cur = 1;
    while (total_ride < n * m) {
        if (seat[cur] != 0) {
            int people = seat[cur];
            seat[cur] = 0;
            ride_cnt[people]++;
            total_ride++;

            if (ride_cnt[people] < m) {
                p.push_back(people);
            }
        }

        for (auto it = p.begin(); it != p.end(); ++it) {
            if (vis[*it][cur] == 0) {
                seat[cur] = *it;
                vis[*it][cur] = 1;

                p.erase(it);
                break;
            }
        }
        cur = (cur % m) + 1;
        ans += 5;
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;
    // freopen("out.txt", "w", stdin);

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
