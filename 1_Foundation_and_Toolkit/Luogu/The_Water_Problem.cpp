#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
template <class T, class F>
struct RMQ {
    vector<vector<T>> st;
    F f;
    RMQ(vector<T> v, F _f) : st(1, v), f(_f) {
        for (int p = 1; (1 << p) <= v.size(); ++p) {
            st.emplace_back(v.size() - (1 << p) + 1);
            for (int j = 0; j < st[p].size(); ++j)
                st[p][j] = f(st[p - 1][j], st[p - 1][j + (1 << (p - 1))]);
        }
    }
    T query(int l, int r) {
        int d = __lg(r - l + 1);
        return f(st[d][l], st[d][r - (1 << d) + 1]);
    }
};
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto max_op = [](int x, int y) { return max(x, y); };
    RMQ<int, decltype(max_op)> mx(a, max_op);

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << mx.query(l - 1, r - 1) << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
