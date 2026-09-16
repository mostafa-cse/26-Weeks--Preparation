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
void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    deque<int> A, B;
    for (int i = 1; i <= n; i++) {
        A.push_back(i);
        B.push_back(i);
    }

    if (a + b > n) {
        cout << "NO" << endl;
    } else {
        vector<int> ans_a, ans_b;

        // Draw match
        int draw = n - (a + b);
        for (int i = 0; i < draw; i++) {
            ans_a.push_back(A.back());
            A.pop_back();

            ans_b.push_back(B.back());
            B.pop_back();
        }

        // A win match
        for (int i = 0; i < a; i++) {
            ans_a.push_back(A[A.size() - a + i]);
        }
        for (int i = 0; i < a; i++) {
            ans_b.push_back(B[i]);
        }
        for (int i = 0; i < a; i++) {
            A.pop_back();
            B.pop_front();
        }

        // B win match
        for (int i = 0; i < b; i++) {
            ans_a.push_back(A[i]);
        }
        for (int i = 0; i < b; i++) {
            ans_b.push_back(B[B.size() - b + i]);
        }
        for (int i = 0 ; i < b; i++) {
            A.pop_back();
            B.pop_front();
        }

        // check
        int winA = 0, winB = 0;
        for (int i = 0; i < n; i++) {
            draw -= (ans_a[i] == ans_b[i]);
            winA += ans_a[i] > ans_b[i];
            winB += ans_a[i] < ans_b[i];
        }

        if (draw == 0 and winA == a and winB == b) {
            cout << "YES" << endl;
            for (int i : ans_a) {
                cout << i << " ";
            }
            cout << endl;

            for (int i : ans_b) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
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
