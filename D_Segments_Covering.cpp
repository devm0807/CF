#include <bits/stdc++.h>
using namespace std;
using ll = long long;


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


struct DSU {
    vector<int> p;
    DSU(int N): p(N+1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        return p[x]==x ? x : p[x]=find(p[x]);
    }
    bool unite(int a, int b){
        a = find(a); 
        b = find(b);
        if(a==b) return false;
        p[b] = a;
        return true;
    }
};

bool predicate(){
    // This function can be used to check some condition
    // For example, checking if a number is prime or not
    return true; // Placeholder implementation
}

// To begin with, it is worth mentioning that if you need to count the number 
// of certain integers in the interval [l,r], it is almost always more convenient 
// to do it this way: count the number of such integers in [0,r+1) (or in [1,r+1)), 
// and then subtract the count in [0,l) (or in [1,l)). Counting the number of integers
// on a prefix is usually significantly easier than in an interval.

ll MOD = 998244353;

ll inv(int a) {
  return a <= 1 ? a : MOD - (long long)(MOD/a) * inv(MOD % a) % MOD;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> l(n), r(n), p(n), q(n);
    vector<vector<int>> seg_ending(m+1);
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> p[i] >> q[i];
        seg_ending[r[i]].push_back(i);
    }
    vector<int> dp(m+1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        dp[0] = (dp[0] * (((q[i]-p[i]) * inv(q[i])) % MOD)) % MOD;
    }
    for(int i = 1; i <= m; i++) {
        for(int j : seg_ending[i]) {
            dp[i] = (dp[i] + (((p[j] * inv(q[j]-p[j])) % MOD) * dp[l[j]-1]) % MOD) % MOD;
        }
    }
    cout << dp[m] << endl;
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