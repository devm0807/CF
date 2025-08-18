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

bool predicate(){
    // This function can be used to check some condition
    // For example, checking if a number is prime or not
    return true; // Placeholder implementation
}
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> freq(26, 0);
    for(int i=0;i<n;i++){
        freq[s[i]-'A']++;
    }
    for(int i=0;i<freq[19];i++){
        cout << 'T';
    }
    for(int i=0;i<freq[5];i++){
        cout << 'F';
    }
    for(int i=0;i<freq[13];i++){
        cout << 'N';
    }
    for(int i=0;i<26;i++){
        if(i!=5 && i!=13 && i!=19){
            for(int j=0;j<freq[i];j++){
                cout << char('A'+i);
            }
        }
    }
    cout << endl;
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