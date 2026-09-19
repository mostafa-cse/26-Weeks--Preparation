#include <bits/stdc++.h>
using namespace std;

struct BooleanParser {
    string s;
    int idx;
    int mask;

    BooleanParser(string _s, int _mask) : s(_s), idx(0), mask(_mask) {}

    // Factor => Sub | '!' Factor
    bool Factor() {
        if (s[idx] == '!') {
            idx++;
            return !Factor();
        }
        if (s[idx] == '(') {
            idx++;
            bool val = Expression();
            idx++;
            return val;
        } else {
            int bit_pos = s[idx] - 'a';
            idx++;
            return (mask & (1 << bit_pos)) != 0;
        }
    }

    bool Term() {
        bool val1 = Factor();
        while (idx < s.length() && s[idx] == '&') {
            idx++;
            bool val2 = Factor();
            val1 = (val1 && val2);
        }
        return val1;
    }

    bool Expression() {
        bool val1 = Term();
        while (idx < s.length() && s[idx] == '|') {
            idx++;
            bool val2 = Term();
            val1 = (val1 || val2);
        }
        return val1;
    }

    bool solve() { return Expression(); }
};

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string expr1, expr2;
        cin >> expr1 >> expr2;

        bool equivalent = true;
        for (int mask = 0; mask < (1 << 10); mask++) {
            BooleanParser p1(expr1, mask);
            BooleanParser p2(expr2, mask);

            if (p1.solve() != p2.solve()) {
                equivalent = false;
                break; 
            }
        }

        cout << "Case " << i << ": ";
        if (equivalent) cout << "Equivalent\n";
        else cout << "Not Equivalent\n";
    }
    return 0;
}
