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


const int LOG_X = 29;
 
struct node {
    int children[2] { -1, -1 };
    int last = -1;
};
 
int find(const vector<node>& trie, int value, int border) {
    int res = -1;
    int current = 0;
    bool ok = true;
    for (int position = LOG_X; ok && position >= 0; position--) {
        int x_bit = (value >> position) & 1;
        int k_bit = (border >> position) & 1;
        auto& children = trie[current].children;
        if (k_bit == 1) {
            if (children[x_bit ^ 1] != -1) {
                current = children[x_bit ^ 1];
            } else {
                ok = false;
            }
        } else {
            if (children[x_bit ^ 1] != -1) {
                res = max(res, trie[children[x_bit ^ 1]].last);
            }
            if (children[x_bit] != -1) {
                current = children[x_bit];
            } else {
                ok = false;
            }
        }
    }
    if (ok) {
        res = max(res, trie[current].last);
    }
    return res;
}
 
void add(vector<node>& trie, int value, int index) {
    int current = 0;
    trie[current].last = max(trie[current].last, index);
    for (int position = LOG_X; position >= 0; position--) {
        int x_bit = (value >> position) & 1;
        if (trie[current].children[x_bit] == -1) {
            trie[current].children[x_bit] = trie.size();
            trie.push_back(node());
        }
        current = trie[current].children[x_bit];
        trie[current].last = max(trie[current].last, index);
    }
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> S(n);
    vector<int> cnt(51, 0);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
        if(S[i] == 0){
            total += 1;
        } else {
            total += S[i];
        }
    }
    cout << total << "\n";
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