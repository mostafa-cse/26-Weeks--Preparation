#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
void solve() {
    int n, w, pw, dw;
    cin >> n >> w >> pw >> dw;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<int> pfx(n);
    for (int i = 0; i < n; ++i) {
        pfx[i] = a[i];
        if (i) pfx[i] += pfx[i - 1];
    }

    auto get_next_word = [&](int start_idx, int max_space) {
        if (start_idx >= n) return n;
        if (a[start_idx] > max_space) return start_idx;

        int l = start_idx, r = n - 1;
        int pos = start_idx;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int sum = pfx[mid] - (start_idx > 0 ? pfx[start_idx - 1] : 0);
            int words_space = mid - start_idx;

            if (sum + words_space <= max_space) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return pos + 1;
    };

    vector<int> next_norm(n + 1, n);
    vector<int> next_pic(n + 1, n);
    for (int i = 0; i < n; ++i) {
        next_norm[i] = get_next_word(i, w);

        int after_left = get_next_word(i, dw);
        next_pic[i] = get_next_word(after_left, w - pw - dw);
    }

    int LOG = 20;
    vector<vector<int>> jump_norm(LOG, vector<int>(n + 1, n));
    vector<vector<int>> jump_pic(LOG, vector<int>(n + 1, n));
    for (int i = 0; i <= n; i++) {
        jump_norm[0][i] = next_norm[i];
        jump_pic[0][i] = next_pic[i];
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i <= n; i++) {
            jump_norm[j][i] = jump_norm[j - 1][jump_norm[j - 1][i]];
            jump_pic[j][i] = jump_pic[j - 1][jump_pic[j - 1][i]];
        }
    }

    auto get_rows_needed = [&](int curr, const vector<vector<int>>& jump) {
        if (curr >= n) return 0LL;
        if (jump[0][curr] == curr) return (long long)2e18;
        int rows = 0;
        for (int j = LOG - 1; j >= 0; j--) {
            if (jump[j][curr] < n) {
                curr = jump[j][curr];
                rows += (1LL << j);
            }
        }
        return rows + 1LL;
    };

    auto advance_rows = [&](int curr, int steps, const vector<vector<int>>& jump) {
        for (int j = 0; j < LOG; j++) {
            if ((steps >> j) & 1) {
                curr = jump[j][curr];
            }
        }
        if (steps >= (1LL << LOG) && jump[0][curr] != curr) {
            curr = n;
        }
        return curr;
    };

    int q;
    cin >> q;
    int text_before_pic = get_rows_needed(0, jump_norm);
    while (q--) {
        int x, h;
        cin >> x >> h;
        if (text_before_pic <= x - 1) {
            cout << text_before_pic + h << endl;
        } else {
            int curr = advance_rows(0, x - 1, jump_norm);
            int text_in_pic = get_rows_needed(curr, jump_pic);

            if (text_in_pic <= h) {
                cout << (x - 1) + h << endl;
            } else {
                curr = advance_rows(curr, h, jump_pic);
                int extra_rows = get_rows_needed(curr, jump_norm);
                cout << (x - 1) + h + extra_rows << endl;
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        // cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
