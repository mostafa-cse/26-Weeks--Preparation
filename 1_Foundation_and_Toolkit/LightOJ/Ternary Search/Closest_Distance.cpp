#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
struct Point {
    double x, y;
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point() {}
    friend istream& operator>>(istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }
    Point operator-(Point &other) {
        Point res;
        res.x = x - other.x;
        res.y = y - other.y;
        return res;
    }
    Point operator+(Point &other) {
        Point res;
        res.x = x + other.x;
        res.y = y + other.y;
        return res;
    }
    Point operator*(double val) {
        return Point(x * val, y * val);
    }
};
double dot(Point &a, Point &b) {
    return a.x * b.x + a.y * b.y;
}
void solve() {
    Point A, B, C, D;
    cin >> A >> B >> C >> D;

    Point U = A - C; // initial distance between two person
    Point V = B + C - A - D; 

    double t = -dot(U, V) / (V.x * V.x + V.y * V.y);
    if (t >= 1) t = 1;
    else if (t <= 0) t = 0;

    V = V * t;
    Point distance = U + V;

    double ans = distance.x * distance.x + distance.y * distance.y;
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
