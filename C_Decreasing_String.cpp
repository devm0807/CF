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
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
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

ll MOD = 998244353;

ll inverse(ll a, ll mod) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inverse(mod % a, mod) % mod;
}

void solve()
{
    string s;
    cin >> s;
    ll pos;
    cin >> pos;
    int n = s.length();
    int to_remove = 0;
    int offset = 0;
    while(pos>0 && to_remove < n) {
        pos -= (n-to_remove);
        to_remove++;
    }
    to_remove--;
    offset = pos + (n-to_remove);
    // cout << to_remove << " " << offset << endl;
    vector<char> stack;
    for (int i = 0; i < n; i++) {
        while(!stack.empty() && stack.back() > s[i] && to_remove > 0) {
            stack.pop_back();
            to_remove--;
        }
        stack.push_back(s[i]);
    }
    while(to_remove > 0 && !stack.empty()) {
        stack.pop_back();
        to_remove--;
    }
    cout << stack[offset-1];
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