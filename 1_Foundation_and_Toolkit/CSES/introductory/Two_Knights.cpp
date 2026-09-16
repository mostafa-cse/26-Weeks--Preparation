#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int ii = i * i;
        cout << ii * (ii - 1) / 2 - 4 * (i - 1) * (i - 2) << endl;
    }
    return 0;
}
