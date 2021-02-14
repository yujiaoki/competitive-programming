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
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {0,1,-1,1,-1,0,1,-1};
int ans = 1;
int sx = -1,sy = -1;
int h,w; 
vvi board(12,vi(12,0));
vector<string> S(10);
void dfs(int x,int y,int pre_orien,int count) {
    if (x < 0 || x >= h || y < 0 || y >= w) return;
    if (board[x][y] == 1) {
        if (x == sx && y == sy) ans = min(ans,count);
        return;
    }
    if (S[x][y] == '.' ||board[x][y] == 1 ) return;
    board[x][y] == 1;
    if (x == 0 || x == h-1 || y == 0 || y == w-1 || !(board[x+1][y] == 1 && board[x-1][y] == 1 && board[x][y+1] == 1 && board[x][y-1] == 1 ) ) {
        rep(i,8) {
            if (i == pre_orien) {
                dfs(x + dx[i],y+dy[i],i,count);
            } else {
                dfs(x + dx[i],y+dy[i],i,count+1);
            } 
        }
    } 
    return;
}
int main(void){
    // Your code here!
    cin >> h >> w;
    rep(i,h) cin >> S[i];
    rep(i,h) rep(j,w) {
        if (S[i][j] == '#') {
            sx = i;
            sy = j;
        }
    }
    dfs(sx,sy,-1,0);
    cout << ans << endl;
}
