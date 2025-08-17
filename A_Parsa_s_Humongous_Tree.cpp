#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 1e9 + 7;

vector<ll> getfactors(ll n)
{
    vector<ll> factors;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (i * i != n)
            {
                factors.push_back(n / i);
            }
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}

ll gcd(ll a, ll b)
{
    if (a == -1 && b == -1)
        return -1;
    if (a == -1 || b == -1)
        return max(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll factorial(ll n, ll mod)
{
    ll answer = 1;
    for (int i = 2; i <= n; i++)
    {
        answer = (answer * i) % mod;
    }
    return answer;
}

bool isAcyclic(vector<vector<ll>>& adj, vector<ll>& visited, ll u, ll parent) {
  if(visited[u]) return false;
  visited[u] = 1;

  bool b = true;
  for(auto v:adj[u]) {
    if(v != parent)
      b &= isAcyclic(adj, visited, v, u);
  }
  return b;
}

int ask(vector<int> query){
    int k = query.size();
    cout << "? " << k << " ";
    for(int i=0;i<k;i++){
        cout << query[i] << " ";
    }
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}
void answer(string s){
    cout << "! " << s << endl;
}

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    vector<int> dp(W + 1, 0);
    for (int i = 1; i <= wt.size(); i++) {
        for (int j = W; j >= wt[i - 1]; j--) {
            dp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}

bool f(vector<ll> a, vector<ll> b, ll x){
    ll n = a.size();
	ll cnt = 0;
	for(ll i = 0; i < n; i++){
		if(x - 1 - a[i] <= cnt && cnt <= b[i]) cnt++;
	}
	return cnt >= x;
}
const ll MAXN = 2e5;
ll dp[2][MAXN] = {0};
void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& l, vector<int>& r) {
    dp[0][u] = 0;
    dp[1][u] = 0;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u, adj, l, r);
            dp[0][u] += max(dp[1][v] + abs(r[v]-l[u]), dp[0][v] + abs(l[v]-l[u]));
            dp[1][u] += max(dp[1][v] + abs(r[v]-r[u]), dp[0][v] + abs(l[v]-r[u]));
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> l(n+1), r(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    vector<vector<int>> adj(n+1);
    int u,v;
    for(int i=1;i<n;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1, adj, l, r);
    cout << max(dp[1][1], dp[0][1]) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int T = 1; // number of test cases
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}