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

ll getFactorial(ll n, ll mod)
{
    ll answer = 1;
    for (int i = 2; i <= n; i++)
    {
        answer = (answer * i) % mod;
    }
    return answer;
}

vector<bool> sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

// To begin with, it is worth mentioning that if you need to count the number
// of certain integers in the interval [l,r], it is almost always more convenient
// to do it this way: count the number of such integers in [0,r+1) (or in [1,r+1)),
// and then subtract the count in [0,l) (or in [1,l)). Counting the number of integers
// on a prefix is usually significantly easier than in an interval.

struct DSU
{
    vector<int> p;
    DSU(int N) : p(N + 1)
    {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        p[b] = a;
        return true;
    }
};

ll MOD = 998244353;

ll inverse(ll a, ll mod)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * inverse(mod % a, mod) % mod;
}

bool f()
{
    return false;
}

ll andRange(ll a, ll b) {
    // ShiftCount variables counts till which bit every value will convert to 0
    int shiftcount = 0;
    //Iterate through every bit of a and b simultaneously
    //If a == b then we know that beyond that the and value will remain constant
    while(a != b and a > 0) {
        shiftcount++;
        a = a >> 1; 
        b = b >> 1;
    }
    return int64_t(a << shiftcount);
}

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;

    // Map unique chars in a to indices
    vector<char> chars;
    unordered_map<char, int> char_idx;
    for (char c : a) {
        if (char_idx.count(c) == 0) {
            char_idx[c] = chars.size();
            chars.push_back(c);
        }
    }
    int m = chars.size();
    k = min(k, m);

    ll ans = 0;
    for (int mask = 0; mask < (1 << m); ++mask) {
        if (__builtin_popcount(mask) > k) continue;
        ll cnt = 0, len = 0;
        for (int i = 0; i < n; ++i) {
            bool unlocked = (mask & (1 << char_idx[a[i]]));
            if (a[i] == b[i] || unlocked) {
                len++;
            } else {
                cnt += len * (len + 1) / 2;
                len = 0;
            }
        }
        cnt += len * (len + 1) / 2;
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1; // number of test cases
    cin >> T;
    while (T--){
        solve();
    }

    return 0;
}