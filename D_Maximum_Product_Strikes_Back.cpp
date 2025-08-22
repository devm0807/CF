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

bool isAcyclic(vector<vector<ll>>& adj, vector<ll>& visited, ll u, ll parent) {
  if(visited[u]) return false;
  visited[u] = 1;

  bool b = true;
  for(auto v:adj[u]) {
    if(v != parent)
      b &= isAcyclic(adj, visited, v, u);
  }
  return b;
}

int ask(vector<int> query){
    int k = query.size();
    cout << "? " << k << " ";
    for(int i=0;i<k;i++){
        cout << query[i] << " ";
    }
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}
void answer(string s){
    cout << "! " << s << endl;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    int ap = n, as = 0;
    for(int i = 0, l = -1; i <= n; i++) {
        if (i == n || a[i] == 0) {
            int cnt = 0;
            bool neg = false;
            int left = -1, right = -1;
            int cl = 0, cr = 0;
            for (int j = l+1; j < i; j++) {
                neg ^= a[j] < 0;
                if (a[j] < 0) {
                    right = j;
                    cr = 0;
                }
 
                if (abs(a[j]) == 2) {
                    cnt++, cr++;
                    if (left == -1) cl++;
                }
 
                if (a[j] < 0 && left == -1) {
                    left = j;
                }
            }
            if (neg) {
                if (cnt - cl > cnt - cr) {
                    right = i;
                    cnt -= cl;
                } else {
                    left = l;
                    cnt -= cr;
                }
            } else {
                left = l, right = i;
            }
            if (ans < cnt) {
                ans = cnt;
                ap = left + 1, as = n - right;
            }
 
            l = i;
        }
    }
    cout << ap << ' ' << as << endl;
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