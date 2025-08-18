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

struct SegTree
{
    int n;
    vector<int> t;
    SegTree(int N) : t(4 * N) {}
    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            t[v] = a[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    int sum(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
        {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    void update(int v, int tl, int tr, int pos, int new_val)
    {
        if (tl == tr)
        {
            t[v] = new_val;
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
};

ll MOD = 998244353;

ll inverse(ll a, ll mod)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * inverse(mod % a, mod) % mod;
}

bool predicate(vector<ll> &a, ll x)
{
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> segs(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> segs[i].first >> segs[i].second;
        segs[i].first--;
        segs[i].second--; // 0-based
    }
    int q;
    cin >> q;
    vector<int> changes(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> changes[i];
        changes[i]--; // 0-based
    }

    int left = 1, right = q, ans = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        vector<int> a(n, 0);
        for (int i = 0; i < mid; ++i)
        {
            a[changes[i]] = 1;
        }
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            pref[i + 1] = pref[i] + a[i];
        }
        bool found = false;
        for (auto [l, r] : segs)
        {
            int ones = pref[r + 1] - pref[l];
            int len = r - l + 1;
            if (ones > len - ones)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans << "\n";
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