#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int n, m;
    cin >> n >> m;

    deque<int> val;
    while (m--) {
        string op;
        cin >> op;

        if (op == "pushLeft") {
            int x;
            cin >> x;
            if (val.size() == n) {
                cout << "The queue is full" << endl;
            } else {
                cout << "Pushed in left: " << x << endl;
                val.push_front(x);
            }
        } else if (op == "pushRight") {
            int x;
            cin >> x;
            if (val.size() == n) {
                cout << "The queue is full" << endl;
            } else {
                cout << "Pushed in right: " << x << endl;
                val.push_back(x);
            }
        } else if (op == "popLeft") {
            if (val.empty()) {
                cout << "The queue is empty" << endl;
            } else {
                cout << "Popped from left: " << val.front() << endl;
                val.pop_front();
            }
        } else if (op == "popRight") {
            if (val.empty()) {
                cout << "The queue is empty" << endl;
            } else {
                cout << "Popped from right: " << val.back() << endl;
                val.pop_back();
            }
        }
    }
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

