#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
string web[50005];
void solve() {
    int last = 0;
    web[last] = "http://www.lightoj.com/";
    int cur = 0;
    while (true) {
        string cmd;
        cin >> cmd;
        if (cmd == "QUIT") {
            break;
        } else if (cmd == "VISIT") {
            string oj;
            cin >> oj;
            cout << oj << endl;

            web[++cur] = oj;
            last = cur;
        } else if (cmd == "BACK") {
            if (cur - 1 < 0) {
                cout << "Ignored" << endl;
            } else {
                cout << web[--cur] << endl;
            }
        } else if (cmd == "FORWARD") {
            if (cur + 1 > last) {
                cout << "Ignored" << endl;
            } else {
                cout << web[++cur] << endl;
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

