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


void solve()
{
    ll N, K;
    cin >> N >> K;
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(K + 1, vector<ll>(2, 0)));
    for(int n=1;n<=N;n++){
        dp[n][1][0] = 1;
        dp[n][1][1] = 1;
    }
    for(int k=2;k<=K;k++){
        for(int n=N;n>=1;n--){  // forward
            int ans = 2;    // 1 plane so copy and itself
            if(n<N){
                ans = (ans + dp[n+1][k][0] - 1)%MOD;
            }
            if(n>1){
                ans = (ans + dp[n-1][k-1][1] - 1)%MOD;
            }
            dp[n][k][0] = ans;
        }
        for(int n=1;n<=N;n++){  // backward
            int ans = 2;
            if(n<N){
                ans = (ans + dp[n+1][k-1][0] - 1)%MOD;
            }
            if(n>1){
                ans = (ans + dp[n-1][k][1] - 1)%MOD;
            }
            dp[n][k][1] = ans;
        }
    }
    cout << dp[1][K][0] << endl;
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