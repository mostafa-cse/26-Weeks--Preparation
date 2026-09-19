#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
vector<pair<int, int>> val;
void solve() {
    int x;
    cin >> x;

    cout << val[x - 1].first << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> divi(1005, 0);
    for (int i = 1; i <= 1005; i++) {
        for (int j = i; j <= 1005; j += i) {
            divi[j] += 1;
        }
    }

    for (int i = 1; i <= 1000; i++) {
        val.push_back({i, divi[i]});
    }
    sort(all(val), [&](pair<int, int> &x, pair<int,int>&y){
        if (x.second == y.second) return x.first > y.first;
        return x.second < y.second;
    });


    for (int i = 1; i <= n; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}

