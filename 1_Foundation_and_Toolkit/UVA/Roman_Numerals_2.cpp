#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
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

    map<int, int> cnt = {
        {'I', 1},
        {'V', 2},
        {'X', 2},
        {'L', 2},
        {'C', 2},
        {'D', 3},
        {'M', 4}
    };
    int n;
    while (cin >> n) {
        string s  = intToRoman(n);

        int ans = 0;
        for (char i : s) {
            ans += cnt[i];
        }
        cout << ans << endl;
    }
    return 0;
}
