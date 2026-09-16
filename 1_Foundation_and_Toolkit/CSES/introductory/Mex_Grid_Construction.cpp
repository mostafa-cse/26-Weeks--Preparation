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

    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        a[0][i] = a[i][0] = i;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            set<int> val;
            // upper
            int ii = i;
            while (--ii >= 0) val.insert(a[ii][j]);

            // left
            int jj = j;
            while (--jj >= 0) val.insert(a[i][jj]);

            int mex = 0;
            for (auto el : val) {
                if (el == mex) mex++;
                else break;
            }
            a[i][j] = mex;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
