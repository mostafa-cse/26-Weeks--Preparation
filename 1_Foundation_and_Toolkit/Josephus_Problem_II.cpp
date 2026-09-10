#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
vector<int> getJosephusSequence(int n, int k) {
    pbds os; // Assumes 'pbds' is typedef'd in your boilerplate
    for (int i = 1; i <= n; i++) os.insert(i);

    vector<int> eliminated;
    int idx = 0; 

    while (!os.empty()) {
        idx = (idx + k - 1) % os.size();
        auto it = os.find_by_order(idx);
        eliminated.push_back(*it);
        os.erase(it);
    }
    return eliminated;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (auto el : getJosephusSequence(n, k + 1)) {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}
