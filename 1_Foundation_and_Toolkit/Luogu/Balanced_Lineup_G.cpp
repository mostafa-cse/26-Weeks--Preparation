#include <bits/stdc++.h>
using namespace std;

template <class T, class F>
struct RMQ {
    vector<vector<T>> st;
    F f;
    RMQ(vector<T> v, F _f) : st(1, v), f(_f) {
        for (int p = 1; (1 << p) <= v.size(); ++p) {
            st.emplace_back(v.size() - (1 << p) + 1);
            for (int j = 0; j < st[p].size(); ++j)
                st[p][j] = f(st[p - 1][j], st[p - 1][j + (1 << (p - 1))]);
        }
    }
    T query(int l, int r) {
        int d = __lg(r - l + 1);
        return f(st[d][l], st[d][r - (1 << d) + 1]);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q))
        return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // C++17 ল্যাম্বডা ম্যাজিক দিয়ে Min এবং Max দুটোই বানিয়ে ফেললাম
    auto min_op = [](int x, int y) { return min(x, y); };
    auto max_op = [](int x, int y) { return max(x, y); };
    RMQ<int, decltype(min_op)> mn(a, min_op);
    RMQ<int, decltype(max_op)> mx(a, max_op);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--; // 0-based indexing

        // চোখের পলকে উত্তর! O(1) Time
        cout << mx.query(l, r) - mn.query(l, r) << "\n";
    }
    return 0;
}
