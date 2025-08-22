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

ll MOD = 998244353;

ll inverse(ll a, ll mod)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * inverse(mod % a, mod) % mod;
}

bool f()
{
    return false;
}

void solve()
{
    ll n;
    cin >> n;
    vector<int> a(n + 1);
    vector<set<int>> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        adj[i].insert(a[i]);
        adj[a[i]].insert(i);
    }
    ll loops = 0;
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    stack<int> st;
    int components_count = 0;
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        components_count++;
        st.push(i);
        while (!st.empty()){ // dfs algorithm
            int u = st.top();
            st.pop();
            if (visited[u])
                continue;
            visited[u] = true;
            for (auto &v : adj[u]){
                if (!visited[v]) {
                    parent[v] = u;
                    st.push(v);
                }
                else if(v != parent[u]) { // if we find a back edge
                    loops++;  
                }
            }
        }
    }
    cout << loops + (components_count!=loops) << " " << components_count << endl;
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