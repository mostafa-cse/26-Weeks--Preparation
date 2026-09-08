#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int m, n;
    cin >> m >> n;
    queue<int> que;
    unordered_set<int> mem;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int word;
        cin >> word;
        if (mem.empty())
        {
            que.emplace(word);
            mem.emplace(word);
            res++;
        }
        else if (!mem.empty())
        {
            if (mem.size() == m && !mem.count(word))
            {
                int tmp = que.front();
                que.pop();
                mem.erase(tmp);
                que.emplace(word);
                mem.emplace(word);
                res++;
            }
            else if (mem.count(word))
            {
                continue;
            }
            else
            {
                que.emplace(word);
                mem.emplace(word);
                res++;
            }
        }
    }

    cout << res << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
