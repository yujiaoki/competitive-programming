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
const ll MOD = 998244353;
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
int n;
string s;
ll dp[1024][1024][10] = {0};
int main(void)
{
    // Your code here!

    cin >> n >> s;

    rep(i, n)
    {
        int x = s[i] - 'A';
        rep(u, 1024)
        {
            rep(j, 10)
            {
                dp[i + 1][u][j] = dp[i][u][j];
                if (j == x)
                {
                    dp[i + 1][u][j] += dp[i][u][j];
                    dp[i + 1][u][j] %= MOD;
                }
            }
        }
        rep(v, 1024)
        {
            if (v & (1 << x))
                continue;
            rep(j, 10)
            {
                dp[i + 1][v | (1 << x)][x] += dp[i][v][j];
                dp[i + 1][v | (1 << x)][x] %= MOD;
            }
        }

        dp[i + 1][(1 << x)][x]++;
        dp[i + 1][(1 << x)][x] %= MOD;
    }
    ll res = 0;
    rep(u, 1024) rep(j, 10)
    {
        res += dp[n][u][j];
        res %= MOD;
    }
    cout << res << endl;
}
