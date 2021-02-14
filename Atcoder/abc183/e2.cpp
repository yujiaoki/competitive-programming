#include <bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
typedef long long ll;
const ll MOD=1000000007;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T>auto MAX(const T& a) { return *max_element(a.begin(),a.end()); }
template<class T>auto MIN(const T& a) { return *min_element(a.begin(),a.end()); }
template<class T, class U>U SUM(const T& a, const U& v) { return accumulate(a.begin(),a.end(), v); }
template<class T, class U>U COUNT(const T& a, const U& v) { return count(a.begin(),a.end(), v); }
template<class T, class U>int LOWER(const T& a, const U& v) { return lower_bound(a.begin(),a.end(), v) - a.begin(); }
template<class T, class U>int UPPER(const T& a, const U& v) { return upper_bound(a.begin(),a.end(), v) - a.begin(); }
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { int g = GCD(a, b); return a / g * b; }
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int,int> P;
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
int h,w;
int dx[] = {1,0,1};
int dy[] = {0,1,1};
ll board[2002][2002];
void dfs(int x,int y) {
    // if (x < 0 || x >= h || y < 0 || y >= w) return;
    // if (board[x][y] == -1) return;
    // board[x][y] += 1;
    if (x == h-1 && y == w-1 ) return;
    rep(i,3) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (board[nx][ny] == -1) continue;
        board[nx][ny] += board[x][y] + 1;
        dfs(nx,ny);
    }
}
// void dfs2(int x,int y) {
//     if (x < 0 || x >= h || y < 0 || y >= w) return;
//     if (board[x][y] == -1) return;
//     if (x == h-1 && y == w-1 ) return;
//     rep(i,3) {
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
//         if (board[nx][ny] == -1) continue;
//         board[nx][ny] += board[x][y];
//         dfs(nx,ny);
//     }
// }
using mint = modint1000000007;

mint dp[2005][2005];
mint dpx[2005][2005];
mint dpy[2005][2005];
mint dpxy[2005][2005];
int main(void){
    // Your code here!
    cin >> h >> w;
    vs s(h);
    rep(i,h) cin >> s[i];
    dp[0][0] = 1;
    dpx[0][0] = 1;
    dpy[0][0] = 1;
    dpxy[0][0] = 1;
    rep(i,h) rep(j,w) {
        if (i == 0 && j == 0) continue;
        if (s[i][j] == '#') continue;
        if (j) dpx[i][j] += dpx[i][j-1];
        if (i) dpy[i][j] += dpy[i-1][j];
        if (i && j) dpxy[i][j] += dpxy[i-1][j-1];
        dp[i][j] += dpx[i][j];
        dp[i][j] += dpy[i][j];
        dp[i][j] += dpxy[i][j];
        dpx[i][j] += dp[i][j];
        dpy[i][j] += dp[i][j];
        dpxy[i][j] += dp[i][j];
    }
    cout << dp[h-1][w-1].val() << endl;
}

