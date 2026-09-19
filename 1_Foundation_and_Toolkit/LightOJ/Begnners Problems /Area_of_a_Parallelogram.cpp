#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
void solve() {
    int x1, y1;
    cin >> x1 >> y1;

    int x2, y2;
    cin >> x2 >> y2;

    int x3, y3;
    cin >> x3 >> y3;


    int area_up = x1 * y2 + x2 * y3 + x3 * y1;
    int area_dwn = y1 * x2 + y2 * x3 + y3 * x1;

    int area = abs(area_up - area_dwn);
    int X = x1 + x3 - x2, Y = y1 + y3 - y2;
    cout << X << " " << Y << " " << area << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
