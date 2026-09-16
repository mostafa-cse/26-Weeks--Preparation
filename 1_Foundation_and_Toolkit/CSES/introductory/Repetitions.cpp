#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    cin >> s;
    s.push_back('-');

    int ans = 0;
    for (int i = 0, cnt = 1; i < s.size(); i++) {
        if (s[i] != s[i + 1]) {
            ans = max(ans, cnt);
            cnt = 0;
        }
        cnt++;
    }
    cout << ans << endl;
    return 0;
}
