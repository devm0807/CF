#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1, 0);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    // int maxdeg = INT_MIN, maxnode = -1;
    // for (int i = 1; i <= n; i++) {
    //     if (deg[i] > maxdeg) {
    //         maxdeg = deg[i];
    //         maxnode = i;
    //     }
    // }
    // vector<bool> visited(n+1, false);
    // visited[maxnode] = true;
    // int count = 0;
    // for (int neighbor : adj[maxnode]){
    //     if (deg[neighbor] == 1)  continue;
    //     stack<int> stk;
    //     stk.push(neighbor);
    //     while (!stk.empty()) {
    //         int node = stk.top();
    //         visited[node] = true;
    //         stk.pop();
    //         if(adj[node].size() == 1) count++;
    //         for (int next : adj[node]) {
    //             if (!visited[next]) {
    //                 stk.push(next);
    //             }
    //         }
    //     }
    // }
    // cout << count << endl;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(deg[i]==1) ans++;
    }
    int root1nbr = INT_MIN;
    for(int u=1;u<=n;u++){
        int cnt = 0;
        if(deg[u]==1){
            cnt++;
        }
        for(int v: adj[u]){
            if(deg[v]==1) cnt++;
        }
        root1nbr = max(root1nbr, cnt);
    }
    cout << ans - root1nbr << endl;
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