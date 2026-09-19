#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        char op;
        cin >> op;

        if (op == 'P') {
            int x, y;

            cin >> x >> y;
            // x -= 1, y-= 1;

            swap(a[x], a[y]);
        } else if (op == 'S') {
            int val = 0;
            cin >> val;

            for (int i = 0; i < n; i++) {
                a[i] += val;
            }
        } else if (op == 'M') {
            int val = 0;
            cin >> val;

            for (int i = 0; i < n; i++) {
                a[i] *= val;
            }
        } else if (op == 'D') {
            int val = 0;
            cin >> val;

            for (int i = 0; i < n; i++) {
                a[i] /= val;
            }
        } else {
            reverse(all(a));
        }
    }

    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}

