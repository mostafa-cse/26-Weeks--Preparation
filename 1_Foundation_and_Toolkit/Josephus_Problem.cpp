#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()

long long josephus_fast(long long n, long long k) {
    if (k == 1) {
        return n;
    }
    long long ans = 0, i = 1;
    while (i < n) {
        long long jumps = (i - ans + k - 2) / (k - 1);
        if (i + jumps > n) jumps = n - i;
        ans = (ans + jumps * k) % (i + jumps);
        i += jumps;
    }
    return ans + 1; // 1-indexed
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int q;
    cin >> q;

    for (int i = 1; i <= q; i++) {
        int n, k;
        cin >> n >> k;

        cout << "Case " << i << ": " << josephus_fast(n, k) << endl;
    }
    return 0;
}
