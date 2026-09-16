#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    multiset<int> left, right;

    auto balance = [&]() {
        while (left.size() > (k + 1) / 2) {
            right.insert(*left.rbegin());
            left.erase(prev(left.end()));
        }
        while (left.size() < (k + 1) / 2 && !right.empty()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    };

    for (int i = 0; i < n; i++) {
        if (left.empty() || a[i] <= *left.rbegin()) {
            left.insert(a[i]);
        } else {
            right.insert(a[i]);
        }
        balance();

        if (i >= k - 1) {
            cout << *left.rbegin() << " ";

            int out_val = a[i - k + 1];

            auto it = left.find(out_val);
            if (it != left.end()) {
                left.erase(it);
            } else {
                right.erase(right.find(out_val));
            }
            balance();
        }
    }
    return 0;
}
