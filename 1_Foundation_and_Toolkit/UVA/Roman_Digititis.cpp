#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    vector<pair<int, string>> roman = {
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
    string ans;
    for (auto [value, symbol] : roman) {
        while (num >= value) {
            num -= value;
            ans += symbol;
        }
    }
    return ans;
}

int main() {
    vector<int> i1(101, 0), v5(101, 0), x10(101, 0), l50(101, 0), c100(101, 0);
    for (int i = 1; i <= 100; i++) {
        string num = intToRoman(i);
        for (char c : num) {
            if (c == 'I') i1[i]++;
            if (c == 'V') v5[i]++;
            if (c == 'X') x10[i]++;
            if (c == 'L') l50[i]++;
            if (c == 'C') c100[i]++;
        }
        i1[i] += i1[i - 1];
        v5[i] += v5[i - 1];
        x10[i] += x10[i - 1];
        l50[i] += l50[i - 1];
        c100[i] += c100[i - 1];
    }

    int n;
    while (cin >> n) {
        if (n == 0) break;
        cout << n << ": ";
        cout << i1[n] << " i, " << v5[n] << " v, " << x10[n] << " x, " << l50[n] << " l, " << c100[n] << " c\n";
    }

    return 0;
}
