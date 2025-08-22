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

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int, int>> freq(26);
    for(int i=0;i<26;i++) freq[i] = {0, i};
    for(int i=0;i<n;i++){
        freq[s[i]-'a'].first++;
    }
    vector<pair<int,int>> freq1 = freq;
    sort(freq.begin(), freq.end());
    reverse(freq.begin(), freq.end());
    // for(int i=0;i<26;i++) cout << freq[i].first << " " << char(freq[i].second+'a') << endl;
    int index = 0;
    int ans = INT_MAX;
    for(int i=1;i<=26;i++){
        if(n%i!=0) continue;

        int extra=0, less=0;
        for(int j=0;j<i;j++){
            if(freq[j].first > n/i) extra += freq[j].first - n/i;
            if(freq[j].first < n/i) less += -1*(freq[j].first - n/i);
        }
        for(int j=i;j<26;j++){
            less += freq[j].first;
        }
        int req = min(extra, less) + (abs(extra-less)+1)/2;
        // cout << i << " " << extra << " " << less << " " << req << endl;
        if(req < ans){
            index = i;
            ans = req;
        }
    }
    set<int> extra, less;
    for(int j=0;j<index;j++){
        if(freq[j].first > n/index) extra.insert(freq[j].second);
        if(freq[j].first < n/index) less.insert(freq[j].second);
    }
    for(int i=0;i<n;i++){
        int c = s[i] - 'a';
        if(freq1[c].first == n/index) continue;

        if(extra.count(c) || (!extra.count(c) && !less.count(c))){
            freq1[c].first--;
            int l = *less.begin();
            s[i] = char(l+'a');
            freq1[l].first++;
            if(freq1[l].first == n/index) less.erase(l);
        }
    }
    cout << ans << endl;
    cout << s << endl;
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