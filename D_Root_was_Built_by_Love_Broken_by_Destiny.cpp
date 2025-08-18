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

ll MAXN = 2e5+10;
vector<ll> fact(MAXN+1);

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

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> u(m), v(m);
    vector<ll> deg(n+1, 0);
    vector<vector<ll>> adj(n+1);
    for(int i=0;i<m;i++){
        cin >> u[i] >> v[i];
        deg[u[i]]++;
        deg[v[i]]++;
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    vector<ll> visited(n+1, 0);
    if(!isAcyclic(adj, visited, 1, -1)){
        cout << 0 << endl;
        return;
    }
    ll ans = 1;
    for(int u=1;u<=n;u++){
        if(deg[u]>=2){
            ll cnt = 0;
            for(auto v: adj[u]){
                if(deg[v]>=2) cnt++;
            }
            if(cnt > 2){
                cout << 0<< endl;
                return;
            }
            ans = ans * fact[deg[u]-cnt] % MOD;
        }
    }
    ll mul = 4;
    ll cnt = 0;
    for(int i=1;i<=n;i++){
        if(deg[i]>1) cnt++;
    }
    if(cnt == 1) mul = 2;
    if(cnt == 0 && n==2) mul = 2;
    // cout << ans << " " <<  mul << " " <<  cnt << endl;
    cout << ans * mul % MOD << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1; // number of test cases
    cin >> T;
    fact[0] = 1;
    for(int i=1;i<=MAXN;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    while (T--)
    {
        solve();
    }

    return 0;
}