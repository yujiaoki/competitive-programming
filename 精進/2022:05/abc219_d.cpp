#include <bits/stdc++.h>
// #include<atcoder/all>
// using namespace atcoder;
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

int dp[302][302][302];

int main(void){
    // Your code here! dp臭がすんごい
    int n; cin >> n;
    int x,y; cin >> x >> y;
    vi a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n+1) rep(j,x+1) rep(k,y+1) dp[i][j][k] = 500;
    rep(i,n+1) dp[i][0][0] = 0;
    rep(i,n) {
        rep(j,x+1) {
            int target_x = min(j + a[i], x);
            rep(k,y+1) {
                        dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
                        int target_y = min(k + b[i], y);
                        dp[i+1][target_x][target_y] = min(dp[i+1][target_x][target_y],dp[i][j][k]+ 1);
                    }
            }
    }
    if (dp[n][x][y] == 500) {
        cout << -1 << endl;
    } else {
        cout << dp[n][x][y] << endl;
    }
}
