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
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    PBDS oset;
    for (int i = 1; i <= n; i++) {
        oset.insert(i);
    }

    int m = k;
    while (oset.size() > 1) {
        m %= oset.size();
        m -= 1;
        if (m < 0) m = oset.size() - 1;
        auto val = oset.find_by_order(m);
        cout << *val << " ";
        oset.erase(val);
        m += k;
        // dout(oset);
        getchar();
    }
    cout << *oset.begin();

    return 0;
}
