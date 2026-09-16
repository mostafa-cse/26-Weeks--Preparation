#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;

   vector<int> ar(n);
   for (int &i :ar) cin >> i;

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[ar[i]]++;
        if (i + 1 >= k) {
            cout << cnt.size() << " ";
            cnt[ar[i - k + 1]]--;
            if (cnt[ar[i - k + 1]] == 0) {
                cnt.erase(ar[i - k + 1]);
            }
        }
    }

    return 0;
}

