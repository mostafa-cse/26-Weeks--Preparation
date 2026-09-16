#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
const int M = 3e5;
class Fenwick {
    int n;
    std::vector<int> bit;
public:
    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void update(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }
    int query(int idx) const {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }
    int query(int l, int r) const {
        return query(r) - query(l - 1);
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(all(b)); b.resize(unique(all(b)) - b.begin());
    vector<int> valIdx(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        valIdx[i] = lower_bound(all(b), a[i]) - b.begin();
    }

    PBDS st;
    Fenwick sum(M);
    Fenwick cnt(M);

    for (int i = 1; i <= n; i++) {
        st.insert(a[i]);
        sum.update(valIdx[i], a[i]);
        cnt.update(valIdx[i], 1);

        if (i >= k) {
            int med = *st.find_by_order((k - 1) >> 1);

            int pos = lower_bound(all(b), med) - b.begin();

            int smallerSum = sum.query(pos);
            int smallerCnt = cnt.query(pos);

            int largerSum = sum.query(M) - sum.query(pos);
            int largerCnt = cnt.query(M) - cnt.query(pos);

            int ans = largerSum - med * largerCnt + smallerCnt * med - smallerSum;
            cout << ans << " ";

            auto it = st.upper_bound(a[i - k + 1]);
            st.erase(it);
            cnt.update(valIdx[i - k + 1], -1);
            sum.update(valIdx[i - k + 1], -a[i - k + 1]);
        }
    }
    return 0;
}
