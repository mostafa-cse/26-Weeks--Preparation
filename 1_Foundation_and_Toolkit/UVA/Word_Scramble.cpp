#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);

        string s;
        while (ss >> s) {
            reverse(all(s));
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
