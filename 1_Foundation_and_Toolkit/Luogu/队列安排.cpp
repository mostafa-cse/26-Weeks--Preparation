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

    vector<int> left(n + 1, 0), right(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int x, p;
        cin >> x >> p;

        if (p) { // add right
            if (right[x] == 0) { // no one
                right[x] = i;
                left[i] = x;
            } else {              // at least one
                right[i] = right[x];
                left[right[x]] = i;
                right[x] = i;
                left[i] = x;
            }
        } else {      // add right
            if (left[x] == 0) {     // no
                left[x] = i;
                right[i] = x;
            } else {                 // atleast one
                right[left[x]] = i;
                left[i] = left[x];
                right[i] = x;
                left[x] = i;
            }
        }
    }

    vector<int> remove(n + 1, 0);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        if (remove[x]) {
            continue;
        } else {
            remove[x] = 1;
            // left
            if (left[x] == 0 and right[x] != 0) {
                left[right[x]] = 0;
                right[x] = 0;
            }
            // middle
            else if (left[x] != 0 and right[x] != 0) {
                right[left[x]] = right[x];
                left[right[x]] = left[x];
            }
            // right
            else if (left[x] != 0 and right[x] == 0) {
                right[left[x]] = 0;
                left[x] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (remove[i]) continue;
        if (left[i] == 0) {
            int val = i;
            while (val != 0) {
                cout << val << " ";
                val = right[val];
            }
            break;;
        }
    }
    return 0;
}
