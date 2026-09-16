#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
int n, k;
vector<int> A, B, C;
void printABC(){
    if (k <= 0) return;

    cout << "A=>";
    if (!A.empty()) {
        cout << "   ";
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " \n"[i == A.size() - 1];
        }
    } else cout << endl;

    cout << "B=>";
    if (!B.empty()) {
        cout << "   ";
        for (int i = 0; i < B.size(); i++) {
            cout << B[i] << " \n"[i == B.size() - 1];
        }
    } else cout << endl;

    cout << "C=>";
    if (!C.empty()) {
        cout << "   ";
        for (int i = 0; i < C.size(); i++) {
            cout << C[i] << " \n"[i == C.size() - 1];
        }
    } else cout << endl;

    cout << endl;
    k--;
}

void move(int from, int to) {
    if (from == 1) {
        if (to == 2) {
            B.push_back(A.back());
        } else {
            C.push_back(A.back());
        }
        A.pop_back();
    } else if (from == 2) {
        if (to == 1) {
            A.push_back(B.back());
        } else {
            C.push_back(B.back());
        }
        B.pop_back();
    } else {
        if (to == 1) {
            A.push_back(C.back());
        } else {
            B.push_back(C.back());
        }
        C.pop_back();
    }
    printABC();
}

void tower(int slices, int from, int aux, int to) {
    if (k <= 0) return;
    if (slices == 0) {
        return;
    }
    tower(slices - 1, from, to, aux);
    move(from, to);
    tower(slices - 1, aux, from, to);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int Case = 1; cin >> n >> k; Case++) {
        if (n == 0 and k == 0) break;

        k++;

        cout << "Problem #" << Case << endl << endl;
        A.clear(), B.clear(), C.clear();
        for (int i = n; i >= 1; i--) A.push_back(i);

        printABC();
        tower(n, 1, 2, 3);
    }
    return 0;
}
