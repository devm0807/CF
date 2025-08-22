#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;

        int L = 1, R = n;
        while (L < R) {
            int m = (L + R) / 2;

            cout << "? " << L << " " << m << endl; // query and flush
            vector<int> vals(m - L + 1);
            for (int i = 0; i < m - L + 1; i++) {
                int x;
                if (!(cin >> x)) return 0; // input closed
                if (x == -1) return 0;      // invalid query => terminate
                vals[i] = x;
            }

            int cnt = 0;
            for (int x : vals) if (x >= L && x <= m) cnt++;

            if (cnt % 2 == 1) {
                R = m;
            } else {
                L = m + 1;
            }
        }
        cout << "! " << L << endl;
    }
    return 0;
}
// 4 2 5 1 3