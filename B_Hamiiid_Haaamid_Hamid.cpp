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
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int l = x-1;
    int r = n-x;

    int l_wall = 0;
    for(int i=l+1;i<n;i++){
        if(s[i]=='#'){
            l_wall = n-i;
            break;
        }
    }
    int r_wall = 0;
    for(int i=l-1;i>=0;i--){
        if(s[i]=='#'){
            r_wall = i+1;
            break;
        }
    }
    if(min(l,l_wall) > min(r, r_wall)){
        cout << min(l, l_wall) + 1 << endl;
    } else {
        cout << min(r, r_wall) + 1 << endl;
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