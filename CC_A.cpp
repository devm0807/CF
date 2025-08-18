#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int A1, B1, A2, B2;
        cin >> A1 >> B1 >> A2 >> B2;
        int diff = (A1 - A2) + (B2 - B1);
        if(diff % 6 != 0){
            cout << "No\n";
            continue;
        }
        int S = diff / 6;
        int z = (A1 - A2) - S;
        if(z < 0){
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }
    return 0;
}