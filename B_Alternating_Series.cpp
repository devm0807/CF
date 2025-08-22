#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin >> n;
    if(n==2){
        cout << -1<<" " << 2<< endl;
        return;
    }
    vector<int> a(n);
    for(int i=0;i<n;i+=2){
        a[i] = -1;
    }
    for(int i=1;i<n;i+=2){
        a[i] = 3;
    }
    if(a[n-1]==3){
        a[n-1] = 2;
    }
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
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