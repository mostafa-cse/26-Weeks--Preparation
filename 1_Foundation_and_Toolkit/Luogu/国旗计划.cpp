#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
struct Guard {
    int id;
    int l, r;
};
const int M = 4e5 + 5;
const int LOG = 20;
int n, m;
Guard g[M];
int nxt[M][LOG];
int ans[M];
bool cmp(const Guard &x, const Guard &y) {
    if (x.l == y.l) return x.r < y.r;
    return x.l < y.l;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> g[i].l >> g[i].r;
        g[i].id = i;
        if (g[i].l > g[i].r) {
            g[i].r += m;
        }
    }
    for (int i = 1; i <= n; i++) {
        g[i + n].id = g[i].id;
        g[i + n].l = g[i].l + m;
        g[i + n].r = g[i].r + m;
    }

    sort(g + 1, g + 2 * n + 1, cmp);

    int ptr = 1;
    for (int i = 1; i <= n * 2; i++) {
        while (ptr <= 2 * n and g[ptr].l <= g[i].r) {
            ptr++;
        }
        nxt[i][0] = ptr - 1;
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= 2 * n; i++) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        int cur = i;
        int count = 1;
        long long target = g[i].l + m;

        for (int j = LOG - 1; j >= 0; j--) {
            if (nxt[cur][j] != 0 && g[nxt[cur][j]].r < target) {
                count += (1 << j);
                cur = nxt[cur][j];
            }
        }
        ans[g[i].id] = count + 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    return 0;
}
