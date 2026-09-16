#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    vector<long long> s(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    deque<int> dq;
    int ans = 0;

    for (int j = 1; j < 2 * n; j++) {
        while (!dq.empty() && s[dq.back()] >= s[j]) {
            dq.pop_back();
        }
        dq.push_back(j);

        if (j >= n) {
            int k = j - n + 1;

            while (!dq.empty() && dq.front() < k) {
                dq.pop_front();
            }

            if (s[dq.front()] >= s[k - 1]) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
