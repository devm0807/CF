#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> s(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i] = s[i]%k;
        s[i] = min(s[i], k - s[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i] = t[i]%k;
        t[i] = min(t[i], k - t[i]);
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    // for(int i=0;i<n;i++){
    //     cout << s[i] << " ";
    // }
    // cout << endl;
    // for(int i=0;i<n;i++){
    //     cout << t[i] << " ";
    // }
    // cout << endl;
    // cout << "##################\n";
    for (int i=0; i<n; i++) {
        if (s[i] != t[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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