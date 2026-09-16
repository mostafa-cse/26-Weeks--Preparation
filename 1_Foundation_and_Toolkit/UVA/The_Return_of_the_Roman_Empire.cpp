#include <bits/stdc++.h>
using namespace std;

bool isValidRoman(const string& s) {
    regex pattern(
        "^(M{0,3})"
        "(CM|CD|D?C{0,3})"
        "(XC|XL|L?X{0,3})"
        "(IX|IV|V?I{0,3})$"
    );

    return regex_match(s, pattern);
}

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

int main() {
    string s;

    while (cin >> s) {
        if (!isValidRoman(s)) {
            cout << "This is not a valid number" << endl;
        } else {
            cout << romanToInt(s) << '\n';
        }
    }
    return 0;
}
