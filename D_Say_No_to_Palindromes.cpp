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

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string t = "abc";
    vector<vector<int>> cost(6, vector<int>(n));
    for(int k=0;k<6;k++){
        for(int i=0;i<n;i++){
            cost[k][i] = s[i]!=t[i%3];
        }
        // cout << t << endl;
        next_permutation(t.begin(), t.end());
    }
    vector<vector<int>> pref(6, vector<int>(n+1));
    for(int k=0;k<6;k++){
        pref[k][0] = 0;
        for(int i=1;i<=n;i++){
            pref[k][i] = pref[k][i-1] + cost[k][i-1];
        }
    }
    for(int q=0;q<m;q++){
        int ans = INT_MAX;
        int l,r;
        cin >> l >> r;
        for(int k=0;k<6;k++){
            ans = min(ans, pref[k][r]-pref[k][l-1]);
        }
        cout << ans << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int T = 1; // number of test cases
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}