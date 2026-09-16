#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    while (cin >> n >> m) {
        cout << n << " " << m << " ";
        int ans = 1;
        for (int i = min(n, m); i <= max(n, m); i++) {
            int cnt = 1, cur = i;
            while (cur != 1) {
                if (cur & 1) cur = 3*cur+1;
                else cur /= 2;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}
