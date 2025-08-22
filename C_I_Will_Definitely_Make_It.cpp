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
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    int cur = h[k-1];
    int time = h[k-1];
    sort(h.begin(), h.end());
    int i=0;
    bool ans = true;
    for(int i = 0;i < n;i++) {
      if(h[i] < cur) continue;
      if(h[i] - cur > time) {
        ans = false;
      }
      cur = h[i];
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
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