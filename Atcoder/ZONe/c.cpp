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
int R, C;
int A[502][502];
int B[502][502];
int board[502][502];

void dfs(int i, int j, int cost)
{
    if (i < 0 || i >= R || j < 0 || j >= C)
        return;
    if (cost >= board[i][j])
        return;
    if (cost < board[i][j])
        board[i][j] = cost;
    // if (i == R - 1 && j == C - 1)
    //     return;
    if (j < C - 1)
    {
        dfs(i, j + 1, board[i][j] + A[i][j]);
    }
    if (j > 0)
    {
        dfs(i, j - 1, board[i][j] + A[i][j - 1]);
    }
    if (i < R - 1)
    {
        dfs(i + 1, j, board[i][j] + B[i][j]);
    }
    FOR(k, 1, i)
    {
        dfs(i - k, j, board[i][j] + 1 + k);
    }
}

int main(void)
{
    // Your code here!
    cin >> R >> C;
    rep(i, R) rep(j, C - 1) cin >> A[i][j];
    rep(i, R - 1) rep(j, C) cin >> B[i][j];
    rep(i, 502) rep(j, 502) board[i][j] = INF;
    dfs(0, 0, 0);
    cout << board[R - 1][C - 1] << endl;
    // rep(i, R)
    // {
    //     rep(j, C) cout << board[i][j] << " ";
    //     cout << endl;
    // }
}
