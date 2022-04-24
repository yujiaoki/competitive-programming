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
int h, w;
char a[2002][2002];

int main(void)
{
    // Your code here!
    cin >> h >> w;
    rep(i, h) rep(j, w) cin >> a[i][j];
    vvi cost(h, vi(w, 0));
    rep(i, h) rep(j, w)
    {
        if (a[i][j] == '-')
            cost[i][j] = -1;
        else
            cost[i][j] = 1;
    }
    vvi opt(h, vi(w, 0));
    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = w - 1; j >= 0; j--)
        {
            if (i == h - 1 && j == w - 1)
                continue;
            if ((i + j) % 2 == 0)
            {
                if (i == h - 1)
                {
                    opt[i][j] = opt[i][j + 1] + cost[i][j + 1];
                    continue;
                }
                if (j == w - 1)
                {
                    opt[i][j] = opt[i + 1][j] + cost[i + 1][j];
                    continue;
                }
                opt[i][j] = max(opt[i + 1][j] + cost[i + 1][j], opt[i][j + 1] + cost[i][j + 1]);
            }
            else
            {
                if (i == h - 1)
                {
                    opt[i][j] = opt[i][j + 1] - cost[i][j + 1];
                    continue;
                }
                if (j == w - 1)
                {
                    opt[i][j] = opt[i + 1][j] - cost[i + 1][j];
                    continue;
                }
                opt[i][j] = min(opt[i + 1][j] - cost[i + 1][j], opt[i][j + 1] - cost[i][j + 1]);
            }
        }
    }
    // 逆から考えるやつ、最適と聞かれたらDPを疑う
    if (opt[0][0] < 0)
        cout << "Aoki" << endl;
    else if (opt[0][0] == 0)
        cout << "Draw" << endl;
    else
        cout << "Takahashi" << endl;
}
