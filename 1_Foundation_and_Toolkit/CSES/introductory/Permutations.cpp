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

    if (n == 1) {
        return cout << 1 << endl, 0;
    }

    /*
        n = 2:
            1 2
            2 1
        n = 3:
        1 2 3
        3 1 2

        n = 4:
        2 4 1 3
    */

    if (n < 4) {
        return cout << "NO SOLUTION" << endl, 0;
    }

    for (int i = 2; i <= n; i += 2) cout << i << " ";
    for (int i = 1; i <= n; i += 2) cout << i << " ";
    return 0;
}
