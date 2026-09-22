#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
struct Point {
    double x, y, z;
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point() {}
    friend istream& operator>>(istream& in, Point& p) {
        in >> p.x >> p.y >> p.z;
        return in;
    }
    Point operator-(Point &other) {
        Point res;
        res.x = x - other.x;
        res.y = y - other.y;
        res.z = z - other.z;
        return res;
    }
    Point operator+(Point &other) {
        Point res;
        res.x = x + other.x;
        res.y = y + other.y;
        res.z = z + other.z;
        return res;
    }
    Point operator*(double t) {
        Point res;
        res.x = x * t;
        res.y = y * t;
        res.z = z * t;
        return res;
    }
};
double dot(Point &a, Point &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
void solve() {
    Point A, B, P;
    cin >> A >> B >> P;

    Point U = A - P; // initial distance between two person
    Point V = B - A;

    double t = -dot(U, V) / (V.x * V.x + V.y * V.y + V.z * V.z);
    if (t >= 1) t = 1;
    else if (t <= 0) t = 0;

    V = V * t;
    Point distance = U + V;

    double ans = distance.x * distance.x + distance.y * distance.y + distance.z * distance.z;
    cout << fixed << setprecision(10) << sqrtl(ans) << endl;
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
