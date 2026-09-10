#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (cin >> n and n) {
        vector<int> a(n);
        for (int &i : a) {
            cin >> i;
        }
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}
