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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    ll v = 0;
    vector<vector<ll>> segs;
    for(int i=0;i<n;i++){
        vector<ll> seg = {a[i],b[i]};
        sort(seg.begin(), seg.end());
        segs.push_back(seg);
        v += abs(a[i]-b[i]);
    }
    sort(segs.begin(), segs.end());
    ll mini = INT_MAX;
    for(int i=0;i<segs.size()-1;i++){
        if(segs[i][1]>segs[i+1][0]){
            cout << v << endl;
            return;
        }
        mini = min(mini, v - (segs[i+1][1]-segs[i+1][0]) - (segs[i][1]-segs[i][0]) + (segs[i+1][0]-segs[i][0]) + (segs[i+1][1]-segs[i][1]));
    }
    cout <<  mini << endl;
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