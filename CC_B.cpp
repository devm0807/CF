#include <bits/stdc++.h>
using namespace std;

int getMex(vector<int>& arr, int n) {
    vector<bool> present(n + 1, false);
    for(int x : arr) {
        if(x < n) present[x] = true;
    }
    for(int i = 0; i <= n; i++) {
        if(!present[i]) return i;
    }
    return n;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    // Try values from 0 to n-1 as potential answer
    for(int target = 0; target < n; target++) {
        vector<int> a_copy = a;
        vector<int> b_copy = b;
        
        // Try to ensure both arrays have numbers 0 to target-1
        bool possible = true;
        for(int val = 0; val < target; val++) {
            bool in_a = false, in_b = false;
            int pos_a = -1, pos_b = -1;
            
            // Check if val exists in either array
            for(int i = 0; i < n; i++) {
                if(a_copy[i] == val) {
                    in_a = true;
                    pos_a = i;
                }
                if(b_copy[i] == val) {
                    in_b = true;
                    pos_b = i;
                }
            }
            
            // If val missing from both arrays, impossible
            if(!in_a && !in_b) {
                possible = false;
                break;
            }
            
            // If val missing from one array but present in other, swap
            if(!in_a && in_b) {
                swap(a_copy[pos_b], b_copy[pos_b]);
            }
            if(!in_b && in_a) {
                swap(a_copy[pos_a], b_copy[pos_a]);
            }
        }
        
        // Check if this target works
        if(possible) {
            int mex_a = getMex(a_copy, n);
            int mex_b = getMex(b_copy, n);
            if(max(mex_a, mex_b) == target) {
                cout << target << "\n";
                return;
            }
        }
    }
    
    // If no earlier value worked, answer is n
    cout << n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}