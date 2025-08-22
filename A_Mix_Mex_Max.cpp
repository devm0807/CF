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

int mex(vector<int> &arr, int l, int r)
{
  sort(arr.begin()+l, arr.end()+r);

  int mex = 0;
  for (int idx = 0; idx <= r; idx++)
  {
    if (arr[idx] == mex || arr[idx]==-1)
    {
      arr[idx]=mex;
      mex += 1;
    }
  }

  return mex;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool has_zero = false;
    unordered_set<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            has_zero = true;
        } else if (a[i] != -1) {
            nums.insert(a[i]);
        }
    }
    if (has_zero) {
        cout << "NO" << endl;
    } else {
        if (nums.size() <= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
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