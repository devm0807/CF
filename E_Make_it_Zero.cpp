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
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    // cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    vector<int> pref(n+1,0);
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1] + a[i];
    }
    vector<int> suff(n+1,0);
    suff[n] = a[n];
    for(int i = n-1; i >= 1; i--){
        suff[i] = suff[i+1] + a[i];
    }
    for(int i = 1; i < n; i++){
        if(pref[i] == suff[i+1]){
            cout << 1 << endl;
            for(int j = 1; j <= n; j++){
                cout << a[j] << " ";
            }
            cout << endl;
            return;
        }
    }
    int i = 0;
    while(i<n && pref[i] < suff[i+1]){
        i++;
    }
    // for(int j = 1; j <= n; j++){
    //     cout << pref[j] << " ";
    // }
    // cout << endl;
    // for(int j = 1; j <= n; j++){
    //     cout << suff[j] << " ";
    // }
    // cout << endl;
    if(i == n){
        cout << -1 << endl;
        return;
    }
    int diff = pref[i] - suff[i+1];
    // cout << diff << endl;
    vector<int> b = a;
    // cout << "i: "<< i << endl;
    if(diff%2!=0){
        cout << -1 << endl;
        return;
    }
    int half_diff = diff / 2;
    while(i>=0){
        if(half_diff<b[i]){
            b[i] -= half_diff;
            diff -= half_diff;
        }else{
            diff -= b[i];
            b[i] = 0;
        }
        i--;
    }
    // for(int j = 1; j <= n; j++){
    //     cout << b[j] << " ";
    // }
    // cout << endl;
    cout << 2 << endl;
    for(int i=1;i<=n;i++){
        cout << a[i]-b[i] << " ";
    }
    cout << endl;
    for(int j = 1; j <= n; j++){
        cout << b[j] << " ";
    }
    cout << endl;
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