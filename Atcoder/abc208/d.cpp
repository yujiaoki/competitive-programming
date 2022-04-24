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
int d[402];
int main(void)
{
    // Your code here!
    int n, m;
    cin >> n >> m;
    vvi cost(n, vi(n, INF));
    vector<vector<P>> G(n); // Firstが到達先、Secondがコスト
    vi a(m), b(m), c(m);
    rep(i, m)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        cost[a[i]][b[i]] = c[i];
        G[a[i]].push_back({b[i], c[i]});
    }
    ll ans = 0;
    rep(s, n) rep(k, n)
    {
        rep(i, n) d[i] = INF;
        d[s] = 0;
        vector<vector<P>> nG(n);
        rep(i, G[s].size())
        {
            if (G[s][i].first > k)
                ans += G[s][i].second;
            else
                nG[s].push_back({G[s][i].first, G[s][i].second});
        }

        rep(i, m)
        {
            if (a[i] == s)
                continue;
            if (a[i] <= k && b[i] <= k)
            {
                nG[a[i]].push_back({b[i], c[i]});
            }
        }
        priority_queue<P, vector<P>, greater<P>> que;
        que.push({0, s});
        while (!que.empty())
        {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (d[v] < p.first)
                continue;
            rep(i, nG[v].size())
            {
                P e = nG[v][i];
                if (d[e.first] > d[v] + e.second)
                {
                    d[e.first] = d[v] + e.second;
                    // if (e.first <= k)
                    que.push({d[e.first], e.first});
                }
            }
        }
        rep(i, n)
        {
            if (d[i] != INF)
                ans += d[i];
        }
    }
    cout << ans << endl;
}
