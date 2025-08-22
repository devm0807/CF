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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    vector<int> b(n+1);
    // vector<vector<int>> p(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
        // p[i] = {a[i],i};
    }
    sort(b.begin()+1, b.end());
    unordered_map<int, int> freq;
    for(int i=k;i<=n;i++){
        freq[b[i]]++;
    }
    int l=1, r=n;
    while(l<r){
        if(a[l]==a[r]){
            l++;
            r--;
        } else if(a[l]>a[r]){
            if(freq[a[l]]>0){
                freq[a[l]]--;
                l++;
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            if(freq[a[r]]>0){
                freq[a[r]]--;
                r--;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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