#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int cnt = 0;
    string s;
    while(getline(cin, s)) {
        for (char c : s) {
            if (c == '\"') {
                cnt++;

                if (cnt & 1) {
                    cout << "\`\`";
                } else {
                    cout << "\'\'";
                }
            } else {
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}
