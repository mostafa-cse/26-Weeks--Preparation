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

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push({x, i});

        while (i - k >= pq.top().second) pq.pop();
        // dout(pq);

        if (pq.size() >= k) {
            cout << pq.top().first << endl;
        }
    }
    return 0;
}

