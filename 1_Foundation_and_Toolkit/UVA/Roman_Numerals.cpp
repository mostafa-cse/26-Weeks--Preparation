#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
int romanToInt(const string& s) {
    unordered_map<char, int> val = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int ans = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        if (i + 1 < (int)s.size() && val[s[i]] < val[s[i + 1]])
            ans -= val[s[i]];
        else
            ans += val[s[i]];
    }
    return ans;
}
string intToRoman(int num) {
    vector<pair<int, string>> roman = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
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
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string x;
    while (cin >> x) {
        if (isdigit(x[0])) {
            cout << intToRoman(stoll(x)) << endl;
        } else {
            cout << romanToInt(x) << endl;
        }
    }
    return 0;
}
