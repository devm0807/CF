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
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    ll c0=0,c1=0,c2=0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        if(a[i]==0) c0++;
        else if(a[i]==1) c1++;
        else c2++;
    }
    ll T = c1 + 2*c2;
    if(s < T){
        for(ll x:a) cout << x << ' ';
        cout << "\n";
        return;
    }
    ll X = s - T;
    if(X == 1){
        for(ll i=0;i<c0;i++) cout << 0 << ' ';
        for(ll i=0;i<c2;i++) cout << 2 << ' ';
        for(ll i=0;i<c1;i++) cout << 1 << ' ';
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
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