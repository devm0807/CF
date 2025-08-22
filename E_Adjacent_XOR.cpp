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
    if(a[n-1] != b[n-1]){
        cout << "NO" << endl;
        return;
    }
    for(int i=n-2;i>=0;i--){
        if(a[i]==b[i] ||
           (a[i] ^ b[i]) == a[i+1] ||
           (a[i] ^ b[i]) == b[i+1]){
            continue;
        } else {
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
