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
    vector<int> query(n);
    iota(query.begin(), query.end(), 1);
    int op = -1, cl = -1;
    if(ask(query)){
        int l=1,r=n, mid;
        while(l+1<r){
            mid = l + (r-l)/2;
            vector<int> q(mid);
            iota(q.begin(), q.end(), 1);
            if(ask(q)){
                r = mid;
            }else{
                l = mid;
            }
        }
        op = r-1;
        cl = r;
    } else {
        cl = 1;
        op = n;
    }
    string s;
    // i ) j ) ( )
    // ( ) ( ) ( )  6
    // ( ) ) ) ( )  2
    // ) ) ( ) ( )  3
    // ) ) ) ) ( )  1
    for(int i=1;i<=n-1;i+=2){
        switch(ask({i,cl,i+1,cl,op,cl})){
            case 6:
                s.push_back('(');
                s.push_back('(');
                break;
            case 2:
                s.push_back('(');
                s.push_back(')');
                break;
            case 3:
                s.push_back(')');
                s.push_back('(');
                break;
            case 1:
                s.push_back(')');
                s.push_back(')');
                break;
            default:
                break;
        }
    }
    if(n%2!=0){
        if(ask({n,cl})){
            s.push_back('(');
        }else{
            s.push_back(')');
        }
    }
    answer(s);
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