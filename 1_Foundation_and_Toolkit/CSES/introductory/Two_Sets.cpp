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

    int sum = (n * (n + 1)) / 2;
    if (sum & 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<int> A(n + 1, 0);
        sum /= 2;
        int Acnt = 0;
        for (int i = n; i >= 1; i--) {
            if (sum - i >= 0) {
                A[i] = 1;
                sum -= i;
                Acnt += 1;
            }
        }

        cout << Acnt << endl;
        for (int i = 1; i <= n; i++) {
            if (A[i] == 1) {
                cout << i << " ";
            }
        }
        cout << endl;

        cout << n - Acnt << endl;
        for (int i = 1; i <= n; i++) {
            if (A[i] == 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
