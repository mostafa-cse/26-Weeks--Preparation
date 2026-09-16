#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n), appartments(m);
    for (int i = 0; i < n; ++i) cin >> applicants[i];
    for (int i = 0; i < m; ++i) cin >> appartments[i];

    sort(all(applicants));

    multiset<int> appart(all(appartments));
    dout(appart);
    dout(applicants);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int xn = applicants[i] - k;
        int xp = applicants[i] + k;

        auto it = appart.lower_bound(xn);
        if (it != appart.end()) {
            if (*it <= xp) {
                ans++;
                appart.erase(it);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
