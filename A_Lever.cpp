#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> c(n);
    int count = 1;
    for (int i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
        count += max(c[i], 0);
        // cout << c[i] << " ";
    }
    // cout << endl;
    cout << count << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; // Number of test cases
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}