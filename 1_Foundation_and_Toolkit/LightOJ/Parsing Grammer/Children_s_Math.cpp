#include <bits/stdc++.h>
#define int long long
using namespace std;

struct EqValue {
    int A;
    int B;
    EqValue operator*(const EqValue other) {
        EqValue res;
        res.A = A * other.B + B * other.A;
        res.B = B * other.B;
        return res;
    }
    EqValue operator+(const EqValue other) {
        EqValue res;
        res.A = A + other.A;
        res.B = B + other.B;
        return res;
    }
    EqValue operator-(const EqValue other) {
        EqValue res;
        res.A = A - other.A;
        res.B = B - other.B;
        return res;
    }
};
struct ExpressionSolve {
    string s;
    int idx = 0;
    ExpressionSolve(string _s) : s(_s), idx(0) {};
    EqValue Factor() {
        if (s[idx] == 'x') {
            idx++; return {1, 0};
        } else if (s[idx] == '(') {
            idx++; // skip '('
            EqValue val = Expression();
            idx++; // skip ')'
            return val;
        }
        long long num = 0;
        while (idx < s.length() && isdigit(s[idx])) {
            num = num * 10 + (s[idx++] - '0');
        }
        return {0, num};
    }
    EqValue Term() {
        EqValue val1 = Factor();
        while (idx < s.length() && s[idx] == '*') {
            idx++;
            EqValue val2 = Factor();
            val1 = val1 * val2;
        }
        return val1;
    }
    EqValue Expression() {
        EqValue val1 = Term();
        while (idx < s.length() && (s[idx] == '+' || s[idx] == '-')) {
            char op = s[idx++];
            EqValue val2 = Term();
            if (op == '+') {
                val1 = val1 + val2;
            } else if (op == '-') {
                val1 = val1 - val2;
            }
        }
        return val1;
    }
    EqValue solve() { return Expression(); }
};
signed main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Case " << i << ": ";
        string expr;
        cin >> expr;

        string left = "", right = "";
        bool ok = false;
        for (char c : expr) {
            if (c == '=') {
                ok = true;
                continue;
            }
            (ok ? right : left).push_back(c);
        }

        ExpressionSolve leftSide(left);
        ExpressionSolve rightSide(right);
        EqValue ans = leftSide.solve() - rightSide.solve();
        // ax + b = 0;
        // ax = -b

        cerr << ans.A << " " << ans.B << endl;

        if (ans.A == 0) {
            if (ans.B == 0) {
                cout << "infinitely many solutions" << endl;
            } else {
                cout << "no solution" << endl;
            }
        } else {
            if (ans.B % ans.A == 0) {
                cout << -ans.B / ans.A << endl;
            } else {
                long long g = __gcd(abs(ans.A), abs(ans.B));
                long long p = -ans.B / g;
                long long q = ans.A / g;

                if (q < 0) {
                    p = -p;
                    q = -q;
                }
                cout << p << "/" << q << endl;
            }
        }
    }
    return 0;
}
