#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
void solve() {
    double r1, r2, r3;
    cin >> r1 >> r2 >> r3;

    double A = r1 + r2;
    double B = r2 + r3;
    double C = r1 + r3;

    double aTheta = acos((A * A + C * C - B * B) / (2 * A * C));
    double bTheta = acos((A * A + B * B - C * C) / (2 * A * B));
    double cTheta = acos((B * B + C * C - A * A) / (2 * B * C));

    double s = (A + B + C) / 2;
    double area_trangle = sqrtl(s * (s - A) * (s - B) * (s - C));
    double area_circle_sector = 0.5 * (r1 * r1 * aTheta + r2 * r2 * bTheta + r3 * r3 * cTheta);
    cout << fixed << setprecision(10) << area_trangle - area_circle_sector << endl;
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
