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

    int Xor = 0;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        Xor ^= x;
    }

    for (int i = 1; i <= n; ++i) {
        Xor ^= i;
    }
    cout << Xor << endl;
    return 0;
}
