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

ll getFactorial(ll n, ll mod)
{
    ll answer = 1;
    for (int i = 2; i <= n; i++)
    {
        answer = (answer * i) % mod;
    }
    return answer;
}
const ll MAXN = 1005;
ll factorial[MAXN];
ll modInv(ll a)
{
    return a <= 1 ? a : MOD - (MOD / a) * modInv(MOD % a) % MOD;
}
ll nCk(ll n, ll k)
{
    return factorial[n] * modInv(factorial[k] * factorial[n - k] % MOD) % MOD;
}

ll query(ll x, ll y)
{
    cout << "? " << x << " " << y << endl;
    ll ans;
    cin >> ans;
    return ans;
}
void printAnswer(vector<ll>& ans)
{
    cout << "! ";
    for (ll x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}
void solve()
{
    ll n;
    cin >> n;
    int l = 1, r = 2;
    vector<ll> ans(n, 0);
    while(r<=n){
        ll lmodr = query(l, r);
        ll rmodl = query(r, l);
        // cout << "lmodr: " << lmodr << ", rmodl: " << rmodl << ", l: " << l << ", r: " << r << endl;
        if(lmodr > rmodl) {    // a[l] < a[r]
            ans[l-1] = lmodr;
            l = r;
        } else {
            ans[r-1] = rmodl;
        }
        r++;
    }
    ans[l-1] = n;
    printAnswer(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1; // number of test cases
    // cin >> T;
    // factorial[0] = 1;
    // for (int i = 1; i <= MAXN; i++) {
    //     factorial[i] = factorial[i - 1] * i % MOD;
    // }
    while (T--)
    {
        solve();
    }

    return 0;
}