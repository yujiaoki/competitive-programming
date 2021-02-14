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
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int h,w;
void solve(int x,int y,vvi &board) {
    if (x < 0 || x >= h || y < 0 || y >= w) return;
    if (board[x][y] != 0) return ;
    board[x][y] = 1;
    rep(i,4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        while(!(nx < 0 || nx >= h || ny < 0 || ny >= w)) {
            if (board[nx][ny] != 0) break;
            board[nx][ny] = 1;
            nx += dx[i];
            ny += dy[i];
        }
        // solve(nx,ny,board);
    }
}
int main(void){
    // Your code here!
    int n,m; cin >> h >> w >> n >> m;
    vi a(n),b(n),c(m),d(m);
    vvi board(h,vi(w,0));
    rep(i,n) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    rep(i,m) {
        cin >> c[i] >> d[i];
        c[i]--;
        d[i]--;
        board[c[i]][d[i]] = -1;
    }
    ll ans = 0;
    rep(i,n) {
        solve(a[i],b[i],board);
    }
    rep(i,h) {
        rep(j,w) {
            if (board[i][j] == 1) ans++;
            // cout << board[i][j] << " ";
        }
        // cout  << endl;
    }
    cout << ans << endl;
}
