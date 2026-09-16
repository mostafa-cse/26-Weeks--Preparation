#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    while(getline(cin, s)) {
        vector<int> nums;
        stringstream ss(s);
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }

        for (int i : nums) {
            cout << i << " ";
        }
        cout << endl;
        int n = nums.size();

        while (!is_sorted(all(nums))) {
            int mx = nums[0];
            int pos = 0;
            bool ok = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < mx) {
                    pos = i;
                    mx = nums[i];
                    ok = false;
                }
            }

            if (ok) {
                break;
            } else {
                cout << n - pos << " ";
                reverse(nums.begin(), nums.begin() + pos + 1);
            }
        }
        dout(nums);
        cout << 0 << endl;
    }
    return 0;
}
