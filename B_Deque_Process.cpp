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

long long countinv(const vector<int>& arr) {
    long long inv = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (arr[i] > arr[j])
                inv++;
    return inv;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), q;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    int l = 0, r = n-1;
    int type = 1;
    string s = "";
    while (l < r){
        if(type == 1){
            if(p[l] < p[r]){
                q.push_back(p[r--]);
                s.push_back('R');
                q.push_back(p[l++]);
                s.push_back('L');
                type = 2;
            } else {
                q.push_back(p[l++]);
                s.push_back('L');
                q.push_back(p[r--]);
                s.push_back('R');
                type = 2;
            }
        } else {
            if(p[l] < p[r]){
                q.push_back(p[l++]);
                s.push_back('L');
                q.push_back(p[r--]);
                s.push_back('R');
                type = 1;
            } else {
                q.push_back(p[r--]);
                s.push_back('R');
                q.push_back(p[l++]);
                s.push_back('L');
                type = 1;
            }
        }
    }
    if (l==r){
        s.push_back('L');
    }
    cout << s << endl;
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