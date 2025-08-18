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

pair<int,int> isSubMedian(vector<int>& a, int k, int v){
    int n = a.size();
    vector<int> greater(n), pref(n+1, 0);
    for(int i=0; i<n; i++){
        if(a[i] >= v) {
            greater[i] = 1;
        } else {
            greater[i] = -1;
        }
        pref[i+1] = pref[i] + greater[i];
    }
    int l = 1, r = k;
    while(r <= n){
        if(pref[r] - pref[l-1] >= 0){
            return {l, r};
        }
        if(pref[r-k+1] < pref[l-1]){
            l = r-k+2;
        }
        r++;
    }
    return {0,0};
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lo = 1, hi = 3e5, mid = 0;
    int left, right;
    while (lo < hi) {
        mid = (lo + hi + 1) / 2;
        auto [l, r] = isSubMedian(a, k, mid);
        if (l == 0) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    auto [l, r] = isSubMedian(a, k, lo);;
    cout << lo << " " <<  l << " " << r << "\n";
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