#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<int> deg(n+1, 0);
        bool bad = false;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            cin >> a[i] >> b[i];
            if(a[i] == b[i]) bad = true;           // loop -> impossible
            deg[a[i]]++; deg[b[i]]++;
            adj[a[i]].push_back(b[i]);
            adj[b[i]].push_back(a[i]);
        }
        if(bad) {
            cout << "NO\n";
            continue;
        }
        for(int v=1; v<=n; ++v) if(deg[v] != 2) { bad = true; break; }
        if(bad) {
            cout << "NO\n";
            continue;
        }
        vector<char> vis(n+1, 0);
        for(int v=1; v<=n; ++v){
            if(!vis[v]){
                // BFS/DFS to get component size (number of vertices)
                int sz = 0;
                stack<int> st;
                st.push(v);
                vis[v] = 1;
                while(!st.empty()){
                    int u = st.top(); st.pop();
                    ++sz;
                    for(int w: adj[u]){
                        if(!vis[w]){
                            vis[w] = 1;
                            st.push(w);
                        }
                    }
                }
                if(sz % 2 == 1) { bad = true; break; } // odd cycle length -> impossible
            }
        }
        cout << (bad ? "NO\n" : "YES\n");
    }
    return 0;
}
