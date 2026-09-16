#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void slidingWindowInversions(const vector<int>& a, int k) {
  pbds window;
  long long inv = 0;

  for (int i = 0; i < (int)a.size(); i++) {
    inv += window.size() - window.order_of_key({a[i], 1e9});
    window.insert({a[i], i});

    if (i >= k - 1) {
      cout << inv << " ";

      int rem = i - k + 1;
      window.erase({a[rem], rem});
      inv -= window.order_of_key({a[rem], -1});
    }
  }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    slidingWindowInversions(a, k);
    return 0;
}
