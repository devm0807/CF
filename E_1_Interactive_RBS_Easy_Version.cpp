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
int query(const vector<int>& vec) {
    cout << "? " << vec.size();
    for (int i : vec) {
        cout << " " << i;
    }
    cout << endl;
    int result;
    cin >> result;
    return result;
}

void solve()
{
    int n;
    cin >> n;
    
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 1);

    int f_all = query(idx);

    int p = -1;
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        vector<int> q;
        for(int i=1;i<=mid;i++){
            q.push_back(i);
        }
        for(int i=1;i<=n;i++){
            q.push_back(i);
        }
        int f_mid = query(q);

        if(f_mid >= f_all && f_mid !=0) {
            p = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    string ans(n, ' ');
    ans[p-1] = '(';

    for(int i=0;i<p-1;i++){
        ans[i] = ')';
    }
    for(int i=p+1;i<=n;i++){
        if(query({p,i}) == 1) {
            ans[i-1] = ')';
        } else {
            ans[i-1] = '(';
        }
    }
    
    cout << "! " << ans << endl;
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