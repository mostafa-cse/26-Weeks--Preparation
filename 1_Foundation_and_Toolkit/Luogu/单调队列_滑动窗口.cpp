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
    int n, k;
    cin >> n >> k;

    priority_queue<pair<int, int>> mx, mn;
    vector<int> ans_mx, ans_mn;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        mx.push({x, i});
        mn.push({-x, i});

        if (mn.size() >= k) {
            while (!mn.empty() and mn.top().second <= i - k) mn.pop();
            while (!mx.empty() and mx.top().second <= i - k) mx.pop();

            // dout(i, mn);
            // dout(i, mx);
            // cerr << endl;
            ans_mn.push_back(-mn.top().first);
            ans_mx.push_back(mx.top().first);
        }
    }

    for (int &i : ans_mn) cout << i << " "; cout << endl;
    for (int &i : ans_mx) cout << i << " "; cout << endl;
    return 0;
}
