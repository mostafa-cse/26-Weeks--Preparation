#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
#define all(x) x.begin(), x.end()
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;


    struct exam_mark
    {
        int a, b, c;
        int total;
        int id;
        exam_mark() : a(0), b(0), c(0), total(0) {}
        void all_mark() {
            total = a + b + c;
        }

        bool operator<(exam_mark &other) {
            if (total == other.total) {
                if (a == other.a) {
                    return id < other.id;
                } else {
                    return a > other.a;
                }
            }
            return total > other.total;
        }
    };

    vector<exam_mark> student(n);
    for (int i = 0; i < n; i++) {
        cin >> student[i].a >> student[i].b >> student[i].c;
        student[i].all_mark();
        student[i].id = i + 1;
    }
    sort(all(student));
    for (int i = 0; i < 5; i++) {
        cout << student[i].id << " " << student[i].total << endl;
    }
    return 0;
}
