#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, start, end) for (int i = start; i <= end; i++)
const int INF = 1001001001;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
typedef long long ll;
const ll MOD = 1000000007;
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
auto MAX(const T &a) { return *max_element(a.begin(), a.end()); }
template <class T>
auto MIN(const T &a) { return *min_element(a.begin(), a.end()); }
template <class T, class U>
U SUM(const T &a, const U &v) { return accumulate(a.begin(), a.end(), v); }
template <class T, class U>
U COUNT(const T &a, const U &v) { return count(a.begin(), a.end(), v); }
template <class T, class U>
int LOWER(const T &a, const U &v) { return lower_bound(a.begin(), a.end(), v) - a.begin(); }
template <class T, class U>
int UPPER(const T &a, const U &v) { return upper_bound(a.begin(), a.end(), v) - a.begin(); }
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
int LCM(int a, int b)
{
    int g = GCD(a, b);
    return a / g * b;
}
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef set<int> si;
//---------------------------------------------------------------------------------------------------

int main(void)
{
    // Your code here!
    ll n, m;
    cin >> n >> m;
    vll a(m), b(m), c(m), d(m);
    rep(i, m)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }
    vector<vector<pair<ll, ll>>> G(n);
    rep(i, m)
    {
        G[a[i]].push_back({b[i], (ll)(1e9) * c[i] + d[i]});
        G[b[i]].push_back({a[i], (ll)(1e9) * c[i] + d[i]});
    }
    vll dd(n, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    dd[0] = 0;
    que.push({0, 0});
    while (!que.empty())
    {
        pair<ll, ll> p = que.top();
        que.pop();
        ll v = p.second;
        if (dd[v] < p.first)
            continue;
        rep(i, G[v].size())
        {
            ll to = G[v][i].first;
            ll C = G[v][i].second / (ll)(1e9);
            ll D = G[v][i].second % (ll)(1e9);
            ll mi = 1e18;
            ll j = -dd[v] - 1 + floor(sqrt(D));
            if (dd[v] + j + 1 > 0)
            {
                mi = min(mi, dd[v] + j + C + D / (dd[v] + j + 1));
            }
            j = -dd[v] - 1 + ceil(sqrt(D));
            if (dd[v] + j + 1 > 0)
            {
                mi = min(mi, dd[v] + j + C + D / (dd[v] + j + 1));
            }

            if (dd[to] > mi)
            {
                dd[to] = mi;
                que.push({dd[to], to});
            }
        }
    }
    if (dd[n - 1] == 1e18)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dd[n - 1] << endl;
    }
}
