#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    // A, E, I, O, U, Y, W, H
    set<char> encd = {'A', 'E', 'I', 'O', 'U', 'Y', 'W', 'H'};
    map<char, char> mark = {
        {'B', '1'},
        {'P', '1'},
        {'F', '1'},
        {'V', '1'},
        {'C', '2'},
        {'S', '2'},
        {'K', '2'},
        {'G', '2'},
        {'J', '2'},
        {'Q', '2'},
        {'X', '2'},
        {'Z', '2'},
        {'D', '3'},
        {'T', '3'},
        {'L', '4'},
        {'M', '5'},
        {'N', '5'},
        {'R', '6'},
    };
    for (int i = 0; i < 10; i++) cout << " ";
    cout << "NAME";
    for (int i = 0; i < 15; i++) cout << " ";
    cout << "SOUNDEX CODE" << endl;
    while (cin >> s) {
        string code;
        for (int i = 0; i < s.size(); i++){
            if (i == 0) {
                code.push_back(s[i]);
                continue;
            }
            if (encd.count(s[i])) continue;
            code.push_back(s[i]);
        }

        string ans;
        ans.push_back(code[0]);
        for (int i = 1; i < code.size(); i++) {
            ans.push_back(mark[code[i]]);
        }
        for (int i = 0; i < )
    }
    return 0;
}
