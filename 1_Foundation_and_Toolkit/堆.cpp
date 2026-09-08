#include<bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
string cdn[2] = {"YES", "NO"};
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    int n;
    cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
    	int c;
    	cin >> c;

    	if (c == 1) {
    		int x;
    		cin >> x;

    		pq.push(-x);
    	} else {
    		if (c == 2) {
    			cout << pq.top() * -1 << endl;
    		} else {
    			pq.pop();
    		}
    	}
    }
    return 0;
}
